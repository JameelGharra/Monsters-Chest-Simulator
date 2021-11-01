#include <iostream>
#include "DropsLoader.h"

DropsLoader *const DropsLoader::instance = nullptr;

/**
 * analyzes the files that are relevant to be drops
 */
DropsLoader::DropsLoader ()
    : current_directory (std::filesystem::path ("Monsters"))
{

}
const DropsLoader &DropsLoader::get_instance ()
{
  if (instance == nullptr)
    {
      instance = new DropsLoader ();
    }
  return *instance;
}
DropsLoader::~DropsLoader ()
{
  delete instance;
}
void DropsLoader::get_monster_name (const std::filesystem::directory_entry
                                    &directory_entry, std::string &monster_name)
{
  size_t prefix_under_score;
  std::string file_name;
  file_name = directory_entry.path ().filename ().string ();
  if (file_name.find (instance->file_prefix) != std::string::npos)
    {
      prefix_under_score = file_name.find ('_');
      if (prefix_under_score >= file_name.length () - 1)
        {
          throw std::invalid_argument ("Error: One of the files have bad name.");
        }
      monster_name = file_name.substr (0, prefix_under_score + 1);
    }
}
void
DropsLoader::retrieve_monster_drops (const std::filesystem::directory_entry &entry, std::string &drop_line)
{
  instance->file_reader.open (entry.path ());
  if (instance->file_reader.is_open ())
    {
      while (getline (instance->file_reader, drop_line))
        {
          retrieve_drop_data (drop_line);
        }
    }
}
void DropsLoader::load_monster_drops ()
{
  std::string monster_name, drop_line;
  for (const auto &entry : std::filesystem::directory_iterator (instance->current_directory))
    {
      get_monster_name (entry, monster_name);
      retrieve_monster_drops (entry, drop_line);
      
    }
}
void DropsLoader::retrieve_drop_data (const std::string &line)
{
  std::regex drop_regex ("([@$]) (\\w+) ([1-3]) ([1-9]{1}[0-9]*) ([1-9]{1}[0-9]*)\\/([1-9][0-9]*)");
  std::smatch matcher;
  if (std::regex_search (line, matcher, drop_regex))
    {
      for (int i = 1; i < matcher.size (); ++i)
        {
          instance->arr_regex_drop.push_back (matcher.str (i));
        }
      return;
    }
  throw std::invalid_argument ("Error: bad drop line in the drop file.");
}
void DropsLoader::parse_regex_groups ()
{
  //@ Clean_Avantoe 1 10 10231/20
}
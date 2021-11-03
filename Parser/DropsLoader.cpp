#include <iostream>
#include "DropsLoader.h"

DropsLoader *DropsLoader::instance = nullptr;

/**
 * analyzes the files that are relevant to be drops
 */
DropsLoader::DropsLoader ()
    : current_directory (std::filesystem::path (R"(C:\Users\jamee\Desktop\C++\Araxxi-Chest-Simulator\Monsters)"))
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
  prefix_under_score = file_name.find ('_');
  if (prefix_under_score >= file_name.length () - 1)
    {
      throw std::invalid_argument ("Error: One of the files have bad name.");
    }
  monster_name = file_name.substr (0, prefix_under_score + 1);

}
void debug_print_drops() {
  int counter = 1;
  for(const auto &ptr : DropsLoader::drop_tables) {
    if(!(*ptr)->empty())
      std::cout << "Table #" << counter << std::endl;
      for(const auto &element : (**ptr)) {
        std::cout << "name: " << element.name << " - quantity: "
        << element.quantity << " - chance: " << element.chance << std::endl;
      }
      ++counter;
  }
}
void
DropsLoader::retrieve_monster_drops (const std::filesystem::directory_entry &entry, std::string &drop_line)
{
  instance->file_reader.open (entry.path ());
  if (instance->file_reader.is_open ())
    {
      current_guaranteed_drops = new std::set<Drop> ();
      current_food_drops = new std::set<Drop> ();
      current_main_drops = new std::set<Drop> ();
      current_unique_drops = new std::set<Drop> ();
      while (getline (instance->file_reader, drop_line))
        {
          retrieve_drop_data (drop_line);
        }
        debug_print_drops();
    }
}
void DropsLoader::load_monster_drops ()
{
  std::string monster_name, drop_line;
  for (const auto &entry : std::filesystem::directory_iterator (instance->current_directory))
    {
      if (entry.path ().filename ().string ().find (instance->file_prefix)
          != std::string::npos)
        {
          get_monster_name (entry, monster_name);
          retrieve_monster_drops (entry, drop_line);
        }
    }
}
void DropsLoader::retrieve_drop_data (const std::string &line)
{
  if (!instance->arr_regex_drop.empty ())
    {
      instance->arr_regex_drop.clear ();
    }
  std::regex drop_regex ("(\\w+) ([1-4]) ([1-9]{1}[0-9]*) ([1-9]{1}[0-9]*)\\/([1-9][0-9]*)");
  std::smatch matcher;
  if (std::regex_search (line, matcher, drop_regex))
    {
      for (int i = 1; i < matcher.size (); ++i)
        {
          instance->arr_regex_drop.push_back (matcher.str (i));
        }
      parse_regex_groups ();
      return;
    }
  throw std::invalid_argument ("Error: bad drop line in the drop file.");
}
void DropsLoader::filter_under_scores (std::string &str)
{
  size_t under_score_pos;
  while ((under_score_pos = str.find ('_')) != std::string::npos)
    {
      str.replace (under_score_pos, 1, " ");
    }
}
void DropsLoader::parse_regex_groups ()
{
  filter_under_scores (instance->arr_regex_drop[DROP_NAME]);
  (*drop_tables[std::stoi (instance->arr_regex_drop[TABLE_ID])])->emplace (
      Drop (
          instance->arr_regex_drop[DROP_NAME],
          std::stoi (instance->arr_regex_drop[DROP_QUANTITY]),
          std::stof (instance->arr_regex_drop[DROP_CHANCE_TOP])
          / std::stof (instance->arr_regex_drop[DROP_CHANCE_DOWN])
      ));
  //Clean_Avantoe 1 10 10231/20
}
#include "DropsLoader.h"
#include "../Monsters/Monster.h"
#include "../MonsterFactory.cpp"

/**
 * analyzes the files that are relevant to be drops
 */
DropsLoader::DropsLoader ()
    : current_directory (std::filesystem::current_path ())
{
  size_t prefix_under_score;
  std::string file_name, monster_name;
  for (const auto &entry : std::filesystem::directory_iterator (current_directory))
    {
      file_name = entry.path ().string ();
      if ((prefix_under_score = file_name.find (file_prefix)
                                != std::string::npos)
          && prefix_under_score < file_name.length ())
        {
          monster_name = file_name.substr(0, prefix_under_score+1);
          if(pre_loaded_monsters.contains (monster_name)) {
            
          }
        }
    }
}

const DropsLoader &DropsLoader::get_instance ()
{
  return instance;
}
/**
 * MonsterFactory.cpp: matches the right type for each monster.
 */

#include "Monster.h"
#include "../Parser/DropsLoader.h"
#include "Araxxi.cpp"

class MonsterFactory {
 private:
  static DropsLoader::preloaded_monsters_id
  map_monster (const std::string &monster_name)
  {
    const DropsLoader &loader = DropsLoader::get_instance ();
    if (monster_name == loader.preloaded_monster[loader.MONSTER_ARAXXI])
      {
        return loader.MONSTER_ARAXXI;
      }
    return loader.MONSTER_UNKNOWN;
  }
 public:
  explicit MonsterFactory (const std::string &monster_name)
  {
    switch (map_monster (monster_name))
      {
        case DropsLoader::MONSTER_ARAXXI {
          
        }
      }
  }
};


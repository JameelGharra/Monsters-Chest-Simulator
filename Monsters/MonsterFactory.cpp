#include "MonsterFactory.h"

const MonsterFactory *MonsterFactory::instance = nullptr;

const MonsterFactory *MonsterFactory::get_instance ()
{
  if (instance == nullptr)
    {
      instance = new MonsterFactory ();
    }
  return instance;
}

Monster *MonsterFactory::create_monster (const std::string &monster_name)
{
  if (monster_name == instance->preloaded_monster_name[MONSTER_ARAXXI])
    {
      //return new Araxxi();
      return new Monster(
          false,
          MonstersLoader::current_guaranteed_drops,
          MonstersLoader::current_food_drops,
          MonstersLoader::current_main_drops,
          MonstersLoader::current_unique_drops
      );
    }
  else
    {
      return new Monster(
                        false,
                        MonstersLoader::current_guaranteed_drops,
                         MonstersLoader::current_food_drops,
                         MonstersLoader::current_main_drops,
                         MonstersLoader::current_unique_drops
                         );
    }
}
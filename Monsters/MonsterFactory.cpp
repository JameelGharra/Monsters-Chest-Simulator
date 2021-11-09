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
      return new Araxxi();
    }
  else
    {
      return Monster();
    }
}
/**
 * MonsterFactory.h: matches the right type for each monster.
 */

#ifndef MONSTER_FACTORY_H
#define MONSTER_FACTORY_H

#include "Monster.h"
#include "../Parser/MonstersLoader.h"
/* preloaded monsters */
#include "Araxxi.cpp"

class MonsterFactory {
 private:
  const static short preloaded_monsters_amount = 1;
  enum preloaded_monster_id {
      MONSTER_ARAXXI
  };
  const std::string preloaded_monster_name[preloaded_monsters_amount] = {
      "Araxxi"
  };
  MonsterFactory() = default;
  ~MonsterFactory() = default;
  const static MonsterFactory* instance;

 public:
  static Monster *create_monster(const std::string &monster_name);
  const static MonsterFactory *get_instance();
};
#endif
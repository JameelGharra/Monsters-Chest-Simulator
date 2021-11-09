#include "Monster.h"

Monster::Monster (
    const bool &enraged, const auto *const &guaranteed_drops, const auto *const &food_drops,
    const auto *const &main_drops, const auto *const &unique_drops)
    :
    is_enraged (enraged),
    is_guaranteed_drops (!guaranteed_drops->empty ()),
    is_food_drops (!food_drops->empty ()),
    is_main_drops (!main_drops->empty ()),
    is_unique_drops (!unique_drops->empty ())
{}

std::set<Drop> Monster::roll_drop ()
{
  RandomGenerator::get_instance()->operator() (guaranteed_drops);
  RandomGenerator::get_instance()->operator() (food_drops);
  RandomGenerator::get_instance()->operator()(main_drops);
  RandomGenerator::get_instance()->operator()(unique_drops);
}
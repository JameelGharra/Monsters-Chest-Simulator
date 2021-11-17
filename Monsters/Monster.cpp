#include "Monster.h"

Monster::Monster (
    const bool &enraged, const auto *const &guaranteed_drops_, const auto *const &food_drops_,
    const auto *const &main_drops_, const auto *const &unique_drops_)
    :
    guaranteed_drops(guaranteed_drops_),
    food_drops(food_drops_),
    main_drops(main_drops_),
    unique_drops(unique_drops_),
    is_enraged (enraged),
    is_guaranteed_drops (!guaranteed_drops->empty ()),
    is_food_drops (!food_drops->empty ()),
    is_main_drops (!main_drops->empty ()),
    is_unique_drops (!unique_drops->empty ())
{}

std::set<const Drop*> Monster::roll_drop ()
{
  std::set<const Drop*> roll_result;
  RandomGenerator::get_instance()->operator() (guaranteed_drops);
  RandomGenerator::get_instance()->operator() (food_drops);
  RandomGenerator::get_instance()->operator()(main_drops);
  RandomGenerator::get_instance()->operator()(unique_drops);
  return std::move(roll_result);
}
/**
 * Monster.cpp: a class that represents the boss and its' drop
 * mechanics.
 */

#ifndef MONSTER_H
#define MONSTER_H

#include <set>
#include "../Parser/Drop.cpp"
#include "RandomGenerator.cpp"

struct Monster {
    bool is_enraged = false;
    bool is_guaranteed_drops;
    bool is_food_drops;
    bool is_main_drops;
    bool is_unique_drops;

    const std::set<Drop> *const guaranteed_drops;
    const std::set<Drop> *const food_drops;
    const std::set<Drop> *const main_drops;
    const std::set<Drop> *const unique_drops;

    Monster (const bool &enraged, const auto* const &guaranteed_drops, const auto* const &food_drops,
             const auto* const &main_drops, const auto* const &unique_drops);
    virtual std::set<Drop> roll_drop ();
};
#endif
/**
 * Monster.cpp: a class that represents the boss and its' drop
 * mechanics.
 */

#include <set>
#include "Drop.cpp"

struct Monster {
    bool is_enraged;
    bool is_guaranteed_drops;
    bool is_food_drops;
    bool is_main_drops;
    bool is_unique_drops;

    std::set<Drop> drops;
    
    Monster (const bool &enraged, const bool &guaranteed, const bool &food,
             const bool &main, const bool &unique) :
        is_enraged (enraged),
        is_guaranteed_drops (guaranteed),
        is_food_drops (food),
        is_main_drops (main),
        is_unique_drops (unique)
    {}
    virtual std::set<Drop> roll_drop() = 0;
};
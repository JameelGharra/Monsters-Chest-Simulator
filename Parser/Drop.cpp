/**
 * Drop.cpp: represents a drop for a monster.
 */

#include <string>
struct Drop {
    const std::string name;
    const float chance;
    const int min_quantity;
    const int max_quantity;

    Drop (std::string name_, const int &min_quantity_, const int &max_quantity_, const float &chance_)
        :
        name (std::move (name_)), chance (chance_), min_quantity(min_quantity_),
        max_quantity(max_quantity_)
    {
    }
    bool operator< (const Drop &other) const
    {
      return this->name.compare(other.name) < 0 ;
    }
};
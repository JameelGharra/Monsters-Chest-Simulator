/**
 * Drop.cpp: represents a drop for a monster.
 */

#ifndef DROP_H
#define DROP_H

#include <string>
struct Drop {
    const std::string name;
    const float chance;
    const int min_quantity;
    const int max_quantity;
    mutable int recent_quantity;

    Drop (std::string name_, const int &min_quantity_, const int &max_quantity_, const float &chance_)
        :
        name (std::move (name_)), chance (chance_), min_quantity(min_quantity_),
        max_quantity(max_quantity_), recent_quantity(0)
    {
    }
    bool operator< (const Drop &other) const
    {
      return this->name.compare(other.name) < 0 ;
    }
};
#endif
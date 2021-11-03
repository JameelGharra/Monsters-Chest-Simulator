/**
 * Drop.cpp: represents a drop for a monster.
 */

#include <string>

struct Drop {
    const std::string name;
    const float chance;
    const int quantity;

    Drop(std::string name_, const int &quantity_, const float &chance_):
    name(std::move(name_)), chance(chance_), quantity(quantity_) {
    }
    bool operator<(const Drop &other) const {
      return this->name != other.name;
    }
};
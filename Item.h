/**
* Item.h: represents an item inside the world of RuneScape.
*/

#include <string>
#include <utility>

struct Item {
    const std::string name;
    int quantity;

    Item(std::string name):name(std::move(name)) {}
};
/**
 * Drop.cpp: represents a drop for a monster.
 */

#include <string>
#include "Item.h"

 struct Drop: public Item {
  const float chance_mode_easy;
  const float chance_mode_hard;

  Drop (const std::string &name, const float &chance_easy, const float &chance_hard) :
      Item(name),
      chance_mode_easy (chance_easy),
      chance_mode_hard (chance_hard)
  {}
};
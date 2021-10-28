/**
 * DropsLoader: responsible to retrieve all the drop rates for each
 * monster if available and found in the directory.
 */

#ifndef DROPSLOADER_H
#define DROPSLOADER_H

#include <filesystem>
#include <set>
#include <vector>
#include <fstream>
#include "../Monsters/Monster.h"

class DropsLoader {
 private:
  const static DropsLoader instance;
  const std::filesystem::path current_directory;
  const std::string msg_bad_alloc = "Error: Bad memory allocation.";
  const std::string file_prefix = "Drops_";

  const static std::set<Monster> available_monsters;
  DropsLoader ();

 public:
  enum preloaded_monsters_id {
      MONSTER_ARAXXI,
      MONSTER_UNKNOWN
  };
  const std::vector<std::string> preloaded_monster = {
      "Araxxi"
  };

  void operator= (const DropsLoader &other) = delete;
  static const DropsLoader &get_instance ();
};

#endif
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
#include <regex>
//#include "../Monsters/Monster.h"

class DropsLoader {
 private:
  static DropsLoader* const instance;
  const std::filesystem::path current_directory;
  const std::string msg_bad_alloc = "Error: Bad memory allocation.";
  const std::string file_prefix = "Drops_";
  std::ifstream file_reader;
  std::vector<std::string> arr_regex_drop;
  DropsLoader ();
  ~DropsLoader();
  static void get_monster_name(const std::filesystem::directory_entry &entry, std::string &monster_name);
  static void load_monster_drops();
  static void retrieve_monster_drops(const std::filesystem::directory_entry &entry, std::string &drop_line);
  static void retrieve_drop_data(const std::string &line);
  static void parse_regex_groups();

  enum DropRegex {
      BOSS_MODE,
      DROP_NAME,
      TABLE_ID,
      DROP_QUANTITY,
      DROP_CHANCE_TOP,
      DROP_CHANCE_DOWN
  };

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
/**
 * MonstersLoader: responsible to retrieve all the drop rates for each
 * monster and load them to a monster object (possibly a preloaded monster
 * if found).
 */

#ifndef MONSTERSLOADER_H
#define MONSTERSLOADER_H

#include <iostream>
#include <filesystem>
#include <set>
#include <vector>
#include <fstream>
#include <regex>
#include "../Monsters/Monster.h"

class MonstersLoader {
 private:
  static MonstersLoader* instance;
  const std::filesystem::path current_directory;
  const std::string msg_bad_alloc = "Error: Bad memory allocation.";
  const std::string file_prefix = "Drops_";
  std::ifstream file_reader;
  const std::regex drop_regex;
  std::vector<std::string> unparsed_regex_results;
  inline static std::set<Drop>* current_guaranteed_drops = nullptr;
  inline static std::set<Drop>* current_food_drops = nullptr;
  inline static std::set<Drop>* current_main_drops = nullptr;
  inline static std::set<Drop>* current_unique_drops = nullptr;
  inline static std::array<std::set<Drop>**, 4> drop_tables {
    &current_guaranteed_drops, &current_main_drops,
    &current_unique_drops, &current_food_drops
  };

  MonstersLoader ();
  ~MonstersLoader();
  static void filter_under_scores(std::string &str);
  static void get_monster_name(const std::filesystem::directory_entry &entry, std::string &monster_name);
  static void retrieve_monster_drops(const std::filesystem::directory_entry &entry, std::string &drop_line);
  static void retrieve_drop_data(const std::string &line);
  static void parse_regex_groups();
  static void create_drop(const bool &is_ranged_quantity);
  enum DropRegex {
      DROP_NAME = 0,
      TABLE_ID,
      DROP_QUANTITY_MIN,
      DROP_QUANTITY_MAX,
      DROP_CHANCE_TOP,
      DROP_CHANCE_DOWN
  };
 public:
  static void load_monster_drops();
  void operator= (const MonstersLoader &other) = delete;
  static const MonstersLoader &get_instance ();
  friend void debug_print_drops();
};

#endif
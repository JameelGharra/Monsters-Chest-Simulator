/**
 * Runner.cpp: will be responsible of executing the whole program and connect
 * each component & module with each other to perform the purpose of the
 * program.
 */

#include <iostream>
#include "Parser/MonstersLoader.h"

int main() {
  std::cout << "Running the chest simulator.." << std::endl;
  try
    {
      MonstersLoader::get_instance();
      MonstersLoader::load_monster_drops();
    }
    catch(std::bad_alloc &exception) {
      std::cerr << "Error: bad memory allocation." << std::endl;
    }
    catch(std::invalid_argument &exception) {
      std::cerr << exception.what() << std::endl;
    }
  return EXIT_SUCCESS;
}
/**
 * Runner.cpp: will be responsible of executing the whole program and connect
 * each component & module with each other to perform the purpose of the
 * program.
 */

#include <iostream>
#include "Parser/DropsLoader.h"

int main() {
  std::cout << "Running the chest simulator.." << std::endl;
  try
    {
      DropsLoader::get_instance ();
    }
    catch(std::bad_alloc &exception) {
      std::cerr << "Error: bad memory allocation." << std::endl;
    }
  return EXIT_SUCCESS;
}
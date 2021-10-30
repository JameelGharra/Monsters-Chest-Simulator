#include <iostream>
#include "DropsLoader.h"

const DropsLoader *DropsLoader::instance = nullptr;
/**
 * analyzes the files that are relevant to be drops
 */
DropsLoader::DropsLoader ()
    : current_directory (std::filesystem::current_path ())
{
  size_t prefix_under_score;
  std::string file_name, monster_name;
  for (const auto &entry : std::filesystem::directory_iterator (current_directory))
    {
      file_name = entry.path ().filename().string ();
      if (file_name.find (file_prefix) != std::string::npos)
        {
          prefix_under_score = file_name.find('_');
          if(prefix_under_score >= file_name.length()-1) {
            std::cerr << "Error: One of the files have bad name." << std::endl;
          }
          monster_name = file_name.substr(0, prefix_under_score+1);
          file_reader.open (entry.path());
          std::string line;
          if(file_reader.is_open()) {
            while(getline (file_reader, line)) {
              std::cout << line << std::endl;
            }
          }
        }
    }
}

const DropsLoader &DropsLoader::get_instance ()
{
  if(instance == nullptr) {
    instance = new DropsLoader();
  }
  return *instance;
}
DropsLoader::~DropsLoader() {
  delete instance;
}
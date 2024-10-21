#include "../config.hpp"

#include <iostream>

int main(int argc, const char* argv[]) {
  DisplayBase* display = NULL;

  size_t init = 0;
  std::filesystem::path path = std::filesystem::current_path();

  if(argc != 1)
    for(int i = 1; i < argc; i ++)
      for(const Init& j : inits) {
        if(argv[i][0] == '-' && j.flag == argv[i])
          init = i;
        else if(argv[i][0] != '-')
          path = argv[i];
      }

  if(!std::filesystem::is_directory(path)) {
    std::cerr << path << "is not a directory.\n";
    return -1;
  }

  display = inits[init].function();
  display->init(path);
  std::cout << display->output();

  if(display != NULL) {
    for(InformationBase* i : display->information)
      delete i;
    delete display;
  }
  return 0;
}

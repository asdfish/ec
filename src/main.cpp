#include "../config.hpp"

#include <iostream>

int main(int argc, const char* argv[]) {
  DisplayBase* display = NULL;

  size_t init = 0;
  std::vector<std::filesystem::path> paths;

  if(argc != 1)
    for(int i = 1; i < argc; i ++) {
      if(argv[i][0] == '-')
        for(const Init& j : inits)
          if(j.flag == argv[i]) {
            init = i;
            goto next_argument;
          }

      paths.push_back(argv[i]);

next_argument:
      continue;
    }
  else
    paths.push_back(".");

  for(const std::filesystem::path& path : paths)
    if(!std::filesystem::is_directory(path)) {
      std::cerr << path << " is not a directory.\n";
      return -1;
    }

  display = inits[init].function();

  if(display != NULL) {
    display->init(paths);
    std::cout << display->output();

    for(InformationBase* i : display->information)
      delete i;
    delete display;
  }
  return 0;
}

#include "../config.hpp"

#include <iostream>

int main(int argc, const char* argv[]) {
  if(argc == 1) {
    flags[0]->init(std::filesystem::current_path());
    std::cout << flags[0]->output();
    goto cleanup;
  } else {
    std::filesystem::path search_directory = std::filesystem::current_path();
    int flag = 0;
    for(int i = 1; i < argc; i ++) {
      if(argv[i][0] != '-')
        search_directory = argv[i];
      else
        for(size_t j = 0; j < flags.size(); j ++)
          if(flags[j]->flag == argv[i])
            flag = i;
    }

    if(!std::filesystem::is_directory(search_directory)) {
      std::cerr << search_directory << " is not a directory.\n";
      goto cleanup;
    }

    flags[flag]->init(search_directory);
    std::cout << flags[flag]->output();
  }

cleanup:
  for(unsigned int i = 0; i < flags.size(); i ++) {
    for(unsigned int j = 0; j < flags[i]->information.size(); j ++)
      delete flags[i]->information[j];
    delete flags[i];
  }
  
  return 0;
}

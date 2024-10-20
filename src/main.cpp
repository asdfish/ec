#include <information/file_size.hpp>
#include <utils.hpp>
#include <iostream>

int main(void) {
  const auto dirents = directory_entries(".");

  FileSize* fs = new FileSize({
    { "B",  1 },
    { "KB", 1000 },
    { "MB", 1000000 },
    { "GB", 1000000000 },
  });

  const auto fs_o = fs->output(dirents);

  for(const auto& i : fs_o)
    std::cout << i << '\n';

  delete fs;

  return 0;
}

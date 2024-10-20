#include <information/file_permissions.hpp>
#include <utils.hpp>
#include <iostream>

int main(void) {
  const auto dirents = directory_entries(".");

  FilePermissions* fp = new FilePermissions({
    .read = "r",
    .write = "w",
    .execute = "x",

    .none = "-",
    .separator = " ",
  });

  const auto fp_o = fp->output(dirents);
  for(const auto& i : fp_o)
    std::cout << i << '\n';

  delete fp;

  return 0;
}

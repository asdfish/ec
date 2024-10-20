#include <information/argumentless/relative_path.hpp>
#include <utils.hpp>
#include <iostream>

int main(void) {
  const auto dirents = directory_entries(".");

  RelativePath* rp = new RelativePath();
  const auto rp_o = rp->output(dirents);
  for(const auto& s : rp_o)
    std::cout << s << '\n';

  delete rp;

  return 0;
}

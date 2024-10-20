#include <information/file_extension_rules.hpp>
#include <utils.hpp>
#include <iostream>

int main(void) {
  const auto dirents = directory_entries(".");

  FileExtensionRules* fer = new FileExtensionRules(std::vector<std::vector<std::string>>{
    { " " },
    { "cpp", ".hpp" }
  });
  
  const auto& fer_o = fer->output(dirents);
  for(const auto& i : fer_o)
    std::cout << i << '\n';

  delete fer;

  return 0;
}

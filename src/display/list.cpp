#include <display/list.hpp>
#include <utils.hpp>

std::string List::output(void) {

  std::string output;
  for(const std::string& i : table)
    output += i + "\n";

  return output;
}

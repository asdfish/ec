#include <display/list.hpp>
#include <utils.hpp>

std::string List::output(void) {
  for(std::vector<std::string>& column : table) {
    size_t largest_length = 0;
    for(const std::string& item : column) {
      size_t item_length = ansi_color_string_length(item);
      if(item_length > largest_length)
        largest_length = item_length;
    }

    for(std::string& item : column) {
      size_t item_length = ansi_color_string_length(item);
      while(item_length < largest_length) {
        item += " ";
        item_length ++;
      }
    }
  }

  std::string output;
  for(size_t i = 0; i < table[0].size(); i ++) {
    for(size_t j = 0; j < table.size(); j ++)
      output += table[j][i] + separator;
    output += "\n";
  }

  return output;
}

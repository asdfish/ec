#include <display/list.hpp>
#include <utils.hpp>

std::string List::output(void) {
  for(std::vector<std::string>& column : information) {
    size_t largest_length = 0;
    for(const std::string& item : column) {
      size_t item_length = ansi_color_string_length(item);
      if(item_length > largest_length)
        largest_length = item_length;
    }

    for(std::string& item : column)
      while(item.length() < largest_length)
        item += " ";
  }

  std::string output;
  for(size_t i = 0; i < information[0].size(); i ++) {
    for(size_t j = 0; j < information.size(); j ++)
      output += information[j][i] + separator;
    output += "\n";
  }

  return output;
}

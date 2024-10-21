#include <display/display_base.hpp>
#include <utils.hpp>

DisplayBase::DisplayBase(const std::string& input_separator, const std::vector<InformationBase*>& input_information):
  separator(input_separator), information(input_information) {
}

void DisplayBase::init(const std::filesystem::path& path) {
  std::vector<std::filesystem::directory_entry> directory_entries = get_directory_entries(path);

  std::vector<std::vector<std::string>> table;
  table.reserve(information.size());
  for(InformationBase* information_base : information)
    table.push_back(information_base->output(directory_entries));

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

  this->table.reserve(table[0].size());
  for(size_t i = 0; i < table[0].size(); i ++) {
    std::string combined_row;
    for(size_t j = 0; j < table.size(); j ++)
      combined_row += table[j][i] + separator;
    this->table.push_back(combined_row);
  }
}

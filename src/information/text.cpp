#include <information/text.hpp>

Text::Text(const std::string& input_text) : text(input_text) {};
Text::Text(const std::string& input_title, const std::string& input_text) : text(input_text) {
  display_title = true;
  title = input_title;
};

std::vector<std::string> Text::output(const std::vector<std::filesystem::directory_entry>& directory_entries) {
  std::vector<std::string> output;

  output.reserve(directory_entries.size() + display_title);

  if(display_title)
    output.push_back(title);

  for(size_t i = 0; i < directory_entries.size(); i ++)
    output.push_back(text);

  return output;
};
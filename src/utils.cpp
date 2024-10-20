#include <utils.hpp>
#include <iostream>

size_t ansi_color_string_length(const std::string& string) {
  if(string.find("\e") == std::string::npos)
    return string.length();

  size_t length = 0;

  size_t location = 0;
  std::string string_copy = string.substr(0, string.length());

  while((location = string_copy.find("\e")) != std::string::npos) {
    length += location;

    string_copy.erase(0, location + 1);

    size_t ansi_end = string_copy.find("m");
    if(ansi_end != std::string::npos)
      string_copy.erase(0, ansi_end + 1);
  }
  return length;
}

std::vector<std::filesystem::directory_entry> get_directory_entries(const std::filesystem::path& path) {
  std::vector<std::filesystem::directory_entry> directory_entries;
  for(const std::filesystem::directory_entry& directory_entry : std::filesystem::directory_iterator(path))
    directory_entries.push_back(directory_entry);

  return directory_entries;
}

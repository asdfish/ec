#include <information/argumentless/file_name.hpp>

std::vector<std::string> FileName::output(const std::vector<std::filesystem::directory_entry>& directory_entries) {
  std::vector<std::string> output;
  output.reserve(directory_entries.size() + display_title);

  if(display_title)
    output.push_back(title);

  for(const std::filesystem::directory_entry& directory_entry : directory_entries)
    output.push_back(directory_entry.path().filename().string());

  return output;
}

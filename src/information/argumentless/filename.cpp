#include <information/argumentless/filename.hpp>

std::vector<std::string> Filename::output(const std::vector<std::filesystem::directory_entry>& directory_entries) {
  std::vector<std::string> output;
  output.reserve(directory_entries.size() + display_title);

  for(const std::filesystem::directory_entry& directory_entry : directory_entries)
    output.push_back(directory_entries.path().filename().string());

  return output;
}

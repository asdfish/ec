#include <information/argumentless/filename.hpp>

std::vector<std::string> Filename::output(const std::vector<std::filesystem::directory_entry>& directory_entries) {
  std::vector<std::string> output;

  output.reserve(directory_entries.size() + display_title);

  return output;
}

#include <information/argumentless/file_extension.hpp>

std::vector<std::string> FileExtension::output(const std::vector<std::filesystem::directory_entry>& directory_entries) {
  std::vector<std::string> output;
  output.reserve(directory_entries.size() + display_title);

  for(const std::filesystem::directory_entry& directory_entry : directory_entries)
    output.push_back(directory_entry.path().extension().string());

  return output;
}

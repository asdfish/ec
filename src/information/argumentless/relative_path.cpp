#include <information/argumentless/relative_path.hpp>

std::vector<std::string> RelativePath::output(const std::vector<std::filesystem::directory_entry>& directory_entries) {
  std::vector<std::string> output;
  output.reserve(directory_entries.size() + display_title);

  if(display_title)
    output.push_back(title);

  for(const std::filesystem::directory_entry& directory_entry : directory_entries)
    output.push_back(directory_entry.path().relative_path().string());

  return output;
}

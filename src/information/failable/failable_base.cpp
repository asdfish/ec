#include <information/failable/failable_base.hpp>

std::vector<std::string> FailableBase::output(const std::vector<std::filesystem::directory_entry>& directory_entries) {
  std::vector<std::string> output;
  output.reserve(directory_entries.size());

  for(const std::filesystem::directory_entry& directory_entry : directory_entries) {
    try {
      output.push_back(this->process_directory_entry(directory_entry));
    } catch(const std::exception& ex) {
      output.push_back(unknown_text);
    }
  }

  return output;
}

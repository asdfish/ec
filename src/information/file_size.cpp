#include <information/file_size.hpp>

FileSize::FileSize(const std::vector<Size>& input_sizes, const std::string& input_unknown_size):
  sizes(input_sizes),
  unknown_size(input_unknown_size){}

std::vector<std::string> FileSize::output(const std::vector<std::filesystem::directory_entry>& directory_entries) {
  std::vector<std::string> output;
  output.reserve(directory_entries.size());

  for(const std::filesystem::directory_entry& directory_entry : directory_entries) {
    try {

      const std::filesystem::path& path = directory_entry.path();

      size_t size = std::filesystem::file_size(path);
      std::string size_name = sizes[0].name;

      for(size_t i = sizes.size() - 1; i > 0; i --) {
        size_t comparing_size = sizes[i].size;

        if(size / comparing_size != 0) {
          size = size / comparing_size;
          size_name = sizes[i].name;
          break;
        }
      }

      output.push_back(std::to_string(size) + size_name);
    } catch(const std::exception& err) {
      output.push_back(unknown_size);
    }
  }

  return output;
}

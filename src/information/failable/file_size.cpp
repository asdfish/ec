#include <information/failable/file_size.hpp>


FileSize::FileSize(const std::vector<Size>& input_sizes, const std::string& input_unknown_text) :
  sizes(input_sizes) {
  unknown_text = input_unknown_text;
}


std::string FileSize::process_directory_entry(const std::filesystem::directory_entry& directory_entry) {
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

  return std::to_string(size) + size_name;
}

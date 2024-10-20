#include <information/file_size.hpp>

FileSize::FileSize(const std::vector<Size>& input_sizes) : sizes(input_sizes) {}
FileSize::FileSize(const std::string& input_title, const std::vector<Size>& input_sizes) : sizes(input_sizes) {
  display_title = true;
  title = input_title;
}

std::vector<std::string> FileSize::output(const std::vector<std::filesystem::directory_entry>& directory_entries) {
  std::vector<std::string> output;
  output.reserve(directory_entries.size() + display_title);

  if(display_title)
    output.push_back(title);

  for(const std::filesystem::directory_entry& directory_entry : directory_entries) {
    const std::filesystem::path& path = directory_entry.path();

    if(std::filesystem::is_directory(path)) {
      output.push_back("0" + sizes[0].name);
      continue;
    }

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
  }

  return output;
}

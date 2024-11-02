#ifndef FILE_SIZE_HPP
#define FILE_SIZE_HPP

#include <information/information_base.hpp>

struct Size {
  std::string name;
  size_t size;
};

class FileSize : public InformationBase {
  public:
    std::vector<Size> sizes;
    std::string unknown_size;

    FileSize(const std::vector<Size>& input_sizes, const std::string& input_unknown_size);
    std::vector<std::string> output(const std::vector<std::filesystem::directory_entry>& directory_entries);
};

#endif

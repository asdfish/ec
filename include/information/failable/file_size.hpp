#include <information/failable/failable_base.hpp>

struct Size {
  std::string name;
  size_t size;
};

class FileSize : public FailableBase {
  public:
    std::vector<Size> sizes;

    FileSize(const std::vector<Size>& input_sizes, const std::string& input_unknown_text);
  private:
    std::string process_directory_entry(const std::filesystem::directory_entry& directory_entry) override;
};

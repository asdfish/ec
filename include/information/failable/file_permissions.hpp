#ifndef FILE_PERMISSIONS_HPP
#define FILE_PERMISSIONS_HPP

#include <information/failable/failable_base.hpp>

struct FilePermissionTexts {
  std::string read;
  std::string write;
  std::string execute;

  std::string none;
  std::string separator;
};

class FilePermissions : public FailableBase {
  public:
    FilePermissionTexts permission_texts;

    FilePermissions(const FilePermissionTexts& input_permission_texts, const std::string& input_unknown_text);
  private:
    std::string process_directory_entry(const std::filesystem::directory_entry& directory_entry) override;
};

#endif

#ifndef FILE_PERMISSIONS_HPP
#define FILE_PERMISSIONS_HPP

#include <information/information_base.hpp>

struct FilePermissionTexts {
  std::string read;
  std::string write;
  std::string execute;

  std::string none;
  std::string separator;
};

class FilePermissions : public InformationBase {
  public:
    FilePermissionTexts permission_texts;

    FilePermissions(const FilePermissionTexts& input_permission_texts);
    std::vector<std::string> output(const std::vector<std::filesystem::directory_entry>& directory_entries) override;
};

#endif

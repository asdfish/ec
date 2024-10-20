#include <information/file_permissions.hpp>

FilePermissions::FilePermissions(const FilePermissionTexts& input_permission_texts) : permission_texts(input_permission_texts) {}
FilePermissions::FilePermissions(const std::string& input_title, const FilePermissionTexts& input_permission_texts) : permission_texts(input_permission_texts) {
  display_title = true;
  title = input_title;
}

std::vector<std::string> FilePermissions::output(const std::vector<std::filesystem::directory_entry>& directory_entries) {
  std::vector<std::string> output;
  output.reserve(directory_entries.size() + display_title);

  if(display_title)
    output.push_back(title);

  return output;
}

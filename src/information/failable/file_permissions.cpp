#include <information/failable/file_permissions.hpp>
#include <array>

constexpr static const std::array<std::filesystem::perms, 9> processed_perms = {
  std::filesystem::perms::owner_read,
  std::filesystem::perms::owner_write,
  std::filesystem::perms::owner_exec,
  std::filesystem::perms::group_read,
  std::filesystem::perms::group_write,
  std::filesystem::perms::group_exec,
  std::filesystem::perms::others_read,
  std::filesystem::perms::others_write,
  std::filesystem::perms::others_exec,
};

FilePermissions::FilePermissions(const FilePermissionTexts& input_permission_texts, const std::string& input_unknown_text):
  permission_texts(input_permission_texts) {
  unknown_text = input_unknown_text;
}

std::string FilePermissions::process_directory_entry(const std::filesystem::directory_entry& directory_entry) {
  const std::filesystem::perms permissions = std::filesystem::status(directory_entry.path()).permissions();

  std::string output;
  for(unsigned int i = 0; i < processed_perms.size(); i ++) {
    if((permissions & processed_perms[i]) != std::filesystem::perms::none)
      switch(i % 3) {
        case 0:
          output += permission_texts.read;
          break;
        case 1:
          output += permission_texts.write;
          break;
        case 2:
          output += permission_texts.execute;
          break;
      }
    else
      output += permission_texts.none;

    if(i % 3 == 2 && i != processed_perms.size() - 1)
      output += permission_texts.separator;
  }

  return output;
}

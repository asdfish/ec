#include <information/file_permissions.hpp>
#include <array>

FilePermissions::FilePermissions(const FilePermissionTexts& input_permission_texts):
  permission_texts(input_permission_texts) {}

std::vector<std::string> FilePermissions::output(const std::vector<std::filesystem::directory_entry>& directory_entries) {
  std::vector<std::string> output;
  output.reserve(directory_entries.size());

  for(const std::filesystem::directory_entry& directory_entry : directory_entries) {
    const std::filesystem::perms permissions = std::filesystem::status(directory_entry.path()).permissions();

    std::string output_buffer;

    const std::array<std::filesystem::perms, 9> processed_perms = {
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

    for(unsigned int i = 0; i < processed_perms.size(); i ++) {
      if((permissions & processed_perms[i]) != std::filesystem::perms::none)
        switch(i % 3) {
          case 0:
            output_buffer += permission_texts.read;
            break;
          case 1:
            output_buffer += permission_texts.write;
            break;
          case 2:
            output_buffer += permission_texts.execute;
            break;
        }
      else
        output_buffer += permission_texts.none;
      if(i % 3 == 2)
        output_buffer += permission_texts.separator;
    }

    output.push_back(output_buffer);
  }

  return output;
}

#include <information/file_permissions.hpp>

#include <iostream>

FilePermissions::FilePermissions(const FilePermissionTexts& input_permission_texts):
  permission_texts(input_permission_texts) {}

std::vector<std::string> FilePermissions::output(const std::vector<std::filesystem::directory_entry>& directory_entries) {
  std::vector<std::string> output;
  output.reserve(directory_entries.size());

  for(const std::filesystem::directory_entry& directory_entry : directory_entries) {
    const std::filesystem::perms permissions = std::filesystem::status(directory_entry.path()).permissions();

    std::string output_buffer;

    if((permissions & std::filesystem::perms::owner_read) != std::filesystem::perms::none)
      output_buffer += permission_texts.read;
    else
      output_buffer += permission_texts.none;
    if((permissions & std::filesystem::perms::owner_write) != std::filesystem::perms::none)
      output_buffer += permission_texts.write;
    else
      output_buffer += permission_texts.none;
    if((permissions & std::filesystem::perms::owner_exec) != std::filesystem::perms::none)
      output_buffer += permission_texts.execute;
    else
      output_buffer += permission_texts.none;

    output_buffer += permission_texts.separator;

    if((permissions & std::filesystem::perms::group_read) != std::filesystem::perms::none)
      output_buffer += permission_texts.read;
    else
      output_buffer += permission_texts.none;
    if((permissions & std::filesystem::perms::group_write) != std::filesystem::perms::none)
      output_buffer += permission_texts.write;
    else
      output_buffer += permission_texts.none;
    if((permissions & std::filesystem::perms::group_exec) != std::filesystem::perms::none)
      output_buffer += permission_texts.execute;
    else
      output_buffer += permission_texts.none;

    output_buffer += permission_texts.separator;

    if((permissions & std::filesystem::perms::others_read) != std::filesystem::perms::none)
      output_buffer += permission_texts.read;
    else
      output_buffer += permission_texts.none;
    if((permissions & std::filesystem::perms::others_write) != std::filesystem::perms::none)
      output_buffer += permission_texts.write;
    else
      output_buffer += permission_texts.none;
    if((permissions & std::filesystem::perms::others_exec) != std::filesystem::perms::none)
      output_buffer += permission_texts.execute;
    else
      output_buffer += permission_texts.none;

    output.push_back(output_buffer);
  }

  return output;
}

#include <information/file_type.hpp>

FileType::FileType(const FileTypeTexts& input_file_type_texts):
  file_type_texts(input_file_type_texts) {}

std::vector<std::string> FileType::output(const std::vector<std::filesystem::directory_entry>& directory_entries) {
  std::vector<std::string> output;
  output.reserve(directory_entries.size());

  for(const std::filesystem::directory_entry& directory_entry : directory_entries) {
    if(directory_entry.is_symlink())
      output.push_back(file_type_texts.symlink);
    else if(directory_entry.is_block_file())
      output.push_back(file_type_texts.block_file);
    else if(directory_entry.is_character_file())
      output.push_back(file_type_texts.character_file);
    else if(directory_entry.is_directory())
      output.push_back(file_type_texts.directory);
    else if(directory_entry.is_fifo())
      output.push_back(file_type_texts.fifo);
    else if(directory_entry.is_other())
      output.push_back(file_type_texts.other);
    else if(directory_entry.is_regular_file())
      output.push_back(file_type_texts.regular_file);
    else if(directory_entry.is_socket())
      output.push_back(file_type_texts.socket);
  }

  return output;
}

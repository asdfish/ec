#ifndef FILE_TYPE_HPP
#define FILE_TYPE_HPP

#include <information/information_base.hpp>

struct FileTypeTexts {
  std::string block_file;
  std::string character_file;
  std::string directory;
  std::string fifo;
  std::string other;
  std::string regular_file;
  std::string socket;
  std::string symlink;
};

class FileType : public InformationBase {
  public:
    FileType(const FileTypeTexts& input_file_type_texts);
    FileType(const std::string&, const FileTypeTexts& input_file_type_texts);
    std::vector<std::string> output(const std::vector<std::filesystem::directory_entry>& directory_entries) override;

  private:
    struct FileTypeTexts file_type_texts;
};

#endif

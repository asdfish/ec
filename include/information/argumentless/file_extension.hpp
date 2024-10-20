#ifndef FILE_EXTENSION_HPP
#define FILE_EXTENSION_HPP

#include <information/argumentless/argumentless_base.hpp>

class FileExtension : public ArgumentlessBase {
  public:
    using ArgumentlessBase::ArgumentlessBase;

    std::vector<std::string> output(const std::vector<std::filesystem::directory_entry>& directory_entries) override;
};

#endif

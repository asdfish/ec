#ifndef RELATIVE_PATH_HPP
#define RELATIVE_PATH_HPP

#include <information/argumentless/argumentless_base.hpp>

class RelativePath : public ArgumentlessBase {
  public:
    using ArgumentlessBase::ArgumentlessBase;
    std::vector<std::string> output(const std::vector<std::filesystem::directory_entry>& directory_entries) override;
};

#endif

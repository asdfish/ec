#include <information/argumentless/argumentless_base.hpp>

class Filename : public ArgumentlessBase {
  public:
    using ArgumentlessBase::ArgumentlessBase;

    std::vector<std::string> output(const std::vector<std::filesystem::directory_entry>& directory_entries) override;
};

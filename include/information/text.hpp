#ifndef TEXT_HPP
#define TEXT_HPP

#include <information/information_base.hpp>

class Text : public InformationBase {
  public:
    Text(const std::string& input_text);

    std::vector<std::string> output(const std::vector<std::filesystem::directory_entry>& directory_entries) override;
  private:
    std::string text;
};

#endif

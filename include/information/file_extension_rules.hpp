#ifndef FILE_EXTENSION_RULES_HPP
#define FILE_EXTENSION_RULES_HPP

#include <information/information_base.hpp>

class FileExtensionRules : public InformationBase {
  public:
    std::vector<std::vector<std::string>> rules;

    FileExtensionRules(const std::vector<std::vector<std::string>>& input_rules);
    FileExtensionRules(const std::string& title, const std::vector<std::vector<std::string>>& input_rules);
    std::vector<std::string> output(const std::vector<std::filesystem::directory_entry>& directory_entries) override;
};

#endif

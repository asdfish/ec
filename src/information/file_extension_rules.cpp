#include <information/file_extension_rules.hpp>

FileExtensionRules::FileExtensionRules(const std::vector<std::vector<std::string>>& input_rules):
  rules(input_rules) {}
FileExtensionRules::FileExtensionRules(const std::string& input_title, const std::vector<std::vector<std::string>>& input_rules):
  rules(input_rules) {
  display_title = true;
  title = input_title;
}

std::vector<std::string> FileExtensionRules::output(const std::vector<std::filesystem::directory_entry>& directory_entries) {
  std::vector<std::string> output;
  output.reserve(directory_entries.size() + display_title);

  if(display_title)
    output.push_back(title);

  const std::string default_output = rules[0][0];

  for(const std::filesystem::directory_entry& directory_entry : directory_entries) {
    const std::string filename = directory_entry.path().string();
    std::string next_entry = default_output;

    for(const std::vector<std::string>& rule_vector : rules) {
      const std::string& output_buffer = rule_vector[0];
      for(size_t i = 1; i < rule_vector.size(); i ++) {
        const std::string& rule = rule_vector[i];

        if(filename.substr(filename.length() - rule.length(), rule.length()) == rule) {
          next_entry = output_buffer;
          goto add_next_entry;
        }
      }
    }

add_next_entry:
    output.push_back(next_entry);
  }

  return output;
}

#include <display/display_base.hpp>
#include <utils.hpp>

DisplayBase::DisplayBase(const std::string& input_flag, const std::string& input_separator, const std::vector<InformationBase*>& input_information):
  flag(input_flag), separator(input_separator), information(input_information) {
}

void DisplayBase::init(const std::filesystem::path& path) {
  std::vector<std::filesystem::directory_entry> directory_entries = get_directory_entries(path);

  table.reserve(information.size());
  for(InformationBase* information_base : information)
    table.push_back(information_base->output(directory_entries));
}

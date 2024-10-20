#include <display/display_base.hpp>
#include <utils.hpp>

DisplayBase::DisplayBase(const std::string& input_separator, const std::vector<InformationBase*>& input_information):
  separator(input_separator) {
  std::vector<std::filesystem::directory_entry> directory_entries = get_directory_entries(std::filesystem::current_path());

  information.reserve(input_information.size());
  for(InformationBase* information_base : input_information) {
    information.push_back(information_base->output(directory_entries));
    delete information_base;
  }
}

#ifndef DISPLAY_BASE_HPP
#define DISPLAY_BASE_HPP

#include <information/information_base.hpp>

class DisplayBase {
  public:
    std::string separator;
    std::vector<std::string> table;
    std::vector<InformationBase*> information;

    DisplayBase(const std::string& separator, const std::vector<InformationBase*>& input_information);
    void init(const std::vector<std::filesystem::path>& paths);
    virtual ~DisplayBase(void) {}
    virtual std::string output(void) = 0;

  private:
    void process_directory_entries(const std::vector<std::filesystem::directory_entry>& directory_entries);
};

#endif

#ifndef DISPLAY_BASE_HPP
#define DISPLAY_BASE_HPP

#include <information/information_base.hpp>

class DisplayBase {
  public:
    std::string flag;
    std::string separator;
    std::vector<std::vector<std::string>> table;
    std::vector<InformationBase*> information;

    DisplayBase(const std::string& input_flag, const std::string& separator, const std::vector<InformationBase*>& input_information);
    void init(const std::filesystem::path& path);
    virtual ~DisplayBase(void) {}
    virtual std::string output(void) = 0;
};

#endif

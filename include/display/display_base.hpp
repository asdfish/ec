#ifndef DISPLAY_BASE_HPP
#define DISPLAY_BASE_HPP

#include <information/information_base.hpp>

class DisplayBase {
  public:
    std::vector<std::vector<std::string>> information;

    DisplayBase(const std::vector<InformationBase*>& input_information);
    virtual ~DisplayBase(void) {}
    virtual std::string output(void) = 0;
};

#endif

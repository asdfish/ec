#ifndef LIST_HPP
#define LIST_HPP

#include <display/display_base.hpp>

class List : public DisplayBase {
  public:
    using DisplayBase::DisplayBase;

    std::string output(void) override;
};

#endif

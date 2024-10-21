#ifndef COMPACT_HPP
#define COMPACT_HPP

#include <display/display_base.hpp>

class Compact : public DisplayBase {
  public:
    using DisplayBase::DisplayBase;

    std::string output(void) override;
};

#endif

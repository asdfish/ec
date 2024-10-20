#ifndef ARGUMENTLESS_BASE_HPP
#define ARGUMENTLESS_BASE_HPP

#include <information/information_base.hpp>

class ArgumentlessBase : public InformationBase {
  public:
    ArgumentlessBase(void);
    ArgumentlessBase(const std::string& input_title);
};

#endif

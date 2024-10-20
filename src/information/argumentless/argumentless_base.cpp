#include <information/argumentless/argumentless_base.hpp>

ArgumentlessBase::ArgumentlessBase(void) {}
ArgumentlessBase::ArgumentlessBase(const std::string& input_title) {
  display_title = true;
  title = input_title;
}

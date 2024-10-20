#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <display/list.hpp>
#include <information/file_size.hpp>

static const std::vector<DisplayBase*> flags = {
  new List("", " ", {
    new FileSize({
      { "B", 1 }
    })
  }),
};

#endif

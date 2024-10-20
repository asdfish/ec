#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <display/list.hpp>
#include <information/argumentless/file_name.hpp>
#include <information/file_extension_rules.hpp>
#include <information/file_size.hpp>
#include <information/file_type.hpp>
#include <information/text.hpp>

static const std::vector<DisplayBase*> flags = {
  new List("", " ", {
    new Text(" "),
    new FileExtensionRules({
      { "" },
      { "\e[31m\e[0m", ".git", ".gitignore" },
      { "", "Makefile" },
      { "\e[34m\e[0m", ".c", ".h" },
      { "\e[34m\e[0m", ".cpp", ".hpp" },
    }),
    new FileType({
      "",
      "",
      "\e[32m",
      "",
      "",
      "\e[36m",
      "",
      "\e[37m"
    }),
    new FileName(),
    new Text("\e[0m"),
    new FileSize({
      { "\e[33mB\e[0m", 1 },
      { "\e[33mKB\e[0m", 1000 },
      { "\e[33mMB\e[0m", 1000000 },
      { "\e[33mGB\e[0m", 1000000000 },
    }),
  }),
};

#endif

#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <display/list.hpp>
#include <information/argumentless/file_name.hpp>
#include <information/file_extension_rules.hpp>
#include <information/file_permissions.hpp>
#include <information/file_size.hpp>
#include <information/file_type.hpp>
#include <information/text.hpp>

static const std::vector<DisplayBase*> flags = {
  new List("", "", {
    new Text(" "),
    new FileExtensionRules({
      { "" },
      { "\e[31m\e[0m", ".git", ".gitignore", ".patch" },
      { "", "Makefile" },
      { "\e[34m\e[0m", ".c", ".h" },
      { "\e[34m\e[0m", ".cpp", ".hpp" },
      { "\e[33m\e[0m", ".rs" },
      { "\e[33m\e[0m", ".js", ".json" },
      { "\e[34m\e[0m", ".css" },
      { "\e[31m\e[0m", ".html" },
      { "", ".bashrc", ".sh" },
      { "\e[34m\e[0m", ".lua" },
      { "\e[37m\e[0m", ".ini", ".jsonc", ".yaml", ".toml", ".conf" },
      { "", ".mp3", ".wav", ".opus", ".flac" },
      { "", ".md" },
      { "", ".jpg", ".png", ".svg" },
      { "", ".pdf", ".epub" },
      { "", ".txt", ".log" }
    }),
    new FileSize({
      { "\e[33mB\e[0m", 1 },
      { "\e[33mKB\e[0m", 1000 },
      { "\e[33mMB\e[0m", 1000000 },
      { "\e[33mGB\e[0m", 1000000000 },
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
  }),
};

#endif

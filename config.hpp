#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <display/compact.hpp>
#include <display/display_base.hpp>
#include <display/list.hpp>
#include <information/argumentless/file_name.hpp>
#include <information/failable/file_size.hpp>
#include <information/failable/file_permissions.hpp>
#include <information/file_extension_rules.hpp>
#include <information/file_type.hpp>
#include <information/text.hpp>

DisplayBase* default_init(void) {
  return new List("", {
    new Text(" "),
    new FilePermissions({"r", "w", "x", "-", " "}, "??? ??? ???"),
    new FileExtensionRules({
      { "" },
      { "\e[31m\e[0m", ".git", ".gitignore", ".gitconfig", ".gitmodules", ".patch" },
      { "", "Makefile" },
      { "\e[34m\e[0m", ".c", ".h" },
      { "\e[34m\e[0m", ".cpp", ".hpp" },
      { "\e[33m\e[0m", ".rs", ".cargo" },
      { "\e[33m\e[0m", ".js", ".json", ".npm" },
      { "\e[34m\e[0m", ".css" },
      { "\e[31m\e[0m", ".html" },
      { "\e[33m\e[0m", ".bashrc", ".bash_profile", ".bash_history", ".bash_logout", ".sh" },
      { "\e[34m\e[0m", ".lua" },
      { "\e[37m\e[0m", ".ini", ".jsonc", ".yaml", ".toml", ".conf", ".config" },
      { "\e[31m\e[0m", ".mozilla" },
      { "", ".mp3", ".wav", ".opus", ".flac" },
      { "󰕧", ".mp4", ".mkv" },
      { "", ".md" },
      { "\e[34m\e[0m", ".jpg", ".png", ".svg" },
      { "", ".pdf", ".epub" },
      { "", ".txt", ".log" },
      { "", ".o" }
    }),
    new FileSize({
      { "\e[33mB\e[0m", 1 },
      { "\e[33mKB\e[0m", 1000 },
      { "\e[33mMB\e[0m", 1000000 },
      { "\e[33mGB\e[0m", 1000000000 },
    }, "???"),
    new FileType({
      "",
      "",
      "\e[32m",
      "",
      "",
      "\e[36m",
      "",
      "\e[37m󰌷"
    }),
    new FileName(),
    new Text("\e[0m"),
  });
}

DisplayBase* quiet_init(void) {
  return new Compact("", {
    new Text(" "),
    new FileType({
      "",
      "",
      "\e[32m",
      "",
      "",
      "\e[36m",
      "",
      "\e[37m󰌷"
    }),
    new FileName(),
    new Text("\e[0m"),
  });
}

typedef DisplayBase* (*init_function)(void);

struct Init {
  std::string flag;
  init_function function;
};

static const std::vector<Init> inits = {
  { "", default_init },
  { "-q", quiet_init }
};

#endif

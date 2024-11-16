#include <display/compact.hpp>

extern "C" {
  #include <sys/ioctl.h>
  #include <unistd.h>
};

std::string Compact::output(void) {
  struct winsize window_size;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &window_size);
  unsigned int width = window_size.ws_col;

  size_t length = 0;

  std::string output;

  for(unsigned int i = 0; i < table.size(); i ++) {
    output += table[i];

    length += table[i].length();
    if(length > width || i == table.size() - 1) {
      output += "\n";
      length = 0;
    }
  }

  return output;
}

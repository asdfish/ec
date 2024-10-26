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
  for(const std::string& i : table) {
    output += i;

    length += i.length();
    if(length > width) {
      output += "\n";
      length = 0;
    }
  }

  return output;
}

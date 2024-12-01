#include <display/compact.hpp>

#ifdef __WIN32
extern "C" {
#include <windows.h>
};
#else
extern "C" {
  #include <sys/ioctl.h>
  #include <unistd.h>
};
#endif // __WIN32

std::string Compact::output(void) {
#ifdef __WIN32
  CONSOLE_SCREEN_BUFFER_INFO console_screen_buffer_info;
  unsigned int width = 0;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &console_screen_buffer_info);

  width = console_screen_buffer_info.srWindow,Right - console_screen_buffer_info.srWindow.Left + 1;
#else
  struct winsize window_size;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &window_size);
  unsigned int width = window_size.ws_col;
#endif // __WIN32

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

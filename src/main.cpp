#include <display/list.hpp>
#include <information/argumentless/file_name.hpp>
#include <information/file_size.hpp>

#include <iostream>

int main(void) {
  List l (" ", std::vector<InformationBase*> {
    new FileSize(std::vector<Size> {
      { "B", 1 },
      { "KB", 1000 }
    }),
    new FileName()
  });

  std::cout << l.output();
  return 0;
}

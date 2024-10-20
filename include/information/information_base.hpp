#ifndef INFORMATION_BASE_HPP
#define INFORMATION_BASE_HPP

#include <filesystem>
#include <string>
#include <vector>

class InformationBase {
  public:
    virtual ~InformationBase(void) {};
    virtual std::vector<std::string> output(const std::vector<std::filesystem::directory_entry>& directory_entries) = 0;
};

#endif

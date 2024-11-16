#ifndef FAILABLE_BASE_HPP
#define FAILABLE_BASE_HPP

#include <information/information_base.hpp>

class FailableBase : public InformationBase {
  public:
    std::string unknown_text;
    std::vector<std::string> output(const std::vector<std::filesystem::directory_entry>& directory_entries) override;

  private:
    virtual std::string process_directory_entry(const std::filesystem::directory_entry& directory_entry) = 0;
};

#endif

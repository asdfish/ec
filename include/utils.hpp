#ifndef UTILS_HPP
#define UTILS_HPP

#include <filesystem>
#include <string>
#include <vector>

extern size_t ansi_color_string_length(const std::string& string);
extern std::vector<std::filesystem::directory_entry> directory_entries(std::string path);

#endif

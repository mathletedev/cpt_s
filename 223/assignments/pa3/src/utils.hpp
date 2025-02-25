#pragma once

#include <string>
#include <vector>

// reads a single CSV line into a vector of strings
// uses comma delimiters, escapes commas inside quotes
std::vector<std::string> parse_csv_line(const std::string &line);

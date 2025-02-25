#include "utils.hpp"

std::vector<std::string> parse_csv_line(const std::string &line) {
	std::vector<std::string> res;
	std::string curr;
	bool in_quotes = false;

	for (size_t i = 0; i < line.size(); ++i) {
		char c = line[i];

		if (c == '"') {
			in_quotes = !in_quotes;
			continue;
		}

		if (c == ',' && !in_quotes) {
			res.push_back(curr);
			curr.clear();
			continue;
		}

		curr += c;
	}

	res.push_back(curr);
	return res;
}

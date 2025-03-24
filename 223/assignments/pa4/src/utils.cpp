#include "utils.hpp"

LinkedList<std::string> utils::parse_csv(const std::string &input) {
	LinkedList<std::string> res;
	std::string curr;
	bool in_quotes = false;

	for (size_t i = 0; i < input.size(); ++i) {
		char c = input[i];

		if (c == '"') {
			// escaped quotes
			if (i + 1 < input.size() && input[i + 1] == '"') {
				curr += '"';
				++i;
				continue;
			}

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

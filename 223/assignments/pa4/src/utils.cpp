#include "utils.hpp"

LinkedList<std::string> utils::split(std::string input, std::string delimiter) {
	LinkedList<std::string> res;

	for (size_t i = input.find(delimiter); i != std::string::npos;
	     i = input.find(delimiter)) {
		res.push_back(input.substr(0, i));
		input = input.substr(i + delimiter.size());
	}
	res.push_back(input);

	return res;
}

LinkedList<std::string> utils::parse_csv(const std::string &input) {
	LinkedList<std::string> res;
	std::string curr;
	bool in_quotes = false;

	for (size_t i = 0; i < input.size(); ++i) {
		char c = input[i];

		if (c == '"') {
			// escaped quotes
			if (i + 1 < input.size() && input[i + 1] == '"' &&
			    !(i + 2 < input.size() && input[i + 2] == ',')) {
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

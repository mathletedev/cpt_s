#include "utils.hpp"

// waits until enter is pressed
void utils::suspend() {
	std::cout << "Press Enter to continue...";
	getchar();
}

// reads a token from a csv file into string, parsing quotes as needed
bool utils::read_token(std::ifstream &fstream, std::string &string,
		       char delim) {
	string = "";

	char c;
	bool quoted = false;
	// read next char
	while (fstream.get(c)) {
		// process quotes
		if (c == '"') {
			quoted ^= 1;
			continue;
		}

		// break if delimiter or newline is encountered outside of
		// quotes
		if (!quoted && (c == delim || c == '\n')) break;

		string += c;
	}

	// read was successful if string has characters
	return string.size() != 0;
}

// ignores a line of input
void utils::ignore_line(std::ifstream &fstream) {
	fstream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// get current date from computer
std::string utils::get_date() {
	// http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
	time_t t = time(0);
	tm *now = localtime(&t);

	std::string res = std::to_string(now->tm_year + 1900) + "-" +
			  std::to_string(now->tm_mon + 1) + "-" +
			  std::to_string(now->tm_mday);

	delete now;

	return res;
}

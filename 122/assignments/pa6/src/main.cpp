#include "bst.hpp"
#include "morsecode.hpp"
#include <fstream>

// I tried organising my files in better directories for this project
// and I used CMake to build it
// CLion is working on my machine, but if it's not building,
// I can make another submission with all the files in the root directory

int main() {
	std::ifstream data;

	// Q -> --.-
	data.open("data/MorseTable.txt");
	const bst<char, morse_code> char_to_morse = bst<char, morse_code>(data);
	data.close();

	// example of using template class to convert morse code back to
	// standard text
	// --.- -> Q
	data.open("data/InverseMorseTable.txt");
	const bst<morse_code, char> morse_to_char = bst<morse_code, char>(data);
	data.close();

	std::cout << "char to morse" << std::endl;
	char_to_morse.print();
	std::cout << "----------------" << std::endl;
	std::cout << "morse to char" << std::endl;
	morse_to_char.print();
	std::cout << "----------------" << std::endl;

	data.open("data/Convert.txt");
	std::cout << "Converted text:" << std::endl;
	char_to_morse.process_char(data);
	data.close();

	data.open("data/InverseConvert.txt");
	std::cout << "Converted back:" << std::endl;
	morse_to_char.process(data);
	data.close();

	return 0;
}

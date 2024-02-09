#include <iostream>
#include <string>

int add(int n1, int n2);
std::string add(std::string s1, std::string s2);

int main() {
	int n1 = 10;
	int &r1 = n1;

	char s1[50] = "cat";

	std::cout << "Result: " << add(6, 7) << std::endl;
	std::cout << "Result: " << add(std::string(s1), "dog") << std::endl;

	return 0;
}

int add(int n1, int n2) {
	return n1 + n2;
}

std::string add(std::string s1, std::string s2) {
	return s1 + s2;
}

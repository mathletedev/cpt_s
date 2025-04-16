#include "app.hpp"
#include "tests.hpp"

int main(int argc, char const *argv[]) {
	if (argc == 2 && std::string(argv[1]) == "--test") {
		tests::test_all();
		return 0;
	}

	App app;

	return 0;
}

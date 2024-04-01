#include "app.hpp"

app::app() {
	std::string warning = "";

	while (true) {
		system("clear");

		std::cout << "1. Import course list" << std::endl;
		std::cout << "2. Load master list" << std::endl;
		std::cout << "3. Store master list" << std::endl;
		std::cout << "4. Mark absences" << std::endl;
		std::cout << "5. Edit absences" << std::endl;
		std::cout << "6. Generate report" << std::endl;
		std::cout << "7. Exit" << std::endl;
		std::cout << std::endl;

		if (warning != "") {
			std::cout << warning << std::endl;
			std::cout << std::endl;
		}
		warning = "";

		std::cout << "Select an option: ";

		int option;
		// https://stackoverflow.com/a/60967987
		if (!(std::cin >> option).good() || option < 1 || option > 7) {
			warning = "Invalid option";
			continue;
		}
		// ignore following newline
		std::cin.ignore();

		switch (option) {
		case 1:
			import();
			break;
		case 2:
			load();
			break;
		case 7:
			return;
		}
	}
}

void app::import() {
	system("clear");

	students_.clear();

	std::ifstream fstream;
	fstream.open("data/classlist.csv");

	// ignore headers
	utils::ignore_line(fstream);

	data curr;
	while (fstream >> curr)
		students_.insert(curr);

	std::cout << "Course list imported successfully!" << std::endl;
	utils::suspend();

	fstream.close();
}

void app::load() {
	std::ifstream fstream;
	fstream.open("data/master.csv");

	fstream.close();
}

#include "menu.hpp"

menu::menu() {
	srand(time(0));

	std::string warning = "";

	while (true) {
		system(CLEAR);

		// menu
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

		system(CLEAR);

		switch (option) {
		case 1:
			import();
			break;
		case 2:
			load();
			break;
		case 3:
			store();
			break;
		case 4:
			mark();
			break;
		case 5:
			edit();
			break;
		case 6:
			generate();
			break;
		case 7:
			return;
		}
	}
}

void menu::import() {
	students_.clear();

	std::ifstream fstream;
	fstream.open("data/classlist.csv");

	// ignore headers
	utils::ignore_line(fstream);

	data curr;
	while (curr.read(fstream, false))
		students_.push_front(curr);

	std::cout << "Course list imported successfully!" << std::endl;
	utils::suspend();

	fstream.close();
}

void menu::load() {
	students_.clear();

	std::ifstream fstream;
	fstream.open("data/master.csv");

	utils::ignore_line(fstream);

	data curr;
	while (curr.read(fstream, true))
		students_.push_front(curr);

	std::cout << "Master list loaded successfully!" << std::endl;
	utils::suspend();

	fstream.close();
}

void menu::store() {
	std::ofstream fstream;
	fstream.open("data/master.csv");

	fstream << ",ID,Name,Email,Units,Program,Level,Absences,Dates\n";

	// cycle through student list
	list<data> tmp;
	while (!students_.is_empty())
		tmp.push_front(students_.pop_front());

	while (!tmp.is_empty()) {
		data curr = tmp.pop_front();
		curr.write(fstream);
		fstream << '\n';

		students_.push_front(curr);
	}

	std::cout << "Master list stored successfully!" << std::endl;
	utils::suspend();

	fstream.close();
}

void menu::mark() {
	list<data> tmp;
	while (!students_.is_empty())
		tmp.push_front(students_.pop_front());

	std::string date = utils::get_date();

	while (!tmp.is_empty()) {
		system(CLEAR);
		std::cout << "Date: " << date << std::endl;

		data curr = tmp.pop_front();
		std::cout << curr.get_name() << " absent? y/n: ";

		char c;
		std::cin >> c;

		if (c == 'y' || c == 'Y') {
			curr.set_num_absences(curr.get_num_absences() + 1);
			curr.get_dates_absences().push(date);
		}

		students_.push_front(curr);
	}

	// ignore enter key
	std::cin.ignore();

	system(CLEAR);

	std::cout << "Reached end of student list" << std::endl;
	utils::suspend();
}

void menu::edit() {
	std::cout << "Work in progress" << std::endl;
	utils::suspend();
}

void menu::generate() {
	std::ofstream fstream;
	fstream.open("data/report.txt");

	std::string warning = "";
	int option;

	while (true) {
		system(CLEAR);

		std::cout << "1. Generate report for all students" << std::endl;
		std::cout << "2. Generate report for students matching or "
			     "exceeding threshold"
			  << std::endl;
		std::cout << std::endl;

		if (warning != "") {
			std::cout << warning << std::endl;
			std::cout << std::endl;
		}
		warning = "";

		std::cout << "Select an option: ";

		// https://stackoverflow.com/a/60967987
		if (!(std::cin >> option).good() || option < 1 || option > 2) {
			warning = "Invalid option";
			continue;
		}

		// ignore following newline
		std::cin.ignore();
		break;
	}

	system(CLEAR);

	int threshold;
	if (option == 2) {
		std::cout << "Enter absence threshold: ";
		std::cin >> threshold;
		std::cin.ignore();

		fstream << "Threshold: " << threshold << " absences\n";

		system(CLEAR);
	} else
		fstream << "Full student report\n";

	list<data> tmp;

	// put data into second linked list
	while (!students_.is_empty())
		tmp.push_front(students_.pop_front());

	// O(N) time complexity because peek() is O(1)
	// O(N) space complexity because of tmp list
	while (!tmp.is_empty()) {
		data curr = tmp.pop_front();
		students_.push_front(curr);

		if (option == 1) {
			fstream << curr.get_name() << ": "
				<< curr.get_num_absences() << " absences";
			if (curr.get_num_absences() > 0)
				fstream << " ("
					<< curr.get_dates_absences().peek()
					<< ")";
			fstream << "\n";

			continue;
		}

		// check threshold
		if (curr.get_num_absences() >= threshold)
			fstream << curr.get_name() << "\n";
	}

	std::cout << "Report generated successfully!" << std::endl;
	utils::suspend();

	fstream.close();
}

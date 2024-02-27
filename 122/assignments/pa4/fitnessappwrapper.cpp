#include "fitnessappwrapper.hpp"

FitnessAppWrapper::FitnessAppWrapper() {
	// initialises both weekly vectors with 7 elements
	weeklyDietPlan = std::vector<DietPlan>(7);
	weeklyExercisePlan = std::vector<ExercisePlan>(7);
}

// main function for running app
void FitnessAppWrapper::runApp() {
	while (true) {
		// get choice from user
		int choice = displayMenu();
		int selection;
		std::cout << choice << std::endl;

		system(CLEAR);

		std::fstream fileStream;

		// process choice
		switch (choice) {
		case 1:
			// open fileStream in input mode
			fileStream.open("dietPlans.txt", std::fstream::in);
			loadWeeklyPlan(fileStream, weeklyDietPlan);

			std::cout << "Successfully loaded weekly diet plan"
				  << std::endl;
			break;
		case 2:
			fileStream.open("exercisePlans.txt", std::fstream::in);
			loadWeeklyPlan(fileStream, weeklyExercisePlan);

			std::cout << "Successfully loaded weekly exercise plan"
				  << std::endl;
			break;
		case 3:
			// open fileStream in output mode
			fileStream.open("dietPlans.txt", std::fstream::out);
			storeWeeklyPlan(fileStream, weeklyDietPlan);

			std::cout << "Successfully stored weekly diet plan"
				  << std::endl;
			break;
		case 4:
			fileStream.open("exercisePlans.txt", std::fstream::out);
			storeWeeklyPlan(fileStream, weeklyExercisePlan);

			std::cout << "Successfully stored weekly exercise plan"
				  << std::endl;
			break;
		case 5:
			displayWeeklyPlan(weeklyDietPlan);
			break;
		case 6:
			displayWeeklyPlan(weeklyExercisePlan);
			break;
		case 7:
			// get an index
			selection = selectPlan(weeklyDietPlan) - 1;
			system(CLEAR);
			weeklyDietPlan[selection].editGoal();
			break;
		case 8:
			selection = selectPlan(weeklyExercisePlan) - 1;
			system(CLEAR);
			weeklyExercisePlan[selection].editGoal();
			break;
		// exit app
		case 9:
			// store most recent plans
			fileStream.open("dietPlans.txt", std::fstream::out);
			storeWeeklyPlan(fileStream, weeklyDietPlan);
			fileStream.close();
			fileStream.open("exercisePlans.txt", std::fstream::out);
			storeWeeklyPlan(fileStream, weeklyExercisePlan);
			fileStream.close();

			std::cout << "Successfully stored weekly plans"
				  << std::endl;
			std::cout << "Exiting application..." << std::endl;
			return;
		}

		// close fileStream!
		if (fileStream.is_open()) fileStream.close();

		utils::suspend();
	}
}

void FitnessAppWrapper::loadDailyPlan(std::fstream &fileStream, Plan &plan) {
	fileStream >> plan;
}

// use a template for both DietPlan and ExercisePlan
template <class T>
void FitnessAppWrapper::loadWeeklyPlan(std::fstream &fileStream,
				       std::vector<T> &weeklyPlan) {
	for (int i = 0; i < 7; ++i)
		loadDailyPlan(fileStream, weeklyPlan[i]);
}

// use template to use polymorphic Plan::toString
template <class T>
void FitnessAppWrapper::displayDailyPlan(T &plan) {
	std::cout << plan << std::endl;
}

template <class T>
void FitnessAppWrapper::displayWeeklyPlan(std::vector<T> &weeklyPlan) {
	for (int i = 0; i < weeklyPlan.size(); ++i)
		displayDailyPlan(weeklyPlan[i]);
}

void FitnessAppWrapper::storeDailyPlan(std::fstream &fileStream, Plan &plan) {
	fileStream << plan << std::endl;
}

template <class T>
void FitnessAppWrapper::storeWeeklyPlan(std::fstream &fileStream,
					std::vector<T> &weeklyPlan) {
	for (int i = 0; i < weeklyPlan.size(); ++i)
		storeDailyPlan(fileStream, weeklyPlan[i]);
}

// displays a menu, receives and validates user selection, returns selection
int FitnessAppWrapper::displayMenu() {
	int choice = -1;
	bool warn = false;

	do {
		system(CLEAR);

		std::cout << "Select a command:" << std::endl;
		NEWLINE;
		std::cout << "1. Load weekly diet plan from file." << std::endl;
		std::cout << "2. Load weekly exercise plan from file."
			  << std::endl;
		std::cout << "3. Store weekly diet plan to file." << std::endl;
		std::cout << "4. Store weekly exercise plan to file."
			  << std::endl;
		std::cout << "5. Display weekly diet plan to screen."
			  << std::endl;
		std::cout << "6. Display weekly exercise plan to screen."
			  << std::endl;
		std::cout << "7. Edit daily diet plan." << std::endl;
		std::cout << "8. Edit daily exercise plan." << std::endl;
		std::cout << "9. Exit." << std::endl;
		NEWLINE;

		if (warn) std::cout << "Invalid input" << std::endl;
		std::cout << "> ";

		std::cin >> choice;
		utils::flush();

		warn = true;
	} while (choice < 1 || choice > 9);

	return choice;
}

// get a validated number from 1-7 for plan in vector
template <class T>
int FitnessAppWrapper::selectPlan(std::vector<T> &weeklyPlan) {
	int choice = -1;
	bool warn = false;

	do {
		system(CLEAR);

		std::cout << "Select a plan:" << std::endl;
		NEWLINE;
		for (int i = 0; i < weeklyPlan.size(); ++i)
			std::cout << i + 1 << ". " << weeklyPlan[i]
				  << std::endl;
		NEWLINE;

		if (warn) std::cout << "Invalid input" << std::endl;
		std::cout << "> ";

		std::cin >> choice;
		utils::flush();

		warn = true;
	} while (choice < 1 || choice > weeklyPlan.size());

	return choice;
}

#pragma once

#include "plan.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class FitnessAppWrapper {
	public:
		void runApp();

	private:
		std::vector<DietPlan> weeklyDietPlan = std::vector<DietPlan>(7);
		std::vector<DietPlan> weeklyExercisePlan =
		    std::vector<DietPlan>(7);

		void loadDailyPlan(std::ifstream &fileStream, DietPlan &plan);
		void loadWeeklyPlan(std::ifstream &fileStream,
				    std::vector<DietPlan> weeklyPlan);

		void displayDailyPlan();
		void displayWeeklyPlan();

		void storeDailyPlan();
		void storeWeeklyPlan();

		void displayMenu();
};

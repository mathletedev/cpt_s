#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Plan {
	public:
		std::string toString() const;

		void setGoal(int goal);

		void editGoal();

		friend std::ifstream &operator>>(std::ifstream &fileStream,
						 Plan &plan);
		friend std::ostream &operator<<(std::ostream &stream,
						const Plan &plan);
		friend std::ofstream &operator<<(std::ofstream &fileStream,
						 const Plan &plan);

	protected:
		int goal = 0;
		std::string name = "Goal";
		std::string date = "01/01/1970";
};

class DietPlan : public Plan {};

class ExercisePlan : public Plan {};

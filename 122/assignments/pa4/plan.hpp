#pragma once

#include <iostream>
#include <string>
#include <vector>

class Plan {
	public:
	void setGoal(int goal);

	protected:
	int goal;
	std::string name;
	std::string date;
};

class DietPlan : public Plan {};

class ExercisePlan : public Plan {};

class FitnessAppWrapper {
	public:
	void runApp(void);
	void loadWeeklyPlan(std::ifstream &fileStream,
			    std::vector<DietPlan> weeklyPlan);
};

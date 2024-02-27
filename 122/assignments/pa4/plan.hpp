/*
 * Programming Assignment 4
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-02-28
 * Plan classes
 */

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// base class for DietPlan and ExercisePlan
class Plan {
	public:
		Plan(int goal = 0, std::string name = "Goal",
		     std::string date = "01/01/1970");
		Plan(const Plan &other);

		~Plan();

		Plan &operator=(const Plan &other);

		std::string toString() const;

		void setGoal(const int goal);

		void editGoal();

		friend std::fstream &operator>>(std::fstream &fileStream,
						Plan &plan);
		friend std::ostream &operator<<(std::ostream &stream,
						const Plan &plan);
		friend std::fstream &operator<<(std::fstream &fileStream,
						const Plan &plan);

	protected:
		int goal;
		std::string name;
		std::string date;
};

class DietPlan : public Plan {
	public:
		std::string toString() const;

		friend std::ostream &operator<<(std::ostream &stream,
						const DietPlan &plan);
};

class ExercisePlan : public Plan {
	public:
		std::string toString() const;

		friend std::ostream &operator<<(std::ostream &stream,
						const ExercisePlan &plan);
};

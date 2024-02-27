/*
 * Programming Assignment 4
 * Author: Neal Wang
 * Lab: 05
 * Due date: 2024-02-28
 * Basic fitness application
 */

#pragma once

#include "plan.hpp"
#include "utils.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class FitnessAppWrapper {
	public:
		FitnessAppWrapper();

		void runApp();

	private:
		std::vector<DietPlan> weeklyDietPlan;
		std::vector<ExercisePlan> weeklyExercisePlan;

		void loadDailyPlan(std::fstream &fileStream, Plan &plan);
		// use a template for both DietPlan and ExercisePlan
		template <class T>
		void loadWeeklyPlan(std::fstream &fileStream,
				    std::vector<T> &weeklyPlan);

		template <class T>
		void displayDailyPlan(T &plan);
		template <class T>
		void displayWeeklyPlan(std::vector<T> &weeklyPlan);

		void storeDailyPlan(std::fstream &fileStream, Plan &plan);
		template <class T>
		void storeWeeklyPlan(std::fstream &fileStream,
				     std::vector<T> &weeklyPlan);

		int displayMenu();
		template <class T>
		int selectPlan(std::vector<T> &weeklyPlan);
};

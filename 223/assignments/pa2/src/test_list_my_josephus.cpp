#include "test_list_my_josephus.hpp"
#include "list_my_josephus.hpp"
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

void test_list_my_josephus() {
	std::fstream df("target/destinations.csv");
	// use `std::list` to stay consistent with ListMyJosephus
	std::list<Destination> destinations;

	int N = 0;
	std::string destination_name;
	while (std::getline(df, destination_name, ';')) {
		destinations.push_back(Destination(N, destination_name));
		++N;
	}
	df.close();

	// `N` will be the total since one more is added

	std::vector<double> times(N);

	for (int i = 1; i <= N; ++i) {
		// https://stackoverflow.com/a/12658061/14946864
		std::random_device seed;
		std::mt19937 rng(seed());
		std::uniform_int_distribution<int> dist(0, i - 1);
		int M = dist(rng);

		// make a new list with first `i` elements
		std::list<Destination> first_N;
		auto it = std::next(destinations.begin(), i);
		std::copy(destinations.begin(), it,
			  std::back_inserter(first_N));

		// copied from `ElapsedTimeExample.cpp`
		clock_t start = clock();
		// INFO: start simulation
		ListMyJosephus lmj(M, i, destinations);
		while (lmj.current_size() > 1) {
			Destination d = lmj.eliminate_destination();
			d.print_position();
			std::cout << ". ";
			d.print_name();
			std::cout << std::endl;
		}
		std::cout << "Final destination: ";
		lmj.print_destinations();
		std::cout << std::endl;
		// INFO: end simulation
		clock_t end = clock();
		times[i - 1] = (double)(end - start) / CLOCKS_PER_SEC;
		std::cout << "(ListMyJosephus) N = " << i << ", M = " << M
			  << " time: " << times[i - 1] << std::endl;
	}

	double total_time = std::accumulate(times.begin(), times.end(), 0.0);
	double avg_time = total_time / N;

	std::cout << "(ListMyJosephus) Total time: " << total_time << "s"
		  << std::endl;
	std::cout << "(ListMyJosephus) Average time per simulation: "
		  << avg_time << "s" << std::endl;

	// append results to file
	std::ofstream of("results.log", std::ios::app);
	of << "ListMyJosephus: " << avg_time << std::endl;
	of.close();
}

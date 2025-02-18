#include "test_vector_my_josephus.hpp"
#include "vector_my_josephus.hpp"
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

// NOTE: refer to `test_vector_my_josephus.cpp` for additional comments

void test_vector_my_josephus() {
	std::fstream df("target/destinations.csv");
	// use `std::vector` to stay consistent with VectorMyJosephus
	std::vector<Destination> destinations;

	int N = 0;
	std::string destination_name;
	while (std::getline(df, destination_name, ';')) {
		destinations.push_back(Destination(N, destination_name));
		++N;
	}
	df.close();

	std::vector<double> times(N);

	for (int i = 1; i <= N; ++i) {
		std::random_device seed;
		std::mt19937 rng(seed());
		std::uniform_int_distribution<int> dist(0, i - 1);
		// int M = 100; // testing for constistency
		int M = dist(rng);

		std::vector<Destination> first_N;
		auto it = std::next(destinations.begin(), i);
		std::copy(destinations.begin(), it,
			  std::back_inserter(first_N));

		clock_t start = clock();
		// INFO: start simulation
		VectorMyJosephus vmj(M, i, destinations);
		while (vmj.current_size() > 1) {
			Destination d = vmj.eliminate_destination();
			d.print_position();
			std::cout << ". ";
			d.print_name();
			std::cout << std::endl;
		}
		std::cout << "Final destination: ";
		vmj.print_destinations();
		std::cout << std::endl;
		// INFO: end simulation
		clock_t end = clock();
		times[i - 1] = (double)(end - start) / CLOCKS_PER_SEC;
		std::cout << "(VectorMyJosephus) N = " << i << ", M = " << M
			  << " time: " << times[i - 1] << "s" << std::endl;
	}

	double total_time = std::accumulate(times.begin(), times.end(), 0.0);
	double avg_time = total_time / N;

	std::cout << "(VectorMyJosephus) Total time: " << total_time << "s"
		  << std::endl;
	std::cout << "(VectorMyJosephus) Average time per simulation: "
		  << avg_time << "s" << std::endl;

	std::ofstream of("results.log", std::ios::app);
	of << "VectorMyJosephus: " << avg_time << std::endl;
	of.close();
}

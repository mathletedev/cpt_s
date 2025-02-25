#include "avl_map.hpp"
#include "us_city.hpp"
#include "utils.hpp"
#include <algorithm>
#include <fstream>
#include <map>
#include <random>
#include <vector>

#define NUM_LOOKUPS 1000

int main() {
	std::ifstream data("./target/uszips.csv");

	AvlMap<int, USCity> avl_map;
	std::map<int, USCity> std_map;
	// NOTE: used vector instead of list due to faster indexing and
	// `std::shuffle()`
	std::vector<int> zips;

	std::string line;
	// ignore first line
	std::getline(data, line);

	while (std::getline(data, line)) {
		std::vector<std::string> columns = parse_csv_line(line);

		std::string zip_s = columns[0];
		int zip = std::stoi(zip_s);
		USCity city(columns);

		avl_map.insert(zip, city);
		std_map.insert(std::make_pair(zip, city));
		zips.push_back(zip);
	}

	std::random_device rd;
	std::mt19937 gen(rd());

	std::shuffle(zips.begin(), zips.end(), gen);
	// keep a copy for std_map since we are mutating the first one

	// INFO: avl_map benchmark
	clock_t start = clock();
	for (int i = 0; i < NUM_LOOKUPS; ++i) {
		int zip = zips[i];

		auto _ = avl_map.find(zip);
	}
	clock_t end = clock();

	double avl_time = (double)(end - start) / CLOCKS_PER_SEC;

	// INFO: std_map benchmark
	start = clock();
	for (int i = 0; i < NUM_LOOKUPS; ++i) {
		int zip = zips[i];

		auto _ = std_map.find(zip);
	}
	end = clock();

	double std_time = (double)(end - start) / CLOCKS_PER_SEC;

	std::cout << "avl_map  elapsed time: " << avl_time << "s" << std::endl;
	std::cout << "std::map elapsed time: " << std_time << "s" << std::endl;

	// NOTE: example of avl_map operations
	// AvlMap<int, int> map;
	// map.insert(1, 10);
	// map.insert(2, 20);
	// map.insert(3, 30);
	// map.insert(4, 40);
	// map.insert(5, 50);
	// map.insert(6, 60);

	// map.erase(5);

	// std::for_each(map.begin(), map.end(), [](const std::pair<int, int>
	// &x) { 	std::cout << x.first << " " << x.second << std::endl;
	// });

	// map.display_adj();

	data.close();

	return 0;
}

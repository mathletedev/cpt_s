#include "packet.hpp"
#include "queue.hpp"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <thread>

#define MIN_WAIT 100
#define MAX_WAIT 1000

int gen_random(int min, int max) {
	return rand() % (max - min + 1) + min;
}

int main() {
	srand(time(0));

	std::ifstream input;
	input.open("data/words.txt");

	queue<packet> traffic;

	int wait_process = gen_random(MIN_WAIT, MAX_WAIT);
	int wait_arrival = gen_random(MIN_WAIT, MAX_WAIT);

	while (true) {
		if (input.eof() && traffic.is_empty()) break;

		if (wait_process < wait_arrival) {
			wait_arrival -= wait_process;
			std::this_thread::sleep_for(
			    std::chrono::milliseconds(wait_process));
			wait_process = gen_random(MIN_WAIT, MAX_WAIT);

			packet p;
			if (!traffic.dequeue(p)) continue;

			std::cout << p.get_data() << std::endl;

			continue;
		}

		wait_process -= wait_arrival;
		std::this_thread::sleep_for(
		    std::chrono::milliseconds(wait_arrival));
		wait_arrival = gen_random(MIN_WAIT, MAX_WAIT);

		std::string word;
		if (!(input >> word)) continue;

		packet p(word.length(), word);

		traffic.enqueue(p);
	}

	input.close();

	return 0;
}

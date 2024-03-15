#include "simulation.hpp"
#include "tests.hpp"

// comment out this line to run simulation without tests
// #define TESTING

#ifdef TESTING
int main() {
	tests().test_all();

	return 0;
}
#else
// number of minutes to run simulation for
#define N 1000000

int main() {
	simulation(N).run();

	return 0;
}
#endif

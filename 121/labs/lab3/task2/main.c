#include "functions.h"
#include "headers.h"

int main(void) {
	double theta = read("angle (radians) of elevation");
	double distance = read("distance (ft) to target");
	double velocity = read("projectile velocity (ft/sec)");

	double time = calculate_time(distance, velocity, theta);
	double height = calculate_height(velocity, theta, time);

	printf("Time (sec) of flight: %g\n", time);
	printf("Height of impact: %g\n", height);

	return 0;
}

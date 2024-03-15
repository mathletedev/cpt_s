#include "simulation.hpp"

simulation::simulation(int n) {
	srand(time(nullptr));

	n_ = n;
}

void simulation::run() {
	next_express_ = random(1, 5);
	next_normal_ = random(3, 8);

	time_express_ = 0;
	time_normal_ = 0;

	curr_express_ = 0;
	curr_normal_ = 0;

	customer_number_ = 1;

	// t_ is time in minutes
	for (t_ = 0; t_ < n_; ++t_)
		update();
}

// updates a single minute of the simulation
void simulation::update() {
	if (t_ % ONE_DAY == 0)
		// reset customer numbers
		customer_number_ = 1;

	if (!express_.is_empty() &&
	    curr_express_ == express_.peek()->get_service_time()) {
		data data = express_.dequeue();
		std::cout << curr_time() << " | Customer "
			  << data.get_customer_number()
			  << " checked out at express lane ("
			  << data.get_total_time() << " minutes)\n";

		curr_express_ = 0;
		// remove service time from running total
		time_express_ -= data.get_service_time();
	}
	if (!normal_.is_empty() &&
	    curr_normal_ == normal_.peek()->get_service_time()) {
		data data = normal_.dequeue();
		std::cout << curr_time() << " | Customer "
			  << data.get_customer_number()
			  << " checked out at normal lane ("
			  << data.get_total_time() << " minutes)\n";

		curr_normal_ = 0;
		time_normal_ -= data.get_service_time();
	}

	if (next_express_ == 0) {
		std::cout << curr_time() << " | Customer " << customer_number_
			  << " arrived at express lane\n";

		next_express_ = random(1, 5);
		int service_time = random(1, 5);

		// sum of service_time + own service_time
		time_express_ += service_time;
		// subtract curr_express_ because that time has already passed
		express_.enqueue(data(customer_number_++, service_time,
				      time_express_ - curr_express_));
	}
	if (next_normal_ == 0) {
		std::cout << curr_time() << " | Customer " << customer_number_
			  << " arrived at normal lane\n";

		next_normal_ = random(3, 6);
		int service_time = random(3, 6);

		time_normal_ += service_time;
		normal_.enqueue(data(customer_number_++, service_time,
				     time_normal_ - curr_normal_));
	}

	if (t_ % 10 == 0 && t_ > 0) {
		std::cout << curr_time() << " | Express lane: ";
		express_.print();
		std::cout << "\n";
		std::cout << curr_time() << " | Normal lane: ";
		normal_.print();
		std::cout << "\n";
	}

	--next_express_;
	--next_normal_;

	if (!express_.is_empty()) ++curr_express_;
	if (!normal_.is_empty()) ++curr_normal_;
}

// returns a random number in [low, high]
int simulation::random(int low, int high) const {
	return rand() % (high - low + 1) + low;
}

// returns current time as HH:MM
std::string simulation::curr_time() const {
	std::string mins = std::to_string(t_ % 60);
	std::string hours = std::to_string((t_ / 60) % 24);
	if (mins.length() == 1) mins = "0" + mins;
	if (hours.length() == 1) hours = "0" + hours;

	return hours + ":" + mins;
}

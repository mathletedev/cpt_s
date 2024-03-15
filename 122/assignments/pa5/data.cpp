#include "data.hpp"

data::data(const int &customer_number, const int service_time,
	   const int total_time) {
	customer_number_ = customer_number;
	service_time_ = service_time;
	total_time_ = total_time;
}

data::data(const data &other) {
	*this = other;
}

data::~data() {
	// nothing to do
}

int data::get_customer_number() const {
	return customer_number_;
}

int data::get_service_time() const {
	return service_time_;
}

int data::get_total_time() const {
	return total_time_;
}

data &data::operator=(const data &rhs) {
	customer_number_ = rhs.customer_number_;
	service_time_ = rhs.service_time_;
	total_time_ = rhs.total_time_;

	return *this;
}

bool operator==(const data &lhs, const data &rhs) {
	return lhs.customer_number_ == rhs.customer_number_ &&
	       lhs.service_time_ == rhs.service_time_ &&
	       lhs.total_time_ == rhs.total_time_;
}

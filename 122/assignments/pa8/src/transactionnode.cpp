#include "transactionnode.hpp"

transaction_node::transaction_node(std::string const &data, int const &units)
    : node(data) {
	units_ = units;
}

transaction_node::~transaction_node() {
	// nothing to do
}

void transaction_node::print_data() const {
	std::cout << data_ << " (" << units_ << " units)" << std::endl;
}

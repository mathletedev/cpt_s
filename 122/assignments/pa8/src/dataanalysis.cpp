#include "dataanalysis.hpp"

data_analysis::~data_analysis() {
	if (csv_stream_.is_open()) csv_stream_.close();
}

void data_analysis::run_analysis() {
	open("data/data.csv");

	std::string consumed;
	// consume header line
	std::getline(csv_stream_, consumed);

	process();
	std::cout << std::endl;

	write_trends();
}

void data_analysis::open(std::string const &path) {
	csv_stream_.open(path);
}

// reads and parses data_point from the next line in csv_stream_
// returns false if read failed (used to find EOF)
bool data_analysis::parse_line(data_point &data_point) {
	if ((csv_stream_ >> data_point.units).fail()) return false;

	char c;
	// read comma, then first character
	csv_stream_ >> c >> c;

	data_point.type = "";
	// read into data_point.type until next comma
	for (; c != ','; csv_stream_ >> c)
		data_point.type += c;

	std::string tmp;
	// transaction type
	csv_stream_ >> tmp;

	data_point.transaction_type = tmp == "Purchased" ? purchased : sold;

	return true;
}

// reads through entire csv file line by line
// inserts each line
// displays resulting bsts
void data_analysis::process() {
	data_point curr;

	while (parse_line(curr))
		insert(curr);

	std::cout << "Purchased BST:" << std::endl;
	tree_purchased_.in_order_traversal();
	std::cout << std::endl;

	std::cout << "Sold BST:" << std::endl;
	tree_sold_.in_order_traversal();
}

// inserts a data_point into its corresponding bst
void data_analysis::insert(data_point const &data_point) {
	bst &bst = data_point.transaction_type == purchased ? tree_purchased_
							    : tree_sold_;

	bst.insert(data_point.type, data_point.units);
}

// writes to cout trends in the bsts
void data_analysis::write_trends() const {
	std::cout << "Trends:" << std::endl;

	transaction_node &lp = tree_purchased_.find_smallest();
	std::cout << "Least purchased: " << lp.get_data() << " ("
		  << lp.get_units() << " units)" << std::endl;

	transaction_node &ls = tree_sold_.find_smallest();
	std::cout << "Least sold: " << ls.get_data() << " (" << ls.get_units()
		  << " units)" << std::endl;

	transaction_node &mp = tree_purchased_.find_largest();
	std::cout << "Most purchased: " << mp.get_data() << " ("
		  << mp.get_units() << " units)" << std::endl;

	transaction_node &ms = tree_sold_.find_largest();
	std::cout << "Most sold: " << ms.get_data() << " (" << ms.get_units()
		  << " units)" << std::endl;
}

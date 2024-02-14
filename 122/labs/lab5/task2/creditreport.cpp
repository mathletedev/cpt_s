#include "creditreport.hpp"

CreditReport::CreditReport(){};

void CreditReport::printReport() {
	std::cout << "Credit score: " << creditScore << std::endl;
	std::cout << "Total real estate: " << totalRealEstate << std::endl;
	std::cout << "Credit card debt: " << creditCardDebt << std::endl;
	std::cout << "Number of real estate: " << numRealEstate << std::endl;
	std::cout << "Credit cards: " << creditCards << std::endl;
	std::cout << "Retail cards: " << retailCards << std::endl;
	std::cout << "Oldest account age: " << oldestAge << std::endl;
	std::cout << "Average account age: " << averageAge << std::endl;
	std::cout << "Number of hard inquiries: " << numHardInquiries
		  << std::endl;
}

#pragma once

#include <iostream>

class CreditReport {
	public:
		CreditReport();
		void printReport();

	private:
		int creditScore = 850;
		double totalRealEstate = 0;
		double creditCardDebt = 0;
		int numRealEstate = 0;
		int creditCards = 0;
		int retailCards = 0;
		int oldestAge = 0;
		int averageAge = 0;
		int numHardInquiries = 0;
};

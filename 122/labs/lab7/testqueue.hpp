#pragma once

#include "queue.hpp"
#include <string>

class TestQueue {
	public:
		void runTests();

	private:
		void testIsEmpty();
		void testEnqueue();
		void testDequeue();
		void testPrintRecursive();
};

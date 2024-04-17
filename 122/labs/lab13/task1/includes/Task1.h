#include <iostream>

using std::cout;
using std::endl;

class Base {
	public:
		// void testFunction();
		virtual void testFunction();
};

class Derived : public Base {
	public:
		void testFunction();
};

#include "Task1.h"
int main(void) {
	Base *ptr = new Base;
	ptr->testFunction(); // prints "Base class"
	delete ptr;

	ptr = new Derived;
	ptr->testFunction(); // prints "Base class" because the base class
			     // function is not virtual delete ptr;

	return 0;
}

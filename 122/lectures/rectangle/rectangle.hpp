#pragma once

#include <iostream>

class Rectangle {
      public:
	// setters/mutators
	void set_width(double width);
	void set_length(double width);
	// getters/accessors
	double get_width();
	double get_length();

      private:
	double width;
	double length;
};

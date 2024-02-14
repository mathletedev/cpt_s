#pragma once

#include <iostream>

class Rectangle {
	public:
	// constructor
	// Rectangle(); // default constructor
	Rectangle(double length = 0, double width = 0);
	Rectangle(Rectangle &other); // copy constructor

	// destructor
	~Rectangle(); // free up resources used by object

	// setters/mutators
	void setLength(double length);
	void setWidth(double width);

	// getters/accessors
	double getLength() const; // const means can't mutate object
	double getWidth() const;

	private:
	double width;
	double length;
};

template <class T> T add(T v1, T v2);

Rectangle operator+(Rectangle r1, Rectangle r2);

std::ostream &operator<<(std::ostream &stream, const Rectangle &rectangle);

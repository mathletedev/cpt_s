#include "rectangle.hpp"

Rectangle::Rectangle(double length, double width) {
	this->length = (length < 0) ? 0 : length;
	this->width = (width < 0) ? 0 : width;
}

// other is an "alias", can not pass by value
Rectangle::Rectangle(Rectangle &other) {
	length = other.length;
	width = other.width;
}

Rectangle::~Rectangle() {
	std::cout << "Destructed" << std::endl;
}

double Rectangle::getLength() const {
	return length;
}

double Rectangle::getWidth() const {
	return width;
}

void Rectangle::setLength(double length) {
	this->length = length;
}

void Rectangle::setWidth(double width) {
	this->width = width;
}

template <class T> T add(T v1, T v2) {
	return v1 + v2;
}

Rectangle operator+(Rectangle r1, Rectangle r2) {
	Rectangle res;

	res.setLength(r1.getLength() + r2.getLength());
	res.setWidth(r1.getWidth() + r2.getWidth());

	return res;
}

std::ostream &operator<<(std::ostream &stream, const Rectangle &rectangle) {
	stream << "Width: " << rectangle.getWidth()
	       << " Height: " << rectangle.getLength();

	return stream;
}

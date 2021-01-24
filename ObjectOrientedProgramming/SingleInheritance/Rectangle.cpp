#include <iostream>
#include "rectangle.hpp"


Rectangle::Rectangle() : _length{1}, _width{1}, 
		_area{1}, _perimeter{4} { 
}

Rectangle::Rectangle(int length, int width) : _length{1}, _width{1} {
	set_length(length);
	set_width(width);
	calculate_area();
	calculate_perimeter();
}

Rectangle::Rectangle(const Rectangle &r) : _length{r._length}, 
		_width{r._width}, _area{r._area}, 
		_perimeter{r._perimeter} { 
}

Rectangle::~Rectangle() { }

int Rectangle::length() const {
	return _length;
}

int Rectangle::width() const {
	return _width;
}

int Rectangle::area() const {
	return _area;
}

int Rectangle::perimeter() const {
	return _perimeter;
}

void Rectangle::set_length(int length) {
	if (length > 0) {
		_length = length;
	}
	calculate_area();
	calculate_perimeter();
}

void Rectangle::set_width(int width) {
	if (width > 0) {
		_width = width;
	}
	calculate_area();
	calculate_perimeter();
}

void Rectangle::calculate_area() {
	_area = length() * width();
}

void Rectangle::calculate_perimeter() {
	_perimeter = 2 * (length() + width());
}

void Rectangle::print() const {
	std::cout << length() << ' ' << width() << ' ';
	std::cout << area() << ' ' << perimeter() << '\n';
}

Rectangle Rectangle::operator+(const Rectangle &r) {
	Rectangle temp;
	temp._length = length() + r.length();
	temp.set_width(width() + r.width());
	return temp;
}

Rectangle &Rectangle::operator=(const Rectangle &r) {
	_length = r.length();
	set_width(r.width());
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Rectangle &r) {
	out << r._length << ' ' << r._width << ' ';
	out << r._area << ' ' << r._perimeter;
	return out;
}

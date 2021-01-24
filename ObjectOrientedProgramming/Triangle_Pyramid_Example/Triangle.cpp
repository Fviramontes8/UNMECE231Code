#include "triangle.hpp"
#include <iostream>
#include <cmath>

/*
    ^
   /|\
  / | \
 /  |  \
/___|___\

*/

Triangle::Triangle() : _base{1}, 
		_height{1}, _area{0.5},
		_perimeter{3.23607} {
		
}

Triangle::Triangle(int base, int height) : 
		_base {1}, _height{1} {
	set_base(base);
	set_height(height);
	calculate_area();
	calculate_perimeter();
}

Triangle::Triangle(const Triangle &t) :
		_base{t._base}, _height{t._height},
		_area{t._area}, _perimeter{t._perimeter} {

}

Triangle::~Triangle() { }

int Triangle::base() const {
	return _base;
}

int Triangle::height() const {
	return _height;
}

float Triangle::area() const {
	return _area;
}

float Triangle::perimeter() const {
	return _perimeter;
}

void Triangle::set_base(int base) {
	if (base > 0) {
		_base = base;
	}
	calculate_area();
	calculate_perimeter();
}

void Triangle::set_height(int height) {
	if (height > 0) {
		_height = height;
	}
	calculate_area();
	calculate_perimeter();
}

void Triangle::calculate_area() {
	_area = (1.0/2.0) * (base() * height());
}

void Triangle::calculate_perimeter() {
	float hyp = (0.5 * base()) * (0.5 * base()) + (height() * height());
	hyp = sqrt(hyp);

	_perimeter = base() + (2.0 * hyp);
}

Triangle &Triangle::operator=(const Triangle &t) {
	_base = t._base;
	set_height(t._height);
	return *this;
}

bool Triangle::operator==(const Triangle &t) {
	return (base() == t.base()) && \
		(height() == t.height());
}

bool Triangle::operator!=(const Triangle &t) {
	return !(*this == t);
}

std::ostream &operator<<(std::ostream &out, const Triangle &t) {
	out << t._base << ' ' << t._height << ' ';
	out << t._area << ' ' << t._perimeter;
	return out;
}

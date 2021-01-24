#include "pyramid.hpp"

Pyramid::Pyramid() : Triangle(), Shape3D() {
	calculate_surface_area();
	calculate_volume();
}

Pyramid::Pyramid(int base, int height, int depth) :
		Triangle(base, height), Shape3D(depth) {
	calculate_surface_area();
	calculate_volume();
}
	
Pyramid::Pyramid(const Pyramid &p) :
		Triangle(p._base, p._height), Shape3D(p._depth) {
	calculate_surface_area();
	calculate_volume();
}

Pyramid::~Pyramid() { } 

void Pyramid::set_base(int base) {
	Triangle::set_base(base);
	calculate_surface_area();
	calculate_volume();
}

void Pyramid::set_height(int height) {
	Triangle::set_height(height);
	calculate_surface_area();
	calculate_volume();
}

void Pyramid::set_depth(int depth) {
	Shape3D::set_depth(depth);
	calculate_surface_area();
	calculate_volume();
}

void Pyramid::calculate_surface_area() {
	float bottom_area = base() * depth();
	float forward_back_area = area() * 2;
	float side_area = depth() * height();
	_surface_area = bottom_area + forward_back_area + side_area;
}

void Pyramid::calculate_volume() {
	_volume = (1.0/3.0) * (area() * depth());
}

Pyramid &Pyramid::operator=(const Pyramid &p) {
	_base = p._base;
	_height = p._height;
	set_depth(p._depth);
	return *this;
}

bool Pyramid::operator==(const Pyramid &p) {
	return (base()) == p.base() && \
		(height() == p.height()) && \
		(depth() == depth());
}

bool Pyramid::operator!=(const Pyramid &p) {
	return !(*this == p);
}

std::ostream &operator<<(std::ostream &out, const Pyramid &p) {
	out << p._base << ' ' << p._height << ' ' << p._depth << ' ';
	out << p._surface_area << ' ' << p._volume;
	return out;
}

#include "shape3d.hpp"

Shape3D::Shape3D() : _depth{1} {

}

Shape3D::Shape3D(int depth) : _depth{1} {
	set_depth(depth);
}

Shape3D::Shape3D(const Shape3D &s) : _depth{s._depth} {

}

Shape3D::~Shape3D() { } 

int Shape3D::depth() const {
	return _depth;
}

float Shape3D::surface_area() const {
	return _surface_area;
}

float Shape3D::volume() const {
	return _volume;
}

void Shape3D::set_depth(int depth) {
	if (depth > 0) {
		_depth = depth;
	}
}

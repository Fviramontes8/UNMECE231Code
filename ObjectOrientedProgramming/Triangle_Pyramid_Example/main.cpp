#include <iostream>
//#include "triangle.hpp"
#include "pyramid.hpp"

int main() {
	Triangle t1, t2(1, 1), t3(6, 4);

	if (t1 == t2) {
		std::cout << "Triangles t1 & t2 are equal!\n";
	}

	if (t1 != t3) {
		std::cout << "Triangles t1 & t3 are not equal!\n";
	}

	std::cout << t3 << '\n';

	Pyramid p1, p2(1, 1, 1), p3(3, 4, 5);

	if (p1 == p2) {
		std::cout << "Pyramids p1 & p2 are equal!\n";
	}

	if (p1 != p3) {
		std::cout << "Pyramids p1 & p3 are not equal!\n";
	}

	std::cout << p3 << '\n';

	return 0;
}

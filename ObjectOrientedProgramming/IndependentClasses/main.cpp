#include <iostream>
#include "rectangle.hpp"
#include "cube.hpp"

int main() {
	Rectangle r1, r2(4, 5);
	r1.set_length(3);
	r1.print();

	Rectangle r3(r1 + r2);
	std::cout << r3 << std::endl;

	Cube c1, c2(5, 12, 13);
	c1.set_depth(9);
	c1.print();

	Cube c3(c1 + c2);
	std::cout << c3 << std::endl;

	std::cout << (c1 * 4) << std::endl;

	return 0;
}

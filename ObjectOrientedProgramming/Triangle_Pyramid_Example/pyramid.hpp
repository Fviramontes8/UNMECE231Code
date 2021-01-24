#include <iostream>
#include "triangle.hpp"
#include "shape3d.hpp"

class Pyramid : public Triangle, public Shape3D {
	public:
		Pyramid();
		Pyramid(int base, int height, int depth);
		Pyramid(const Pyramid &p);
		~Pyramid();

		void set_base(int base) override;
		void set_height(int height) override;
		void set_depth(int depth) override;
		void calculate_surface_area() override;
		void calculate_volume() override;

		Pyramid &operator=(const Pyramid &p);
		bool operator==(const Pyramid &p);
		bool operator!=(const Pyramid &p);

		friend std::ostream &operator<<(std::ostream &out, const Pyramid &p);
};

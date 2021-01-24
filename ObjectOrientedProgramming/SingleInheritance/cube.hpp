#include "rectangle.hpp"

class Cube : public Rectangle {
	private:
		int _depth;
		int _surface_area;
		int _volume;
	
	public:
		Cube();
		Cube(int length, int width, int depth);
		Cube(const Cube &c);
		~Cube();

		int depth() const;
		int surface_area() const;
		int volume() const;

		void set_length(int length) override;
		void set_width(int width) override;
		void set_depth(int depth);
		void calculate_surface_area();
		void calculate_volume();

		void print() const final;

		Cube operator+(const Cube &c);
		Cube operator*(int i);

		Cube &operator=(const Cube &c);

		friend std::ostream &operator<<(std::ostream &out, const Cube &c);
};

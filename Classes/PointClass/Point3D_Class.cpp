#include <iostream>

class Point3D {
	private:
		double _x;
		double _y;
		double _z;

	public:
		// Default Unparameterized Constructor
		Point3D() : _x{0}, _y{0}, _z{0} {
			std::cout << "Unparam constructor!\n";
		}

		// Default Parameterized Constructor
		Point3D(double x, double y, double z) : _x{x}, _y{y}, _z{z} {
			std::cout << "Param constructor!\n";
		}

		// Copy Constructor
		Point3D(const Point3D &p) : _x{p._x}, _y{p._y}, _z{p._z}  {
			std::cout << "Copy constructor!\n";
		}

		// Destructor
		~Point3D() {
			std::cout << "Destructor!\n";
		}

		void print() {
			std::cout << "x: " << _x << " y: " << _y << " z: " << _z;
			std::cout << std::endl;
		}
		
		void set_x(double x) {
			if (x >= 0) {
				_x = x;
			}
		}

		void set_y(double y) {
			if (y >= 0) {
				_y = y;
			}
		}

		void set_z(double z) {
			if (z >= 0) {
				_z = z;
			}
		}

		void set(double x, double y, double z) {
			set_x(x);
			set_y(y);
			set_z(z);
		}

		double x() const {
			return _x;
		}

		double y() const {
			return _y;
		}
		
		double z() const {
			return _z;
		}
};

int main() {
	Point3D q;
	Point3D t(8.3, 7.6, 1.2);
	Point3D e(t);

	q.print();
	e.print();

	return 0;
}

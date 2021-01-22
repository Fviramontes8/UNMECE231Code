#include <iostream>
#include <stdexcept>	// std::overflow_error

class Point3D {
	private:
		double _x;
		double _y;
		double _z;

	public:
		// Default Unparameterized Constructor
		Point3D() : _x{0}, _y{0}, _z{0} {
		}

		// Default Parameterized Constructor
		Point3D(double x, double y, double z) : _x{x}, _y{y}, _z{z} {
		}

		// Copy Constructor
		Point3D(const Point3D &p) : _x{p._x}, _y{p._y}, _z{p._z}  {
		}

		// Destructor
		~Point3D() {
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

		// x = lhs + rhs
		// z = 3 + 6
		Point3D operator+(const Point3D &p) {
			Point3D temp;
			temp.set_x(x() + p.x());
			// temp._x = _x + p._x;
			temp.set_y(y() + p.y());
			temp.set_z(z() + p.z());

			return temp;
		}

		Point3D operator-(const Point3D &p) {
			Point3D temp;
			temp.set_x(x() - p.x());
			temp.set_y(y() - p.y());
			temp.set_z(z() - p.z());

			return temp;
		}

		Point3D operator*(const Point3D &p) {
			Point3D temp;
			temp.set_x(x() * p.x());
			temp.set_y(y() * p.y());
			temp.set_z(z() * p.z());

			return temp;
		}

		Point3D operator/(const Point3D &p) {
			Point3D temp;
			if ( (p.x() == 0) || (p.y() == 0) ||
					(p.z() == 0) ) {
				throw std::overflow_error("Divide by zero");
			}
			temp.set_x(x() / p.x());
			temp.set_y(y() / p.y());
			temp.set_z(z() / p.z());

			return temp;
		}

		// a = b;
		// a = a;
		Point3D operator=(const Point3D &p) {
			set_x(p.x());
			set_y(p.y());
			set_z(p.z());

			return *this;
		}

		Point3D operator=(const int &i) {
			set_x(i);
			set_y(i);
			set_z(i);

			return *this;
		}

		bool operator==(const Point3D &p) {
			return ( (x() == p.x()) && \
				(y() == p.y()) && \
				(z() == p.z()) );
		}

		bool operator!=(const Point3D &p) {
			return !(*this == p);
		}

		friend std::ostream &operator<<(std::ostream &out, const Point3D &p) {
			out << p._x << ' ' << p._y << ' ' << p._z;
			return out;
		}

		friend std::istream &operator>>(std::istream &in, Point3D &p) {
			double temp;
			in >> temp;
			p.set_x(temp);
			in >> temp;
			p.set_y(temp);
			in >> temp;
			p.set_z(temp);
			return in;
		}

		// Pre ++
		Point3D operator++() {
			set_x(x() + 1);
			set_y(y() + 1);
			set_z(z() + 1);
			return *this;
		}

		// Post++
		Point3D operator++(int p) {
			Point3D temp = *this;
			++*this;
			return temp;
		}

		// Pre --
		Point3D operator--() {
			set_x(x() - 1);
			set_y(y() - 1);
			set_z(z() - 1);
			return *this;
		}

		// Post--
		Point3D operator--(int p) {
			Point3D temp =  *this;
			--*this;
			return temp;
		}
};

int main() {
	Point3D q;
	Point3D t(8.3, 7.6, 1.2);
	Point3D e(t);

	q.print();
	e.print();

	q.set(1, 1, 1);

	std::cout << q << std::endl;
	Point3D z = t + q++;
	std::cout << z << '\t' << q << std::endl;

	Point3D g = q-- / z;
	std::cout << g << '\t' << q << std::endl;

	/*
	Point3D a = t + q;
	Point3D b = t - q;

	Point3D c = t * e;
	Point3D d = t / e;

	a.print();
	b.print();
	c.print();
	d.print();
	std::cout << a << '\n' << b << '\n';
	std::cout << c << '\n' << d << '\n';

	std::cin >> q;
	std::cout << q << std::endl;

	std::cout << (e == t) << ' ' << (e == q) << '\n';
	std::cout << (e != t) << ' ' << (e != q) << '\n';
	*/


	return 0;
}

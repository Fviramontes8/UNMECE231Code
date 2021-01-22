#include <iostream>

class Vector {
	private:
		double *_elem;
		int _size;
	public:
		// std::vector<int> v = {1, 2, 3, 4};
		Vector(std::initializer_list<double> lst) :
				_elem{new double[lst.size()]}, _size{(int) lst.size()} {
			std::copy(lst.begin(), lst.end(), _elem);
		}

		Vector(const Vector &v) : _elem{new double[v.size()]}, _size{v.size()} {
			for (int i = 0; i != _size; i++) {
				_elem[i] = v._elem[i];
			}
		}

		~Vector() {
			delete[] _elem;
		}

		int size() const {
			return _size;
		}

		double &operator[](int i) {
			return _elem[i];
		}
};

int main() {
	Vector f{1, 2, 3};

	std::cout << f.size() << std::endl;

	Vector s(f);

	s[1] = 8;
	s[0] = 19;

	for (int i = 0; i < s.size(); i++) {
		std::cout << s[i] << ' ';
	}
	std::cout << std::endl;
	
	return 0;
}

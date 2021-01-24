#include <iostream> 

class Triangle {
	protected:
		int _base;
		int _height;
		float _area;
		float _perimeter;
	public:
		Triangle();
		Triangle(int base, int height);
		Triangle(const Triangle &t);
		virtual ~Triangle();

		// Getters
		int base() const;
		int height() const;
		float area() const;
		float perimeter() const;

		// Setters
		virtual void set_base(int base);
		virtual void set_height(int height);
		void calculate_area();
		void calculate_perimeter();

		Triangle &operator=(const Triangle &t);

		bool operator==(const Triangle &t);
		bool operator!=(const Triangle &t);

		friend std::ostream &operator<<(std::ostream &out, const Triangle &t);
};

class Cube {
	private:
		int _length;
		int _width;
		int _depth;
		int _surface_area;
		int _volume;
	
	public:
		Cube();
		Cube(int length, int width, int depth);
		Cube(const Cube &c);
		~Cube();

		int length() const;
		int width() const;
		int depth() const;
		int surface_area() const;
		int volume() const;

		void set_length(int length);
		void set_width(int width);
		void set_depth(int depth);
		void calculate_surface_area();
		void calculate_volume();

		void print() const;

		Cube operator+(const Cube &c);
		Cube operator*(int i);

		Cube &operator=(const Cube &c);

		friend std::ostream &operator<<(std::ostream &out, const Cube &c);
};

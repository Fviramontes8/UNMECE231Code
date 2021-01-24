class Rectangle {
	protected:
		int _length;
		int _width;
		int _area;
		int _perimeter;
	
	public:
		Rectangle();
		Rectangle(int length, int width);
		Rectangle(const Rectangle &r);
		virtual ~Rectangle();

		int length() const;
		int width() const;
		int area() const;
		int perimeter() const;

		virtual void set_length(int length);
		virtual void set_width(int width);
		void calculate_area();
		void calculate_perimeter();

		virtual void print() const;

		Rectangle operator+(const Rectangle &r);
		Rectangle &operator=(const Rectangle &r);

		friend std::ostream &operator<<(std::ostream &out, const Rectangle &r);
};

class Shape3D {
	protected:
		int _depth;
		float _surface_area;
		float _volume;
	public:
		Shape3D();
		Shape3D(int depth);
		Shape3D(const Shape3D &s);
		virtual ~Shape3D();

		int depth() const;
		float surface_area() const;
		float volume() const;

		virtual void set_depth(int depth);
		virtual void calculate_surface_area() = 0;
		virtual void calculate_volume() = 0;
};

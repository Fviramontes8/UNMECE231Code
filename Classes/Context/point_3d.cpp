#include <iostream>

struct _point_3d {
	double x;
	double y;
	double z;

	void (*init) (struct _point_3d *, double, double, double);
	void (*print) (struct _point_3d *);
};

typedef struct _point_3d Point3D;

void set_point(Point3D *p, double p_x, double p_y, double p_z) {
	p->x = p_x;
	p->y = p_y;
	p->z = p_z;
}

void print_point(Point3D *p) {
	std::cout << "x: " << p->x << " y: " << p->y << " z: " << p->z << '\n';
}

int main() {
	Point3D p;
	p.init = set_point;
	p.print = print_point;

	p.init(&p, 3, 7, 12);
	p.print(&p);

	p.init(3, 7, 12);
	p.print();

	return 0;
}

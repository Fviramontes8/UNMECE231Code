GPP=g++ -std=c++17

all: Pyramid.o Shape3D.o Triangle.o main.o
	$(GPP) Pyramid.o Shape3D.o Triangle.o main.o -o moar_tests

Pyramid.o: Pyramid.cpp pyramid.hpp
	$(GPP) -c Pyramid.cpp

Shape3D.o: Shape3D.cpp shape3d.hpp
	$(GPP) -c Shape3D.cpp

Triangle.o: Triangle.cpp triangle.hpp
	$(GPP) -c Triangle.cpp

main.o: main.cpp triangle.hpp
	$(GPP) -c main.cpp

clean:
	rm *.o
	rm moar_tests

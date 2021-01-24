all: main.o Rectangle.o Cube.o
	g++ -std=c++17 main.o Rectangle.o Cube.o -o test_shapes

main.o: main.cpp rectangle.hpp
	g++ -std=c++17 -c main.cpp

Rectangle.o: Rectangle.cpp rectangle.hpp
	g++ -std=c++17 -c Rectangle.cpp

Cube.o: Cube.cpp cube.hpp
	g++ -std=c++17 -c Cube.cpp

clean:
	rm *.o
	rm test_shapes

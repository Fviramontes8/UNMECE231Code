all: main.o func_int_list.o
	g++ -std=c++17 main.o func_int_list.o -o TestList

main.o: main.cpp int_list.hpp
	g++ -std=c++17 -c main.cpp

func_int_list.o: func_int_list.cpp int_list.hpp
	g++ -std=c++17 -c func_int_list.cpp

clean:
	rm *.o
	rm TestList

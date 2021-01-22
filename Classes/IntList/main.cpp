#include <iostream>
#include "int_list.hpp"

int main() {
	IntList list;

	if(list.empty()) {
		std::cout << "The list is empty!" << std::endl;
	}
	else {
		std::cout << "The list is not empty!" << std::endl;
	}

	list.add_frontnode(1);
	list.add_frontnode(0);

	if(list.empty()) {
		std::cout << "The list is empty!" << std::endl;
	}
	else {
		std::cout << "The list is not empty!" << std::endl;
	}

	list.add_backnode(5);

	std::cout << "Took a copy of the IntList!";
	std::cout << std::endl << std::endl;
	IntList second_list(list);

	std::cout << "Size of the list: " << list.size();
	std::cout << std::endl << "Entire list: ";
	list.print();
	std::cout << std::endl;

	std::cout << "First node: " << list.front() << " ";
	std::cout << "back node: " << list.back() << std::endl;
	std::cout << std::endl;

	list.rm_frontnode();
	list.rm_backnode();

	std::cout << "Printing first list: ";
	list.print();

	std::cout << "Printing second list: ";
	second_list.print();

	return 0;
}

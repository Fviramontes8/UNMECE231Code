#include <iostream>
#include "int_list.hpp"

void IntList::reccopy(const List *ptr) {
	if(ptr) {
		reccopy(ptr->next);
		add_frontnode(ptr->value);
	}
}

IntList::IntList() {
	_front = nullptr;
	_back = nullptr;
	_size = 0;
}

IntList::IntList(const IntList &list) {
	_front = nullptr;
	_back = nullptr;
	_size = 0;
	reccopy(list._front);
}

IntList::~IntList() {
	while( !empty() ) {
		rm_frontnode();
	}
}

int IntList::front() const {
	return _front->value;
}

int IntList::back() const {
	return _back->value;
}

size_t IntList::size() const {
	return _size;
}

void IntList::print() {
	List *temp;
	for(temp=_front; temp!=nullptr; temp=temp->next) {
		std::cout << temp->value << " ";
	}
	std::cout << std::endl;
}

void IntList::add_frontnode(int data) {
	List *newNode = new List;
	newNode->value = data;

	if(_front == nullptr) {
		newNode->next = nullptr;
		_back = newNode;
	}
	else {
		newNode->next = _front;
	}

	_front = newNode;
	_size++;
}

void IntList::add_backnode(int data) {
	List *newNode = new List;
	newNode->value = data;
	newNode->next = nullptr;

	if(_back != nullptr) {
		_back->next = newNode;
	}

	if(_front == nullptr) {
		_front = newNode;
	}

	_back = newNode;
	_size++;
}

void IntList::rm_frontnode() {
	List *node_to_remove = _front;
	_front = _front->next;

	if(_front==nullptr) {
		_back = nullptr;
	}

	delete node_to_remove;
	_size--;
}

void IntList::rm_backnode() {
	List *node_to_remove = _back;

	if(_front->next != nullptr) {
		List *new_back = _front;
		while(new_back->next != _back) {
			new_back=new_back->next;
		}
		new_back->next = nullptr;
		_back = new_back;
	}
	else {
		_front = nullptr;
		_back = nullptr;
	}

	delete node_to_remove;
	_size--;
}

bool IntList::empty() {
	return ((_front==nullptr) && (_back==nullptr));
}

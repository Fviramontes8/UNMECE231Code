#include <iostream>

class IntList {
	private:
		struct _list {
			int value;
			struct _list *next;
		};
		typedef struct _list List;

		List *_front;
		List *_back;
		size_t _size;

		// Private function to copy data of one IntList to another
		void reccopy(const List *ptr);

	public:
		//Constructors and destructors
		IntList();
		IntList(const IntList &List);
		~IntList();

		// Methods:

		// Getters
		int front() const;
		int back() const;
		size_t size() const;

		// General print function
		void print();

		// Adding data to the IntList class
		void add_frontnode(int data);
		void add_backnode(int data);

		// Removing data from the IntList class
		void rm_frontnode();
		void rm_backnode();

		bool empty();
};


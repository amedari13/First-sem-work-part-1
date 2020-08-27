#include"Header.h"


int main()
{
	Queue q;
	std::cout << "Enter the max size of the queue: ";
	std::cin >> q.max_size;
	Create(q, q.max_size);

	int choice, value;
	std::cout
		<< "To-do list: " << std::endl
		<< "1 - enter element" << std::endl
		<< "2 - delete element" << std::endl
		<< "3 - console output" << std::endl
		<< "4 - max element index - min element index" << std::endl
		<< "5 - exit" << std::endl;
	do {
		std::cout << "Select: ";
		std::cin >> choice;
		switch (choice) {
		case 1: std::cout << "Enter number: "; std::cin >> value; Adding(q, value); break;
		case 2: std::cout << std::endl << "The first element ( " << Getting(q) << " ) was deleted" << std::endl; break;
		case 4: std::cout << MaxMin(q) << std::endl; break;
		case 3: ConsoleOutput(q); break;
		}
	} while (choice != 5);

	delete[] q.data;
}

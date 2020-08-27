#include <fstream>
#include <iostream>
#include "Header.h"
int main()
{
	Stack* first = NULL;
	int choice;
	std::cout
		<< "To-do list: " << std::endl
		<< "1 - enter element" << std::endl
		<< "2 - find & delete element" << std::endl
		<< "3 - console output" << std::endl
		<< "4 - clear stack" << std::endl
		<< "5 - exit" << std::endl;
	do {
		std::cout << "Select: ";
		std::cin >> choice;
		switch (choice) {
		case 1: std::cout << "Enter number: "; Entering(first); /*что-то придумать тут надо*/ break;
		case 2: FindDelete(first); break;
		case 3: ConsoleOutput(first); break;
		case 4: Clear(first); std::cout << "The stack was cleaned up" << std::endl; break;
		}
	} while (choice != 5);

	FileOutput(first);
	FileInput();
	std::cout << "The data is written in file1.txt and rewritten in file2.txt" << std::endl;
}
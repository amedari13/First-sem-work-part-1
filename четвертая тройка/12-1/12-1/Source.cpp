#include "Header.h"
#include <iostream>

int main()
{
	int choice, element;
	Tree* rc = nullptr;
	for (;;)
	{
		std::cout << "\n1 -	Add new element or a new tree\n";
		std::cout << "2 -	Delete element\n";
		std::cout << "3 -	Output\n";
		std::cout << "4 -	Cleaning up\n";
		std::cout << "5 -	My function\n";
		std::cout << "6 -	Exit\n";
		std::cout << "Your choice?\n";
		std::cin >> choice;
		std::cout << "\n";
		switch (choice)
		{
		case 1:  std::cin >> element;  makeTree(rc, element);	break;
		case 2:  std::cin >> element;  deleting(rc, element);	break;
		case 3:  output(rc, 0);	break;
		case 4:  delAll(rc); std::cout << "The tree is empty\n"; break;
		case 5:	 std::cout << Sum(rc) << "\n"; break;
		case 6:	 exit(0); break;
		default: std::cout << "You are dumb\n";
		}
	}
	return 0;
}

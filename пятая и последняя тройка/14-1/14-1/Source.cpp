

#include<ctime>
#include <iostream>
#include "Header.h"

int main()
{

	HashTable table;

	Init(table);
	std::cout << "Enter the information about subjects(press 0 to exit the input): \n";
	for (int i = 0; i < 16; i++) {
		char* name = new char[10];
		std::cin >> name;
		if (name[0] == '0') break;
		Add(table, name);
	}

	std::cout << "The table contains: " << table.size << " records" << std::endl;
	std::cout << "Your table is\n";
	PrintTable(table);
	
	char* name = new char[10];
	std::cout << "\nEnter the subject you need to find:"; std::cin >> name;
	
	unsigned int start_time = clock();
	if (Find(table, name)) std::cout << "The subject is in the table"; else std::cout << "\nThere's no such subject in the table";
	unsigned int end_time = clock();

	char* nameD = new char[10]; 
	std::cout << "\n\nEnter the subject you need to delete:"; std::cin >> nameD;
	if (Delete(table, nameD)) std::cout << "\nThe subject is deleted"; else std::cout << "\nThere's no such subject in the table";
	
	std::cout << "\nThe time of finding is " << (end_time - start_time)*0.001 << " seconds\n";

	std::cout << "\nNow your table is\n";
	PrintTable(table);
	return 0;
}


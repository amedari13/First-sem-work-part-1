

#include <iostream>
#include <ctime>
#include "Header.h"

int main()
{
	
	HashTable table; 

	Init(table);

	std::cout << "Enter the information about subjects(press 0 for year to exit the input): \n";
	Data d;
	for (int i = 0; i < 16; i++) {
		std::cout << "\nEnter the year: ";
		std::cin >> d.year;
		if (d.year == 0) break;

		std::cout << "\nEnter the name: ";
		std::cin >> d.name;

		std::cout << "\nEnter the adress: ";
		std::cin >> d.adress;

		Add(table, d);
	}

	std::cout << "\nYour table is\n";
	PrintTable(table);

	int name;
	std::cout << "\nEnter the year of subject you need to find:"; std::cin >> name;

	unsigned int start_time = clock(); 
	if (Find(table, name)) std::cout << "The subject is in the table"; else std::cout << "\nThere's no such subject in the table";
	unsigned int end_time = clock();

	int nameD;
	std::cout << "\n\nEnter the subject you need to delete:"; std::cin >> nameD;
	if (Delete(table, nameD)) std::cout << "\nThe subject is deleted"; else std::cout << "\nThere's no such subject in the table";

	std::cout << "\nThe time of finding is " << (end_time - start_time) * 0.001 << " seconds\n";

	std::cout << "\nNow your table is\n";
	PrintTable(table);
	return 0;
}


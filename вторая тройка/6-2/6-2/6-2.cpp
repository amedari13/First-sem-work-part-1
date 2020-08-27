#include <iostream> 
#include <cstring>
//В соответствии со своим вариантом разработать программу с использованием
//структуры в виде объединения, для работы с данными из таблицы, приведенной ниже.
//Реализовать функции ввода с клавиатуры, вывода на экран и поиска.

//Вокзал. Номер поезда, пункт назначения, дни следования,
//время прибытия, время отправления.Выбор по пункту назначения.
struct Utypes
{//анонимное обьединение :)
	char destination[20];
	union {
		char number[10];
		char days[20];
		char timeA[10];
		char timeD[10];
	};
};

int main(void)
{
	int quantity;
	std::cout << "Enter the quantity of trains: ";
	std::cin >> quantity;

	Utypes* trains;
	trains = new Utypes[quantity];

	for (int i = 0; i < quantity; i++) {
		std::cout << "Enter the number of the train: ";
		std::cin >> trains[i].number;
		std::cout << "Enter the destination: ";
		std::cin >> trains[i].destination;
		std::cout << "Enter the days of arrival: ";
		std::cin >> trains[i].days;
		std::cout << "Enter the time of arrival: ";
		std::cin >> trains[i].timeA;
		std::cout << "Enter the time of departure: ";
		std::cin >> trains[i].timeD;
		std::cout << std::endl;
	}
	
	char trainFinding[100];
	std::cout << std::endl << "Enter the destination of needed train: "; std::cin >> trainFinding;
	bool isFound = false;
	for (int i = 0; i < quantity; i++) {
		if (strcmp(trains[i].destination, trainFinding) == 0) {
			std::cout << std::endl << "Train if found: " << trains[i].destination;
			isFound = true;
			break;
		}
	}
	if (isFound == false) {
		std::cout << std::endl <<"There's no such train.";
	}

	std::cout << std::endl << "Time of departure of all trains: ";
	for (int i = 0; i < quantity; i++) {
		std::cout << "\n\t" << "The " << i + 1 << "'st train: " << trains[i].timeD;
	}
	
	std::cout << std::endl << "The size of the union is " << sizeof(Utypes) << " bytes.";
	delete[] trains;
	return 0;
}

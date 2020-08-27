
#include "stdio.h"
#include <iostream>
#include <fstream>
//Список клиентов гостиницы.Паспортные данные, даты приезда и отъезда, номер,
//тип размещения(люкс, одноместный, двухместный, трехместный, апартаменты).Поиск гостя по фамилии.


//	ввод элементов структуры с клавиатуры;  есть
//	вывод элементов структуры в консольное окно;  есть
//	удаление заданной структурированной переменной; есть  
//	поиск информации; есть
//	запись информации в файл; есть
//	чтение данных из файла.
int main()
{
	struct client {
		char fullName[100];
		char passport[20];
		char phoneNumber[20];
		char arrivalDate[20];
		char departureDate[20];
		char house[5];
	};
	int number;
	
	//ввод основной информации
	std::cout << "Enter the number of clients: "; std::cin >> number;
	client* array;
	array = new client [number];
	for (int j = 0; j < number; j++)
	{
		std::cout << std::endl << "Enter fullname of the " << j + 1 << "'s client" << std::endl;
		std::cin >> array[j].fullName;
		std::cout << std::endl << "Passport info: ";
		std::cin >> array[j].passport;
		std::cout << std::endl << "Phone number: ";
		std::cin >> array[j].phoneNumber;
		std::cout << std::endl << "Date of arrival: ";
		std::cin >> array[j].arrivalDate;
		std::cout << std::endl << "Date of departure: ";
		std::cin >> array[j].departureDate;
		std::cout << std::endl << "Type of appartment: ";
		std::cin >> array[j].house; std::cout << std::endl;
	}

	//удаление заданной структурированной переменной 
	int deleteNumber;
	std::cout << "Enter the number of structure to delete : ";
	std::cin >> deleteNumber;
	for (int ind = deleteNumber - 1; ind < number; ind++) {
		array[ind] = array[ind + 1];
	}
	number--;


	//вывод элементов структуры в консольное окно
	std::cout << "List of clients phone numbers: ";
	for (int i = 0; i < number; i++) {
		std::cout << array[i].phoneNumber << std::endl;
	}




	//поиск информации(Поиск гостя по фамилии)
	char person[100];
	std::cout << "Enter full name of needed person: "; std::cin >> person;
	bool isFound = false;
	for (int i = 0; i < number; i++) {
		if (strcmp(array[i].fullName, person) == 0) {
			std::cout << "Person if found: " << array[i].fullName;
			isFound = true;
		}	
	}
	if (isFound == false) {
		std::cout << "There's no such person.";
	}


	//запись информации в файл
	std::ofstream out("Info.txt");

	int clientInd;
	std::cout << std::endl << "Enter the client, which information you want to be written: ";  std::cin >> clientInd;

	out << std::endl << "Full name: " << array[clientInd - 1].fullName;
	out << std::endl << "Passport info: " << array[clientInd - 1].passport;
	out << std::endl << "Phone number: " << array[clientInd - 1].phoneNumber;
	out << std::endl << "Date of arrival: " << array[clientInd - 1].arrivalDate;
	out << std::endl << "Date of departure: "<< array[clientInd - 1].departureDate;
	out.close();


	//Чтение из файла
	std::ifstream is("Info.txt");
	std::cout << "All strings started with letter P " << std::endl;
	char c;
	while (is.get(c)) {
		//считали первый символ строки
		if (c == 'P') {
			// копируем строку
			std::cout << c;
			while (is.get(c)) {
				std::cout << c;
				if (c == '\n')
					break;
			}
			// строка скопирована
		}
		else {
			// пропускаем строку
			while (is.get(c)) {
				if (c == '\n')
					break;
			}
		}
	}


	
	delete[] array;
}



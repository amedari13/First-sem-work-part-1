#include <cstring>
#include <iostream>
//Горожанин.Ф.И.О., дата рождения, адрес, пол(м, ж).
//Выборка по году рождения.Дату рождения организовать
//с помощью битового поля, пол  с помощью перечисления.

//В соответствии со своим вариантом разработать программу
//с использованием перечислений и битовых полей для работы с данными из таблицы, приведенной ниже.
//Реализовать функции ввода с клавиатуры, вывода на экран, удаления, поиска элементов.
//Интерфейс пользователя осуществить в виде меню.

// пол
enum Esex {
	male = 0, female
};

//дата рождения
struct Birthday {
	//	1 бит — 2. 2 бита — 4, 3 бита — 8. 	4 бита — 16 (месяцы)	5 бит — 32 (дни)
	unsigned dd : 5;
	unsigned mm : 4;
	unsigned yy : 12; // 11 - год до 2048
};

//структура горожанина
struct Citizen {
	char name[20];
	Birthday birthday;
	char adress[50];
	Esex sex;
};

int quantity = 0;
Citizen* citizen = 0;

void Info() {
	//работа

	std::cout << "Enter quantity of people: "; std::cin >> quantity;

	// удаляем массив, если он уже был ранее выделен
	delete[] citizen;
	citizen = new Citizen[quantity];

	int d, m, y, s;
	for (int i = 0; i < quantity; i++) {
		std::cout << std::endl << "Enter fullname of the " << i + 1 << "'s cityzen: ";
		std::cin >> citizen[i].name;
		std::cout << std::endl << "Birthday date: ";
		std::cin >> d >> m >> y;
		///работа с битовым полем
		citizen[i].birthday.dd = d;
		citizen[i].birthday.mm = m;
		citizen[i].birthday.yy = y;
		///
		std::cout << std::endl << "Adress: ";
		std::cin >> citizen[i].adress;
		std::cout << std::endl << "Sex(0 - male; 1 - female): ";
		std::cin >> s;
		citizen[i].sex = (Esex)s;
	}
}


void Finding() {
	//поиск человека по имени
	char person[100];
	std::cout << std::endl << "Enter full name of needed cityzen: "; std::cin >> person;
	bool isFound = false;
	for (int i = 0; i < quantity; i++) {
		if (strcmp(citizen[i].name, person) == 0) {
			std::cout << "Person if found: " << citizen[i].name;
			isFound = true;
			break;
		}
	}
	if (isFound == false) {
		std::cout << "There's no such person.";
	}
}

void Sorting() {
	//сортировка по возрастанию возраста
	std::cout << std::endl << "Age ascending: " << std::endl;

	for (int i = 0; i < quantity; i++) {
		for (int j = i + 1; j < quantity; j++) {
			if (citizen[i].birthday.yy < citizen[j].birthday.yy) {
				Citizen t = citizen[i];
				citizen[i] = citizen[j];
				citizen[j] = t;
			}
		}
	}

	if (citizen[0].sex == (Esex)1) {
		std::cout << std::endl << "The youngest cityzen of this town is female named " << citizen[0].name;
	}
	else if (citizen[0].sex == (Esex)0) {
		std::cout << std::endl << "The youngest cityzen of this town is male named " << citizen[0].name;
	}
	std::cout << std::endl << "Time before the cityzen will die: " << (31 - (int)citizen[0].birthday.dd) << " days "
		<< (12 - (int)citizen[0].birthday.mm) << " month " << (2047 - (int)citizen[0].birthday.yy) << " years";
}


void DelitingNumber() {
	//удаление заданной структурированной переменной 
	int deleteNumber;
	std::cout << std::endl << "Enter the number of structure to delete : ";
	std::cin >> deleteNumber;
	for (int i = deleteNumber - 1; i < quantity - 1; i++) {
		citizen[i] = citizen[i + 1];
	}
	quantity--;
}

int main()
{
	/// меню
	std::cout << "To-do list: " << std::endl << "1 - enter information " << std::endl << "2 - find a citizen" << std::endl
		<< "3 - sorting by age" << std::endl << "4 - deleting structure number" << std::endl << "5 - exit" << std::endl;
	int choice;
	do {
		std::cin >> choice;
		switch (choice) {
		case 1: Info(); break;
		case 2: Finding(); break;
		case 3: Sorting(); break;
		case 4: DelitingNumber(); break;
		}
		std::cout << std::endl << "What should we do next?" << std::endl;

	} while (choice != 5);
	
	delete[] citizen;
}

// программный модуль с главной функцией

#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;


int main()
{
	Address* head = NULL;
	Address* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	int choose;
	do {
		cout << "Выбор: " << endl;
		cout << "1 - ввод имени" << endl;
		cout << "2 - удаление имени" << endl;
		cout << "3 - вывод на экран" << endl;
		cout << "4 - поиск" << endl;
		cout << "5 - запись в файл" << endl;
		cout << "6 - считывание из файла" << endl;
		cout << "7 - моя функция по удалению k элементов" << endl;
		cout << "8 - выход" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1: {
			insert(setElement(), &head, &last);
			break;
		}
		case 2: {
			char dname[NAME_SIZE];
			cout << "введите имя: ";
			cin.getline(dname, NAME_SIZE - 1, '\n');
			cin.getline(dname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			delet(dname, &head, &last);
			break;
		}
		case 3: {
			outputList(&head, &last);
			break;
		}
		case 4: {
			char fname[NAME_SIZE];
			cout << "введите имя: ";
			cin.getline(fname, NAME_SIZE - 1, '\n');
			cin.getline(fname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			find(fname, &head);
			break;
		}
		case 5: {
			writeToFile(&head);
			break;
		}
		case 6: {
			readFromFile(&head, &last);
			break;
		}
		case 8: {
			break;
		}
		case 7: {
			int k;
			cout << "введите количество элементов которые вы хотите удалить: ";
			cin >> k;
			deleteKFirst(k, &head, &last);
		}
			  //default:
			  //	cout << "введите корректное число" << endl;
			  //	break;
		}
	} while (choose != 8);
}

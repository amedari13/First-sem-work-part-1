#include <iostream>
#include <fstream>
#include <string>
//4.  В соответствии со своим вариантом разработать программу с использованием
//односвязного списка по данным, представленным в таблице ниже.
//Программа должна содержать меню с пунктами : добавление элемента,
//удаление элемента, поиск элемента, вывод списка в консольное окно, запись списка в файл, считывание списка из файла.

//Создать список, содержащий элементы вещественного типа. Найти среднее значение положительных элементов.

struct list
{
	float number; //значение
	list* next;//указатель на следующую позицию
};

void Adding(list*&p, float value) {//функция добавления элемента, передается адрес списка и символ, который добавляется 

	list* newP = new list;
	if (newP != NULL){     //есть ли место? 
		newP->number = value;
		newP->next = p;
		p = newP;
	}else
		std::cout << "Faluire of adding " << std::endl;
}

float Deleting(list*&p, float value) {//функция удаления, передается адрес списка и символ, который удаляется 
	list* previous, * current, * temp;
	if (value == p->number)
	{
		temp = p;
		p = p->next;    // отсоединить узел 
		delete temp;      //освободить отсоединенный узел 
		return value;
	}
	else
	{
		previous = p;
		current = p->next;
		while (current != NULL && current->number != value)
		{
			previous = current;
			current = current->next; // перейти к следующему 
		}
		if (current != NULL)
		{
			temp = current;
			previous->next = current->next;
			delete(temp);
			return value;
		}
	}
	return 0;

}

list* Finding(list* item, double value) {// ох уж та рекурсия
	// проверяем, соответствует ли текущий элемент
	if (item->number == value)
		return item;
	// если нет, ищем в оставшейся части списка
	// проверяем последний ли это элемент
	if (!item->next) return 0;
	// рекурсивно вызываем эту же функцию для дочернего элемента
	return Finding(item->next, value);
}

void ConsoleOutput(list*p) {//функиця вывода
	if (p == NULL)
		std::cout << "The list is empty" << std::endl;
	else
	{
		std::cout << "The list: " << std::endl;
		while (p != NULL)
		{
			std::cout << "-->" << p->number;
			p = p->next;
		}
		std::cout << "-->NULL" << std::endl;
	}
} 

void Summary(list* p)
{
	double sum = 0; int counter = 0;
	for(; p != NULL; p = p->next) { // переход к следующему узлу
		if ((p->number) > 0) {
			sum += (p->number);
			counter++;
		}
	}
	std::cout << "Average value of positive elements: " << sum / counter << std::endl;
}

void FileOutput(list*p) {
	std::ofstream out("file1.txt");
	if (p == NULL)
		out << "The list is empty" << std::endl;
	else
	{
		out << "The list: ";
		while (p != NULL)
		{
			out << "-->" << p->number;
			p = p->next;
		}
		out << "-->NULL" << std::endl;
	}
	out.close();
}

void FileReading() {
	char buff[100];
	std::ifstream in("file1.txt");
	std::ofstream out("file2.txt");
	in.getline(buff, 100);
	out << buff;
	in.close(); out.close();
}

int main()
{
	list* first = NULL;
	float value; 
	int choice;
	std::cout
		<< "To-do list: " << std::endl
		<< "1 - enter element" << std::endl
		<< "2 - delete element" << std::endl
		<< "3 - find element" << std::endl
		<< "4 - console output" << std::endl
		<< "5 - file output" << std::endl
		<< "6 - file reading" << std::endl
		<< "7 - exit" << std::endl;
	do {
		std::cout << "Select: ";
		std::cin >> choice;
		switch (choice) {
		case 1: std::cout << "Enter number: "; std::cin >> value; Adding(first, value); break;
		case 2: std::cout << "Enter deliting number ";
			std::cin >> value;
			if (Deleting(first, value))
			{
				std::cout << "The element " << value << " was deleted " << std::endl;
			}
			else
				std::cout << "The element does not exist" << std::endl; break;
		case 3: std::cout << "Enter needed number: "; std::cin >> value; 
			if (Finding(first, value))
			{
				std::cout << "The element " << value << " was detected " << std::endl;
			}
			else
				std::cout << "The element does not exist" << std::endl; break;
		case 4: ConsoleOutput(first); Summary(first); break;
		case 5: FileOutput(first); break;
		case 6: FileReading(); break;	
		}
	} while (choice != 7);
}
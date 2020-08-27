
//Создать проект, демонстрирующий работу со стеком, организованным
//на основе списка, в соответствии со своим вариантом из таблицы ниже.
//Все операции со стеком реализовать через функции.
//Дополнить проект функциями очистки стека clear(), сохранения в файл и считывания из файла.

//Разработать функцию, которая удаляет из стека первый отрицательный элемент, если такой есть
#include <fstream>
#include <iostream>


struct Stack
{
	int data;
	Stack* next;
};

bool IsEmpty(Stack* size) { return size == 0; }

int Pop(Stack*& stack) // Извлечение элемента
{
	int tmp = stack->data;
	Stack *pv = stack;
	stack = stack->next;       // вершиной становится предшествующий элемент
	delete pv;           // освобождается память 
	return tmp;
}

void Push(Stack*& stack, int d) // Добавление элемента
{
	Stack* pv = new Stack;
	pv->data = d;   // значение помещается в стек     
	pv->next = stack;
	stack = pv;
}

void Entering(Stack*&stack) {
	int number;
	std::cin >> number;
	Push(stack, number);
}

void FindDelete(Stack*& stack) {
	Stack* temp = 0;
	int element;
	bool alreadyFound = false;
	for (; !IsEmpty(stack);) {
		int d = Pop(stack);
		if (!alreadyFound && d < 0) {
			element = d;
			alreadyFound = true;
		}
		else
			Push(temp, d);
	}
	for (; !IsEmpty(temp);) {
		Push(stack, Pop(temp));
	}
	if (!alreadyFound)
		std::cout << "The element doesn't exist" << std::endl;
	else
		std::cout << "The deleted element is " << element << std::endl;
}

void ConsoleOutput(Stack*stack) {
	if (stack == NULL)
		std::cout << "The stack is empty" << std::endl;
	else
	{
		std::cout << "The stack: " << std::endl;
		while (stack != NULL)
		{
			std::cout << "-->" << stack->data;
			stack = stack->next;
		}
	}
	std::cout << "-->NULL" << std::endl;
}

void FileOutput(Stack*stack) {
	std::ofstream out("file1.txt");
	if (stack == NULL)
		out << "The stack is empty" << std::endl;
	else
	{
		out << "The stack: ";
		while (stack != NULL)
		{
			out << "-->" << stack->data;
			stack = stack->next;
		}
		out << "-->NULL" << std::endl;
	}
	out.close();
}

void FileInput() {
	char buff[100];
	std::ifstream in("file1.txt");
	std::ofstream out("file2.txt");
	in.getline(buff, 100);
	out << buff;
	out << std::endl << "The rewritten version :)";
	in.close(); out.close();
}

void Clear(Stack*& stack) {
	while (!IsEmpty(stack)) Pop(stack);
}


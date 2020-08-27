//
//


//Создать проект из нескольких файлов, демонстрирующий работу с очередью. В соответствии со своим вариантом выполнить задание из таблицы, представленной ниже. 
//Разработать меню и реализовать все операции с очередью через функции. Максимальный размер очереди ввести с клавиатуры.

//Создать очередь для целых чисел и функции для ввода, вывода и удаления элементов очереди. 
//Найти количество элементов между максимальным и минимальным элементами очереди. 

//"первым введен, первым выведен"

#include <iostream>

struct Queue{
  int* data;
  int max_size;
  int size;
};

void Create(Queue& q, int max_size) {
	q.size = 0;
	q.max_size = max_size;
	q.data = new int[q.max_size];
}

void Adding(Queue& q, int value) {//функция добавления элемента 
	if (q.size < q.max_size) {
		q.data[q.size] = value;
		q.size++;
	}
	else
		std::cout << "The queue is full" << std::endl;
}

int Getting(Queue& q) {//функция удаления 
	int deleted = q.data[0];
	q.size--;//удаляем ненужную память
	for (int i = 0; i < q.size; i++) {
		q.data[i] = q.data[i + 1];
	}
	return deleted;
}

void ConsoleOutput(Queue& q) {//функиця вывода на экран
	std::cout << "The queue is ";
	for (int i = 0; i < q.size; i++) {
		std::cout << q.data[i] << " ";
	}
	std::cout << std::endl;
}

int MaxMin(Queue& q) {
	int max = -999, min = 999, maxI, minI;
	for (int i = 0; i < q.size; i++) {
		if (q.data[i] > max) { max = q.data[i]; maxI = i; }
		if (q.data[i] < min) { min = q.data[i]; minI = i; }
	}
	return abs(maxI - minI);
}
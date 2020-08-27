//В соответствии со своим вариантом разработать проект для условия из таблицы, 
//представленной ниже. Построить хеш-таблицы с цепочками разного размера с коллизиями. 
//Для вариантов с 1 по 8 вычисление хеш - функции произвести по методу 
//универсального хеширования. 
//Исследовать время поиска информации.
//Список электронных адресов. Создать хеш-таблицу со следующими полями: адрес, фамилия абонента, год создания. Ключ – год создания.

#include <iostream>
#include "Header.h"


void Init(HashTable& table)
{
	for (int i = 0; i < 16; ++i)
		table.table[i] = 0;
}


void Add(HashTable& table, Data d)
{
	int hash = Hash(d.year);
	List* list = table.table[hash % 16];
	List* prev = 0;
	while (list) {
		prev = list;
		list = list->next;
	}
	if (prev == 0) {
		table.table[hash % 16] = new List;
		table.table[hash % 16]->data = d;
		table.table[hash % 16]->next = 0;
	}
	else {
		prev->next = new List;
		prev->next->data = d;
		prev->next->next = 0;
	}
}

bool Find(HashTable& table, int number)
{
	int hash = Hash(number);
	List* list = table.table[hash % 16];

	while(list) {
		if (list->data.year == number) {
			std::cout << list->data.year << std::endl;
			std::cout << list->data.name << std::endl;
			std::cout << list->data.adress << std::endl;
			return true;
		}
		list = list->next;
	}
	return false;
}

unsigned Hash(int year) { 
	int a = 31415, b = 27183, p = 15; // p - размер таблицы - 1
	return (a * year + b) % p; 
}

void PrintTable(HashTable& table)
{
	
	for (int index = 0; index < 16; ++index){
		List* list = table.table[index];
		while (list) {
			std::cout << list->data.year << std::endl;
			std::cout << list->data.name << std::endl;
			std::cout << list->data.adress << std::endl;
			list = list->next;
		}
	}
}

bool Delete(HashTable& table, int number) {
	int hash = Hash(number);
	List* list = table.table[hash % 16];
	List* prev = 0;
	while (list) {
		if (list->data.year == number) {
			list->data.year = 0;
			if (prev == 0) table.table[hash % 16] = 0;
			else prev->next = list->next;
			return true;
		}
		prev = list;
		list = list->next;
		
	}
	return false;
}

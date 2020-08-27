#include "Header.h"
//3. Разработать программу работы с бинарным деревом,
//в которую включить основные функции манипуляции данными 
//и функцию в соответствии со своим вариантом из таблицы, представленной ниже

//Дан указатель p1 на корень бинарного дерева. Написать функцию 
//вывода количества листьев дерева, которые являются правыми дочерними вершинами.

#include <iostream>


void makeTree(Tree*& Root, int value) {    //Создание дерева и добавление элемента
	if (Root == nullptr) {
		Root = new Tree;
		Root->Left = 0; Root->Right = 0;
		Root->key = value;
		return;
	}
	if (value > Root->key) {
		makeTree(Root->Right, value);
	}if (value < Root->key) {
		makeTree(Root->Left, value);
	}
	else return;
}

Tree* deleting(Tree*& Root, int element) {    //удаление элемента и поиск по дереву
	// Del, Prev_Del - удаляемый элемент и его предыдущий ;
	// R, Prev_R - элемент, на который заменяется удаленный, и его родитель; 
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != element)//поиск элемента и его родителя 
	{
		Prev_Del = Del;
		if (Del->key > element)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL)              // элемент не найден
	{
		puts("\nThere's no such element");
		return Root;
	}
	if (Del->Right == NULL) // поиск элемента R для замены
		R = Del->Left;
	else if (Del->Left == NULL)
		R = Del->Right;
	else
		{
		Prev_R = Del; //поиск самого правого элемента в левом поддереве
		R = Del->Left;
		while (R->Right != NULL)
		{
			Prev_R = R;
			R = R->Right;
		}
		if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R 
			R->Right = Del->Right;
		else
		{
			R->Right = Del->Right;
			Prev_R->Right = R->Left;
			R->Left = Prev_R;
		}
	}
	if (Del == Root) Root = R;	//удаление корня и замена его на R
	else
		// поддерево R присоединяется к родителю удаляемого узла
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // на левую ветвь 
		else
			Prev_Del->Right = R;	// на правую ветвь
	int tmp = Del->key;
	std::cout << "\nThe element " << tmp << " was deleted\n" << std::endl;
	delete Del;
	return Root;

}

void output(Tree* Root, int level) //Вывод дерева
{
	if (Root)
	{
		output(Root->Right, level + 1); //вывод правого поддерева
		for (int i = 0; i < level; i++)
			std::cout << " ";

		int tm = Root->key;
		std::cout << tm << std::endl;

		output(Root->Left, level + 1); //вывод левого поддерева
	}
}

void delAll(Tree*& Root) //Очистка дерева
{
	if (Root != NULL)
	{
		delAll(Root->Left);
		delAll(Root->Right);
		delete Root;
	}
}

int Sum(Tree* Root, int level) {

	int counter = 0;
	if (level != counter) {
		Sum(Root->Right, level + 1);
		Sum(Root->Left, level + 1);
	}
	else if(level==counter)

	
}
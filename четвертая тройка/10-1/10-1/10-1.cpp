

//
////программный модуль

//deleteKFirst(int k) – функция удаления К первых элементов списка. 
#include <iostream>
#include <fstream>

#include "Header.h"
using namespace std;

//-----------------------------------------------------------
void insert(Address* e, Address** phead, Address** plast) //Добавление в конец списка
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
//-----------------------------------------------------------



Address* setElement()        // Создание элемента и ввод его значений с клавиатуры 
{
	Address* temp = new  Address();
	if (!temp)
	{
		cout << "ошибка выделения памяти";
		return NULL;
	}
	cout << "введите имя: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "введите город: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------


void outputList(Address** phead, Address** plast)      ///Вывод списка на экран
{
	Address* t = *phead;
	while (t)
	{
		cout << t->name << ' ' << t->city << endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------


void find(char name[NAME_SIZE], Address** phead)   // Поиск имени в списке
{
	Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cout << "имя не найдено" << endl;
	else
		cout << t->name << ' ' << t->city << endl;
}
//-----------------------------------------------------------


void delet(char name[NAME_SIZE], Address** phead, Address** plast) { // Удаление имени

  // выполняем поиск элемента по имени
  // t - указатель на текущий элемент
	struct Address* t = *phead;
	// выполняем цикл, пока не достигнем нулевого элемента
	while (t) {
		// сравниваем имя с заданым
		if (!strcmp(name, t->name)) {
			break;
		}
		// если имя не совпадает, то переходим к следующему элементу
		t = t->next;
	}
	// если ничего не нашли то выход
	if (!t) {
		cerr << "имя не найдено" << endl;
	}
	else
	{
		// если нашли, то выполяем процедуру удаления
		if (*phead == t) {
			// если удалять нужно первый элемент
			// то нужно одновременно откорректировать указатель phead
			// присваиваем ему указатель на следующий элемент
			*phead = t->next;
			if (*phead) {
				// если следующий элемент существует, то помечаем, что он первый
				(*phead)->prev = NULL;
			}
			else {
				// если вдруг оказалось, что следующего элемента нет
				// значит список теперь пуст, корректируем plast
				*plast = NULL;
			}
		}
		else
		{
			// если это не первый элемент
			// то корректируем указатели предыдущего элемента
			t->prev->next = t->next;
			if (t != *plast) {
				// и последующего элемента, если он не последний
				t->next->prev = t->prev;
			}
			else {
				// если всё таки последний, то изменяем plast
				*plast = t->prev;
			}
		}

		// теперь фактически удаляем сам элемент
		delete t;
		cout << "элемент удален" << endl;
	}
}
void writeToFile(Address** phead)       //Запись в файл
{
	struct Address* t = *phead;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "wb");
	if (err)
	{
		cerr << "файл не открывается" << endl;
		exit(1);
	}
	cout << "сохранение в файл" << endl;
	while (t)
	{
		fwrite(t, sizeof(struct Address), 1, fp);
		t = t->next;
	}
	fclose(fp);
}
//-----------------------------------------------------------


void readFromFile(Address** phead, Address** plast)    //Считывание из файла
{
	struct Address* t;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "rb");
	if (err)
	{
		cerr << "файл не открывается" << endl;
		exit(1);
	}
	while (*phead)
	{
		*plast = (*phead)->next;
		delete* phead;
		*phead = *plast;
	}
	*phead = *plast = NULL;
	cout << "загрузка из файла" << endl;
	while (!feof(fp))
	{
		t = new Address();
		if (!t)
		{
			cerr << "ошибка выделения памяти" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct Address), 1, fp)) break;
		insert(t, phead, plast);
	}
	fclose(fp);
}
//
//
//


//моя функция
void deleteKFirst(int k, Address** phead, Address** plast) {

	struct Address* t = *phead;
	for (int i = 0; i < k; i++, t = t->next) {
		// выполяем процедуру удаления
			// удалять нужно первый элемент
			// нужно одновременно откорректировать указатель phead
			// присваиваем ему указатель на следующий элемент
		*phead = t->next;
		if (*phead) {
			// если следующий элемент существует, то помечаем, что он первый
			(*phead)->prev = NULL;
		}
		else {
			// если вдруг оказалось, что следующего элемента нет
			// значит список теперь пуст, корректируем plast
			*plast = NULL;

		}
		
	}
}

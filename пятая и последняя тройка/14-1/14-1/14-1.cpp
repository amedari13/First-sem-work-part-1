//
//В соответствии со своим вариантом построить хеш - таблицы с открытой адресацией 
//разного размера, например, 16, 32 или 32, 64, 128 с коллизиями.В таблице h'(key) - значение хеш-функции, приведшее к коллизии.
//Исследовать время поиска в хеш - таблицах. В приложении Excel построить соответствующие графики.

//Использовать в проекте функцию универсального хеширования.


#include "Header.h"



void Init(HashTable& table)
{
	// все элементы таблицы помечаем пустыми
	for (int index = 0; index < 16; index++)
		table.data[index].empty = true;

	// в таблице не элементов
	table.size = 0;
}



void Add(HashTable& table, const char* p)
{
	// нет места
	if (table.size >= 16) return;

	// увеличиваем размер
	table.size++;

	// вычисляем хэш
	unsigned h = Hash(p);
	for (int index = 0;; index++)
	{
		// проверяем свободна ли ячейка, соответсттвующая хэшу
		if (table.data[h % 16].empty)
		{
			// если пустая используем её
			table.data[h % 16].name = p;

			// помечаем, что ячейка используется
			table.data[h % 16].empty = false;

			return;
		}

		// если нет, то переходим к следующему варианту
		// расположения ячейки
		h++;
	}
}

bool Find(HashTable& table, const char* p)
{
	// вычисляем хэш
	unsigned h = Hash(p);
	for (int index = 0; index < 16; index++)
	{
		// проверяем свободна ли ячейка с соответствующим хэшем
		if (!table.data[h % 16].empty)
		{
			// ячейка занята, но это не гарантирует, что здесь записано
			// именно искомое значение

			// сравниваем содержимое ячейки с переданным нам значением
			if (strcmp(p, table.data[h % 16].name) == 0)
			{
				// элемент совпадает, поиск завершен
				return true;
			}

			// нет, это не тот элемент, продолжаем
		}

		h++;
	}

	return false;
}

unsigned Hash(const char* p)
{
	int h = 16;
	for (; *p != 0; p++)
	{
		h = 127 * h + *p;
	}
	return h;
}


void PrintTable(HashTable& table)
{
	// чтобы перебирать содержимое таблицы
	// достаточно просматривать все ячейки
	// проверяя, свободны они или заняты
	for (int index = 0; index < 16; ++index)
	{
		if (!table.data[index].empty)
			// если ячейка занята, выводим её содержимое
			std::cout << table.data[index].name << std::endl;
	}
}

bool Delete(HashTable& table, const char *p) {
	// вычисляем хэш
	unsigned h = Hash(p);
	for (int index = 0; index < 16; index++)
	{
		// проверяем свободна ли ячейка с соответствующим хэшем
		if (!table.data[h % 16].empty)
		{
			// ячейка занята, но это не гарантирует, что здесь записано
			// именно искомое значение

			// сравниваем содержимое ячейки с переданным нам значением
			if (strcmp(p, table.data[h % 16].name) == 0)
			{
				// элемент совпадает, поиск завершен
				table.data[h % 16].empty = true;
				return true;
			}

			// нет, это не тот элемент, продолжаем
		}

		h++;
	}

	return false;
}

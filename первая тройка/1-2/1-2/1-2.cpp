#include <locale>
#include <iostream>

int mine(int**& array, int cols, int rows, int& count) {
	array = new int* [cols];
	for (int i = 0; i < cols; i++) {
		array[i] = new int[rows];
	}
	srand((unsigned)time(NULL));
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			array[i][j] = rand() % 3;
		}
	}

	for (int j = 0; j < rows; j++) {
		for (int i = 0; i < cols; i++) {
			if (array[i][j] == 0) {
				count++; break;
			}
		}
	}
	return 0;
}

int main()
{
	//Дана целочисленная прямоугольная матрица. Если есть в матрице нулевые элементы, то определить ко-личество строк, содержащих их. 
	setlocale(LC_CTYPE, "rus");
	int** array, cols, rows, count = 0;
	std::cout << "Введте размер матрицы: ";
	std::cin >> cols >> rows;
	mine(array, cols, rows, count);
	for (int j = 0; j < rows; j++) {
		for (int i = 0; i < cols; i++) {
			std::cout << array[i][j] << "\t";
		}std::cout << "\n";
	}
	std::cout << "Количество строк с нулевыми элементами: " << count;
}

#include <iostream>
#include <locale>
void mine();

//	1. В массиве из целых чисел найти в процентах частоту появления каждого из k наиболее часто встретившихся чисел(k – натуральное число, не превосходящее числа элементов массива).

int justDoTheJob(int* array, int size, int* counts, int* elements)
{
	int size2 = 0;
	for (int i = 0; i < size; i++) {
		bool found = false;
		int j = 0;
		for (j = 0; j < size2; j++) {
			if (array[i] == elements[j]) {
				found = true;
				break;
			}
		}
		if (found) {
			counts[j]++;
		}
		else {
			elements[j] = array[i];
			counts[j] = 1;
			size2++;
		}
	}
	return size2;
}

int findMax(int* counts, int size2)
{
	int index = 0;
	int max = -1;
	for (int j = 0; j < size2; j++) {
		if (counts[j] > max) {
			max = counts[j];
			index = j;
		}
	}
	return index;
}

int main() {
	setlocale(LC_CTYPE, "Rus");
	int* array, * elements, * counts, sum = 0, k, size, periodicity;
	std::cout << "Введите размер массива ";
	std::cin >> size;
	std::cout << "Введите необходимое количество элементов ";
	std::cin >> k;

	
	srand((unsigned)time(NULL));
	array = new int[size];
	std::cout << "Исходный массив: ";
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 11;
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;

	elements = new int[size];
	counts = new int[size];

	int size2 = justDoTheJob(array, size, counts, elements);

	for (int i = 0; i < k; i++) {
		int index = findMax(counts, size2);
		int count = counts[index];

		if (count < 0) break;

		periodicity = 100.0 * count / size;
		std::cout.precision(2);
		std::cout << "Элемент " << elements[index]
			<< ", частота появления равна " << periodicity
			<< "% (" << counts[index] << "/" << size << ")"
			<< std::endl;

		counts[index] = -1;
	}

	delete[] array;
	delete[] elements;
	delete[] counts;
}
void mine() {};
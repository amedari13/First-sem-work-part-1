

// Компоненты файла f –  целые двухзначные (отличные от нуля) числа,
// причем 10 положитель-ных чисел, 10 отрицательных, и т. д. 
// Получить файл g, в котором записаны сначала 5 положительных чисел, затем 5 отрицательных и т. д.


#include <stdio.h>
#include <iostream>
#include <locale>

int main()
{
	int element, array[20];
	int err, err2, err3;
	FILE* f, * g;
	srand((unsigned)time(0));


	
	err = fopen_s(&f, "f.txt", "a");
	if (err != 0)
	{
		perror("Error occured\n");
		return EXIT_FAILURE;
	}

	for (int i = 0, j = 10; i < 10, j < 20; i++, j++) {
		array[i] = rand() % 89 + 10;
		array[j] = -(rand() % 89 + 10);
	}
	for (int i = 0; i < 20; i++)
	{
		fprintf(f, "%d ", array[i]);
	}
	fclose(f); 

	err2 = fopen_s(&f, "f.txt", "r");
	err3 = fopen_s(&g, "g.txt", "a");
	if (err2 != 0 || err3 != 0)
	{
		printf("Error occured\n");
		return EXIT_FAILURE;
	}

	for (int index = 0; index < 20; ++index) {
		int k = fscanf_s(f, "%d", &array[index]);
		if (k == 0) {
			printf("Error occured");
			return EXIT_FAILURE;
		}
	}
	
	int pos = 5, neg = 5;
	for (int i = 0; i < 20; ++i) {
		if (pos) {
			if (array[i] > 0) {
				fprintf(g, "%d ", array[i]); pos--;
			}
		}
		else if (neg) {
			if (array[i] < 0) {
				fprintf(g, "%d ", array[i]); neg--;
			}
		}
	}
	
	printf("File g was made \n");
	fclose(f);
	fclose(g);

	return 0;
}

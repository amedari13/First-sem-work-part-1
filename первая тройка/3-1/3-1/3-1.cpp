

#include <stdio.h>
#include <iostream>
#include <locale>
//  Даны два файла вещественных чисел с именами fA и fB, содержащие
//  элементы прямоугольных матриц M1 и M2 по строкам, 
//  причем начальный элемент каждого файла содержит количество столбцов соответствующей матрицы.
//  Создать файл той же структуры с именем fC, содержащий сумму M1+M2. 

int main()
{
	int cols, rows, **arrayA, **arrayB;
	errno_t errA, errB, errC;
	FILE* fA,* fB,* fC;
	std::cout << "Enter matrix size: ";
	std::cin >> cols >> rows;

	arrayA = new int* [cols];
	arrayB = new int* [cols];
	for (int i = 0; i < cols; i++)
	{
		arrayA[i] = new int[rows];
		arrayB[i] = new int[rows];
	}
	srand((unsigned)time(0));
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++) {
			arrayB[i][j] = rand() % 10;
			arrayA[i][j] = rand() % 10;
		}
	}
	
	errA = fopen_s(&fA, "matrixA.txt", "w");
	errB = fopen_s(&fB, "matrixB.txt", "w");
	errC = fopen_s(&fC, "matrixC.txt", "w");
	if (errA != 0 || errB != 0 || errC!=0) 
	{
		perror("Невозможно создать файл\n");
		return EXIT_FAILURE;
	}
	

	arrayA[0][0] = cols;
	arrayB[0][0] = cols;
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++) {
			fprintf(fB, "%d; ", arrayB[i][j]);
			fprintf(fA, "%d; ", arrayA[i][j]);
			fprintf(fC, "%d; ", arrayA[i][j]+arrayB[i][j]);
		}fprintf(fA, "\n"); fprintf(fB, "\n"); fprintf(fC, "\n");
	}
	


	printf("Matrix C has been filled \n");
	for (int i = 0; i < rows; i++) {
		delete arrayA[i];
		delete arrayB[i];
	}
	delete []arrayA;
	delete []arrayB;
	fclose(fA);
	fclose(fB);
	return 0;
}


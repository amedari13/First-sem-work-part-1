//
//
//В соответствии со своим вариантом написать программу для сортировок массивов 
//указанными в таблице методами. Исходные массивы заполняются случайными числами.

//Ввести массив А, в массив В перенести все элементы массива А, имеющие четный индекс, 
//справа от которых расположены элементы с нечетным значением.  i%2==0&&arr[i]%2!=0
//Массив В отсортировать по убыванию, 
//используя алгоритмы сортировок : сортировка слиянием, сортировка Хоара.

#include <iostream>
#include<locale>

int* Fusion(int* arrayA, int size) {
	int ind = 0;
	int* arrayB = new int[ind];
	for (int i = 0; i < size; i++) {
		if (i % 2 == 0 && arrayA[i+1] % 2 != 0) {
			arrayB[ind] = arrayA[i];
			ind++;
		}
	}
	return arrayB;
}

void merge(int arr[], int start, int mid, int end)
{
	int start2 = mid + 1;

	// Если массив уже отсортирован
	if (arr[mid] <= arr[start2]) {
		return;
	}

	// Два указателя для поддержания старта
		// обоих массивов для слияния
	while (start <= mid && start2 <= end) {

		// если первый элемент на нужном месте 
		if (arr[start] <= arr[start2]) {
			start++;
		}
		else {
			int value = arr[start2];
			int index = start2;
			//Перемещаем все элементы между элементами 1
				// и элементом 2, справа на 1.
			while (index != start) {
				arr[index] = arr[index - 1];
				index--;
			}
			arr[start] = value;

			// передвигаем на 1 указатели
			start++;
			mid++;
			start2++;
		}
	}
}

void mergeSort(int arr[], int l, int r)
{// l - левый индекс and r - правый индекс
  // подмассива для сортировки 
	if (l < r) {
		//То же, что(l + r) / 2, но избегает переполнения
		// для больших l и r 
		int m = l + (r - l) / 2;

		// сортировка первой и второй части
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}






int Border(int* array, int first, int last) {  //Разбиение Ломуто
	int border = array[last - 1];
	int tmp = first;
	for (int j = first; j <= last - 2; j++) {
		if (array[j] <= border) {
			std::swap(array[tmp], array[j]);
			tmp++;
		}
	}
	std::swap(array[tmp], array[last - 1]);
	return tmp;
}

int* Hoar(int* array, int first, int last)
{
	//возвращает массив
	if (first < last) {
		int tmp = Border(array, first, last); //воображаемая граница
		Hoar(array, first, tmp); //идем указателями слева и справа массива до границы
		Hoar(array, tmp + 1, last);
	}
	return array;
}

int main()
{
	const int size = 10000;
	int A[size];
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++) {
		A[i] = rand() % 100;
	}
	///
	std::cout << "\nThe first array - A:\n";

	for (int i = 0; i < size; i++) {
		std::cout << A[i] << "\t";
	}std::cout << std::endl;
	unsigned int start_time = clock();
	Hoar(A, 0, size);
	unsigned int end_time = clock();

	
	for (int i = 0; i < size; i++) {
		std::cout << A[i] << "\t";
	}
	std::cout << "\nTime of work:" << (end_time - start_time) * 0.001;
	

	
	
	
	
	
	
	
	
	
	///
	/*std::cout << "\nThe second array - B:\n";
	int* B = Fusion(A, size);
	for (int i = 0; i < sizeof(B)/sizeof(int); i++) {
		std::cout << B[i] << "\t";
	}std::cout << std::endl;
	mergeSort(B, 0, size-1);
	for (int i = 0; i < size; i++) {
		std::cout << B[i] << "\t";
	}
	*/////
}
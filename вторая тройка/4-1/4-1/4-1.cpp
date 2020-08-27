#include <iostream>
#include<fstream>


//1. Скопировать в файл FILE2 только те
//строки из FILE1, которые начинаются с буквы «А».
//Подсчитать количество слов в FILE2.
int main() {
	std::ifstream is("file1.txt");//откуда
	std::ofstream out("file2.txt");//куда
	int quantity = 0;
	char c;

	while (is.get(c)) {
		//считали первый символ строки
		if (c == 'a' || c == 'A') {
			// копируем строку
			out << c;
			while (is.get(c)) {
				out << c;
				if (c == '\n')
					//quantity++;
					break;
			}
			// строка скопирована
		}
		else {
			// пропускаем строку
			while (is.get(c)) {
				if (c == '\n')
					break;
			}
		}
	}
	is.close();
	out.close();
	//std::cout << "Quantity of words in the second file: " << quantity;
	return 0;
}
#include <iostream>
#include <fstream>

//2. Ввести с клавиатуры строку символов, 
//состоящую из групп цифр и нулей, и записать ее в файл.
//Прочитать из файла данные и вывести самую короткую группу.

//Во второй программе ввод информации с клавиатуры и вывод
//в консольное окно осуществить в главной функции,
//а запись в файл и чтение из файла в функциях пользователя.
//Встроенные функции для работы со строками не использовать.


int fileWork( char* str, char*str2) {
	std::ofstream out("file1.txt");
	if (out.fail())
	{
		std::cout << "\n Ошибка открытия файла";
		exit(1);
	}
	out << str;
	out.close();
	std::ifstream in("file1.txt");
	if (out.fail())
	{
		std::cout << "\n Ошибка открытия файла";
		exit(1);
	}
	in >> str2;
	in.close();

}

int main()
{
	setlocale(LC_CTYPE, "RUSSIAN");
	const int num = 100;
	char str[num], str2[num];
	int sum = 1, min = 9999, minIndex = -1, len = 0;
	gets_s(str);

	fileWork(str, str2);

	if (str2[0]) // цикл запускаем только тогда, если строка не пустая
		for (int index = 0; str2[index] != 0; ++index) {
			if (str2[index] == str2[index + 1]) {
				++sum;
			}
			else if (sum < min) {
				// если сразу же попадаем сюда, значит есть хотя бы 1 символ
				min = sum;
				minIndex = index - min + 1;
				sum = 1;
			}
		}
	if (minIndex == -1) {
		std::cout << "Строка пустая :(" << std::endl;
	}
	else {
		std::cout << "Минимальная длина строк, содержащих " << str2[minIndex]
			<<", и которая начинается в позиции " << minIndex
			<< " составляет " << min
			<< std::endl;
	}
}
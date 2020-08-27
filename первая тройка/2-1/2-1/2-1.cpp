#include <iostream>

//В соответствии со своим вариантом отделить корни двух уравнений и вычислить их методом дихотомии для исходных данных из таблицы, приведенной ниже.
//Точность вычислений принять равной e = 0,001 для всех вариантов.
//Операторы метода вычисления корня оформить в виде функции пользователя, уравнения записать также в виде функций пользователя.
//В главной функции предусмотреть ввод исходных данных, обращения к функции, реализующей метод дихотомии для двух уравнений.
//В процессе выполнения программы определить корни двух уравнений.Использовать указатель на функцию
//
//
// x3 + x – 3,
//cos3(x)

double Func;

double myFunc(double x) {
	return (pow(x, 3) + x - 3);
}
double myFunc2(double x) {
	return (pow(cos(x), 3));
}

double Task(double (*Func)(double), double a, double b) {
	double e = 0.001, x = 0, x1 = 0;
	
	while ((abs(a - b) / 2 > 2 * e)){
		x = (a + b) / 2;
		if (Func(x)*Func(a)<=0) {
			b = x;
		}
		else {
			a = x;
		}
	}
	return x;
}

int main()
{
	double a, b;
	std::cout << "Parametrs: " << std::endl;
	std::cin >> a >> b;
	std::cout << "The first function: "<< Task(myFunc, a, b) << std::endl << "The second function: " << Task(myFunc2, a, b);
	return 0;
}

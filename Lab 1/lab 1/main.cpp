#include "stdafx.h"
#include "Auxil.h"                            // вспомогательные функции 
#include <iostream>
#include <ctime>
#include <locale>

#define  CYCLE  1000000                       
int fibonacci(int i)
{
	int value = 0;
	if (i < 1) {
		return 0;
	}
	if (i == 1) {
		return 1;
	}
	return fibonacci(i - 1) + fibonacci(i - 2);
}
int _tmain(int argc, _TCHAR* argv[])
{

	double  av1 = 0, av2 = 0;
	clock_t  startTime = 0, endTime = 0;

	setlocale(LC_ALL, "rus");

	auxil::start();                          // старт генерации 
	startTime = clock();                            // фиксация времени 
	for (int i = 0; i < CYCLE; i++)
	{
		av1 += (double)auxil::iget(-100, 100); // сумма случайных чисел 
		av2 += auxil::dget(-100, 100);         // сумма случайных чисел 
	}
	endTime = clock();                            // фиксация времени 


	std::cout << std::endl << "количество циклов:         " << CYCLE;
	std::cout << std::endl << "среднее значение (int):    " << av1 / CYCLE;
	std::cout << std::endl << "среднее значение (double): " << av2 / CYCLE;
	std::cout << std::endl << "продолжительность (у.е):   " << (endTime - startTime);
	std::cout << std::endl << "                  (сек):   "
		<< ((double)(endTime - startTime)) / ((double)CLOCKS_PER_SEC);
	std::cout << std::endl;
	for (int n = 1; n <= 50; n++)
	{
		startTime = clock();
		int num = fibonacci(n);
		endTime = clock();
		std::cout << std:: endl << n << "-е число Фибоначчи: " << num << ". Время на нахождение числа: " /*<< ((double)(endTime - startTime)) / ((double)CLOCKS_PER_SEC);*/ << (endTime - startTime);
	}
    std:: cout << std::endl;
	system("pause");

	return 0;
}


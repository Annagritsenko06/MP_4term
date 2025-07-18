#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Combi.h"
#include <tchar.h>
#include "Knapsack.h"
#define NN 18  // Количество предметов

int _tmain(int argc, _TCHAR* argv[]) {
    setlocale(LC_ALL, "rus");
    srand(static_cast<unsigned int>(time(0)));  // Инициализация генератора случайных чисел

    int V = 300;  // Вместимость рюкзака

    int v[NN];  // Массив весов предметов
    int c[NN];  // Массив стоимостей предметов

    // Генерация случайных весов и стоимостей
    for (int i = 0; i < NN; i++) {
        v[i] = rand() % (291) + 10;  // Вес от 10 до 300 кг
        c[i] = rand() % (51) + 5;    // Стоимость от 5 до 55 у.е.
    }

    short m[NN] = { 0 };  // Количество предметов каждого типа, инициализируем нулями

    int maxcc = knapsack_s(
        V,   // [in]  вместимость рюкзака 
        NN,  // [in]  количество типов предметов 
        v,   // [in]  размер предмета каждого типа  
        c,   // [in]  стоимость предмета каждого типа     
        m    // [out] количество предметов каждого типа  
    );

    std::cout << std::endl << "-------- Задача о рюкзаке --------- ";
    std::cout << std::endl << "- количество предметов : " << NN;
    std::cout << std::endl << "- вместимость рюкзака  : " << V;
    std::cout << std::endl << "- размеры предметов    : ";
    for (int i = 0; i < NN; i++) std::cout << v[i] << " ";
    std::cout << std::endl << "- стоимости предметов  : ";
    for (int i = 0; i < NN; i++) std::cout << c[i] << " ";
    std::cout << std::endl << "- оптимальная стоимость рюкзака: " << maxcc;
    std::cout << std::endl << "- вес рюкзака: ";
    int s = 0;
    for (int i = 0; i < NN; i++) s += m[i] * v[i];
    std::cout << s;
    std::cout << std::endl << "- выбраны предметы: ";
    for (int i = 0; i < NN; i++) std::cout << " " << m[i];
    std::cout << std::endl << std::endl;

    system("pause");
    return 0;
}
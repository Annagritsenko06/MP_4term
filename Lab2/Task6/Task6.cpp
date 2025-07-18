#include <iostream>
#include "..//Boat(Task5)/Combi.h"
#include "..//Boat(Task5)/Combi.cpp"
#include "..//Boat(Task5)/Knapsack.h"
#include <time.h>
#include <iomanip> 
#include <tchar.h>
#define NN (sizeof(c)/sizeof(int))
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "rus");
    int V = 600,              // вместимость рюкзака              
        v[] = { 25, 56, 67, 40, 20, 27, 37, 33, 33, 44, 53, 12,
               60, 75, 12, 55, 54, 42, 43 ,44},
        c[] = { 15, 26, 27, 43, 16, 26, 42, 22, 34, 12, 33, 30,
               12, 45, 60, 41, 33, 11, 14, 16 };
    short m[NN];
    int maxcc = 0;
    clock_t t1, t2;
    std::cout << std::endl << "-------- Задача о рюкзаке --------- ";
    std::cout << std::endl << "- вместимость рюкзака  : " << V;
    std::cout << std::endl << "-- количество ------ продолжительность -- ";
    std::cout << std::endl << "    предметов          вычисления  ";
    for (int i = 14; i <= NN; i++)
    {
        t1 = clock();
        maxcc = knapsack_s(V, i, v, c, m);
        t2 = clock();
        std::cout << std::endl << "       " << std::setw(2) << i
            << "               " << std::setw(5) << (t2 - t1);
    }
    std::cout << std::endl << std::endl;

    std::cout << "Продолжительность вычислений " << t2-t1 << " y.e" << std::endl;
    system("pause");
    return 0;
}

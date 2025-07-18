// --- main  
//    расстановка скобок  
#include <cmath>
#include <memory.h>
#include <iostream>
#include "MultiMatrix.h"   // умножение матриц 

#define N 6
int main()
{

	int Mc[N + 1] = { 9,12,20,23,30,40,51 }, Ms[N][N], r = 0, rd = 0;

	memset(Ms, 0, sizeof(int) * N * N);
	r = OptimalM(1, N, N, Mc, OPTIMALM_PARM(Ms));
	setlocale(LC_ALL, "ru_RU.UTF-8");
	std::cout << std::endl;
	std::cout << std::endl << "-- расстановка скобок (рекурсивное решение) "
		<< std::endl;
	std::cout << std::endl << "размерности матриц: ";
	for (int i = 1; i <= N; i++) std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
	std::cout << std::endl << "минимальное количество операций умножения: " << r;
	std::cout << std::endl << std::endl << "матрица S" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < N; j++)  std::cout << Ms[i][j] << "  ";
	}
	std::cout << std::endl;

	memset(Ms, 0, sizeof(int) * N * N);
	rd = OptimalMD(N, Mc, OPTIMALM_PARM(Ms));
	std::cout << std::endl
		<< "-- расстановка скобок (динамическое программирование) " << std::endl;
	std::cout << std::endl << "размерности матриц: ";
	for (int i = 1; i <= N; i++)
		std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
	std::cout << std::endl << "минимальное количество операций умножения: "
		<< rd;
	std::cout << std::endl << std::endl << "матрица S" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < N; j++)  std::cout << Ms[i][j] << "  ";
	}
	std::cout << std::endl << std::endl;
	system("pause");

	return 0;
}


//
//
//
//#include "strGenerate.h"
//#include "Levenshtein.h"
//#include <cstdlib>
//#include <ctime>
//#include <iostream>
//#include <algorithm>
//#include <iomanip>
//using namespace std;
//
//#define LEN_S1 300
//#define LEN_S2 200
//#define K (1./5.)
//#define LEN_PREFIX_S1 (int)(LEN_S1 * (double)K)
//#define LEN_PREFIX_S2 (int)(LEN_S2 * (double)K)
//
//int main()
//{
//	srand((unsigned)time(NULL));
//	setlocale(LC_ALL, "ru_RU.UTF-8");
//	char* S1, *S2;
//	S1 = strGenerate::strGenerate(LEN_S1);
//	S2 = strGenerate::strGenerate(LEN_S2);
//
//	cout << "-----------------------Строка 1-----------------------" <<endl<< S1 << endl;
//	cout << "-----------------------Строка 2-----------------------" <<endl<< S2 << endl;
//
//	clock_t t1 = 0, t2 = 0, t3, t4;
//	
//	std::cout << std::endl<<endl;
//	cout << "Строка 1: " << prefix(S1, LEN_PREFIX_S1) << endl;
//	cout << "Строка 2: " << prefix(S2, LEN_PREFIX_S2) << endl;
//	cout << endl;
//	std::cout << std::endl << "--Расстояние Левенштейна -----" << std::endl;
//	
//	std::cout << std::endl << "---длина--- рекурсия -- дин.програм.---"
//		<< std::endl;
//	int lev = 0, lev_r = 0;
//	int sum = 0, sum_r = 0;
//	for (int i = 4; i < std::min(LEN_PREFIX_S1, LEN_PREFIX_S2); i++)
//	{
//
//
//		t1 = clock(); lev = levenshtein_r(i, prefix(S1, LEN_PREFIX_S1), i, prefix(S2, LEN_PREFIX_S2)); t2 = clock();
//		t3 = clock(); lev_r = levenshtein(i, prefix(S1, LEN_PREFIX_S1), i, prefix(S2, LEN_PREFIX_S2)); t4 = clock();
//		std::cout << std::right << std::setw(2) << i - 2 << "/" << std::setw(2) << i
//			<< "        " << std::left << std::setw(10) << (t2 - t1)
//			<< "   " << std::setw(10) << (t4 - t3) << std::endl;
//	}
//
//	/*for (int i = 0; i < std::min(LEN_PREFIX_S1, LEN_PREFIX_S2); i++)
//	{
//		
//		t1 = clock(); lev = levenshtein_r(i, prefix(S1, LEN_PREFIX_S1), i, prefix(S2, LEN_PREFIX_S2)); t2 = clock();
//		t3 = clock(); lev_r = levenshtein(i, prefix(S1, LEN_PREFIX_S1), i, prefix(S2, LEN_PREFIX_S2)); t4 = clock();
//		std::cout << std::right << std::setw(2) << 
//			 "        " << std::left << std::setw(10) << (t2 - t1)
//			<< "   " << std::setw(10) << (t4 - t3) << std::endl;
//		sum_r += t2 - t1;
//		sum += t4 - t3;
//	}*/
//	//cout << lev << endl << lev_r << endl;
//	//cout << sum_r << "\t" << sum << endl;
//	system("pause");
//	return 0;
//}
//
//


#include "Header.h"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define К 200
int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	void (*function[])(char ****str, int n1, int n, int m) = {printMatrix, findPal};
	char ****str = NULL;
	int n1, n, m;
	int y;
	int again = 1;
	while (again)
	{
		n1 = enterN1();
		n = enterN();
		m = enterM();
		if (mem(n1, n, m, К) == 0)
			return 1;
		str = mem(n1, n, m, К);
		inputMatrix(str, n1, n, m, К);
		function[1](str, n1, n, m);
		function[0](str, n1, n, m);
		// Данные строки имеют такой же смысл как и 2 строки выше
		//	findPal(str, n1, n, m);
		//	printMatrix(str, n1, n, m);
		memClear(str, n1, n, m);
		again = againProg();
	}
}

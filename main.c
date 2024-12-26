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
		while (1)
		{
			printf("Введите кол-во\033[33m матриц\033[0m n1 :\t");
			y = scanf_s("%d", &n1);
			if (CheckElement(n1, y))
				break;
		};
		while (1)
		{
			printf("Введите кол-во \033[36mстрок\033[0m :\t");
			y = scanf_s("%d", &n);
			if (CheckElement(n, y))
				break;
		}
		while (1)
		{
			printf("Введите кол-во \033[37mстолбцов\033[0m :\t");
			y = scanf_s("%d", &m);
			if (CheckElement(m, y))
				break;
		}
		if (mem(n1, n, m, К) == 0)
			return 1;
		str = mem(n1, n, m, К);
		inputMatrix(str, n1, n, m, К);
		function[1](str, n1, n, m);
		function[0](str, n1, n, m);
		//	findPal(str, n1, n, m);
		//	printMatrix(str, n1, n, m);
		memClear(str, n1, n, m);
		printf("Хотите попробовать снова? \033[32mДа - 1\033[0m. \033[31mНет - 0 \033[0m:\t");
		while (1)
		{
			y = scanf_s("%d", &again);
			if (y != 1 || (again != 0 && again != 1))
			{
				printf("\033[31mОшибка. Переход к завершению...\033[0m");
				rewind(stdin);
				return 1;
			}
			else
				break;
		}
	}
}

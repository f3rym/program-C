#include "Header.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char ****mem(int n1, int n, int m, int К)
{
	char ****str = NULL;
	str = (char ****)calloc(n1, sizeof(char ***));
	if (str == NULL)
	{
		printf("Ошибка выделения памяти.");
		return NULL;
	}
	for (int i = 0; i < n1; i++)
	{
		*(str + i) = (char ***)calloc(n, sizeof(char **));
		if (*(str + i) == NULL)
		{
			printf("Ошибка выделения памяти.");
			return NULL;
		}
		for (int j = 0; j < n; j++)
		{
			*(*(str + i) + j) = (char **)calloc(m, sizeof(char *));
			if (*(*(str + i) + j) == NULL)
			{
				printf("Ошибка выделения памяти.");
				return NULL;
			}
			for (int l = 0; l < m; l++)
			{
				*(*(*(str + i) + j) + l) = (char *)calloc(К, sizeof(char));
				if (*(*(*(str + i) + j) + l) == NULL)
				{
					printf("Ошибка выделения памяти.");
					return NULL;
				}
			}
		}
	}
	return str;
}

int CheckElement(int a, int y)
{
	if (y != 1 || a <= 0 || a >= INT_MAX)
	{
		printf("\n\033[31mОшибка. Введено не число или оно > %d. Попробуй снова.\033[0m\n\n", INT_MAX);
		rewind(stdin);
		return 0;
	}
	else
		return 1;
}

int inputMatrix(char ****str, int n1, int n, int m, int К)
{
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n; j++)
			for (int l = 0; l < m; l++)
			{
				printf("Введите строку [\033[36m%d\033[0m][\033[36m%d\033[0m] матрицы \033[33m%d\033[0m :\t", j + 1, l + 1, i + 1);
				rewind(stdin);
				fgets(*(*(*(str + i) + j) + l), К, stdin);
			}
	return 0;
}

int isPalindrome(char *buffer, int start, int end)
{
	if (start > end)
		return 1;
	else if (*(buffer + start) != *(buffer + end))
		return 0;
	return isPalindrome(buffer, start + 1, end - 1);
}

void findPal(char ****str, int n1, int n, int m)
{
	char *buffer;
	int index, rIndex, palCount;
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
			{
				char *p = *(*(*(str + i) + j) + k);
				int len = (int)strlen(p);
				char *newStr = (char *)calloc(len + 20, sizeof(char));
				rIndex = 0;
				index = 0;
				palCount = 0;
				for (int h = 0; h <= len + 1; h++)
				{
					if (*(p + h) == ' ' || *(p + h) == '\t' || *(p + h) == '\n')
					{
						if (index > 0)
						{
							// Выделяем память для взятого слова
							buffer = (char *)calloc(index + 1, sizeof(char));
							// Последний символ это нулевой
							*(buffer + index) = '\0';
							// Заполняем слово символами
							for (int y = 0; y < index; y++)
								*(buffer + y) = *(p + h - index + y);
							// Если  слово палиндром то перезаписываем строку
							if (isPalindrome(buffer, 0, index - 1))
							{
								if (rIndex > 0)
									*(newStr + rIndex++) = ' ';
								strcpy_s(newStr + rIndex, len + 1 - rIndex, buffer);
								rIndex += index;
								palCount++;
							}
							free(buffer);
							index = 0;
						}
					}
					else
						index++;
				}
				// Замена оригинальной строки на строку, содержащую только палиндромы
				len = (int)strlen(p);
				if (len <= 0 || p == NULL)
				{
					printf("Ошибка: некорректная длина строки или p не инициализирована.\n");
					continue;
				}
				len += 20;
				if (palCount == 0 || len == 0)
				{
					char strNull[] = "\033[31mНе найдено палиндромов.\033[0m";
					strcpy_s(p, len + 20, strNull);
				}
				else
					sprintf_s(p, len, "%d %s", palCount, newStr);
				free(newStr);
			}
}

void printMatrix(char ****str, int n1, int n, int m)
{
	printf("\nОбработанные\033[0m матрицы\033[0m:\n");
	for (int i = 0; i < n1; i++)
	{
		printf("\nМатрица \033[33m%d\033[0m :\n", i + 1);
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				printf("Элемент [\033[36m%d\033[0m][\033[36m%d\033[0m] : %s\t", j + 1, k + 1, *(*(*(str + i) + j) + k));
			}
			printf("\n\n");
		}
	}
}

void memClear(char ****str, int n1, int n, int m)
{
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int l = 0; l < m; l++)
			{
				free(*(*(*(str + i) + j) + l));
			}
			free(*(*(str + i) + j));
		}
		free(*(str + i));
	}
	free(str);
}

void SayHello()
{
	printf("Hello World");
}

void SayBye()
{
	printf("Bye POOOPS");
}
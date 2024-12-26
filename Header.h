#pragma once

char**** mem(int n1, int n, int m, int К);

int CheckElement(int a, int y);

int inputMatrix(char**** str, int n1, int n, int m, int К);

int isPalindrome(char* buffer, int start, int end);

void findPal(char**** str, int n1, int n, int m);

void printMatrix(char**** str, int n1, int n, int m);

void memClear(char**** str, int n1, int n, int m);

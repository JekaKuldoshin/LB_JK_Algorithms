#pragma once
#include<iostream>
#include<chrono>
#include <clocale>
#include<conio.h>
#include<iomanip>
#include<algorithm>
#include "windows.h"
#include <time.h>

using namespace std;

//#define PRINT

#define N1 = 10
#define N2 = 100
#define N3 = 1000
#define N4 = 10000
#define N5 = 100000

struct Data {
	int size1 = 10;
	int size2 = 100;
	int size3 = 1000;
	int size4 = 10000;
	int size5 = 100000;

	int print = 0;

};

void Fun_InsertSort();
void InsertSort(int* arr, int N);
void Fun_InsertSort();

void print_mas_new(int size, int A[]);
void print_mas_old(int size, int A[]);

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

#define G 100000

#define N1 = 10
#define N2 = 100
#define N3 = 1000
#define N4 = 10000
#define N5 = 20000
#define N6 = 30000

struct Data {
	int size1 = 10;
	int size2 = 100;
	int size3 = 1000;
	int size4 = 10000;
	int size5 = 20000;
	int size6 = 30000;

	int print = 0;

};

void create_mas_Rand(int size, int A[]);
void create_mas_Up(int size, int A[]);
void create_mas_Down(int size, int A[]);

void InsertSort(int* arr, int N);
void Fun_InsertSortRand();
void Fun_InsertSortUp();
void Fun_InsertSortDown();

void radixSort(int* arr, int N);
void countingSort(int* arr, int N, int div, int k);

void Fun_RadixSortRand();
void Fun_RadixSortUp();
void Fun_RadixSortDown();

void Fun_HeapSortRand();
void Fun_HeapSortUp();
void Fun_HeapSortDown();

void print_mas_new(int size, int A[]);
void print_mas_old(int size, int A[]);

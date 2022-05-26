#pragma once
#include<iostream>
#include<conio.h>
#include<iomanip>
#include "windows.h"
#include <time.h>

using namespace std;

#define G 100000

struct Data {
	int size,
		search;
};

void create_mas_Rand(int size, int A[]);
void create_mas_Up(int size, int A[]);
void create_mas_Down(int size, int A[]);

void radixSort(int* arr, int N);
void countingSort(int* arr, int N, int div);

void print_mas_new(int size, int A[]);
void print_mas_old(int size, int A[]);

int LinearSearch(int* arr, Data d);

void Fun_line_search();
void Fun_barrier_search();
void Fun_binary_search();

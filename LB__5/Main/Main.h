#pragma once
#include<iostream>
#include<conio.h>
#include "windows.h"
#include <fstream>  
#include <string>
#include <time.h>
#include<chrono>

using namespace std;

#define G 100000                   //Для работы поразрядной сортировки
#define NO_OF_CHARS 300
#define _CRT_SECURE_NO_WARNINGS

struct Data {      //Структура данных для хранения
	int size,    
		search;
};

class Timer
{
private:
	// Псевдонимы типов используются для удобного доступа к вложенным типам
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};


void create_mas_Rand(int size, int A[]);                            //Функ-я создания рандомного масива
void create_mas_Up(int size, int A[]);							   //Функ-я создания упорядоченного масива
void create_mas_Down(int size, int A[]);						  //Фукн-я создания неупорядоченного масива

void radixSort(int* arr, int N);                                //Сортировка массива поразрядно
void countingSort(int* arr, int N, int div);                   //Доп.функ-я к сортировке

void print_mas_new(int size, int A[]);                       //Функ-я печати нового отсортированного масива
void print_mas_old(int size, int A[]);                      //Функ-я печати масива

int LinearSearch(int* arr, Data d);                       //Линейный поиск в масиве
int BarrierSearch(int* arr, Data d);                     //Барьерный поиск в масиве
int BinarySearch(int* arr, Data d);						//Бинарный поиск в масиве

void Fun_line_search();                               //Основная функ-я линейного поиска 
void Fun_barrier_search();                           //Основная функ-я барьерного поиска
void Fun_binary_search();							//Основная функ-я бинарного поиска

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\ 

void Fun_STR_direct_search();					//Основная функ-я прямого поиска строки 
void Fun_STR_KMP_search();                     //Основная функ-я Кнута-Морриса-Пратта
void Fun_STR_BM_search();					  //Основная функ-я Бойера-Мура
void Fun_STR_RK_search();					 //Основная функ-я Рабина – Карпа

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

void in_file(string s);					  //Функ-я записи строки в файл
string from_the_file(string s);          //Функ-я чтения с файла
string create_str(string s);            //Функ-я создания строки

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

int DirectSearch(string& s, string key);             //Функ-я прямого поиска - логика
//\\//\\ 
int KMPSearch(string& s, string key);              //Функ-я поиска Кнута-Морриса-Пратта - логика
void prefix(string& s, int*& P);                  //Доп.функ-я поиска Кнута-Морриса-Пратта
//\\//\\ 
int BMSearch(string txt, string pat);                                     //Функ-я поиска Бойера-Мура - логика
void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS]);   //Доп.функ-я поиска Бойера-Мура
//\\//\\ 

int RKSearch(string pattern1, string text1, int inputBase);   //Функ-я поиска Рабина – Карпа - логика
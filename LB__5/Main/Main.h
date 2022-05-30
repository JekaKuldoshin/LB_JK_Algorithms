#pragma once
#include<iostream>
#include<conio.h>
#include "windows.h"
#include <fstream>  
#include <string>
#include <time.h>
#include<chrono>

using namespace std;

#define G 100000                   //��� ������ ����������� ����������
#define NO_OF_CHARS 300
#define _CRT_SECURE_NO_WARNINGS

struct Data {      //��������� ������ ��� ��������
	int size,    
		search;
};

class Timer
{
private:
	// ���������� ����� ������������ ��� �������� ������� � ��������� �����
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


void create_mas_Rand(int size, int A[]);                            //����-� �������� ���������� ������
void create_mas_Up(int size, int A[]);							   //����-� �������� �������������� ������
void create_mas_Down(int size, int A[]);						  //����-� �������� ���������������� ������

void radixSort(int* arr, int N);                                //���������� ������� ����������
void countingSort(int* arr, int N, int div);                   //���.����-� � ����������

void print_mas_new(int size, int A[]);                       //����-� ������ ������ ���������������� ������
void print_mas_old(int size, int A[]);                      //����-� ������ ������

int LinearSearch(int* arr, Data d);                       //�������� ����� � ������
int BarrierSearch(int* arr, Data d);                     //��������� ����� � ������
int BinarySearch(int* arr, Data d);						//�������� ����� � ������

void Fun_line_search();                               //�������� ����-� ��������� ������ 
void Fun_barrier_search();                           //�������� ����-� ���������� ������
void Fun_binary_search();							//�������� ����-� ��������� ������

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\ 

void Fun_STR_direct_search();					//�������� ����-� ������� ������ ������ 
void Fun_STR_KMP_search();                     //�������� ����-� �����-�������-������
void Fun_STR_BM_search();					  //�������� ����-� ������-����
void Fun_STR_RK_search();					 //�������� ����-� ������ � �����

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

void in_file(string s);					  //����-� ������ ������ � ����
string from_the_file(string s);          //����-� ������ � �����
string create_str(string s);            //����-� �������� ������

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

int DirectSearch(string& s, string key);             //����-� ������� ������ - ������
//\\//\\ 
int KMPSearch(string& s, string key);              //����-� ������ �����-�������-������ - ������
void prefix(string& s, int*& P);                  //���.����-� ������ �����-�������-������
//\\//\\ 
int BMSearch(string txt, string pat);                                     //����-� ������ ������-���� - ������
void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS]);   //���.����-� ������ ������-����
//\\//\\ 

int RKSearch(string pattern1, string text1, int inputBase);   //����-� ������ ������ � ����� - ������
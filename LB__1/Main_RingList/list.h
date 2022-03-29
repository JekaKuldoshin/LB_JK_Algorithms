#pragma once

#include <windows.h>
#include <iostream>
#include <fstream>
#include <conio.h>


using namespace std;

struct Data
{
	Data* prev, * next;
	//Data* Prev, * Next;
	int number;
	double data;
};

class TList {
private:
	Data* head, * tail;
	int size;
public:

	TList() : head(NULL), tail(NULL), size(0) {};
	~TList();

	int Count();                   //Функ-я возвращающая число элементов

	bool check();
	void Add(double data);
	void create(int num);
	void show(int temp);
	short number(int temp);
	void deleteFromList(int poz);
	void change(int num);
	void addition(TList& LIST);
	void save();
	void form_the_file();
	void in(double s);


};
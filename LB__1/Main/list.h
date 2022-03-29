#pragma once

#include <windows.h>
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

struct Data {
	double data;
	Data* next; // указатель на следующий элемент
	Data* prev; // указатель на предыдущий элемент

	//Data* next1; // указатель на следующий элемент
	//Data* prev1; // указатель на предыдущий элемент
	//Data* next2; // указатель на следующий элемент
	//Data* prev2; // указатель на предыдущий элемент
};


class TList {
private:
	Data* head, * tail;
public:

	TList() : head(NULL), tail(NULL) {};
	~TList();

	bool check();
	void Add(double data);
	void create(int num);
	void show();
	short number();
	void deleteFromList(int poz);
	void change(int num);
	void addition(TList& LIST);
	void save();
	void form_the_file();
	void in(double s);

};

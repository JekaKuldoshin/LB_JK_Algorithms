#pragma once

#include <windows.h>
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

struct Data {
	double data;
	Data* next; // ��������� �� ��������� �������
	Data* prev; // ��������� �� ���������� �������

	//Data* next1; // ��������� �� ��������� �������
	//Data* prev1; // ��������� �� ���������� �������
	//Data* next2; // ��������� �� ��������� �������
	//Data* prev2; // ��������� �� ���������� �������
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

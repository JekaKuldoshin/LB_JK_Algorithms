#pragma once

#include <windows.h>         //������������
#include <iostream>         //�++
#include <fstream>         //�����
#include <conio.h>        //_getch() 

using namespace std;

struct obj {
	char data;               //���������� ����������
	obj* prev;              //��������� �� ������� �������
};

class queue {
private:
	obj* first;         //��������� �� ������
	obj* tail;         //��������� �� �����

public:

	queue() : first(NULL), tail(NULL) {};          //���
	//~queue();                        //����

	void create(int num);          //����-� ��� �������� ���������� ���������
	void Add(char a);             //����
	void show();                 //�����

	int count();               //����-� ��� �������� ���-�� ��������� � �������
	double average();         //����-� ��� ���������� �������� ���������������
	char Max();              //����-� ��� ���������� ����.
	char Min();             //����-� ��� ���������� ���.
	char prevMin();        //����-� ��� ���������� �������� ����� ����������� ���������
	void saveInFile();       //����-� ������ � ����
	void form_the_file();   //����-� ������ � �����

	bool check();           //�������� �� �������
};
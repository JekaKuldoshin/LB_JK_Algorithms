#pragma once

#include <windows.h>         //������������
#include <iostream>         //�++
#include <fstream>         //�����
#include <conio.h>        //_getch() 

using namespace std;

struct obj {
	char data;               //���������� ����������
	obj* prev;
	obj* next;              //��������� �� �������
};

class deque {
private:
	obj* left, * right;            //��������� �� ����

public:

	deque() : left(NULL), right(NULL) {};           //���

	void create_front(int num);          //����-� ��� �������� ���������� ���������
	void create_back(int num);
	void push_front(char a);
	void push_back(char a);             //����
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
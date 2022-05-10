#pragma once

#include <windows.h>         //������������
#include <iostream>         //�++
#include <fstream>         //�����
#include <conio.h>        //_getch() 

using namespace std;

struct obj {
	char data;               //���������� ����������
	obj* next;              //��������� �� �������
};

class stack {
private:
	obj* top;            //��������� �� ����

public:

	stack() : top(NULL) {};           //���
	~stack();                        //����

	void create(int num);          //����-� ��� �������� ���������� ���������

	void push(char d);           //����
	void pop();                 //��������
	short pull();              //�����������
	void show();              //�����

	bool check();           //�������� �� �������
	bool isEmpty();        //�������� �� �������

	void swapTopTail();                //����-� ��� ������ ������ � ������
	void reverse();                   //����-� ��������������� �����
	void delEvery2();                //�������� ������� ������� ��������
	void putInStar();               //����-� ���������� ������ � ��������
	void findMaxPutInZero();       //����-� ��� ���������� ������������� � ������� ����
	void delMin();                //����-� ���������� � �������� ������������ �������� �����
	void delTail();              //����-� �������� ���� ��������� ����� ����������
	void delHead();             //����-� �������� ���� ��������� ����� �������
	void saveInFile();         //����-� ������ � ����
	void form_the_file();     //����-� ������ � �����

};
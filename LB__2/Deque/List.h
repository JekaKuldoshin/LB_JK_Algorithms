#pragma once

#include <windows.h>         //������������
#include <iostream>         //�++
#include <fstream>         //�����
#include <conio.h>        //_getch() 

using namespace std;

struct obj {
	char data;               //���������� ����������
	obj* prev;              //��������� �� ������� �������
	obj* next;             //��������� �� ��������� �������
};

class deque {
private:
	obj* left, * right;            //��������� �� ������ (����) � ����� (�����)

public:

	deque() : left(NULL), right(NULL) {};           //���

	void create_back(int num);                    //����-� ��� �������� ���������� ��������� ������� (������ ������� �� ����-� push_back)
	void push_front(char a);                     //����-� �������� ������ � ������� � ������
	void push_back(char a);                     //�
	void show();                               //�����

	int count();                             //����-� ��� �������� ���-�� ��������� � �������
	void check_pull_6_elem();               //����-� ��� �������� ������������ ������ 6-�� �������� �������
	char pull_6_elem();                    //����-� ������ 6-�� �������� �������
	char pull_last_elem();                //����-� ������ ���������� �������� �������

	void saveInFile();                  //����-� ������ � ����
	void form_the_file();              //����-� ������ � �����

	bool check();                    //�������� �� �������

};
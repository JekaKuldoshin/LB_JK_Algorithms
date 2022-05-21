#pragma once
#include <vector>                //Vector
#include <windows.h>            //����������� � STD_OUTPUT_HANDLE
#include <fstream>             //�����
#include <iostream>           //�++
#include <conio.h>           //_gecth()

using namespace std;

struct Data {
	Data* Left, * Right, * Parent;                //��������� ����� - ������ �����, �������� �������� 
	int year, kol;                               //���������� ��� ����, ���-��
	string name;                                //�������� �������
	Data(string s, int y, int k);
	Data() {}
};

class Tree {                                                        //����� ��������� ������
public:
	Data* Root;                                                   //���������� ��� ������ � �������
	int count, tabs;                                             //���������� ��� �������� � ��������
	Tree();                                                     //���
	void add(string y, int k, int g);                          //����-� ���������� � �������� ������
	void addByYear(Data* node);                               //������� ��� ����������, �� ����, ����� ��� ������� ������ ������ -> ������� ����� ��� ������
	void add_by_y(string name, int y, int k);               //������� ��� ����������, �� ����

	void showForward(Data* n);                             //������� ��� ������ ��������� ������ 
	void showF(Data* n);                                  //����� ������� ������
	void showBackward(Data* n);                          //����� ��������� ������
	void showSymmetrically(Data* n);                    //����� ������������ ������
	void show();                                       //������������� ������� ��� ������, �������� (�������� ������)
	void showPreOrder();                              //������������� ������� ��� ������ ������� ������
	void showPostOrder();                            //������������� ������� ��� ������ ��������� ������
	void showSymm();                                //������������� ������� ��� ������ ������������ ������

	void delLeft(Data* n);                        //����-� �������� ����� ����� � ��������� ��
	void delLeftTree();                          //������� �������� �� ������� ����� �����, � ������ ���� ���� ������ ���������� ��������, ������� � ������� -> delLeft(Data* n);
	void delRight(Data* n);                     //����-� �������� ������ ����� � ��������� �� 
	void delRightTree();					   //������� �������� �� ������� ������ �����, � ������ ���� ���� ������ ���������� ��������, ������� � ������� -> delRight(Data* n);
	void delTree();                           //����-� �������� ��������� ������

	void remake();							//������� ��� �������� ������ ������ � �������� ������ � ����, �������� ���������� �� ������� �������� ������ (Year)

	void makeVectorFromTree(Data* n, vector<Data*>& m);          //������� � ������� ������ � ������ ������� ��� ��������� ��������� ������


	void save(Data* n, string name);               //����-� ��� ������ � ����, ����� �������� ���� �� ����������� ������
	void saveToFile(string name);                 //������������� ������� ��� ������ � ����
	void read(Data* n, string name);             //����-� ��� ������ � �����, ����� �������� ���� �� ����������� ������
	void readFromFile(string name);             //������������� ������� ��� ������ � �����

	bool check();                             //����-� ��� �������� �� ������� ��������� ������
};

#pragma once
#include <iomanip>           //����������� ��� ������
#include <string>            
#include "BinaryTree.h"

using namespace std;

enum RBTColor { Black, Red };    //������������ ������

struct  RBData
{
	int year, kol;
	string name;
	RBTColor color;
	RBData* left, * right, * parent;
	RBData(int y, int k, string name, RBTColor c, RBData* p, RBData* l, RBData* r) :
		year(y), kol(k), name(name), color(c), parent(p), left(l), right(r) { };
};

class  RBTree
{
public:
	RBTree();																  //���
	~RBTree();																 //���� 

	void insert(int y, int k, string name);								   //������������� ����-� ���������� ������ � R/B ������
	void remove(int y, int k, string name);                               //����-� �������� ���� ��������� ������ R/B
	RBData* search(int y, int k, string name);                           //����-� ������ �������� ��� ����������� ��������

	void p() {                                                         //������������� ����-� ������
		printt(root);												  //������� � �������
	}
	void printt(RBData* n);											//����-� ������

	bool checkRB();												 //����-� �������� �� ������� ��������� R/B ������
	void makeRB(Tree t);									    //����-� ��������� ������ � R/B

private:
	void leftRotate(RBData*& root, RBData* x);               //����-� ��� ����������� �����
	void rightRotate(RBData*& root, RBData* y);             //����-� ��� ����������� ������

	void insert(RBData*& root, RBData* node);             //����-� ���������� ������ � R/B ����� 
	void InsertFixUp(RBData*& root, RBData* node);

	void destory(RBData*& node);                        //����-� �������� R/D ������


	void remove(RBData*& root, RBData* node);		 //����-� �������� ���� ��������� ������ R/B
	void removeFixUp(RBData*& root, RBData* node, RBData* parent);

	RBData* search(RBData* node, int y, int k, string name) const;   //����-� ������ �������� ��� ����������� ��������

private:
	RBData* root;									//���������� ��� ������ � �������
	int tabs = 0;								   //���������� ��� �������� ��������
	int  count;                                   //���������� ��� �������� ���-��
};

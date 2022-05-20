#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "BinaryTree.h"

using namespace std;

enum RBTColor { Black, Red };

struct  RBTNode
{
	int year, number;
	string name;
	RBTColor color;
	RBTNode* left, * right, * parent;
	RBTNode(int y, int n, string name, RBTColor c, RBTNode* p, RBTNode* l, RBTNode* r) :
		year(y), number(n), name(name), color(c), parent(p), left(l), right(r) { };
};

class  RBTree
{
	RBTNode* root;
	int tabs = 0;

	void leftRotate(RBTNode*& root, RBTNode* x);// ����� ����
	void rightRotate(RBTNode*& root, RBTNode* y);// ������ ����

	void insert(RBTNode*& root, RBTNode* node);// ��������� ����, ���������� ���������
	void InsertFixUp(RBTNode*& root, RBTNode* node);
	void destory(RBTNode*& node);

	void remove(RBTNode*& root, RBTNode* node);// ������� ���� ��� KEY
	void removeFixUp(RBTNode*& root, RBTNode* node, RBTNode* parent);

	RBTNode* search(RBTNode* node, int y, int n, string name) const;
	void print(RBTNode* node)const;
	//void printt(RBTNode* node);
	void preOrder(RBTNode* tree)const;
	void inOrder(RBTNode* tree)const;
	void postOrder(RBTNode* tree)const;
	
public:
	RBTree();
	~RBTree();

	void insert(int y, int n, string name);    // ��������� ����, ���� ��� �������� �����, ������� ���������
	void remove(int y, int n, string name); // ������� �������� ����
	RBTNode* search(int y, int n, string name);
	void print();
	void p();
	void printt(RBTNode* n);

	void preOrder();    // ��������� ������ ������ �������� ������� ������
	void inOrder();    // ����� ������������������
	void postOrder();    // ����-����� ������		

	void makeRB();

	bool check();
};

















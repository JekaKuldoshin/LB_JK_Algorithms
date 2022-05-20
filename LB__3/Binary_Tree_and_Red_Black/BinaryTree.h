#pragma once
#include <vector>
#include <windows.h>
#include <fstream>
#include <iostream>
#include <conio.h>        //_getch() 

using namespace std;

struct Node {
	Node* Left, * Right, * Parent;
	int year, num;
	string name;
	Node(string s, int y, int n);
	Node() {}
};

class Tree {
public:
	Node* Root;
	int count, tabs;
	Tree();

	void add(string name, int y, int n);
	void addByNum(Node* node);
	void addByN(string name, int num, int g);
	void showForward(Node* n);
	void showF(Node* n);
	void showBackward(Node* n);
	void showSymmetrically(Node* n);
	void show();
	void showPreOrder();
	void showPostOrder();
	void showSymm();
	void delLeft(Node* n);
	void delLeftTree();
	void delRight(Node* n);
	void delRightTree();
	void delTree();
	void makeVectorFromTree(Node* n, vector<Node*>& m);
	void remake();
	void save(Node* n, string name);
	void saveToFile(string name);
	void read(Node* n, string name);
	void readFromFile(string name);
};

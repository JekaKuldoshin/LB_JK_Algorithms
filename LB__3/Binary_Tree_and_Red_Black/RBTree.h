#pragma once
#include <iomanip>           //Манипулятор для вывода
#include <string>            
#include "BinaryTree.h"

using namespace std;

enum RBTColor { Black, Red };    //Перечисление цветов

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
	RBTree();																  //КсП
	~RBTree();																 //КпоУ 

	void insert(int y, int k, string name);								   //Промежуточная функ-я добавления данных в R/B дерево
	void remove(int y, int k, string name);                               //Функ-я удаление узла бинарного дерева R/B
	RBData* search(int y, int k, string name);                           //Функ-я поиска элемента для дальнейшего удаления

	void p() {                                                         //Промежуточная функ-я вывода
		printt(root);												  //Переход в функцию
	}
	void printt(RBData* n);											//Функ-я вывода

	bool checkRB();												 //Функ-я проверки на пустоту бинарного R/B дерева
	void makeRB(Tree t);									    //Функ-я раскраски дерева в R/B

private:
	void leftRotate(RBData*& root, RBData* x);               //Функ-я для перемещения влево
	void rightRotate(RBData*& root, RBData* y);             //Функ-я для перемещения вправо

	void insert(RBData*& root, RBData* node);             //Функ-я добавления данных в R/B дерев 
	void InsertFixUp(RBData*& root, RBData* node);

	void destory(RBData*& node);                        //Функ-я удаления R/D дерева


	void remove(RBData*& root, RBData* node);		 //Функ-я удаление узла бинарного дерева R/B
	void removeFixUp(RBData*& root, RBData* node, RBData* parent);

	RBData* search(RBData* node, int y, int k, string name) const;   //Функ-я поиска элемента для дальнейшего удаления

private:
	RBData* root;									//Переменная для работы с классом
	int tabs = 0;								   //Переменная для подсчета пробелов
	int  count;                                   //Переменная для подсчета кол-ва
};

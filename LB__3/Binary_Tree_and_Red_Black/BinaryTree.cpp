#include "BinaryTree.h"

Node::Node(string s, int y, int n) {
	name = s;
	year = y;
	num = n;
	Left = Right = Parent = nullptr;
}

Tree::Tree() {
	Root = nullptr;
	count = tabs = 0;
}

void Tree::add(string name, int y, int n) {
	Node* temp = new Node(name, y, n);
	Node* ptr, * ptr1;
	ptr = ptr1 = Root;
	while (ptr != 0)
	{
		ptr1 = ptr;
		if (temp->name < ptr->name)
		{
			ptr = ptr->Left;
		}
		else
		{
			ptr = ptr->Right;
		}
	}
	temp->Parent = ptr1;
	if (ptr1 == 0)
	{
		Root = temp;
	}
	else
	{
		if (temp->name < ptr1->name)
		{
			ptr1->Left = temp;
		}
		else
		{
			ptr1->Right = temp;
		}
	}
	count++;

	system("cls");

}

 void Tree::addByNum(Node* node) {
	 Node* temp = new Node(node->name, node->year, node->num);
	 Node* ptr, * ptr1;
	 ptr = ptr1 = Root;
	 while (ptr != 0)
	 {
		 ptr1 = ptr;
		 if (temp->year < ptr->year)
		 {
			 ptr = ptr->Left;
		 }
		 else
		 {
			 ptr = ptr->Right;
		 }
	 }
	 temp->Parent = ptr1;
	 if (ptr1 == 0)
	 {
		 Root = temp;
	 }
	 else
	 {
		 if (temp->year < ptr1->year)
		 {
			 ptr1->Left = temp;
		 }
		 else
		 {
			 ptr1->Right = temp;
		 }
	 }
	 count++;
 }

 void Tree::addByN(string name, int num, int g) {
	 Node* n = new Node(name, num, g);
	 addByNum(n);
 }

 void Tree::showForward(Node* n) {
	 if (n != 0)
	 {
		 tabs++;
		 showForward(n->Right);
		 for (int i = 0; i < tabs; i++) cout << "	";
		 cout << n->name << " " << n->year << " " << n->num << endl;
		 showForward(n->Left);
		 tabs--;
	 }
 }

 void Tree::showF(Node* n) {
	 if (n != 0)
	 {
		 cout << n->name << " " << n->year << " " << n->num << endl;
		 showF(n->Left);
		 showF(n->Right);
	 }
 }

 void Tree::showBackward(Node* n) {
	 if (n != 0)
	 {
		 showBackward(n->Left);
		 showBackward(n->Right);
		 for (int i = 0; i < tabs; i++) cout << "	";
		 cout << n->name << " " << n->year << " " << n->num << endl;
	 }
 }

 void Tree::showSymmetrically(Node* n) {
	 if (n != 0)
	 {
		 showSymmetrically(n->Left);
		 for (int i = 0; i < tabs; i++) cout << "	";
		 cout << n->name << " " << n->year << " " << n->num << endl;
		 showSymmetrically(n->Right);
	 }
 }

 void Tree::show() {
	 if (Root)
	 {
		 
		 showForward(Root);
		 cout << "";
		 cout << "\n\nНажмите на Enter чтобы продолжить...";
		 _getch();
	 }
	 else
	 {
		 cout << "Ошибка! Бинарное дерево отсутствует!!!\n\nНажмите на Enter чтобы продолжить...";
	 }
 }

 void Tree::showPreOrder() {
	 system("cls");
	 if (Root) {
		 cout << "Печать при прямом обходе |" << endl;
		 cout << "-------------------------|\n\n";
		 showF(Root);
	 }
	 else
		 cout << "Ошибка! Бинарное дерево отсутствует!!!\n\nНажмите на Enter чтобы продолжить...";
 }

 void Tree::showPostOrder() {
	 if (Root) {
		 cout << "Печать при обратном обходе |" << endl;
		 cout << "---------------------------|\n\n";
		 showBackward(Root);
	 }
	 else
		 cout << "Ошибка! Бинарное дерево отсутствует!!!\n\nНажмите на Enter чтобы продолжить...";
 }

 void Tree::showSymm() {
	 if (Root) {
		 cout << "Печать при симетричном обходе |" << endl;
		 cout << "------------------------------|\n\n";
		 showSymmetrically(Root);
	 }
	 else
		 cout << "Ошибка! Бинарное дерево отсутствует!!!\n\nНажмите на Enter чтобы продолжить...";
 }

 void Tree::delLeft(Node* n) {
	 if (n != 0)
	 {
		 delLeft(n->Left);
		 delLeft(n->Right);
		 n->Parent->Left = nullptr;
		 n->Parent = 0;
		 delete n;
		 count--;
	 }
 }

 void Tree::delLeftTree() {
	 if (Root->Left != 0)
	 {
		 delLeft(Root->Left);
	 }
	 cout << "Успех! Удаление левого поддерева было выполнено!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
	 _getch();
 }

 void Tree::delRight(Node* n) {
	 if (n != 0)
	 {
		 delRight(n->Right);
		 delRight(n->Left);
		 n->Parent->Right = nullptr;
		 n->Parent = 0;
		 delete n;
		 count--;
	 }
 }

 void Tree::delRightTree() {
	 if (Root->Right != 0)
	 {
		 delRight(Root->Right);
	 }
	 cout << "Успех! Удаление правого поддерева было выполнено!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
	 _getch();
 }

 void Tree::delTree() {
	 system("cls");
	 delLeftTree();
	 delRightTree();
	 Root = nullptr;
	 delete Root;
	 count--;
	 cout << "Успех! Удаление бинарного дерева было выполнено!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
	 _getch();
 }

 void Tree::makeVectorFromTree(Node* n, vector<Node*>& m) {
	 if (n != 0)
	 {
		 m.push_back(n);
		 makeVectorFromTree(n->Left, m);
		 makeVectorFromTree(n->Right, m);
	 }
 }

 void Tree::remake() {
	 Tree tree;
	 vector<Node*> mas;
	 makeVectorFromTree(Root, mas);
	 //tree.addByNum(mas[mas.size() / 2]);
	 //mas.erase(mas.begin() + mas.size() / 2); // for rand
	 for (int i = 0; i < mas.size(); i++)
	 {
		 tree.addByNum(mas[i]);
	 }
	 delTree();
	 *this = tree;
 }

 void Tree::save(Node* n, string name) {
	 if (n != 0)
	 {
		 ofstream fout;
		 if (fout.fail()) cout << "ERROR opening file";
		 fout.open(name, ios::app);
		 fout << n->year << endl << n->num << endl << n->name << endl;
		 fout.close();
		 save(n->Left, name);
		 save(n->Right, name);
	 }
 }

 void Tree::saveToFile(string name) {
	 ofstream fout;
	 if (fout.fail()) cout << "ERROR opening file";
	 fout.open(name, ios::out);
	 fout.close();
	 save(Root, name);
 }

 void Tree::read(Node* n, string name) {
	 ifstream fin;
	 fin.open(name);
	 if (fin.fail()) cout << "ERROR opening file";
	 char buf[300];
	 int year, num, i = 1;
	 string nam;
	 while (fin)
	 {
		 fin.getline(buf, 300);
		 if (i % 3 == 1)
		 {
			 num = atoi(buf);
			 i++;
		 }
		 else if (i % 3 == 2)
		 {
			 year = atoi(buf);
			 i++;
		 }
		 else
		 {
			 nam = string(buf);
			 i++;
			 add(nam, year, num);
		 }
	 }
	 fin.close();
 }

 void Tree::readFromFile(string name) {
	 read(Root, name);
 }
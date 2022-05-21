#include "BinaryTree.h"

Data::Data(string s, int y, int k) {
	name = s;
	year = y;
	kol = k;
	Left = Right = Parent = nullptr;
}

Tree::Tree() {
	Root = nullptr;
	count = tabs = 0;
}

bool Tree::check() {                 //\\//\\ ����-� ��� �������� �� ������� ��������� ������ //\\//\\ 
	if (Root == NULL)
	{
		system("cls");
		cout << "������! �������� ������ �����������!!!\n\n������� �� Enter ����� ����������...";
		_getch();
		return false;
	}
	else
	{
		return true;             //���� ���������� True, �� �� ����� ������������ ���� ������������ ���������
	}

}

void Tree::add(string n, int y, int k) {               //\\//\\ ����-� ���������� � �������� ������ //\\//\\ 
	Data* temp = new Data(n, y, k);           //������� ��������� �� ������
	Data* ptr, * ptr1;                       //��������� �� �����������
	ptr = ptr1 = Root;                      //���������� � �����
	while (ptr != 0)                       //���� �� ���������� ������������ ��������
	{
		ptr1 = ptr;
		if (temp->name < ptr->name)      //���� ��� ������ ������������� Name1 < Name2
		{
			ptr = ptr->Left;           //���������� ����� �����
		}
		else                         //������� ���� Name1 > Name2
		{
			ptr = ptr->Right;      //���������� ������
		}
	}
	temp->Parent = ptr1;        //��������� ������� ���������� ���������
	if (ptr1 == 0)             //���� ��������� ����, �� ���� �������� ������ ������
	{
		Root = temp;         //������� ���������� ������
	}
	else                   //������ ����� ��� ���� ������ � ������
	{
		if (temp->name < ptr1->name)         //���� Name1 < Name2
		{
			ptr1->Left = temp;             //���������� ����� �����
		}
		else                             //������� ���� Name1 > Name2
		{
			ptr1->Right = temp;        //���������� ������
		}
	}
	count++;                        //���������� ��� ��������
}

void Tree::addByYear(Data* node) {                                  //\\//\\ //������� ��� ����������, �� ���� //\\//\\ 
	Data* temp = new Data(node->name, node->year, node->kol);   //������� ��������� �� ������
	Data* ptr, * ptr1;                                         //��������� �� �����������
	ptr = ptr1 = Root;                                        //���������� � �����
	while (ptr != 0)                                         //���� �� ���������� ������������ ��������
	{
		ptr1 = ptr;
		if (temp->year < ptr->year)             //���� ��� ������ ������������� Year1 < Year2
		{
			ptr = ptr->Left;                  //���������� ����� �����
		}
		else                                //������� ���� Year1 > Year2
		{
			ptr = ptr->Right;             //���������� ������
		}
	}
	temp->Parent = ptr1;               //��������� ������� ���������� ���������
	if (ptr1 == 0)                    //���� ��������� ����, �� ���� �������� ������ ������
	{
		Root = temp;			    //������� ���������� ������
	}
	else                          //������ ����� ��� ���� ������ � ������
	{
		if (temp->year < ptr1->year)        //���� Year1 < Year2
		{
			ptr1->Left = temp;            //���������� ����� �����
		}
		else                            //������� ���� Year1 > Year2
		{
			ptr1->Right = temp;       //���������� ������
		}
	}
	count++;					   //���������� ��� ��������
}

void Tree::add_by_y(string name, int y, int k) {       //\\//\\ ������� ��� ����������, �� ���� //\\//\\ 
	Data* n = new Data(name, y, k);        //������� ��������� �� ������
	addByYear(n);                         //�������� � ������� �� ����������� ����� � �������
}

void Tree::showForward(Data* n) {            //\\//\\ ������� ��� ������ ��������� ������ //\\//\\ 
	if (n != 0)    //���� �� ���������� ������
	{
		tabs++;                    //������
		showForward(n->Right);    //������� ������ ������
		for (int i = 0; i < tabs; i++) cout << "	";                 //������ ������������ ���-�� ��������
		cout << n->name << " " << n->year << " " << n->kol << endl;   //������� ������ ����� ������
		showForward(n->Left);                                        //������� ����� ������
		tabs--;
	}
}

void Tree::showF(Data* n) {            //\\//\\ ����� ������� ������ //\\//\\ 
	if (n != 0)  //���� �� ���������� ������
	{
		cout << n->name << " " << n->year << " " << n->kol << endl;  //������� ������
		showF(n->Left);         //������� ����� ������
		showF(n->Right);       //������� ������ ������
	}
}

void Tree::showBackward(Data* n) {        //\\//\\ ����� ��������� ������ //\\//\\ 
	if (n != 0) //���� �� ���������� ������
	{
		showBackward(n->Left);      //������� ����� ������
		showBackward(n->Right);    //������� ������ ������
		for (int i = 0; i < tabs; i++) cout << "	";                 //������ ������������ ���-�� ��������
		cout << n->name << " " << n->year << " " << n->kol << endl;   //������� ������ ����� ������
	}
}

void Tree::showSymmetrically(Data* n) {       //\\//\\ ����� ������������ ������ //\\//\\ 
	if (n != 0)  //���� �� ���������� ������
	{
		showSymmetrically(n->Left);                                   //������� ����� ������
		for (int i = 0; i < tabs; i++) cout << "	";               //������ ������������ ���-�� ��������
		cout << n->name << " " << n->year << " " << n->kol << endl; //������� ������ ����� ������
		showSymmetrically(n->Right);							   //������� ������ ������
	}
}

void Tree::show()                   //\\//\\ ����-� ������� ��������� � ���������� � ������ //\\//\\ 
{
	showForward(Root);     //������� ������	
}

void Tree::showPreOrder() {            //\\//\\ ������������� ������� ��� ������ ������� ������ //\\//\\ 
	system("cls");

	cout << "������ ��� ������ ������ |" << endl;
	cout << "-------------------------|\n\n";
	showF(Root);     //������� � ����-� ������ ������� ������
}

void Tree::showPostOrder() {         //\\//\\ ������������� ������� ��� ������ ��������� ������ //\\//\\ 
	system("cls");
	cout << "������ ��� �������� ������ |" << endl;
	cout << "---------------------------|\n\n";
	showBackward(Root);         //������� � ����-� ������ ��������� ������
}

void Tree::showSymm() {          //\\//\\ ������������� ������� ��� ������ ������������ ������ //\\//\\ 

	system("cls");
	cout << "������ ��� ����������� ������ |" << endl;
	cout << "------------------------------|\n\n";
	showSymmetrically(Root);         //������� � ����-� ������ ������������ ������
}

void Tree::delLeft(Data* n) {       //\\//\\ ����-� �������� ����� ����� � ��������� �� //\\//\\ 
	if (n != 0)            //���� �� ���������� ������
	{
		delLeft(n->Left);				//������� ����� ������
		delLeft(n->Right);			   //������� ������ ������
		n->Parent->Left = nullptr;    //�������� ����� ����� � ��������
		n->Parent = 0;
		delete n;
		count--;                   //��������� ���-��
	}
}

void Tree::delLeftTree() {    //\\//\\ /������� �������� �� ������� ����� ����� //\\//\\ 
	if (Root->Left != 0)	//���� �� ���������� ������
	{
		delLeft(Root->Left);     //������� � ����-� ��������, ������������ ����� ��������� �����
	}
}

void Tree::delRight(Data* n) {		//\\//\\ ����-� �������� ������ ����� � ��������� �� //\\//\\ 
	if (n != 0)					 //���� �� ���������� ������
	{
		delRight(n->Right);			  //������� ������ ������
		delRight(n->Left);		     //������� ����� ������
		n->Parent->Right = nullptr; //�������� ����� ����� � ��������
		n->Parent = 0;
		delete n;
		count--;				 //��������� ���-��
	}
}

void Tree::delRightTree() {		//\\//\\ /������� �������� �� ������� ������ ����� //\\//\\ 
	if (Root->Right != 0)	//���� �� ���������� ������
	{
		delRight(Root->Right);		//������� � ����-� ��������, ������������ ����� ��������� ������
	}
}

void Tree::delTree() {    //\\//\\ ����-� �������� ��������� ������ //\\//\\ 
	delLeftTree();      //������� ����� �����
	delRightTree();    //������� ������ �����
	Root = nullptr;   //�������� ������
	delete Root;     //������� ������
	count--;        //��������� ���-��
}

void Tree::makeVectorFromTree(Data* n, vector<Data*>& m) {		 //\\//\\ ������� � ������� ������ � ������ ������� ��� ��������� ��������� ������ //\\//\\ 
	if (n != 0)						//���� �� ���������� ������
	{
		m.push_back(n);                       //��������� � �����
		makeVectorFromTree(n->Left, m);      //�� ����� �������
		makeVectorFromTree(n->Right, m);    //�� ������ �������
	}
}

void Tree::remake() {              //\\//\\ //������� ��� �������� ������ ������ //\\//\\   
	Tree tree;                                   //����� ������
	vector<Data*> mas;                          //������ ��� ������
	makeVectorFromTree(Root, mas);			   //������� ������ � ������
	for (int i = 0; i < mas.size(); i++)      //������ �� �������
	{
		tree.addByYear(mas[i]);             //��������� ������ � ������� � �������� � �������
	}
	delTree();                            //������� ������
	*this = tree;                        //��������� ������ � ����� Tree

	cout << "�����! �������� ������� ������ ���� ���������! �������� �������� ������ ���� ������������!\n\n��� �������� � ���� ������� ����� �������...";
}

void Tree::save(Data* n, string name) {				//\\//\\ ����-� ������ � ���� //\\//\\ 
	if (n != 0)		//���� �� ���������� ������
	{
		ofstream fout;												//�������� �����
		if (fout.fail()) cout << "������! ���� �� ������!";        //���� �� ��������
		fout.open(name, ios::app);                                //��� ������ � �����
		fout << n->year << endl << n->kol << endl << n->name << endl;   //���������� ����� ������
		fout.close();                                           //���������
		save(n->Left, name);                                   //��������� ��� ������ ��������
		save(n->Right, name);                                 //��������� ��� ������� ��������
	}
}

void Tree::saveToFile(string name) {        //\\//\\ //������������� ������� ��� ������ � ���� //\\//\\ 
	ofstream fout;                                        //�������� �����
	if (fout.fail()) cout << "������! ���� �� ������!";  //���� �� ��������
	fout.open(name, ios::out);
	fout.close();
	save(Root, name);                                 //������� � ������� �� ���������� � ����
}

void Tree::read(Data* n, string name) {            //\\//\\ ����-� ������ � ����� //\\//\\ 
	ifstream fin;                            //���� �� ����
	fin.open(name);							//��������� ���� 
	if (fin.fail()) cout << "������! ���� �� ������!";  //���� �� ��������
	char buf[255];						  //������� �������� ���������� ��� �������� ������ � �����
	int y, k, i = 1;
	string nam;
	while (fin)
	{
		fin.getline(buf, 255);
		if (i % 3 == 1)
		{
			k = atoi(buf);
			i++;
		}
		else if (i % 3 == 2)
		{
			y = atoi(buf);
			i++;
		}
		else
		{
			nam = string(buf);
			i++;
			add(nam, y, k);
		}
	}
	fin.close();
}

void Tree::readFromFile(string name) {    //\\//\\ ������������� ������� ��� ������ � ����� //\\//\\ 
	read(Root, name);
}
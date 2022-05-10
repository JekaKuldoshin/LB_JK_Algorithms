#include "list.h"

stack::~stack()                //\\//\\ ���� //\\//\\ 
{
	if (!isEmpty()) {
		obj* temp = top;              //��������� �� ����
		while (temp->next) {         //������� � ����������
			temp = temp->next;      //������� � ����������
			delete top;            //������� ����
			top = temp;
		}
		top = temp;
		delete top;            //��������
	}
}

bool stack::check() {        //\\//\\ ����-� �������� �� ������� ��������� ������ //\\//\\ 
	if (top==NULL) {        //���� ���� ����, �� �������...
		system("cls");
		cout << "������! ���� �����������!!!\n\n������� �� Enter ����� ����������...";
		_getch();
		return false;
	}
	else
		return true;     //���� ���������� True, �� �� ����� ������������ ���� ������������ ���������
}

bool stack::isEmpty()       //�������� �� �������
{
	if (top)
		return 0;
	else
		return 1;
}

void stack::create(int num) {       //\\//\\ ����-� ��� �������� ������ //\\//\\ 
	int a = 1;     //������� ���������
	char d;     //���������� ��� �����
	for (int i = 0; i < num; i++) {
		cout << "������� ������ ��� " << a++ << " ������� �������� ����� -> ";
		cin >> d;
		push(d);    //������� � ����-� ���������� ��������� � ����� ������
	}
	a = 0;
	system("cls");
}

void stack::push(char d)     //\\//\\ ����-� ��� ������ ����� //\\//\\ 
{
	obj* temp = new obj;          //������� ���������
	temp->data = d;              //������ ��������� � data
	temp->next = top;           //��������� ��������� �� ��������� �������

	top = temp;
}

void stack::pop()         //\\//\\ ����-� ��� �������� ����� //\\//\\ 
{
	if (!top) return;      //���� ������ �� ������, �� �����

	obj* temp = top->next;      //��������� ��������� �� ��������� �������
	delete top;                //�������
	top = temp;
}

short stack::pull()  //\\//\\ ����-� ��� ����������� //\\//\\ 
{
	char data;
	obj* temp = top->next;

	data = top->data;
	delete top;
	top = temp;

	return data;
}

void stack::show()             //\\//\\ ����-� ��� ������ ����� //\\//\\ 
{
	obj* temp = top;
	cout << "����: ";
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	cout << "\n��� ����������� ������� ����� �������...";
	_getch();
}

void stack::swapTopTail()           //\\//\\ ����-� ��� ������ ������ � ������ //\\//\\ 
{
	if (!top->next)               //���� ���� �������
		return;

	if (!top->next->next) {     //���� ��� ��������
		char s1 = pull();
		char s2 = pull();
		push(s1);
		push(s2);
		return;
	}

	else {
		char first = pull();              //�������� ������ �������
		obj* temp = top;                 //������ �� �������� ������ 
		short count = 0;                //���������� ��� ������ � �������� � ������� ���-�� ���������
		while (temp->next) {           //������� �� ������
			count++;                  //�������
			temp = temp->next;
		}
		char* arr = new char[count];        //������ ������ ��� ������

		for (short i = 0; i < count; i++) {      //������ �� ���-�� ��������� �� ������
			arr[i] = pull();                    //���������� � ������
		}
		char last = pull();                   //������� ���������� ������� 
		push(first);                         //������� ������

		for (short i = count - 1; i >= 0; i--) {    //������ �� ���-�� �������� �� ���� ���������
			push(arr[i]);                          //������� ������� ����� ���� ��� �������� ��������� ������� �� ������ �����
		}

		push(last);                             //������� ���������� ��������
	}
}

void stack::reverse()                    //\\//\\ ����-� ��������������� ����� //\\//\\ 
{
	obj* temp = top;                       //��������� �� ������
	short count = 0;                      //���������� ��� �������� ���-�� ���������
	while (temp) {                       //���� ���� ���� ������
		count++;                        //�������
		temp = temp->next;             //�������
	}
	short* arr = new short[count];               //������� ������ � ���-��� ��������� �����
	for (short i = 0; i < count; i++)           
		arr[i] = pull();                       //���������� �� �����
	for (short i = 0; i < count; i++)
		push(arr[i]);                        //� ������� �������� � ����
}

void stack::delEvery2()              //\\//\\ �������� ������� ������� �������� //\\//\\ 
{
	obj* temp = top;                  //��������� �� ������
	stack tempSt;                    //��������� ����������
	while (!isEmpty()) {            //���� �� ���� ����
		tempSt.push(pull());       //�������� � ��������� tempSt
		pop();                    //�������
	}
	while (!tempSt.isEmpty())          //���� �� ���� ����� ���� 
		push(tempSt.pull());          //���������� � ������ ����� � ��������� � ��������
}

void stack::putInStar()        //\\//\\ ����-� ���������� ������ � �������� //\\//\\ 
{
	obj* temp = top;                     //������ �� ������
	int count = 0;                      //��� ��������
	while (temp)                       //���� ��� ������� ������
	{
		count++;                     //�������
		temp = temp->next;          //�������
	}
	temp = top;                   //����������� ������
	if (count % 2 == 0) {                         //���� ������
		for (int i = 0; i < count / 2; i++) {    //���-�� ����� �� 2 ��� ���� ���� ������ ��������
			cout << temp->data << " ";          //������� ������
			temp = temp->next;                 //������� � ����������
		}
		cout << '*' << ' ';                  //������� ������

		while (temp) {                     //���� �� ���������� ������
			cout << temp->data << " ";    //�����
			temp = temp->next;           //�������
		}

	}
	else {                                              //���� ��������
		for (int i = 0; i < count / 2 + 1; i++) {      //����� �� 2 ��� ���� ���� ������ �������� + 1 ��� ���� ���� ����� ������ �������� ��� ���������
			cout << temp->data << " ";                //�������
			temp = temp->next;                       //�������
		}
		cout << '*' << ' ';                        //����� ������

		while (temp) {                           //���� ������ �� ����������
			cout << temp->data << " ";          //�����
			temp = temp->next;                 //�������
		}
	}
	cout << endl;

	cout << "\n��� ����������� ������� ����� �������...";
	_getch();
}


void stack::findMaxPutInZero()              //\\//\\ ����-� ��� ���������� ������������� � ������� ���� //\\//\\ 
{
	if (!isEmpty()) {                             //���� ���� �� ����
		stack newStack;                          //������� ����� ����
		int size = 0, count = 1;                //���������� ��� ���������� ���� ������� "0"
		char max = top->data;                  //������ ������ ������������� �������� ��� ����������� �����������
		while (!isEmpty()) {                  //���� ����� �������� ���� ����� �� ����
			size++;
			if (max < top->data) {          //����������� ���� < ���������
				max = top->data;           //������������
				count = size;             
			}
			newStack.push(pull());       //�������� � �������� � ����� ����

		}
		for (int i = 0; i < size - count; i++) {         //���� ����� �������� �� ����� ��� ����� �������� "0"
			push(newStack.pull());                      //�������� � ������ ����� � �������� � ���������
		}
		
		push(newStack.pull());                        //������� ������������ �����
		push('0');                                   //��������� "0"
		while (!newStack.isEmpty())                 //���� �� ������ �� �����
			push(newStack.pull());                 //������� � ������� � ����������� ����
	}
}

void stack::delMin() {                      //\\//\\ ����-� ���������� � �������� ������������ �������� ����� //\\//\\ 

	if (!isEmpty()) {                            //���� ���� �� ����
		stack newStack;                         //������� ����� ����
		int size = 0, count = 0;
		char min = top->data;                  //���������� � ����������� ���������
		while (!isEmpty()) {                  //���� ����� �� ����
			if (min > top->data) {           //���� ���. > data 
				min = top->data;            //�� ����� �����������
				count = size;              //��������� ��������� ����� ��������
			}
			newStack.push(pull());       //���������� � �������� ����� ����
			size++;                    
		}
		for (int i = 0; i < size - count; i++) {          //���� �� ����� ������� ����� �������
			push(newStack.pull());                       //���������� � ������ ����� � �����������
		}
		pop();                                         //������� ����������� �������
		while (!newStack.isEmpty())                   //���� �� ������ �� �����
			push(newStack.pull());                   //���������� � ������ ����� � �����������
	}
}

void stack::delTail() {                //\\//\\ ����-� �������� ���� ��������� ����� ���������� //\\//\\ 

	char temp = pull();              //���������� ������
	while (!isEmpty())              //���� �� ������ �� �����
		pop();                     //�������
	push(temp);                   //��������� ��������� �������
}

void stack::delHead() {           //\\//\\ ����-� �������� ���� ��������� ����� ������� //\\//\\ 

	while (top->next)          //���� ���������� � �� �����
		pop();                //������� ��� ��������
}

void stack::saveInFile() {           //\\//\\ ����-� ������ � ���� //\\//\\

	obj* temp = top;

	fstream f("Stack.txt", ios::out);        //������� ���������� ��� ������ � ������, ������� ����.
	if (!f.is_open())                           //�������� �� �������� �����
		cout << "������! ���� �� ������!";
	else {
		while (temp) {                       //���� ���� �� ������ �� �����
			f << temp->data << '\t';        //������ ������ ������ � ����
			temp = temp->next;             //��� ������
		}
	}

}

void stack::form_the_file() {                   //\\//\\ ����-� ������ � ����� //\\//\\ 
	
	char a;
	fstream f("Stack.txt", ios::in);   //���������� ��� ������ � ������, ������� ����
	if (!f.is_open())                     //�������� �� �������� �����
		cout << "������! ���� �� ������!";
	else {
		while (f >> a) {
			if (a != ' ')
				push(a);
		}
	}
	reverse();
		f.close();                 //������� ����

	}
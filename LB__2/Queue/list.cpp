#include "list.h"

bool queue::check() {        //\\//\\ ����-� �������� �� ������� ��������� ������� //\\//\\ 
	if (first == NULL) {        //���� ���� ����, �� �������...
		system("cls");
		cout << "������! ������� �����������!!!\n\n������� �� Enter ����� ����������...";
		_getch();
		return false;
	}
	else
		return true;     //���� ���������� True, �� �� ����� ������������ ���� ������������ ���������
}

void queue::create(int num) {       //\\//\\ ����-� ��� �������� ������ //\\//\\ 
	int a = 1;     //������� ���������
	char d;     //���������� ��� �����
	for (int i = 0; i < num; i++) {
		cout << "������� ������ ��� " << a++ << " ������� �������� ����� -> ";
		cin >> d;
		Add(d);    //������� � ����-� ���������� ��������� � ����� ������
	}
	a = 0;
	system("cls");
}

void queue::Add(char a) {
    obj* temp = new obj;
    temp->data = a;
    if (!first) {
        first = temp;
        tail = first;
    }
    else {
        tail->prev = temp;
        tail = temp;
    }
    temp->prev = NULL;
}

void queue::show()             //\\//\\ ����-� ��� ������ ����� //\\//\\ 
{
	obj* temp = first;
	cout << "�������: ";
	while (temp) {
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
	cout << "\n��� ����������� ������� ����� �������...";
	_getch();
}

int queue::count()
{
	int count = 0;
	obj* temp = first;
	while (temp) {
		count++;
		temp = temp->prev;
	}
	return count;
}

double queue::average()
{
	char avarage = ' ';
	obj* temp = first;
	while (temp) {
		avarage += temp->data;
		temp = temp->prev;
	}
	return avarage / count();
}

char queue::Max()
{
	char max = first->data;
	obj* temp = first->prev;
	while (temp) {
		if (max < temp->data)
			max = temp->data;
		temp = temp->prev;
	}

	return max;
}

char queue::Min()
{
	char min = first->data;
	obj* temp = first->prev;
	while (temp) {
		if (min > temp->data)
			min = temp->data;
		temp = temp->prev;
	}

	return min;
}

char queue::prevMin()
{
	char prevMin;
	obj* temp = first;
	if (Min() == first->data)
		return Min();
	while (temp) {

		if (temp->prev->data == Min())
			return temp->data;
		temp = temp->prev;
	}

}

void queue::saveInFile() {           //\\//\\ ����-� ������ � ���� //\\//\\

	obj* temp = first;

	fstream f("Queue.txt", ios::out);        //������� ���������� ��� ������ � ������, ������� ����.
	if (!f.is_open())                           //�������� �� �������� �����
		cout << "������! ���� �� ������!";
	else {
		while (temp) {                       //���� ���� �� ������ �� �����
			f << temp->data << '\t';        //������ ������ ������ � ����
			temp = temp->prev;             //��� ������
		}
	}

}

void queue::form_the_file() {                   //\\//\\ ����-� ������ � ����� //\\//\\ 

	char a;
	fstream f("Queue.txt", ios::in);   //���������� ��� ������ � ������, ������� ����
	if (!f.is_open())                     //�������� �� �������� �����
		cout << "������! ���� �� ������!";
	else {
		while (f >> a) {
			if (a != ' ')
				Add(a);
		}
	}
	f.close();                 //������� ����

}
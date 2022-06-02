#pragma once
#include "DirectAddressing.h"

int DirectHashTable::hashCode(int k) {
	double a = (sqrt(5) - 1) / 2;
	double c = (k * a);
	return fmod(c, 1) * length;

	//return k % length;
}

void DirectHashTable::insert(int data) {
	bool Notpresent = true;

	Data_direct n(hashCode(data), data, false);
	int h = hashCode(data);
	for (int i = h; i < length; i++)
	{
		if (arr[i].data == data) {
			Notpresent = false;
		}

	}
	if (!Notpresent) {
		system("cls");
		cout << "Элемент уже существует в данной хэш-таблице!" << endl;
		_getch();
		return;
	}

	for (int i = h; i < length; i++)
	{
		if (!arr[i].contains)
		{
			arr[i] = n;
			arr[i].contains = true;
			full++;
			break;
		}
	}
	Check();
}
void DirectHashTable::display() {

	cout << "\n\tID";
	cout << " \tDATA ";

	for (int i = 0; i < length; i++) {
		if (arr[i].data != 0) {
			cout << "\n\t"
				<< arr[i].key
				<< " \t"
				<< arr[i].data;
		}
	}
}

void DirectHashTable::Search(int data) {
	int h = hashCode(data);
	int key, flag = 0;

	if (arr[h].data == data) {
		flag = 1;
		system("cls");
		cout << "\nЗапись найдена:";
		cout << "\n\tID ";
		cout << "\tDATA ";
		cout << "\n\t"
			<< arr[h].key
			<< " \t"
			<< arr[h].data;
		_getch();
		return;
	}
	for (int i = h; i < length; i++)
	{
		if (arr[i].data == data)
		{
			flag = 1;
			system("cls");
			cout << "\nЗапись найдена:";
			cout << "\n\tID ";
			cout << "\tDATA ";
			cout << "\n\t"
				<< arr[i].key
				<< " \t"
				<< arr[i].data;
			_getch();
			return;
		}
	}

	if (flag == 0) {
		system("cls"); cout << "Ошибка! Данные были не найдены!\n\nДля перехода в меню нажмите любую клавишу..."; _getch();
	}

}
void DirectHashTable::Delete(int data) {
	int flag = 0;
	int h = hashCode(data);

	if (arr[h].data == data) {
		flag = 1;
		arr[h].key = 0;
		arr[h].data = 0;
		system("cls");
		cout << "Успех! Данные были удалены!\n\nДля перехода в меню нажмите любую клавишу...";
		_getch();
		return;
	}
	for (int i = h; i < length; i++)
	{
		if (arr[i].data == data)
		{
			flag = 1;
			arr[i].key = 0;
			arr[i].data = 0;
			system("cls");
			cout << "Успех! Данные были удалены!\n\nДля перехода в меню нажмите любую клавишу...";
			_getch();
			return;
		}
	}
	if (flag == 0) {
		system("cls"); cout << "Ошибка! Данные были не найдены!\n\nДля перехода в меню нажмите любую клавишу..."; _getch();

	}
}

void  DirectHashTable::from_file() {
	ifstream in;
	//in.open("DirectHash.txt");
	in.open("HashTable.txt");
	if (in.fail()) cout << "ERROR opening file";
	int d;
	while (in >> d)
	{
		insert(d);
	}
	in.close();
}

void DirectHashTable::Check() {
	if ((full * 100 / length) >= 70)
	{
		Resize();
	}
}

void DirectHashTable::Resize() {
	DirectHashTable temp(length + 10);
	for (int i = 0; i < length; i++)
	{
		if (arr[i].contains)
		{
			temp.insert(arr[i].data);
		}
	}
	length += 10;
	arr = new Data_direct[length];
	for (int i = 0; i < length; i++)
	{
		arr[i] = temp.arr[i];
	}
	temp = NULL;
}
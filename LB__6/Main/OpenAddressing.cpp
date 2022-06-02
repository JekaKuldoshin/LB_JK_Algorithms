#pragma once
#include "OpenAddressing.h"

void OpenHashTable::insert(int data) {
	for (int i = 0; i < length; i++) {
		int hash = i % length;
		if (!arr[hash].contains) {
			arr[hash].data = data;
			arr[hash].key = hash;
			arr[hash].contains = true;
			full++;
			break;
		}
	}
	if ((full * 100 / length) >= 70)
	{
		Resize();
	}
}
void OpenHashTable::display() {

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

void OpenHashTable::Search(int key) {

	int flag = 0;

	for (int i = 0; i < length; i++)
	{
		int hash = i % length;
		if (arr[hash].key == key) {
			flag = 1;
			system("cls");
			cout << "\nЗапись найдена:";
			cout << "\n\tID ";
			cout << "\tDATA ";
			cout << "\n\t"
				<< arr[hash].key
				<< " \t"
				<< arr[hash].data;
			_getch();
			return;
		}
	}

	if (flag == 0) {
		system("cls"); cout << "Ошибка! Данные были не найдены!\n\nДля перехода в меню нажмите любую клавишу..."; _getch();
	}

}
void OpenHashTable::Delete(int key) {
	int flag = 0;

	for (int i = 0; i < length; i++)
	{
		int hash = i % length;
		if (arr[hash].key == key) {
			flag = 1;
			arr[hash].key = 0;
			arr[hash].data = 0;
			arr[hash].contains = false;
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

void  OpenHashTable::from_file() {
	ifstream in;
	in.open("HashTable.txt");
	if (in.fail()) cout << "ERROR opening file";
	int d;
	while (in >> d)
	{
		insert(d);
	}
	in.close();
}

void OpenHashTable::Check() {
	if ((full * 100 / length) >= 70)
	{
		Resize();
	}
}

void OpenHashTable::Resize() {
	OpenHashTable temp(length + 10);
	for (int i = 0; i < length; i++)
	{
		if (arr[i].contains)
		{
			temp.insert(arr[i].data);
		}
	}
	length += 10;
	arr = new Data_openAddress[length];
	for (int i = 0; i < length; i++)
	{
		arr[i] = temp.arr[i];
	}
	temp = NULL;
}
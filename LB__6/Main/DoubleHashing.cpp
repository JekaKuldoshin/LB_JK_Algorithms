#pragma once
#include "DoubleHashing.h"

void DoubleHashTable::insert(int data) {
	for (int i = 0; i < length; i++) {
		int hash = (data % length + i * (1 + (data % (length - 1)))) % length;
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
void DoubleHashTable::display() {

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

void DoubleHashTable::Search(int key) {

	int flag = 0;

	for (int i = 0; i < length; i++)
	{
		int hash = (key % length + i * (1 + (key % (length - 1)))) % length;
		if (arr[hash].key == key) {
			flag = 1;
			system("cls");
			cout << "\n������ �������:";
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
		system("cls"); cout << "������! ������ ���� �� �������!\n\n��� �������� � ���� ������� ����� �������..."; _getch();
	}

}
void DoubleHashTable::Delete(int key) {
	int flag = 0;

	for (int i = 0; i < length; i++)
	{
		int hash = (key % length + i * (1 + (key % (length - 1)))) % length;
		if (arr[hash].key == key) {
			flag = 1;
			arr[hash].key = 0;
			arr[hash].data = 0;
			arr[hash].contains = false;
			system("cls");
			cout << "�����! ������ ���� �������!\n\n��� �������� � ���� ������� ����� �������...";
			_getch();
			return;
		}
	}

	if (flag == 0) {
		system("cls"); cout << "������! ������ ���� �� �������!\n\n��� �������� � ���� ������� ����� �������..."; _getch();

	}
}

void  DoubleHashTable::from_file() {
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

void DoubleHashTable::Check() {
	if ((full * 100 / length) >= 70)
	{
		Resize();
	}
}

void DoubleHashTable::Resize() {
	DoubleHashTable temp(length + 10);
	for (int i = 0; i < length; i++)
	{
		if (arr[i].contains)
		{
			temp.insert(arr[i].data);
		}
	}
	length += 10;
	arr = new Data_doubleHash[length];
	for (int i = 0; i < length; i++)
	{
		arr[i] = temp.arr[i];
	}
	temp = NULL;
}
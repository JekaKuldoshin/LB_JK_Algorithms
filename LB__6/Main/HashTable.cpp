#include "HashTable.h"

void HashTable::create_record(int i, int n) {
	index = i % size;

	bool Notpresent = true;

	for (int j = 0; j < size; j++) {
		if (data[i].num == n) {
			Notpresent = false;
		}
	}

	if (!Notpresent) {
		system("cls");
		cout << "Элемент уже существует в данной хэш-таблице!" << endl;
		_getch();
		return;
	}

	for (int j = 0; j < size; j++) {
		if (data[index].id == 0) {
			data[index].id = i;
			data[index].num = n;
			break;
		}
		else {
			index = (index + 1) % size;
		}
	}
}

void HashTable::delete_record(int i) {
	int flag = 0;
	index = i % size;
	for (int j = 0; j < size; j++) {
		if (i == data[index].num) {
			flag = 1;
			data[index].id = 0;
			data[index].num = 0;
			system("cls");
			cout << "Успех! Данные были удалены!\n\nДля перехода в меню нажмите любую клавишу...";
			_getch();
			break;
		}
		else {
			index = (index + 1) % size;
		}
	}

	for (int i = index; i < size; i++)
	{
		if (data[i].num == i)
		{
			flag = 1;
			data[i].id = 0;
			data[i].num = 0;
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

void HashTable::modify_record(int old_id, int new_id, int n) {
	index = old_id % size;
	int flag = 0;
	for (int j = 0; j < size; j++) {
		if (old_id == data[index].num) {
			flag = 1;
			data[index].id = new_id;
			data[index].num = n;
			system("cls");
			cout << "Успех! Данные были модорнизированы!\n\nДля перехода в меню нажмите любую клавишу...";
			_getch();
			break;
		}
		else {
			index = (index + 1) % size;
		}
	}

	for (int i = index; i < size; i++)
	{
		if (data[i].num == i)
		{
			flag = 1;
			data[i].id = new_id;
			data[i].num = n;
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


void HashTable::search()
{
	int index1, num, flag = 0;

	cout << "\nВведите DATA для поиска -> ";
	cin >> num;
	index1 = num % size;

	for (int i = 0; i < size; i++) {
		if (data[index1].num == num) {
			flag = 1;
			system("cls");
			cout << "\nЗапись найдена:";
			cout << "\n\tID ";
			cout << "\tDATA ";
			cout << "\n\t"
				<< data[index1].id
				<< " \t"
				<< data[index1].num;
			break;
		}
		else
			index1 = (index1 + 1) % size;
	}

	for (int i = index1; i < size; i++)
	{
		if (data[i].num == num)
		{
			flag = 1;
			system("cls");
			cout << "\nЗапись найдена:";
			cout << "\n\tID ";
			cout << "\tDATA ";
			cout << "\n\t"
				<< data[i].id
				<< " \t"
				<< data[i].num;
			return;
		}
	}
	if (flag == 0) {
		system("cls"); cout << "Ошибка! Данные были не найдены!\n\nДля перехода в меню нажмите любую клавишу..."; _getch();
	}
}

void HashTable::display()
{
	cout << "\n\tID";
	cout << " \tDATA ";

	for (int i = 0; i < size; i++) {
		if (data[i].id != 0) {
			cout << "\n\t"
				<< data[i].id
				<< " \t"
				<< data[i].num;
		}
	}
}

void HashTable::from_file() {
	int i = 0;
	ifstream in;
	in.open("HashTable.txt");
	if (in.fail()) cout << "ERROR opening file";
	int d;
	while (in >> d)
	{
		create_record(i, d);
		i++;
	}
	in.close();
}
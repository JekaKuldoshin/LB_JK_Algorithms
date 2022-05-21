#include <iostream>
#include "BinaryTree.h"
#include "RBTree.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);            //Руссификатор для ввода
	SetConsoleOutputCP(1251);     //Руссификатор для вывода

	Tree t;           //Локальная переменная для работы с классом
	RBTree rb;

	int year, num;         //Переменные для ввода
	string name;

	int menu;           //Для меню

	while (true) {            // Цикл для меню
		system("cls");
		cout << "                                                          Меню                                                          |" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "1 - Создание / добавление элементов бинарного дерева       | 9 - Создание второго дерева, изменение ключевой переменной |" << endl;
		cout << "2 - Вывод дерева...                                        | 10 - Добавить данные во второе дерево                      |" << endl;
		cout << "3 - Печать при прямом обходе                               | 11 - Раскрасить дерево в R/B                               |" << endl;
		cout << "4 - Печать при обратном обходе                             | 12 - Добавление данных в R/B дерево                        |" << endl;
		cout << "5 - Печать при симметричном обходе                         | 13 - Удаление узла бинарного дерева R/B                    |" << endl;
		cout << "6 - Удаление дерева...                                     | 14 - Запись дерева в файл                                  |" << endl;
		cout << "7 - Удаление левого поддерева и обнуление левой иголки     | 15 - Создание нового дерева из файла                       |" << endl;
		cout << "8 - Удаление правого поддерева и обнуление правой иголки   |                                                            |" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "                                                        16 - Выход                                                      |" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "Сделайте свой выбор -> ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			system("cls");
			cout << "Создание / добавление элементов бинарного дерева |" << endl;
			cout << "-------------------------------------------------|\n\n";
			cout << "Введите название научного журнала - > "; cin >> name;
			cout << "Введите год выпуска -> "; cin >> year;
			cout << "Введите количество номеров -> "; cin >> num;
			t.add(name, year, num);
			system("cls");
			t.show();
			cout << "\n\nНажмите на Enter чтобы продолжить...";
			_getch();
			break;
		case 2:

			system("cls");
			cout << "Вывод дерева           |" << endl;
			cout << "-----------------------|\n";
			cout << "1 - Вывод бинарного    |" << endl;
			cout << "2 - Вывод R/B          |" << endl;
			cout << "-----------------------|\n\n";
			cout << "Сделайте свой выбор -> ";
			cin >> menu;
			switch (menu) {
			case 1:
				if (t.check() == true) {
					system("cls");
					cout << "Вывод бинарного дерева |" << endl;
					cout << "-----------------------|\n";
					t.show();
					cout << "\n\nНажмите на Enter чтобы продолжить...";
					_getch();
				}
				break;
			case 2:
				system("cls");
				if (rb.checkRB() == true) {
					cout << "Вывод R/B дерева |" << endl;
					cout << "-----------------|\n";
					rb.p();
					cout << "\n\nНажмите на Enter чтобы продолжить...";
					_getch();
				}
				break;
			default:
				system("cls");
				cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... ";
				_getch();
				break;
			}
			break;
		case 3:
			if (t.check() == true) {
				t.showPreOrder();
				cout << endl;
				t.show();
				cout << "\n\nНажмите на Enter чтобы продолжить...";
				_getch();
			}
			break;
		case 4:
			if (t.check() == true) {
				t.showPostOrder();
				cout << endl;
				t.show();
				cout << "\n\nНажмите на Enter чтобы продолжить...";
				_getch();
			}
			break;
		case 5:
			if (t.check() == true) {
				t.showSymm();
				cout << endl;
				t.show();
				cout << "\n\nНажмите на Enter чтобы продолжить...";
				_getch();
			}
			break;
		case 6:
			system("cls");
			cout << "Удаление дерева        |" << endl;
			cout << "-----------------------|\n";
			cout << "1 - Удаление бинарного |" << endl;
			cout << "2 - Удаление R/B       |" << endl;
			cout << "-----------------------|\n\n";
			cout << "Сделайте свой выбор -> ";
			cin >> menu;
			switch (menu) {
			case 1:
				if (t.check() == true) {
					system("cls");
					t.delTree();
					cout << "Успех! Удаление бинарного дерева было выполнено!\n\nДля перехода в меню нажмите любую клавишу...";
					_getch();
				}
				break;
			case 2:
				if (rb.checkRB() == true) {
					system("cls");
					rb.~RBTree();
					cout << "Успех! Удаление R/B дерева было выполнено!\n\nДля перехода в меню нажмите любую клавишу...";
					_getch();
				}
				break;
			default:
				system("cls");
				cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... ";
				_getch();
				break;
			}
			break;
		case 7:
			if (t.check() == true) {
				system("cls");
				t.delLeftTree();
				cout << "Успех! Удаление левого поддерева было выполнено!\n\nДля перехода в меню нажмите любую клавишу...";
				_getch();
			}
			break;
		case 8:
			if (t.check() == true) {
				system("cls");
				t.delRightTree();
				cout << "Успех! Удаление правого поддерева было выполнено!\n\nДля перехода в меню нажмите любую клавишу...";
				_getch();
			}
			break;
		case 9:
			if (t.check() == true) {
				system("cls");
				t.remake();
				_getch();
			}
			break;
		case 10:
			if (t.check() == true) {
				system("cls");
				cout << "Добавить данные во второе дерево |" << endl;
				cout << "---------------------------------|\n\n";
				t.show();
				cout << "\nВведите название научного журнала - > "; cin >> name;
				cout << "Введите год выпуска -> "; cin >> year;
				cout << "Введите количество номеров -> "; cin >> num;
				t.add_by_y(name, year, num);
				system("cls");
				cout << "Успех! Добавление данных было выполнено!\n\nДля перехода в меню нажмите любую клавишу...";
				_getch();
			}
			break;
		case 11:
			if (t.check() == true) {
				system("cls");
				rb.makeRB(t);
				cout << "Успех! Раскраска дерева в R/B было выполнено!\n\nДля перехода в меню нажмите любую клавишу...";
				_getch();
			}
			break;
		case 12:
			system("cls");
			cout << "Добавление данных в R/B дерево |" << endl;
			cout << "-------------------------------|\n\n";
			rb.p();
			cout << "\nВведите название научного журнала - > "; cin >> name;
			cout << "Введите год выпуска -> "; cin >> year;
			cout << "Введите количество номеров -> "; cin >> num;
			rb.insert(year, num, name);
			system("cls");
			cout << "Успех! Добавление данных в R/B дерево было выполнено!\n\nДля перехода в меню нажмите любую клавишу...";
			_getch();
			break;
		case 13:
			if (rb.checkRB() == true) {
				system("cls");
				cout << "Удаление узла бинарного дерева R/B |" << endl;
				cout << "-----------------------------------|\n\n";
				rb.p();
				cout << "\nВведите название научного журнала - > "; cin >> name;
				cout << "Введите год выпуска -> "; cin >> year;
				cout << "Введите количество номеров -> "; cin >> num;
				rb.remove(year, num, name);
				system("cls");
				cout << "Успех! Удаление узла в R/B дереве было выполнено!\n\nДля перехода в меню нажмите любую клавишу...";
				_getch();
			}
			break;
		case 14:
			if (t.check() == true) {
				system("cls");
				t.saveToFile("BinaryTree.txt");
				cout << "Успех! Данные были записаны в файл!\n\nДля перехода в меню нажмите любую клавишу...";
				_getch();
			}
			break;
		case 15:
			system("cls");
			t.readFromFile("BinaryTree.txt");
			cout << "Успех! Данные были записаны в бинарное дерево!\n\nДля перехода в меню нажмите любую клавишу...";
			_getch();
			break;
		case 16:                  //\\ //\\ Выход //\\ //\\ 
			system("cls");
			cout << "Thanks for your attention!!" << endl << endl;
			return 0;
			break;
		default:                   //\\ //\\ Обработка не правильных введеных значений //\\ //\\ 
			system("cls");
			cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... ";
			_getch();
			break;
		}
	}

	return 0;
}
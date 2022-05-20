#include <iostream>
#include "BinaryTree.h"
#include "RBTree.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);            //Руссификатор для ввода
	SetConsoleOutputCP(1251);     //Руссификатор для вывода

	Tree t;
	RBTree rb;

	int menu;       //Переменные для меню
	int num, g;
	string name;

	while (true) {            // Цикл для меню
		system("cls");
		//t.show();
		//cout << endl << endl;
		//rb.p();

		cout << "                                                          Меню                                                          |" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "1 - Создание / добавление элементов бинарного дерева       | 9 - Создание второго дерева, изменение ключевой переменной |" << endl;
		cout << "2 - Вывод дерева.....                                      | 10 - Добавить данные во второе дерево                      |" << endl;
		cout << "3 - Печать при прямом обходе                               | 11 - Раскрасить дерево в R/B                               |" << endl;
		cout << "4 - Печать при обратном обходе                             | 12 - Добавление данных в R/B дерево                        |" << endl;
		cout << "5 - Печать при симетричном обходе                          | 13 - Удаление бинарного дерева R/B                         |" << endl;
		cout << "6 - Удаление дерева                                        | 14 - Запись дерева в файл                                  |" << endl;
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
			cout << "Введите год выпуска -> "; cin >> num;
			cout << "Введите количество номеров -> "; cin >> g;
			t.add(name, num, g);
			system("cls");
			t.show();
			break;
		case 2:
			cout << "Вывод бинарного дерева |" << endl;
			cout << "-----------------------|\n\n";
			t.show();
			cout << endl << endl;
			rb.p();

			break;
		case 3:
			t.showPreOrder();
			t.show();
			_getch();
			break;
		case 4:
			t.showPostOrder();
			_getch();
			break;
		case 5:
			t.showSymm();
			_getch();
			break;
		case 6:
			t.delTree();
			_getch();
			break;
		case 7:
			t.delLeftTree();
			_getch();
			break;
		case 8:
			t.delRightTree();
			_getch();
			break;
		case 9:
			t.remake();
			_getch();
			break;
		case 10:
			cout << "Enter name: "; cin >> name;
			cout << "Enter number: "; cin >> num;
			cout << "Enter group: "; cin >> g;
			t.addByN(name, num, g);
			_getch();
			break;
		case 11:
			rb.makeRB(t);
			_getch();
			break;
		case 12:
			cout << "Enter name: "; cin >> name;
			cout << "Enter number: "; cin >> num;
			cout << "Enter group: "; cin >> g;
			rb.insert(num, g, name);
			_getch();
			break;
		case 13:
			cout << "Enter name: "; cin >> name;
			cout << "Enter number: "; cin >> num;
			cout << "Enter group: "; cin >> g;
			rb.remove(num, g, name);
			_getch();
			break;
		case 14:
			t.saveToFile("1.txt");
			cout << "Saved" << endl;
			_getch();
			break;
		case 15:
			t.readFromFile("1.txt");
			_getch();
			break;
		case 16:                  //\\ //\\ Выход //\\ //\\ 
			system("cls");
			cout << "Thanks for your attention!!" << endl << endl;
			return 0;
			break;
		default:                   //\\ //\\ Обработка не правильных введеных значений //\\ //\\ 
			system("cls");
			cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... " << endl;
			_getch();
			break;
		}
	}

	return 0;
}
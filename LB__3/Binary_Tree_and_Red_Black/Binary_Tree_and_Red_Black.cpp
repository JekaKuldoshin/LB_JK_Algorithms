#include "BinaryTree.h"
#include "RBTree.h"

int main()
{
	SetConsoleCP(1251);            //Руссификатор для ввода
	SetConsoleOutputCP(1251);     //Руссификатор для вывода

	Tree t;
	RBTree rb;

	int menu;       //Переменные для меню
	int year, num;
	string name;

	while (true) {            // Цикл для меню
		system("cls");
		//t.show();
		//cout << endl << endl;
		//rb.p();

		cout << "                                                          Меню                                                          |" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "1 - Создание / добавление элементов бинарного дерева       | 9 - Создание второго дерева, изменение ключевой переменной |" << endl;
		cout << "2 - Вывод дерева...                                        | 10 - Добавить данные во второе дерево                      |" << endl;
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
			cout << "Введите год выпуска -> "; cin >> year;
			cout << "Введите количество номеров -> "; cin >> num;
			t.add(name, year, num);
			system("cls");
			t.show();
			break;
		case 2:
			if (t.check() == true) {
				system("cls");
				cout << "Вывод дерева           |" << endl;
				cout << "-----------------------|\n";
				cout << "1 - Вывод бинарного    |"<<endl;
				cout << "2 - Вывод R/B          |" << endl;
				cout << "-----------------------|\n\n";
				cout << "Сделайте свой выбор -> ";
				cin >> menu;
				switch (menu) {
				case 1:
					system("cls");
					t.show();
					break;
				case 2:
					system("cls");
					rb.p();
					_getch();
					break;
				default:
					system("cls");
					cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... ";
					_getch();
					break;
				}
			}
			break;
		case 3:
			if (t.check() == true) {
				t.showPreOrder();
				t.show();
			}
			break;
		case 4:
			if (t.check() == true) {
				t.showPostOrder();
				t.show();
			}
			break;
		case 5:
			if (t.check() == true) {
				t.showSymm();
				t.show();
			}
			break;
		case 6:
			if (t.check() == true) {
				t.delTree();
				cout << "Успех! Удаление бинарного дерева было выполнено!\n\nДля перехода в меню нажмите любую клавишу...";
				_getch();
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
				t.remake();
				_getch();
			}
			break;
		case 10:
			if (t.check() == true) {
					cout << "Введите название научного журнала - > "; cin >> name;
					cout << "Введите год выпуска -> "; cin >> year;
					cout << "Введите количество номеров -> "; cin >> num;
					t.add_by_y(name, year, num);
					_getch();
			}
			break;
		case 11:
			if (t.check() == true) {
				rb.makeRB();
				rb.p();
			_getch();
			}
			break;
		case 12:
			cout << "Введите название научного журнала - > "; cin >> name;
			cout << "Введите год выпуска -> "; cin >> year;
			cout << "Введите количество номеров -> "; cin >> num;
			rb.insert(year, num, name);
			_getch();
			break;
		case 13:
			cout << "Введите название научного журнала - > "; cin >> name;
			cout << "Введите год выпуска -> "; cin >> year;
			cout << "Введите количество номеров -> "; cin >> num;
			rb.remove(year, num, name);
			_getch();
			break;
		case 14:
			if (t.check() == true) {
				t.saveToFile("BinaryTree.txt");
				cout << "Saved" << endl;
				_getch();
			}
			break;
		case 15:
				t.readFromFile("BinaryTree.txt");
				
			
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
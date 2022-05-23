#include "Main.h"

int main(void) {
	SetConsoleCP(1251);            //Руссификатор для ввода
	SetConsoleOutputCP(1251);     //Руссификатор для вывода

	int menu;       //Переменные для меню

	while (true) {            // Цикл для меню
		system("cls");
		cout << "             Меню             |" << endl;
		cout << "------------------------------|" << endl;
		cout << "1 - Сортировка вставками      |" << endl;
		cout << "2 - Порозрядная сортировка    |" << endl;
		cout << "3 - Пирамидальная сортировка  |" << endl;
		cout << "------------------------------|" << endl;
		cout << "         4 - Выход            |" << endl;
		cout << "------------------------------|" << endl;
		cout << "Сделайте свой выбор -> ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			link_menu1:
			system("cls");
			cout << "                     Меню                   |" << endl;
			cout << "--------------------------------------------|" << endl;
			cout << "1 - Неупорядоченный массив                  |" << endl;
			cout << "2 - Упорядочнный массив                     |" << endl;
			cout << "3 - Упорядочнный массив в обратном порядке  |" << endl;
			cout << "--------------------------------------------|" << endl;
			cout << "       4 - Вернуться в главное меню         |" << endl;
			cout << "--------------------------------------------|" << endl;
			cout << "Сделайте свой выбор -> ";
			cin >> menu;

			switch (menu)
			{
			case 1:
				Fun_InsertSortRand();
				break;

			case 2:
				Fun_InsertSortUp();
				break;
				
			case 3:
				Fun_InsertSortDown();
				break;

			case 4:
				break;

			default:
				system("cls");
				cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... " << endl;
				_getch();
				goto link_menu1;
				break;
			}        
			break;
		case 2:
		link_menu2:
			system("cls");
			cout << "                     Меню                   |" << endl;
			cout << "--------------------------------------------|" << endl;
			cout << "1 - Неупорядоченный массив                  |" << endl;
			cout << "2 - Упорядочнный массив                     |" << endl;
			cout << "3 - Упорядочнный массив в обратном порядке  |" << endl;
			cout << "--------------------------------------------|" << endl;
			cout << "       4 - Вернуться в главное меню         |" << endl;
			cout << "--------------------------------------------|" << endl;
			cout << "Сделайте свой выбор -> ";
			cin >> menu;

			switch (menu)
			{
			case 1:
				Fun_RadixSortRand();
				break;

			case 2:
				Fun_RadixSortUp();
				break;

			case 3:
				Fun_RadixSortDown();
				break;

			case 4:
				break;

			default:
				system("cls");
				cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... " << endl;
				_getch();
				goto link_menu2;
				break;
			}
			break;
		case 3:
		link_menu3:
			system("cls");
			cout << "                     Меню                   |" << endl;
			cout << "--------------------------------------------|" << endl;
			cout << "1 - Неупорядоченный массив                  |" << endl;
			cout << "2 - Упорядочнный массив                     |" << endl;
			cout << "3 - Упорядочнный массив в обратном порядке  |" << endl;
			cout << "--------------------------------------------|" << endl;
			cout << "       4 - Вернуться в главное меню         |" << endl;
			cout << "--------------------------------------------|" << endl;
			cout << "Сделайте свой выбор -> ";
			cin >> menu;

			switch (menu)
			{
			case 1:
				Fun_HeapSortRand();
				break;

			case 2:
				Fun_HeapSortUp();
				break;

			case 3:
				Fun_HeapSortDown();
				break;

			case 4:
				break;

			default:
				system("cls");
				cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... " << endl;
				_getch();
				goto link_menu3;
				break;
			}
			break;
		case 4:
			return 0;
			break;
		default:
			system("cls");
			cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... " << endl;
			_getch();
			break;
		}



	}
}
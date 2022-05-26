#include "Main.h"

int main(void) {
	SetConsoleCP(1251);            //Руссификатор для ввода
	SetConsoleOutputCP(1251);     //Руссификатор для вывода

	Data d;
	int menu;       //Переменные для меню

	while (true) {            // Цикл для меню
		system("cls");
		cout << "       Меню         |" << endl;
		cout << "--------------------|" << endl;
		cout << "1 - Поиск числа     |" << endl;
		cout << "2 - Поиск строки    |" << endl;
		cout << "--------------------|" << endl;
		cout << "     3 - Выход      |" << endl;
		cout << "--------------------|" << endl;
		cout << "Сделайте свой выбор -> ";
		cin >> menu;

		switch (menu)
		{
		case 1:
		link_menu1:
			system("cls");
			cout << "                   Меню                 |" << endl;
			cout << "----------------------------------------|" << endl;
			cout << "1 - Линейный поиск                      |" << endl;
			cout << "2 - Поиск барьером                      |" << endl;
			cout << "3 - Сортировка данных + бинарный поиск  |" << endl;
			cout << "----------------------------------------|" << endl;
			cout << "     4 - Вернуться в главное меню       |" << endl;
			cout << "----------------------------------------|" << endl;
			cout << "Сделайте свой выбор -> ";
			cin >> menu;

			switch (menu)
			{
			case 1:
				Fun_line_search();
				break;

			case 2:
				Fun_barrier_search();
				break;

			case 3:
				Fun_binary_search();
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
			cout << "                   Меню                 |" << endl;
			cout << "----------------------------------------|" << endl;
			cout << "1 - Линейный поиск                      |" << endl;
			cout << "2 - Поиск барьером                      |" << endl;
			cout << "3 - Сортировка данных + бинарный поиск  |" << endl;
			cout << "----------------------------------------|" << endl;
			cout << "     4 - Вернуться в главное меню       |" << endl;
			cout << "----------------------------------------|" << endl;
			cout << "Сделайте свой выбор -> ";
			cin >> menu;

			switch (menu)
			{
			case 1:
				/*Fun_line_search();*/
				break;

			case 2:
				/*Fun_barrier_search();*/
				break;

			case 3:
				/*Fun_binary_search();*/
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
		case 3:							//\\ //\\ Выход //\\ //\\ 
			system("cls");
			cout << "Thanks for your attention!!" << endl << endl;
			return 0;
			break;

		default:
			system("cls");
			cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... ";
			_getch();
			break;
		}
	}
}
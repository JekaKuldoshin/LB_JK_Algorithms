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
		cout << "         4 - Выход           |" << endl;
		cout << "------------------------------|" << endl;
		cout << "Сделайте свой выбор -> ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			Fun_InsertSort();
			break;
		case 2:

			break;
		case 3:

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
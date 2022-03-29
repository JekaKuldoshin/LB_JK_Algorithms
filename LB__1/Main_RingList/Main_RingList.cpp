﻿#include "list.h"

int main(void) {
	SetConsoleCP(1251);            //Руссификатор для ввода
	SetConsoleOutputCP(1251);     //Руссификатор для вывода

	TList lst;
	TList LST;
	double d;

	int num = 0;
	int num2 = 0;


	int menu;       //Переменные для меню
	int menu2;

	while (true) {            // Цикл для меню
		system("cls");
		cout << "                                        Меню                                                                 |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "1 - Создание списка                      | 6 - Поменять местами два соседних элемента                        |" << endl;
		cout << "2 - Вывод списка                         | 7 - Обьеденить два списка (дописование в конец первого списка)    |" << endl;
		cout << "3 - Добавить элемент в список (в конец)  | 8 - Очистить список                                               |" << endl;
		cout << "4 - Удаление любого элемента             | 9 - Запись списка в файл                                          |" << endl;
		cout << "5 - Узнать кол-во элементов в списке     | 10 - Создание нового списка из файла                              |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "                                      11 - Выход                                                             |" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "Сделайте свой выбор -> ";
		cin >> menu;

		switch (menu)
		{
		case 1:                         //Создание списка
			system("cls");
			cout << "Какое кол-во элементов Вы хотите добавить в список?  -> ";
			cin >> num;

			lst.create(num);
			lst.show(lst.Count());
			cout << "Для продолжения нажмите любую клавишу...";
			_getch();

			system("cls");
			cout << "Успех! Данные были иннициализированны и выведены!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
			_getch();
			system("cls");
			break;

		case 2:                             //Вывод
			if (lst.check() == true) {
				system("cls");
				cout << "Вывод списка |" << endl;
				cout << "-------------|\n\n";

				lst.show(lst.Count());
				cout << "Для продолжения нажмите любую клавишу...";
				_getch();


				/*cout << "Успех! Данные были выведены!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
				_getch();*/
				system("cls");
			}
			break;

		case 3:                            //Доб. в конец
			if (lst.check() == true) {
				system("cls");
				cout << "Добавление элемента в конец списка |" << endl;
				cout << "-----------------------------------|\n\n";
				cout << "Введите данные > ";
				cin >> d;
				lst.Add(d);

				system("cls");
				cout << "Успех! Данные были добавлены в список!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
				_getch();
				system("cls");
			}
			break;

		case 4:                            //Удаление любого элемента
			if (lst.check() == true) {
				system("cls");
				cout << "Удаление элемента списка |" << endl;
				cout << "-------------------------|\n\n";

				lst.show(lst.Count());

				cout << "\nВведите номер удаляемого элемента -> ";
				cin >> num;
				lst.deleteFromList(num);

				/*system("cls");
				cout << "Успех! Удаление элемента было выполнено!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
				_getch();*/
				system("cls");
			}
			break;

		case 5:
			if (lst.check() == true) {
				system("cls");
				cout << "Узнать кол-во элементов в списке |" << endl;
				cout << "---------------------------------|\n\n";
				num = lst.number(lst.Count());

				if ((num % 10 > 4) || (num % 10 == 0) || (num % 100 == 11) || (num % 100 == 12) || (num % 100 == 13) || (num % 100 == 14))
				{
					cout << "В списке содержится " << num << " элементов " << endl;
					goto link;
				}

				if (num % 10 == 1)
				{
					cout << "В списке содержится " << num << " элемент " << endl;
					goto link;
				}

				if ((num % 100 == 2) || (num % 100 == 3) || (num % 100 == 4));
				{
					cout << "В списке содержится " << num << " элемента " << endl;
					goto link;
				}
			link:

				cout << "\n\nДля перехода в меню нажмите любую клавишу..." << endl;
				_getch();
				system("cls");
			}
			break;

		case 6:
			if (lst.check() == true) {
				system("cls");
				cout << "Поменять местами два соседних элемента |" << endl;
				cout << "---------------------------------------|\n\n";
				cout << "Исходный список - > "; lst.show(lst.Count());
				cout << endl;
				cout << "Введите номер элемента списка -> ";
				cin >> num;
				lst.change(num);
				system("cls");
			}
			break;

		case 7:
			if (lst.check() == true) {
				system("cls");
				cout << "Обьеденить два списка |" << endl;
				cout << "----------------------|\n\n";
				cout << "Какое кол-во элементов Вы хотите добавить в список?  -> ";
				cin >> num;
				LST.create(num);
				lst.addition(LST);
				lst.show(lst.Count());
				_getch();

				system("cls");
				cout << "Успех! Обьединение списков было выполнено!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
				_getch();
				system("cls");
			}
			break;

		case 8:
			if (lst.check() == true) {
			link3:
				system("cls");
				cout << "Удаление списка |" << endl;
				cout << "----------------|\n\n";
				cout << "Вы точно хотите удалить список?\n";
				cout << "(1 - да; 2 - нет)\n" << endl;
				cout << "Ваш выбор -> ";
				cin >> num;
				if (num <= 0 || num > 2) {
					system("cls");
					cout << "Отсутствует пункт меню! Попробуйте еще раз!\n\nДля перехода на шаг назад нажмите любую клавишу..." << endl;
					_getch();
					goto link3;
				}
				else {
					if (num == 1) {
						lst.~TList();
						system("cls");
						cout << "Успех! Удаление списка было выполнено!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
						_getch();
					}
					else
						system("cls");
				}
			}
			break;
		case 9:
			if (lst.check() == true) {
			link4:
				system("cls");
				cout << "Запись списка в файл |" << endl;
				cout << "---------------------|\n\n";
				cout << "Вы точно хотите записать список в файл?\n";
				cout << "(1 - да; 2 - нет)\n" << endl;
				cout << "Ваш выбор -> ";
				cin >> num;
				if (num <= 0 || num > 2) {
					system("cls");
					cout << "Отсутствует пункт меню! Попробуйте еще раз!\n\nДля перехода на шаг назад нажмите любую клавишу..." << endl;
					_getch();
					goto link4;
				}
				else {
					if (num == 1) {
						lst.save();
						system("cls");
						cout << "Успех! Запись списка в файл было выполнено!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
						_getch();
					}
					else
						system("cls");
				}
				break;

		case 10:
		link5:
			system("cls");
			cout << "Чтение списка c файла |" << endl;
			cout << "----------------------|\n\n";
			cout << "Вы точно хотите создать список c файла?\n";
			cout << "(1 - да; 2 - нет)\n" << endl;
			cout << "Ваш выбор -> ";
			cin >> num;
			if (num <= 0 || num > 2) {
				system("cls");
				cout << "Отсутствует пункт меню! Попробуйте еще раз!\n\nДля перехода на шаг назад нажмите любую клавишу..." << endl;
				_getch();
				goto link5;
			}
			else {
				if (num == 1) {
					lst.form_the_file();
					system("cls");
					cout << "Успех! Чтение списка с файла было выполнено!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
					_getch();
				}
				break;
		case 11:
			system("cls");
			cout << "Thanks for your attention!!" << endl << endl;
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
	}
}

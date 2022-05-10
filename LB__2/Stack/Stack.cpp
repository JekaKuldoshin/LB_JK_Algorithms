﻿#include "list.h"

int main(void) {
	SetConsoleCP(1251);            //Руссификатор для ввода
	SetConsoleOutputCP(1251);     //Руссификатор для вывода

	int num = 0;          //Переменная для работы с заполнением
	stack st;           //Создание стека и работы с ним

	int menu;       //Переменные для меню

	while (true) {            // Цикл для меню
		system("cls");
		cout << "                                       Меню                                                       |" << endl;
		cout << "--------------------------------------------------------------------------------------------------|" << endl;
		cout << "1 - Создание стека                       | 7 - Найти максимальный элемент и после него вставить 0 |" << endl;
		cout << "2 - Вывод стека                          | 8 - Удалить минимальный элемент                        |" << endl;
		cout << "3 - Обмен первого и последнего элемента  | 9 - Удаление всех элементов кроме первого              |" << endl;
		cout << "4 - Перевернуть стек                     | 10 - Удаление всех элементов кроме последнего          |" << endl;
		cout << "5 - Удалить каждый второй элемент стека  | 11 - Запись стека в файл                               |" << endl;
		cout << "6 - Вставить '*' в середину стека        | 12 - Создание нового стека из файла                    |" << endl;
		cout << "--------------------------------------------------------------------------------------------------|" << endl;
		cout << "                                      13 - Выход                                                  |" << endl;
		cout << "--------------------------------------------------------------------------------------------------|" << endl;
		cout << "Сделайте свой выбор -> ";
		cin >> menu;

		switch (menu)
		{
		case 1:                         //\\ //\\ Создание списка //\\ //\\ 
			system("cls");

			cout << "Какое кол-во элементов Вы хотите добавить в стек?  -> ";
			cin >> num;

			st.create(num);         //Функ-я для создания стека
			st.show();             //Функ-я для вывода
			system("cls");
			cout << "Успех! Данные были инициализированны и выведены!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
			_getch();
			system("cls");
			break;

		case 2:                            //\\ //\\ Вывод //\\ //\\ 
			if (st.check() == true) {     //Функ-я проверки на наличее данных в списке
				system("cls");
				cout << "Вывод стека |" << endl;
				cout << "------------|\n\n";
				st.show();            //Функ-я вывода
				system("cls");
			}
			break;

		case 3:                            //\\ //\\ Обмен первого и последнего элемента //\\ //\\ 
			if (st.check() == true) {
				system("cls");
				cout << "Обмен первого и последнего элемента |" << endl;
				cout << "------------------------------------|\n\n";
				st.swapTopTail();         //Функ-я обмена
				st.show();               //Функ-я вывода
				system("cls");
				cout << "Успех! Данные были успешно обменены!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
				_getch();
				system("cls");
			}
			break;

		case 4:                            //\\ //\\ Перевернуть стек //\\ //\\ 
			if (st.check() == true) {  //Функ-я проверки на наличее данных в списке
				system("cls");
				cout << "Перевернуть стек                |" << endl;
				cout << "--------------------------------|\n";
				cout << "'Дно стека становиться вершиной'|" << endl;
				cout << "--------------------------------|\n\n";

				st.reverse();   //Функ-я обмена
				st.show();     //Функ-я вывода
				system("cls");
				cout << "Успех! Стек был успешно обменены!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
				_getch();
				system("cls");
			}
			break;

		case 5:                            //\\ //\\  Удалить каждый второй элемент стека //\\ //\\ 
			if (st.check() == true) { //Функ-я проверки на наличее данных в списке
				system("cls");
				cout << "Удаление каждого второго элемента стека |" << endl;
				cout << "----------------------------------------|\n\n";
				st.delEvery2();         //Функ-я удаления каждого второго
				st.show();             //Функ-я вывода
				system("cls");
				cout << "Успех! Стек был успешно изменен!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
				_getch();
				system("cls");
			}
			break;

		case 6:                       //\\ //\\ Вставить '*' в середину стека //\\ //\\ 
			if (st.check() == true) {  //Функ-я проверки на наличее данных в списке
				system("cls");
				cout << "Вставить '*' в середину стека                                  |" << endl;
				cout << "---------------------------------------------------------------|\n";
				cout << "'Вставить символ '*' в середину стека, если количество парное, |" << endl;
				cout << "или после среднего елемента, если количество непарное'         |" << endl;
				cout << "---------------------------------------------------------------|\n\n";

				st.putInStar();    //Функ-я вставки звезды

				system("cls");
				cout << "Успех! Функ-я вставки '*' в середину стека была выполнена!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
				_getch();

				system("cls");
			}
			break;

		case 7:                       //\\ //\\ Найти максимальный элемент и после него вставить 0 //\\ //\\ 
			if (st.check() == true) {  //Функ-я проверки на наличее данных в списке
				system("cls");
				cout << "Найти максимальный элемент и после него вставить 0 |" << endl;
				cout << "---------------------------------------------------|\n\n";
				st.findMaxPutInZero();   //Функ-я нахождения макс. и вставка нуля 
				st.show();              //Функ-я вывода

				system("cls");
				cout << "Успех! Нахождение максимального элемента и вставка 0-я была выполнена!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
				_getch();
				system("cls");
			}
			break;

		case 8:                          //\\ //\\ Удалить минимальный элемент //\\ //\\ 
			if (st.check() == true) {  //Функ-я проверки на наличее данных в списке
			link3:
				system("cls");
				cout << "Удаление минимального элемента |" << endl;
				cout << "----------------|\n\n";
				cout << "Вы точно хотите удалить минимальный элемент?\n";
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
						system("cls");
						st.delMin();         //Функ-я удаления минимального
						st.show();          //Функ-я вывода
						system("cls");
						cout << "Успех! Удаление минимального елемента было выполнено!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
						_getch();
					}
					else
						system("cls");
				}
			}
			break;
		case 9:                          //\\ //\\ Удалить все кроме первого элемента //\\ //\\ 
			if (st.check() == true) {  //Функ-я проверки на наличее данных в списке
			link4:
				system("cls");
				cout << "Удаление всех элементов кроме первого |" << endl;
				cout << "--------------------------------------|\n\n";
				cout << "Вы точно хотите удалить все элементы стека кроме первого?\n";
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
						system("cls");
						st.delHead();         //Функ-я удаления с конца и до головы
						st.show();           //Функ-я вывода
						system("cls");
						cout << "Успех! Удаление всех елементов кроме первого было выполнено!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
						_getch();
					}
					else
						system("cls");
				}
			}
			break;
		case 10:                          //\\ //\\ Удалить все кроме последнего элемента //\\ //\\ 
			if (st.check() == true) {  //Функ-я проверки на наличее данных в списке
			link5:
				system("cls");
				cout << "Удаление всех элементов кроме последнего |" << endl;
				cout << "-----------------------------------------|\n\n";
				cout << "Вы точно хотите удалить все элементы стека кроме последнего?\n";
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
						system("cls");
						st.delTail();       //Функ-я удаления с головы и до конца
						st.show();         //Функ-я вывода
						system("cls");
						cout << "Успех! Удаление всех елементов кроме последнего было выполнено!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
						_getch();
					}
					else
						system("cls");
				}
			}
			break;

		case 11:                           //\\ //\\ Запись в файл //\\ //\\ 
			if (st.check() == true) {   //Функ-я проверки на наличее данных в списке
			link6:
				system("cls");
				cout << "Запись стека в файл |" << endl;
				cout << "---------------------|\n\n";
				cout << "Вы точно хотите записать стек в файл?\n";
				cout << "(1 - да; 2 - нет)\n" << endl;
				cout << "Ваш выбор -> ";
				cin >> num;
				if (num <= 0 || num > 2) {
					system("cls");
					cout << "Отсутствует пункт меню! Попробуйте еще раз!\n\nДля перехода на шаг назад нажмите любую клавишу..." << endl;
					_getch();
					goto link6;
				}
				else {
					if (num == 1) {
						st.saveInFile();        //Переходим в функ-ю записи в файл
						system("cls");
						cout << "Успех! Запись стека в файл было выполнено!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
						_getch();
					}
					else
						system("cls");
				}
				break;

		case 12:                //\\ //\\ Чтение с файла //\\ //\\ 
		link7:
			system("cls");
			cout << "Чтение стека c файла  |" << endl;
			cout << "----------------------|\n\n";
			cout << "Вы точно хотите создать стек c файла?\n";
			cout << "(1 - да; 2 - нет)\n" << endl;
			cout << "Ваш выбор -> ";
			cin >> num;
			if (num <= 0 || num > 2) {
				system("cls");
				cout << "Отсутствует пункт меню! Попробуйте еще раз!\n\nДля перехода на шаг назад нажмите любую клавишу..." << endl;
				_getch();
				goto link7;
			}
			else {
				if (num == 1) {
					st.form_the_file();          //Заходим в функ-ю чтения списка с файла
					system("cls");
					cout << "Успех! Чтение стека с файла было выполнено!\n\nДля перехода в меню нажмите любую клавишу..." << endl;
					_getch();
				}
				break;
		case 13:                  //\\ //\\ Выход //\\ //\\ 
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
		}
	}
}
	

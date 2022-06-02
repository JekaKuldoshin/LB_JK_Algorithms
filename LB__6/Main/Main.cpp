#include "HashTable.h"
#include "DirectAddressing.h"
#include "OpenAddressing.h"
#include "QuadraticProbing.h"
#include "DoubleHashing.h"

int main(void) {
	SetConsoleCP(1251);            //Руссификатор для ввода
	SetConsoleOutputCP(1251);     //Руссификатор для вывода

	int menu;       //Переменные для меню

	 //Размер хэш-табл
	int i;        //ID хєш-табл
	int n;       //NUM
	int old_id, new_id;

	HashTable h;
	OpenHashTable o(20);

	DirectHashTable d(9);
	QuadraticHashTable q(11);
	DoubleHashTable D(11);


	while (true) {            // Цикл для меню
	link:
		system("cls");
		cout << "                 Меню                  |" << endl;
		cout << "---------------------------------------|" << endl;
		cout << "1 - Работа с прямой адресацией         |" << endl;
		cout << "2 - Работа с открытой адресацией       |" << endl;
		cout << "3 - Работа с адресациями + хэш функции |" << endl;
		cout << "---------------------------------------|" << endl;
		cout << "              4 - Выход                |" << endl;
		cout << "---------------------------------------|" << endl;
		cout << "Сделайте свой выбор -> ";
		cin >> menu;

		switch (menu) {
		case 1:
		link_menu:
			system("cls");
			cout << "    Работа с прямой адресацией     |" << endl;
			cout << "-----------------------------------|" << endl;
			cout << "1 - Создать данные в хэш-таблицу   |" << endl;
			cout << "2 - Удаление данных                |" << endl;
			cout << "3 - Модифицирование данных         |" << endl;
			cout << "4 - Поиск элементов в хэш-таблице  |" << endl;
			cout << "5 - Вывод данных                   |" << endl;
			cout << "-----------------------------------|" << endl;
			cout << "   6 - Вернуться в главное меню    |" << endl;
			cout << "-----------------------------------|" << endl;
			cout << "Сделайте свой выбор -> ";
			cin >> menu;

			switch (menu)
			{
			case 1:
				system("cls");
				cout << "        Меню         |" << endl;
				cout << "---------------------|" << endl;
				cout << "1 - Ввод вручную     |" << endl;
				cout << "2 - Запись с файла   |" << endl;
				cout << "---------------------|" << endl;
				cout << "3 - Вернуться в меню |" << endl;
				cout << "---------------------|" << endl;
				cout << "Сделайте свой выбор -> ";
				cin >> menu;
				switch (menu)
				{
				case 1:
					system("cls");
					cout << "\n\n";
					cout << "Введите id: ";
					cin >> i;
					cout << "Введите num: ";
					cin >> n;
					h.create_record(i, n);

					cout << "\n\nДля перехода в меню нажмите любую клавишу...";
					_getch();
					goto link_menu;
					break;
				case 2:
					h.from_file();
					system("cls");
					cout << "Успех! Данные были занесены!\n\nДля перехода в меню нажмите любую клавишу...";
					_getch();
					goto link_menu;
					break;
				case 3:
					goto link_menu;
					break;
				default:
					system("cls");
					cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... ";
					_getch();
					break;
				}
				break;
			case 2:
				system("cls");
				h.display();
				cout << "\n\n";
				cout << "Введите DATA - елемент который хотите удалить: ";
				cin >> i;
				h.delete_record(i);
				goto link_menu;
				break;
			case 3:
				system("cls");
				h.display();
				cout << "\n\n";
				cout << "Введите DATA - элемента которое хотите модорнизировать: ";
				cin >> old_id;
				cout << "Введите новый id: ";
				cin >> new_id;
				cout << "Введите новый num: ";
				cin >> n;
				h.modify_record(old_id, new_id, n);
				goto link_menu;
				break;
			case 4:
				system("cls");
				h.display();
				h.search();
				_getch();
				goto link_menu;
				break;
			case 5:
				system("cls");
				h.display();
				cout << "\n\nНажмите на Enter чтобы продолжить...";
				_getch();
				goto link_menu;
				break;

			case 6:							//\\ //\\ Выход //\\ //\\ 
				break;

			default:
				system("cls");
				cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... ";
				_getch();
				goto link_menu;
				break;
			}
			break;
		case 3:
		link_menu2:
			system("cls");
			cout << "                 Меню                |" << endl;
			cout << "-------------------------------------|" << endl;
			cout << "1 - Метод цепочки                    |" << endl;
			cout << "2 - Метод квадратичное пробирование  |" << endl;
			cout << "3 - Метод двойного хеширования       |" << endl;
			cout << "-------------------------------------|" << endl;
			cout << "    4 - Вернуться в главное меню     |" << endl;
			cout << "-------------------------------------|" << endl;
			cout << "Сделайте свой выбор -> ";
			cin >> menu;
			switch (menu)
			{
			case 1:
			link_menu3:
				system("cls");
				cout << "     Работа с методом цепочки      |" << endl;
				cout << "-----------------------------------|" << endl;
				cout << "1 - Создать данные в хэш-таблицу   |" << endl;
				cout << "2 - Удаление данных                |" << endl;
				cout << "3 - Поиск элементов в хэш-таблице  |" << endl;
				cout << "4 - Вывод данных                   |" << endl;
				cout << "-----------------------------------|" << endl;
				cout << "   5 - Вернуться в главное меню    |" << endl;
				cout << "-----------------------------------|" << endl;
				cout << "Сделайте свой выбор -> ";
				cin >> menu;
				switch (menu) {
				case 1:
				link_menu31:
					system("cls");
					cout << "        Меню         |" << endl;
					cout << "---------------------|" << endl;
					cout << "1 - Ввод вручную     |" << endl;
					cout << "2 - Запись с файла   |" << endl;
					cout << "---------------------|" << endl;
					cout << "3 - Вернуться в меню |" << endl;
					cout << "---------------------|" << endl;
					cout << "Сделайте свой выбор -> ";
					cin >> menu;
					switch (menu)
					{
					case 1:
						system("cls");
						cout << "\n\n";
						cout << "Введите DATA-> ";
						cin >> n;
						d.insert(n);
						cout << "\n\nДля перехода в меню нажмите любую клавишу...";
						_getch();
						goto link_menu3;
						break;
					case 2:
						d.from_file();
						system("cls");
						cout << "Успех! Данные были занесены!\n\nДля перехода в меню нажмите любую клавишу...";
						_getch();
						goto link_menu3;
						break;
					case 3:
						goto link_menu3;
						break;
					default:
						system("cls");
						cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... ";
						_getch();
						goto link_menu31;
						break;
					}
					break;

				case 2:
					system("cls");
					d.display();
					cout << "\n\n";
					cout << "Введите DATA - елемент который хотите удалить -> ";
					cin >> n;
					d.Delete(n);
					goto link_menu3;
					break;
				case 3:
					system("cls");
					d.display();
					cout << "\n\n";
					cout << "Введите DATA для поиска -> ";
					cin >> n;
					d.Search(n);
					goto link_menu3;
					break;
				case 4:
					system("cls");
					d.display();
					cout << "\n\nНажмите на Enter чтобы продолжить...";
					_getch();
					goto link_menu3;
					break;
				case 5:
					goto link_menu2;
					break;
				default:
					system("cls");
					cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... ";
					_getch();
					goto link_menu3;
					break;
				}
				break;
			case 2:
			link2:
				system("cls");
				cout << "     Квадратичное пробирование     |" << endl;
				cout << "-----------------------------------|" << endl;
				cout << "1 - Создать данные в хэш-таблицу   |" << endl;
				cout << "2 - Удаление данных                |" << endl;
				cout << "3 - Поиск элементов в хэш-таблице  |" << endl;
				cout << "4 - Вывод данных                   |" << endl;
				cout << "-----------------------------------|" << endl;
				cout << "   5 - Вернуться в главное меню    |" << endl;
				cout << "-----------------------------------|" << endl;
				cout << "Сделайте свой выбор -> ";
				cin >> menu;
				switch (menu) {
				case 1:
				link21:
					system("cls");
					cout << "        Меню         |" << endl;
					cout << "---------------------|" << endl;
					cout << "1 - Ввод вручную     |" << endl;
					cout << "2 - Запись с файла   |" << endl;
					cout << "---------------------|" << endl;
					cout << "3 - Вернуться в меню |" << endl;
					cout << "---------------------|" << endl;
					cout << "Сделайте свой выбор -> ";
					cin >> menu;
					switch (menu)
					{
					case 1:
						system("cls");
						cout << "\n\n";
						cout << "Введите DATA-> ";
						cin >> n;
						q.insert(n);
						system("cls");
						cout << "Успех! Данные были занесены!\n\nДля перехода в меню нажмите любую клавишу...";
						_getch();
						goto link2;
						break;
					case 2:
						q.from_file();
						system("cls");
						cout << "Успех! Данные были занесены!\n\nДля перехода в меню нажмите любую клавишу...";
						_getch();
						goto link2;
						break;
					case 3:
						goto link2;
						break;
					default:
						system("cls");
						cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... ";
						_getch();
						goto link21;
						break;
					}
					break;

				case 2:
					system("cls");
					q.display();
					cout << "\n\n";
					cout << "Введите ID - елемент который хотите удалить -> ";
					cin >> n;
					q.Delete(n);
					goto link2;
					break;
				case 3:
					system("cls");
					q.display();
					cout << "\n\n";
					cout << "Введите ID для поиска -> ";
					cin >> n;
					q.Search(n);
					goto link2;
					break;
				case 4:
					system("cls");
					q.display();
					cout << "\n\nНажмите на Enter чтобы продолжить...";
					_getch();
					goto link2;
					break;
				case 5:
					goto link_menu2;
					break;
				default:
					system("cls");
					cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... ";
					_getch();
					goto link2;
					break;
				}
				break;
			case 3:
			link3:
				system("cls");
				cout << "    Метод двойного хеширования     |" << endl;
				cout << "-----------------------------------|" << endl;
				cout << "1 - Создать данные в хэш-таблицу   |" << endl;
				cout << "2 - Удаление данных                |" << endl;
				cout << "3 - Поиск элементов в хэш-таблице  |" << endl;
				cout << "4 - Вывод данных                   |" << endl;
				cout << "-----------------------------------|" << endl;
				cout << "   5 - Вернуться в главное меню    |" << endl;
				cout << "-----------------------------------|" << endl;
				cout << "Сделайте свой выбор -> ";
				cin >> menu;
				switch (menu) {
				case 1:
				link31:
					system("cls");
					cout << "        Меню         |" << endl;
					cout << "---------------------|" << endl;
					cout << "1 - Ввод вручную     |" << endl;
					cout << "2 - Запись с файла   |" << endl;
					cout << "---------------------|" << endl;
					cout << "3 - Вернуться в меню |" << endl;
					cout << "---------------------|" << endl;
					cout << "Сделайте свой выбор -> ";
					cin >> menu;
					switch (menu)
					{
					case 1:
						system("cls");
						cout << "\n\n";
						cout << "Введите DATA-> ";
						cin >> n;
						D.insert(n);
						system("cls");
						cout << "Успех! Данные были занесены!\n\nДля перехода в меню нажмите любую клавишу...";
						_getch();
						goto link3;
						break;
					case 2:
						D.from_file();
						system("cls");
						cout << "Успех! Данные были занесены!\n\nДля перехода в меню нажмите любую клавишу...";
						_getch();
						goto link3;
						break;
					case 3:
						goto link3;
						break;
					default:
						system("cls");
						cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... ";
						_getch();
						goto link31;
						break;
					}
					break;

				case 2:
					system("cls");
					D.display();
					cout << "\n\n";
					cout << "Введите ID - елемент который хотите удалить -> ";
					cin >> n;
					D.Delete(n);
					goto link3;
					break;
				case 3:
					system("cls");
					D.display();
					cout << "\n\n";
					cout << "Введите ID для поиска -> ";
					cin >> n;
					D.Search(n);
					goto link3;
					break;
				case 4:
					system("cls");
					D.display();
					cout << "\n\nНажмите на Enter чтобы продолжить...";
					_getch();
					goto link3;
					break;
				case 5:
					goto link_menu2;
					break;
				default:
					system("cls");
					cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... ";
					_getch();
					goto link3;
					break;
				}
				break;
			case 4:
				goto link;
				break;
			default:
				system("cls");
				cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... ";
				_getch();
				goto link_menu2;
				break;
			}
		case 2:
		link_menu4:
			system("cls");
			cout << "   Работа с открытой адресацией    |" << endl;
			cout << "-----------------------------------|" << endl;
			cout << "1 - Создать данные в хэш-таблицу   |" << endl;
			cout << "2 - Удаление данных                |" << endl;
			cout << "3 - Поиск элементов в хэш-таблице  |" << endl;
			cout << "4 - Вывод данных                   |" << endl;
			cout << "-----------------------------------|" << endl;
			cout << "   5 - Вернуться в главное меню    |" << endl;
			cout << "-----------------------------------|" << endl;
			cout << "Сделайте свой выбор -> ";
			cin >> menu;
			switch (menu) {
			case 1:
			link4:
				system("cls");
				cout << "        Меню         |" << endl;
				cout << "---------------------|" << endl;
				cout << "1 - Ввод вручную     |" << endl;
				cout << "2 - Запись с файла   |" << endl;
				cout << "---------------------|" << endl;
				cout << "3 - Вернуться в меню |" << endl;
				cout << "---------------------|" << endl;
				cout << "Сделайте свой выбор -> ";
				cin >> menu;
				switch (menu)
				{
				case 1:
					system("cls");
					cout << "\n\n";
					cout << "Введите DATA-> ";
					cin >> n;
					o.insert(n);
					_getch();
					system("cls");
					cout << "Успех! Данные были занесены!\n\nДля перехода в меню нажмите любую клавишу...";
					_getch();
					goto link_menu4;
					break;
				case 2:
					o.from_file();
					system("cls");
					cout << "Успех! Данные были занесены!\n\nДля перехода в меню нажмите любую клавишу...";
					_getch();
					goto link_menu4;
					break;
				case 3:
					goto link_menu4;
					break;
				default:
					system("cls");
					cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... ";
					_getch();
					goto link4;
					break;
				}
				break;
			case 2:
				system("cls");
				o.display();
				cout << "\n\n";
				cout << "Введите ID - елемент который хотите удалить -> ";
				cin >> n;
				o.Delete(n);
				goto link_menu4;
				break;
			case 3:
				system("cls");
				o.display();
				cout << "\n\n";
				cout << "Введите ID для поиска -> ";
				cin >> n;
				o.Search(n);
				_getch();
				goto link_menu4;
				break;
			case 4:
				system("cls");
				o.display();
				cout << "\n\nНажмите на Enter чтобы продолжить...";
				_getch();
				goto link_menu4;
				break;
			case 5:
				goto link;
				break;
			default:
				system("cls");
				cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... ";
				_getch();
				goto link_menu4;
				break;
			}
			break;

		case 4:
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
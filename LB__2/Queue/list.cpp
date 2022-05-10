#include "list.h"

bool queue::check() {        //\\//\\ Функ-я проверки на наличие элементов очереди //\\//\\ 
	if (first == NULL) {        //Если пуст стек, то выводим...
		system("cls");
		cout << "Ошибка! Очередь отсутствует!!!\n\nНажмите на Enter чтобы продолжить...";
		_getch();
		return false;
	}
	else
		return true;     //Если возврашает True, то мы можем пользоваться всем функционалом программы
}

void queue::create(int num) {       //\\//\\ Функ-я для создания списка //\\//\\ 
	int a = 1;     //Счеткик элементов
	char d;     //Переменная для ввода
	for (int i = 0; i < num; i++) {
		cout << "Введите данные для " << a++ << " позиции элемента стека -> ";
		cin >> d;
		Add(d);    //Переход в функ-ю добавления элементов в конец списка
	}
	a = 0;
	system("cls");
}

void queue::Add(char a) {
    obj* temp = new obj;
    temp->data = a;
    if (!first) {
        first = temp;
        tail = first;
    }
    else {
        tail->prev = temp;
        tail = temp;
    }
    temp->prev = NULL;
}

void queue::show()             //\\//\\ Функ-я для вывода стека //\\//\\ 
{
	obj* temp = first;
	cout << "Очередь: ";
	while (temp) {
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
	cout << "\nДля продолжения нажмите любую клавишу...";
	_getch();
}

int queue::count()
{
	int count = 0;
	obj* temp = first;
	while (temp) {
		count++;
		temp = temp->prev;
	}
	return count;
}

double queue::average()
{
	char avarage = ' ';
	obj* temp = first;
	while (temp) {
		avarage += temp->data;
		temp = temp->prev;
	}
	return avarage / count();
}

char queue::Max()
{
	char max = first->data;
	obj* temp = first->prev;
	while (temp) {
		if (max < temp->data)
			max = temp->data;
		temp = temp->prev;
	}

	return max;
}

char queue::Min()
{
	char min = first->data;
	obj* temp = first->prev;
	while (temp) {
		if (min > temp->data)
			min = temp->data;
		temp = temp->prev;
	}

	return min;
}

char queue::prevMin()
{
	char prevMin;
	obj* temp = first;
	if (Min() == first->data)
		return Min();
	while (temp) {

		if (temp->prev->data == Min())
			return temp->data;
		temp = temp->prev;
	}

}

void queue::saveInFile() {           //\\//\\ Функ-я записи в файл //\\//\\

	obj* temp = first;

	fstream f("Queue.txt", ios::out);        //Создали переменную для работы с файлом, создали файл.
	if (!f.is_open())                           //Проверка на открытие файла
		cout << "Ошибка! Файл не найден!";
	else {
		while (temp) {                       //Цикл пока не дойдем до конца
			f << temp->data << '\t';        //Запись данных списка в файл
			temp = temp->prev;             //Шаг вперед
		}
	}

}

void queue::form_the_file() {                   //\\//\\ Функ-я чтения с файла //\\//\\ 

	char a;
	fstream f("Queue.txt", ios::in);   //Переменная для работы с файлом, открыли файл
	if (!f.is_open())                     //Проверка на открытие файла
		cout << "Ошибка! Файл не найден!";
	else {
		while (f >> a) {
			if (a != ' ')
				Add(a);
		}
	}
	f.close();                 //Закрыли файл

}
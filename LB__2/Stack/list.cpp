#include "list.h"

stack::~stack()                //\\//\\ КпоУ //\\//\\ 
{
	if (!isEmpty()) {
		obj* temp = top;              //Указатель на верх
		while (temp->next) {         //Переход к следующему
			temp = temp->next;      //Переход к следующему
			delete top;            //Удалить верх
			top = temp;
		}
		top = temp;
		delete top;            //Удаление
	}
}

bool stack::check() {        //\\//\\ Функ-я проверки на наличие элементов списка //\\//\\ 
	if (top==NULL) {        //Если пуст стек, то выводим...
		system("cls");
		cout << "Ошибка! Стек отсутствует!!!\n\nНажмите на Enter чтобы продолжить...";
		_getch();
		return false;
	}
	else
		return true;     //Если возврашает True, то мы можем пользоваться всем функционалом программы
}

bool stack::isEmpty()       //Проверка на пустоту
{
	if (top)
		return 0;
	else
		return 1;
}

void stack::create(int num) {       //\\//\\ Функ-я для создания списка //\\//\\ 
	int a = 1;     //Счеткик элементов
	char d;     //Переменная для ввода
	for (int i = 0; i < num; i++) {
		cout << "Введите данные для " << a++ << " позиции элемента стека -> ";
		cin >> d;
		push(d);    //Переход в функ-ю добавления элементов в конец списка
	}
	a = 0;
	system("cls");
}

void stack::push(char d)     //\\//\\ Функ-я для записи стека //\\//\\ 
{
	obj* temp = new obj;          //Создаем указатель
	temp->data = d;              //Данные переносим в data
	temp->next = top;           //Переводим указатель на следующий элемент

	top = temp;
}

void stack::pop()         //\\//\\ Функ-я для удаления стека //\\//\\ 
{
	if (!top) return;      //Если начало не пустое, то выход

	obj* temp = top->next;      //указатель переводим на следующий элемент
	delete top;                //Удаляем
	top = temp;
}

short stack::pull()  //\\//\\ Функ-я для вытягивания //\\//\\ 
{
	char data;
	obj* temp = top->next;

	data = top->data;
	delete top;
	top = temp;

	return data;
}

void stack::show()             //\\//\\ Функ-я для вывода стека //\\//\\ 
{
	obj* temp = top;
	cout << "Стек: ";
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	cout << "\nДля продолжения нажмите любую клавишу...";
	_getch();
}

void stack::swapTopTail()           //\\//\\ Функ-я для обмена начала с концом //\\//\\ 
{
	if (!top->next)               //Если один элемент
		return;

	if (!top->next->next) {     //Если два элемента
		char s1 = pull();
		char s2 = pull();
		push(s1);
		push(s2);
		return;
	}

	else {
		char first = pull();              //Вытянули первый элемент
		obj* temp = top;                 //Данные на верхушку ставим 
		short count = 0;                //Переменная для работы с массивом и подсчет кол-ва элементов
		while (temp->next) {           //Переход по данным
			count++;                  //Подсчет
			temp = temp->next;
		}
		char* arr = new char[count];        //Создал массив для данных

		for (short i = 0; i < count; i++) {      //Исходя из кол-ва переходим по данным
			arr[i] = pull();                    //Вытягиваем в массив
		}
		char last = pull();                   //Вытянул последений элемент 
		push(first);                         //Вставил первый

		for (short i = count - 1; i >= 0; i--) {    //Исходя из кол-ва проходим по всем элементам
			push(arr[i]);                          //Вставка массива после того как вставили последний элемент на первое место
		}

		push(last);                             //Вставка последнего элемента
	}
}

void stack::reverse()                    //\\//\\ Функ-я переворачивания стека //\\//\\ 
{
	obj* temp = top;                       //Поставили на начало
	short count = 0;                      //Переменная для подсчета кол-ва элементов
	while (temp) {                       //Цикл пока есть данные
		count++;                        //Подсчет
		temp = temp->next;             //Переход
	}
	short* arr = new short[count];               //Создали массив с кол-вом элементов стека
	for (short i = 0; i < count; i++)           
		arr[i] = pull();                       //Вытягиваем со стека
	for (short i = 0; i < count; i++)
		push(arr[i]);                        //И обратно загяняем в стек
}

void stack::delEvery2()              //\\//\\ Удаление каждого второго элемента //\\//\\ 
{
	obj* temp = top;                  //Поставили на начало
	stack tempSt;                    //Временная переменная
	while (!isEmpty()) {            //Если не пуст стек
		tempSt.push(pull());       //Вытянули и заполнили tempSt
		pop();                    //Удаляем
	}
	while (!tempSt.isEmpty())          //Если не пуст новый стек 
		push(tempSt.pull());          //Вытягиваем с нового стека и заполняем в исходный
}

void stack::putInStar()        //\\//\\ Функ-я заполнения звезды в середину //\\//\\ 
{
	obj* temp = top;                     //Ставим на начало
	int count = 0;                      //Для подсчета
	while (temp)                       //Цикл для посчета данных
	{
		count++;                     //Подсчет
		temp = temp->next;          //Переход
	}
	temp = top;                   //Переместили наверх
	if (count % 2 == 0) {                         //Если четное
		for (int i = 0; i < count / 2; i++) {    //Кол-во делим на 2 для того чтоб узнать середину
			cout << temp->data << " ";          //Выводим данные
			temp = temp->next;                 //Переход к следующему
		}
		cout << '*' << ' ';                  //Вставка звезды

		while (temp) {                     //Пока не закончатся данные
			cout << temp->data << " ";    //Вывод
			temp = temp->next;           //Переход
		}

	}
	else {                                              //Если нечетное
		for (int i = 0; i < count / 2 + 1; i++) {      //Делим на 2 для того чтоб узнать середину + 1 для того чтоб найти псевдо середину для нечетного
			cout << temp->data << " ";                //Выводим
			temp = temp->next;                       //Переход
		}
		cout << '*' << ' ';                        //Вывод звезды

		while (temp) {                           //Пока данные не закрнчатся
			cout << temp->data << " ";          //Вывод
			temp = temp->next;                 //Переход
		}
	}
	cout << endl;

	cout << "\nДля продолжения нажмите любую клавишу...";
	_getch();
}


void stack::findMaxPutInZero()              //\\//\\ Функ-я для нахождения максимального и вставки нуля //\\//\\ 
{
	if (!isEmpty()) {                             //Если стек не пуст
		stack newStack;                          //Создаем новый стек
		int size = 0, count = 1;                //Переменные для нахождение куда ставить "0"
		char max = top->data;                  //Задаем данные максимального элемента для дальнейшего сравнивания
		while (!isEmpty()) {                  //Цикл будет работать пока будет не пуст
			size++;
			if (max < top->data) {          //Сравнивания Макс < элементом
				max = top->data;           //Присваивание
				count = size;             
			}
			newStack.push(pull());       //Вытянули и записали в новый стек

		}
		for (int i = 0; i < size - count; i++) {         //Цикл будет работать до места где нужно поствить "0"
			push(newStack.pull());                      //Вытянули с нового стека и вставили в начальный
		}
		
		push(newStack.pull());                        //Вставил максимальное число
		push('0');                                   //Вставляем "0"
		while (!newStack.isEmpty())                 //Пока не дойдем до конца
			push(newStack.pull());                 //Вытянул и вставил в изначальный стек
	}
}

void stack::delMin() {                      //\\//\\ Функ-я нахождения и удаления минимального элемента стека //\\//\\ 

	if (!isEmpty()) {                            //Если стек не пуст
		stack newStack;                         //Создаем новый стек
		int size = 0, count = 0;
		char min = top->data;                  //Переменная с минимальным элементом
		while (!isEmpty()) {                  //Пока будет не пуст
			if (min > top->data) {           //Если Мин. > data 
				min = top->data;            //То тогда присваиваем
				count = size;              //Сохраняем положение этого элемента
			}
			newStack.push(pull());       //Вытягиваем и заполнем новый стек
			size++;                    
		}
		for (int i = 0; i < size - count; i++) {          //Идем до места которое нужно удалить
			push(newStack.pull());                       //Вытягиваем с нового стека в изначальный
		}
		pop();                                         //Удаляем минимальный элемент
		while (!newStack.isEmpty())                   //Пока не дойдем до конца
			push(newStack.pull());                   //Вытягиваем с нового стека в изначальный
	}
}

void stack::delTail() {                //\\//\\ Функ-я удаления всех элементов кроме последнего //\\//\\ 

	char temp = pull();              //Вытягиваем данные
	while (!isEmpty())              //Пока не дойдем до конца
		pop();                     //Удаляем
	push(temp);                   //Вставляем последний элемент
}

void stack::delHead() {           //\\//\\ Функ-я удаления всех элементов кроме первого //\\//\\ 

	while (top->next)          //Один пропускаем и до конца
		pop();                //Удаляем все элементы
}

void stack::saveInFile() {           //\\//\\ Функ-я записи в файл //\\//\\

	obj* temp = top;

	fstream f("Stack.txt", ios::out);        //Создали переменную для работы с файлом, создали файл.
	if (!f.is_open())                           //Проверка на открытие файла
		cout << "Ошибка! Файл не найден!";
	else {
		while (temp) {                       //Цикл пока не дойдем до конца
			f << temp->data << '\t';        //Запись данных списка в файл
			temp = temp->next;             //Шаг вперед
		}
	}

}

void stack::form_the_file() {                   //\\//\\ Функ-я чтения с файла //\\//\\ 
	
	char a;
	fstream f("Stack.txt", ios::in);   //Переменная для работы с файлом, открыли файл
	if (!f.is_open())                     //Проверка на открытие файла
		cout << "Ошибка! Файл не найден!";
	else {
		while (f >> a) {
			if (a != ' ')
				push(a);
		}
	}
	reverse();
		f.close();                 //Закрыли файл

	}
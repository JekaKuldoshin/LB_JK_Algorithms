#pragma once

#include <windows.h>         //Руссификатор
#include <iostream>         //С++
#include <fstream>         //Файлы
#include <conio.h>        //_getch() 

using namespace std;

struct obj {
	char data;               //Символьная переменная
	obj* prev;
	obj* next;              //Указатель на переход
};

class deque {
private:
	obj* left, * right;            //Указатель на верх

public:

	deque() : left(NULL), right(NULL) {};           //КсП

	void create_front(int num);          //Функ-я для создания нескольких элементов
	void create_back(int num);
	void push_front(char a);
	void push_back(char a);             //Ввод
	void show();                 //Вывод

	int count();               //Функ-я для подсчета кол-ва элементов в очереди
	double average();         //Функ-я для нахождения среднего арифметического
	char Max();              //Функ-я для нахождения Макс.
	char Min();             //Функ-я для нахождения Мин.
	char prevMin();        //Функ-я для нахождения элемента перел минимальным значением
	void saveInFile();       //Функ-я записи в файл
	void form_the_file();   //Функ-я чтения с файла

	bool check();           //Проверка на пустоту

};
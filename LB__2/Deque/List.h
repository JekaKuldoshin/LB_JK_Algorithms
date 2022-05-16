#pragma once

#include <windows.h>         //Руссификатор
#include <iostream>         //С++
#include <fstream>         //Файлы
#include <conio.h>        //_getch() 

using namespace std;

struct obj {
	char data;               //Символьная переменная
	obj* prev;              //Указатель на прошлый элемент
	obj* next;             //Указатель на следующий элемент
};

class deque {
private:
	obj* left, * right;            //Указатель на начало (Лево) и конец (право)

public:

	deque() : left(NULL), right(NULL) {};           //КсП

	void create_back(int num);                    //Функ-я для создания нескольких элементов очереди (делает переход на функ-ю push_back)
	void push_front(char a);                     //Функ-я внесения данных в очередь с начало
	void push_back(char a);                     //С
	void show();                               //Вывод

	int count();                             //Функ-я для подсчета кол-ва элементов в очереди
	void check_pull_6_elem();               //Функ-я для проверки правильности вывода 6-го элемента очереди
	char pull_6_elem();                    //Функ-я вывода 6-го элемента очереди
	char pull_last_elem();                //Функ-я вывода последнего элемента очереди

	void saveInFile();                  //Функ-я записи в файл
	void form_the_file();              //Функ-я чтения с файла

	bool check();                    //Проверка на пустоту

};
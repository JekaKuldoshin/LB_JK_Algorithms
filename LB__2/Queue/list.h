#pragma once

#include <windows.h>         //Руссификатор
#include <iostream>         //С++
#include <fstream>         //Файлы
#include <conio.h>        //_getch() 

using namespace std;

struct obj {
	char data;               //Символьная переменная
	obj* prev;              //Указатель на прошлый элемент
};

class queue {
private:
	obj* first;         //Указатель на начало
	obj* tail;         //Указатель на конец

public:

	queue() : first(NULL), tail(NULL) {};          //КсП
	//~queue();                        //КпоУ

	void create(int num);          //Функ-я для создания нескольких элементов
	void Add(char a);
	void show();              //Вывод

	int count();
	double average();
	char Max();
	char Min();
	char prevMin();
	void saveInFile();
	void form_the_file();

	bool check();           //Проверка на пустоту

	//void saveInFile();         //Функ-я записи в файл
	//void form_the_file();     //Функ-я чтения с файла

};
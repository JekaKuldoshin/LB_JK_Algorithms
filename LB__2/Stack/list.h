#pragma once

#include <windows.h>         //Руссификатор
#include <iostream>         //С++
#include <fstream>         //Файлы
#include <conio.h>        //_getch() 

using namespace std;

struct obj {
	char data;               //Символьная переменная
	obj* next;              //Указатель на переход
};

class stack {
private:
	obj* top;            //Указатель на верх

public:

	stack() : top(NULL) {};           //КсП
	~stack();                        //КпоУ

	void create(int num);          //Функ-я для создания нескольких элементов

	void push(char d);           //Ввод
	void pop();                 //Удаление
	short pull();              //Вытягивание
	void show();              //Вывод

	bool check();           //Проверка на пустоту
	bool isEmpty();        //Проверка на пустоту

	void swapTopTail();                //Функ-я для обмена начала с концом
	void reverse();                   //Функ-я переворачивания стека
	void delEvery2();                //Удаление каждого второго элемента
	void putInStar();               //Функ-я заполнения звезды в середину
	void findMaxPutInZero();       //Функ-я для нахождения максимального и вставки нуля
	void delMin();                //Функ-я нахождения и удаления минимального элемента стека
	void delTail();              //Функ-я удаления всех элементов кроме последнего
	void delHead();             //Функ-я удаления всех элементов кроме первого
	void saveInFile();         //Функ-я записи в файл
	void form_the_file();     //Функ-я чтения с файла

};
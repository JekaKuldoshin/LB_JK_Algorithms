#pragma once

#include <windows.h>         //Руссификатор
#include <iostream>         //С++
#include <fstream>         //Файлы
#include <conio.h>        //_getch() 

using namespace std;

struct Data {
	Data* prev, * next;           //Прошлое, следующие
	double data;                 //Переменная для списка
};


class TList {
private:
	Data* head, * tail;          //Начало, конец
public:

	TList() : head(NULL), tail(NULL) {};                  //КсП
	~TList();                                            //КпоУ

	bool check();                                      //Функ-я проверки на наличие элементов списка
	void Add(double data);                            //Функ-я для добавления данных в конец списка
	void create(int num);                                   //Функ-я для создания списка
	void show();                                    //Функ-я вывода
	short number();                        //Функ-я для нахождения кол-ва элементов списка
	void deleteFromList(int poz);                 //Функ-я для удаления выбранного элемента
	void change(int num);                        //Функ-я смены соседних элементов списка
	void addition(TList& LIST);                 //Функ-я обьединения двух списков
	void save();                               //Функ-я сохранения в файл
	void form_the_file();                     //Функ-я чтения с файла
	void in(double s);                       //Функ-я для работы с функцией чтения с файла

};

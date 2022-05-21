#pragma once
#include <vector>                //Vector
#include <windows.h>            //Русификатор и STD_OUTPUT_HANDLE
#include <fstream>             //Файлы
#include <iostream>           //С++
#include <conio.h>           //_gecth()

using namespace std;

struct Data {
	Data* Left, * Right, * Parent;                //Указатели Левой - Правой ветки, родитель элемента 
	int year, kol;                               //Переменные для года, кол-ва
	string name;                                //Название журнала
	Data(string s, int y, int k);
	Data() {}
};

class Tree {                                                        //Класс бинарного дерева
public:
	Data* Root;                                                   //Переменная для работы с классом
	int count, tabs;                                             //Переменная для подсчета и пробелов
	Tree();                                                     //КпУ
	void add(string y, int k, int g);                          //Функ-я добавления в бинарное дерево
	void addByYear(Data* node);                               //Функция для добавления, по Году, когда уже создали второе дерево -> создаем место под данные
	void add_by_y(string name, int y, int k);               //Функция для добавления, по Году

	void showForward(Data* n);                             //Функция для вывода бинарного дерева 
	void showF(Data* n);                                  //Вывод прямого обхода
	void showBackward(Data* n);                          //Вывод обратного обхода
	void showSymmetrically(Data* n);                    //Вывод симетричного обхода
	void show();                                       //Промежуточная функция для вывода, проверка (Бинарное дерево)
	void showPreOrder();                              //Промежуточная функция для вывода прямого обхода
	void showPostOrder();                            //Промежуточная функция для вывода обратного обхода
	void showSymm();                                //Промежуточная функция для вывода симетричного обхода

	void delLeft(Data* n);                        //Функ-я удаления левой ветки и зануливам ее
	void delLeftTree();                          //Функция проверки на пустоту левой ветки, в случае если есть данные продолжаем удаление, заходим в функцию -> delLeft(Data* n);
	void delRight(Data* n);                     //Функ-я удаления правой ветки и зануливам ее 
	void delRightTree();					   //Функция проверки на пустоту правую ветку, в случае если есть данные продолжаем удаление, заходим в функцию -> delRight(Data* n);
	void delTree();                           //Функ-я удаление бинарного дерева

	void remake();							//Функция для создания нового дерева и переноса данных в него, изменяем переменную по которой строится дерево (Year)

	void makeVectorFromTree(Data* n, vector<Data*>& m);          //Создаем и заносим данные в вектор массива для раскраски бинарного дерева


	void save(Data* n, string name);               //Функ-я для записи в файл, будет работать пока не закончаться данные
	void saveToFile(string name);                 //Промежуточная функция для записи в файл
	void read(Data* n, string name);             //Функ-я для чтения с файла, будет работать пока не закончаться данные
	void readFromFile(string name);             //Промежуточная функция для чтения с файла

	bool check();                             //Функ-я для проверки на пустоту бинарного дерева
};

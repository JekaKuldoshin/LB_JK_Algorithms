#pragma once             //Метод цепочки
#include <fstream>  
#include<iostream>
#include <vector>
#include<conio.h>

using namespace std;

struct Data_quadratic
{
	int key,
		data;
	vector<Data_quadratic> list;
	bool contains;

	friend class DirectHashTable;
	Data_quadratic() {
		key = 0;
		data = 0;
		contains = false;
	}
	Data_quadratic(int k, int d, bool i) {
		key = k;
		data = d;
		contains = i;
	}
};

class QuadraticHashTable {
	Data_quadratic* arr;
	int length,
		full = 0;
public:
	QuadraticHashTable(int size) {
		length = size;
		arr = new Data_quadratic[length];
	}

	void insert(int);
	void Check();
	void Resize();
	void display();
	void Search(int);
	void Delete(int);
	void from_file();

};
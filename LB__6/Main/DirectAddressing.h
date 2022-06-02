#pragma once             //Метод цепочки
#include <fstream>  
#include<iostream>
#include <vector>
#include<conio.h>

using namespace std;

struct Data_direct
{
	int key,
		data;
	vector<Data_direct> list;
	bool contains;

	friend class DirectHashTable;
	Data_direct() {
		key = 0;
		data = 0;
		contains = false;
	}
	Data_direct(int k, int d, bool i) {
		key = k;
		data = d;
		contains = i;
	}
};

class DirectHashTable {
	Data_direct* arr;
	int length,
		full = 0;
public:
	DirectHashTable(int size) {
		length = size;
		arr = new Data_direct[length];
	}

	int hashCode(double);
	void insert(int);
	void Check();
	void Resize();
	void display();
	void Search(int);
	void Delete(int);
	void from_file();

};
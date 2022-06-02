#pragma once             //Метод цепочки
#include <fstream>  
#include<iostream>
#include <vector>
#include<conio.h>

using namespace std;

struct Data_doubleHash
{
	int key,
		data;
	vector<Data_doubleHash> list;
	bool contains;

	friend class DirectHashTable;
	Data_doubleHash() {
		key = 0;
		data = 0;
		contains = false;
	}
	Data_doubleHash(int k, int d, bool i) {
		key = k;
		data = d;
		contains = i;
	}
};

class DoubleHashTable {
	Data_doubleHash* arr;
	int length,
		full = 0;
public:
	DoubleHashTable(int size) {
		length = size;
		arr = new Data_doubleHash[length];
	}

	void insert(int);
	void Check();
	void Resize();
	void display();
	void Search(int);
	void Delete(int);
	void from_file();

};
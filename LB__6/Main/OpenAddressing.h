#pragma once             //Метод цепочки
#include <fstream>  
#include<iostream>
#include <vector>
#include<conio.h>

using namespace std;

struct Data_openAddress
{
	int key,
		data;
	vector<Data_openAddress> list;
	bool contains;

	friend class DirectHashTable;
	Data_openAddress() {
		key = 0;
		data = 0;
		contains = false;
	}
	Data_openAddress(int k, int d, bool i) {
		key = k;
		data = d;
		contains = i;
	}
};

class OpenHashTable {
	Data_openAddress* arr;
	int length,
		full = 0;
public:
	OpenHashTable(int size) {
		length = size;
		arr = new Data_openAddress[length];
	}

	void insert(int);
	void Check();
	void Resize();
	void display();
	void Search(int);
	void Delete(int);
	void from_file();

};
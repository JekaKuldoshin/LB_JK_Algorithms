#pragma once
#include<iostream>
#include<conio.h>
#include "windows.h"
#include <fstream>  
#include <string>
#include <iomanip>



using namespace std;

class Data {
	int id;
	int num;
	friend class HashTable;
public:
	Data() {
		id = 0;
		num = 0;
	}
};

class HashTable {
	Data data[100];
	int index;
	int size = 20;
public:
	void create_record(int i, int n);
	void delete_record(int i);
	void modify_record(int old_id, int new_id, int n);
	void display();
	void search();
	void from_file();

};
#pragma once
#include "Main.h"

void InsertSort(int* arr, int N) {
	int j;
	long long k = 0;
	for (int i = 0; i < N - 1; i++)//n
	{
		j = i + 1;//n
		while (arr[j] < arr[j - 1])//2
		{
			swap(arr[j], arr[j - 1]);//3
			j--;//1
			k += 6;
		}
		k += 3;
	}
	cout << "\n���-�� �������� = " << k << endl;
}

void radixSort(int* arr, int N) {
	int max = arr[0];                //���� ���������� ������ �������� �������
	long long k = 0;
	for (int i = 1; i < N; i++) { //������� ������������ �������� �������
		if (arr[i] > max) {
			max = arr[i];
			k += 4;
		}
		k += 3;
	}
	for (int div = 1; max / div > 0; div *= 10) { //��� ������������� ������ ���������� ���������(���-�� ������� ����� ������������� ����� �������)
		countingSort(arr, N, div, k);       //������� ��� ������ ����� � �������
		k += 3;
	}
	cout << "\n���-�� �������� = " << k << endl;

}
void countingSort(int* arr, int N, int div, int k) {
	int output[G];                            //���������� 10 ������� ������ �� ������� ������������ ����� ������� ��� ������ ����� �� 0 �� 9.
	int count[10] = { 0 };

	for (int i = 0; i < N; i++) {
		count[(arr[i] / div) % 10]++;
		k += 3;
	}
	for (int i = 1; i < 10; i++) {
		count[i] += count[i - 1];
		k += 3;
	}

	for (int i = N - 1; i >= 0; i--)
	{
		output[count[(arr[i] / div) % 10] - 1] = arr[i];
		count[(arr[i] / div) % 10]--;
		k += 4;
	}

	for (int i = 0; i < N; i++) {
		arr[i] = output[i];
		k += 3;
	}
}

void heapify(int v[], int n, int i, int k)
{
	int maxim = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && v[l] > v[maxim]) {
		maxim = l;
		k += 3;
	}
	if (r < n && v[r] > v[maxim]) {
		maxim = r;
		k += 3;
	}
	if (maxim != i)
	{
		swap(v[i], v[maxim]);
		heapify(v, n, maxim, k);
		k += 4;
	}
}
void HeapSort(int v[], int n)
{
	long long k = 0;
	for (int i = n / 2 - 1; i >= 0; i--) { 
		heapify(v, n, i, k); 
		k += 3;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		swap(v[0], v[i]);
		heapify(v, i, 0, k);
		k += 3;
	}
	cout << "\n���-�� �������� = " << k << endl;
}


void create_mas_Rand(int size, int A[]) {
	for (int i = 0; i <= (size - 1); i++)
	{
		A[i] = rand() % (size * 5);
	}
}
void create_mas_Up(int size, int A[]) {
	int num = 1;
	for (int i = 0; i < size; i++) { // +
		A[i] = num++;
	}
}
void create_mas_Down(int size, int A[]) {
	int a = size;
	for (int i = 0; i < size; i++)
	{
		A[i] = a--; // ����������� ��������
	}
}


void print_mas_new(int size, int A[]) {

	cout << "\n������ ����� ����������:\n";
	for (int k = 0; k < size; k++)
	{
		cout << A[k] << " | ";
	}
}
void print_mas_old(int size, int A[]) {

	for (int k = 0; k < size; k++)
	{
		cout << A[k] << " | ";
	}
}

void print_Insert_TAB_Rand() {
	cout << "------------------------------|" << endl;
	cout << "    �������������� ������     |" << endl;
	cout << "                              |" << endl;
	cout << "    ����������  ���������     |" << endl;
	cout << "------------------------------|" << endl << endl;
}
void print_Insert_TAB_Up() {
	cout << "------------------------------|" << endl;
	cout << "     ������������ ������      |" << endl;
	cout << "                              |" << endl;
	cout << "    ����������  ���������     |" << endl;
	cout << "------------------------------|" << endl << endl;
}
void print_Insert_TAB_Down() {
	cout << "------------------------------|" << endl;
	cout << "    ������������ ������       |" << endl;
	cout << "    � �������� �������        |" << endl;
	cout << "   ����������  ���������      |" << endl;
	cout << "------------------------------|" << endl << endl;
}

void print_Radix_TAB_Rand() {
	cout << "------------------------------|" << endl;
	cout << "    �������������� ������     |" << endl;
	cout << "                              |" << endl;
	cout << "   �����������  ����������    |" << endl;
	cout << "------------------------------|" << endl << endl;
}
void print_Radix_TAB_Up() {
	cout << "------------------------------|" << endl;
	cout << "     ������������ ������      |" << endl;
	cout << "                              |" << endl;
	cout << "   �����������  ����������    |" << endl;
	cout << "------------------------------|" << endl << endl;
}
void print_Radix_TAB_Down() {
	cout << "------------------------------|" << endl;
	cout << "    ������������ ������       |" << endl;
	cout << "    � �������� �������        |" << endl;
	cout << "   �����������  ����������    |" << endl;
	cout << "------------------------------|" << endl << endl;
}

void print_Heap_TAB_Rand() {
	cout << "------------------------------|" << endl;
	cout << "    �������������� ������     |" << endl;
	cout << "                              |" << endl;
	cout << "   ������������� ����������   |" << endl;
	cout << "------------------------------|" << endl << endl;
}
void print_Heap_TAB_Up() {
	cout << "------------------------------|" << endl;
	cout << "     ������������ ������      |" << endl;
	cout << "                              |" << endl;
	cout << "   ������������� ����������   |" << endl;
	cout << "------------------------------|" << endl << endl;
}
void print_Heap_TAB_Down() {
	cout << "------------------------------|" << endl;
	cout << "    ������������ ������       |" << endl;
	cout << "    � �������� �������        |" << endl;
	cout << "  ������������� ����������    |" << endl;
	cout << "------------------------------|" << endl << endl;
}



void Fun_InsertSortRand() {
	Data d;
	cout.setf(ios::fixed);
	cout.precision(6);

	system("cls");
link:

	print_Insert_TAB_Rand();
	cout << "������ ������� -> " << d.size1 << endl << endl;
	
	int* A1 = new int[d.size1];
	
	create_mas_Rand(d.size1, A1);

	if (d.print == 1)
	print_mas_old(d.size1, A1);

	clock_t start1 = clock();
	InsertSort(A1, d.size1); // ����������
	clock_t end1 = clock();

	if (d.print == 1)
	print_mas_new(d.size1,A1);
	
	cout << endl;
	double time1 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num1 = d.size1;


	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	/////////////////////////////////////////////////////////////////////////////
	print_Insert_TAB_Rand();
	cout << "������ ������� -> " << d.size2 << endl << endl;
	
	int* A2 = new int[d.size2];
	create_mas_Rand(d.size2, A2);

	if (d.print == 1)
		print_mas_old(d.size2, A2);

	start1 = clock();
	InsertSort(A2, d.size2); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size2, A2);

	cout << endl;
	double time2 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num2 = d.size2;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	//////////////////////////////////////////////////////////////////////
	print_Insert_TAB_Rand();
	cout << "������ ������� -> " << d.size3 << endl << endl;
	
	int* A3 = new int[d.size3];
	create_mas_Rand(d.size3, A3);

	if (d.print == 1)
		print_mas_old(d.size3, A3);

	start1 = clock();
	InsertSort(A3, d.size3); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size3, A3);

	cout << endl;
	double time3 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num3 = d.size3;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	////////////////////////////////////////////////////////////////
	print_Insert_TAB_Rand();
	cout << "������ ������� -> " << d.size4 << endl << endl;

	int* A4 = new int[d.size4];
	create_mas_Rand(d.size4, A4);

	if (d.print == 1)
		print_mas_old(d.size4, A4);

	start1 = clock();
	InsertSort(A4, d.size4); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size4, A4);

	cout << endl;
	double time4 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num4 = d.size4;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	////////////////////////////////////////////////////////
	print_Insert_TAB_Rand();
	cout << "������ ������� -> " << d.size5 << endl << endl;

	int* A5 = new int[d.size5];
	create_mas_Rand(d.size5, A5);

	if (d.print == 1)
		print_mas_old(d.size5,A5);

	start1 = clock();
	InsertSort(A5, d.size5); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size5, A5);

	cout << endl;
	double time5 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num5 = d.size5;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	///////////////////////////////////////////////////////
	print_Insert_TAB_Rand();
	cout << "������ ������� -> " << d.size6 << endl << endl;

	int* A6 = new int[d.size6];
	create_mas_Rand(d.size6, A6);

	if (d.print == 1)
		print_mas_old(d.size6, A6);

	start1 = clock();
	InsertSort(A6, d.size6); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size6, A6);

	cout << endl;
	double time6 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num6 = d.size6;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	///////////////////////////////////////////////////////

	int n = 6;

	cout << endl;
	cout << " |----------------------------------------------------------------------------------------------------------|" << endl;
	cout << " |                                                  �������������� ������                                   |" << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;
	cout << " |                            |                ���������� ��������� � �������                               |" << endl;
	cout << " |                            |-----------------------------------------------------------------------------|" << endl;
	cout << " |                            | " << setw(n) << num1 << setw(5) << "     | " << setw(n) << num2 << setw(5) << "     | " << setw(n) << num3 << setw(5) << "     | " << setw(n) << num4 << setw(5) << "     | " << setw(n) << num5 << setw(5) << "     | " << setw(n) << num6 << setw(5) << "     | " << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;
	cout << " | C��������� ���������       | " << setw(10) << time1 << " | " << setw(10) << time2 << " | " << setw(10) << time3 << " | " << setw(10) << time4 << " | " << setw(10) << time5 << " | " << setw(10) << time6 << " | " << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;


	cout << "\n������� ������� Enter ��� �������� � ����..." << endl;
	_getch();
	system("cls");

}
void Fun_InsertSortUp() {
	Data d;
	cout.setf(ios::fixed);
	cout.precision(6);

	system("cls");
link:

	print_Insert_TAB_Up();
	cout << "������ ������� -> " << d.size1 << endl << endl;

	int* A1 = new int[d.size1];

	create_mas_Up(d.size1, A1);

	if (d.print == 1)
		print_mas_old(d.size1, A1);

	clock_t start1 = clock();
	InsertSort(A1, d.size1); // ����������
	clock_t end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size1, A1);

	cout << endl;
	double time1 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num1 = d.size1;


	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	/////////////////////////////////////////////////////////////////////////////
	print_Insert_TAB_Up();
	cout << "������ ������� -> " << d.size2 << endl << endl;

	int* A2 = new int[d.size2];
	create_mas_Up(d.size2, A2);

	if (d.print == 1)
		print_mas_old(d.size2, A2);

	start1 = clock();
	InsertSort(A2, d.size2); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size2, A2);

	cout << endl;
	double time2 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num2 = d.size2;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	//////////////////////////////////////////////////////////////////////
	print_Insert_TAB_Up();
	cout << "������ ������� -> " << d.size3 << endl << endl;

	int* A3 = new int[d.size3];
	create_mas_Up(d.size3, A3);

	if (d.print == 1)
		print_mas_old(d.size3, A3);

	start1 = clock();
	InsertSort(A3, d.size3); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size3, A3);

	cout << endl;
	double time3 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num3 = d.size3;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	////////////////////////////////////////////////////////////////
	print_Insert_TAB_Up();
	cout << "������ ������� -> " << d.size4 << endl << endl;

	int* A4 = new int[d.size4];
	create_mas_Up(d.size4, A4);

	if (d.print == 1)
		print_mas_old(d.size4, A4);

	start1 = clock();
	InsertSort(A4, d.size4); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size4, A4);

	cout << endl;
	double time4 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num4 = d.size4;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	////////////////////////////////////////////////////////
	print_Insert_TAB_Up();
	cout << "������ ������� -> " << d.size5 << endl << endl;

	int* A5 = new int[d.size5];
	create_mas_Up(d.size5, A5);

	if (d.print == 1)
		print_mas_old(d.size5, A5);

	start1 = clock();
	InsertSort(A5, d.size5); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size5, A5);

	cout << endl;
	double time5 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num5 = d.size5;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	///////////////////////////////////////////////////////
	print_Insert_TAB_Up();
	cout << "������ ������� -> " << d.size6 << endl << endl;

	int* A6 = new int[d.size6];
	create_mas_Up(d.size6, A6);

	if (d.print == 1)
		print_mas_old(d.size6, A6);

	start1 = clock();
	InsertSort(A6, d.size6); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size6, A6);

	cout << endl;
	double time6 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num6 = d.size6;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	///////////////////////////////////////////////////////

	int n = 6;

	cout << endl;
	cout << " |----------------------------------------------------------------------------------------------------------|" << endl;
	cout << " |                                                  ������������ ������                                     |" << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;
	cout << " |                            |                ���������� ��������� � �������                               |" << endl;
	cout << " |                            |-----------------------------------------------------------------------------|" << endl;
	cout << " |                            | " << setw(n) << num1 << setw(5) << "     | " << setw(n) << num2 << setw(5) << "     | " << setw(n) << num3 << setw(5) << "     | " << setw(n) << num4 << setw(5) << "     | " << setw(n) << num5 << setw(5) << "     | " << setw(n) << num6 << setw(5) << "     | " << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;
	cout << " | C��������� ���������       | " << setw(10) << time1 << " | " << setw(10) << time2 << " | " << setw(10) << time3 << " | " << setw(10) << time4 << " | " << setw(10) << time5 << " | " << setw(10) << time6 << " | " << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;


	cout << "\n������� ������� Enter ��� �������� � ����..." << endl;
	_getch();
	system("cls");

}
void Fun_InsertSortDown() {
	Data d;
	cout.setf(ios::fixed);
	cout.precision(6);

	system("cls");
link:

	print_Insert_TAB_Down();
	cout << "������ ������� -> " << d.size1 << endl << endl;

	int* A1 = new int[d.size1];

	create_mas_Down(d.size1, A1);

	if (d.print == 1)
		print_mas_old(d.size1, A1);

	clock_t start1 = clock();
	InsertSort(A1, d.size1); // ����������
	clock_t end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size1, A1);

	cout << endl;
	double time1 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num1 = d.size1;


	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	/////////////////////////////////////////////////////////////////////////////
	print_Insert_TAB_Down();
	cout << "������ ������� -> " << d.size2 << endl << endl;

	int* A2 = new int[d.size2];
	create_mas_Down(d.size2, A2);

	if (d.print == 1)
		print_mas_old(d.size2, A2);

	start1 = clock();
	InsertSort(A2, d.size2); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size2, A2);

	cout << endl;
	double time2 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num2 = d.size2;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	//////////////////////////////////////////////////////////////////////
	print_Insert_TAB_Down();
	cout << "������ ������� -> " << d.size3 << endl << endl;

	int* A3 = new int[d.size3];
	create_mas_Down(d.size3, A3);

	if (d.print == 1)
		print_mas_old(d.size3, A3);

	start1 = clock();
	InsertSort(A3, d.size3); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size3, A3);

	cout << endl;
	double time3 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num3 = d.size3;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	////////////////////////////////////////////////////////////////
	print_Insert_TAB_Down();
	cout << "������ ������� -> " << d.size4 << endl << endl;

	int* A4 = new int[d.size4];
	create_mas_Down(d.size4, A4);

	if (d.print == 1)
		print_mas_old(d.size4, A4);

	start1 = clock();
	InsertSort(A4, d.size4); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size4, A4);

	cout << endl;
	double time4 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num4 = d.size4;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	////////////////////////////////////////////////////////
	print_Insert_TAB_Down();
	cout << "������ ������� -> " << d.size5 << endl << endl;

	int* A5 = new int[d.size5];
	create_mas_Down(d.size5, A5);

	if (d.print == 1)
		print_mas_old(d.size5, A5);

	start1 = clock();
	InsertSort(A5, d.size5); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size5, A5);

	cout << endl;
	double time5 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num5 = d.size5;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	///////////////////////////////////////////////////////
	print_Insert_TAB_Down();
	cout << "������ ������� -> " << d.size6 << endl << endl;

	int* A6 = new int[d.size6];
	create_mas_Down(d.size6, A6);

	if (d.print == 1)
		print_mas_old(d.size6, A6);

	start1 = clock();
	InsertSort(A6, d.size6); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size6, A6);

	cout << endl;
	double time6 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num6 = d.size6;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	///////////////////////////////////////////////////////

	int n = 6;

	cout << endl;
	cout << " |----------------------------------------------------------------------------------------------------------|" << endl;
	cout << " |                                        ������������ ������ � �������� �������                            |" << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;
	cout << " |                            |                ���������� ��������� � �������                               |" << endl;
	cout << " |                            |-----------------------------------------------------------------------------|" << endl;
	cout << " |                            | " << setw(n) << num1 << setw(5) << "     | " << setw(n) << num2 << setw(5) << "     | " << setw(n) << num3 << setw(5) << "     | " << setw(n) << num4 << setw(5) << "     | " << setw(n) << num5 << setw(5) << "     | " << setw(n) << num6 << setw(5) << "     | " << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;
	cout << " | C��������� ���������       | " << setw(10) << time1 << " | " << setw(10) << time2 << " | " << setw(10) << time3 << " | " << setw(10) << time4 << " | " << setw(10) << time5 << " | " << setw(10) << time6 << " | " << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;


	cout << "\n������� ������� Enter ��� �������� � ����..." << endl;
	_getch();
	system("cls");

}


void Fun_RadixSortRand() {
	Data d;
	cout.setf(ios::fixed);
	cout.precision(6);

	system("cls");
link:

	print_Radix_TAB_Rand();
	cout << "������ ������� -> " << d.size1 << endl << endl;

	int* A1 = new int[d.size1];

	create_mas_Rand(d.size1, A1);

	if (d.print == 1)
		print_mas_old(d.size1, A1);

	clock_t start1 = clock();
	radixSort(A1, d.size1); // ����������
	clock_t end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size1, A1);

	cout << endl;
	double time1 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num1 = d.size1;


	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	/////////////////////////////////////////////////////////////////////////////
	print_Radix_TAB_Rand();
	cout << "������ ������� -> " << d.size2 << endl << endl;

	int* A2 = new int[d.size2];
	create_mas_Rand(d.size2, A2);

	if (d.print == 1)
		print_mas_old(d.size2, A2);

	start1 = clock();
	radixSort(A2, d.size2); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size2, A2);

	cout << endl;
	double time2 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num2 = d.size2;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	//////////////////////////////////////////////////////////////////////
	print_Radix_TAB_Rand();
	cout << "������ ������� -> " << d.size3 << endl << endl;

	int* A3 = new int[d.size3];
	create_mas_Rand(d.size3, A3);

	if (d.print == 1)
		print_mas_old(d.size3, A3);

	start1 = clock();
	radixSort(A3, d.size3); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size3, A3);

	cout << endl;
	double time3 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num3 = d.size3;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	////////////////////////////////////////////////////////////////
	print_Radix_TAB_Rand();
	cout << "������ ������� -> " << d.size4 << endl << endl;

	int* A4 = new int[d.size4];
	create_mas_Rand(d.size4, A4);

	if (d.print == 1)
		print_mas_old(d.size4, A4);

	start1 = clock();
	radixSort(A4, d.size4); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size4, A4);

	cout << endl;
	double time4 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num4 = d.size4;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	////////////////////////////////////////////////////////
	print_Radix_TAB_Rand();
	cout << "������ ������� -> " << d.size5 << endl << endl;

	int* A5 = new int[d.size5];
	create_mas_Rand(d.size5, A5);

	if (d.print == 1)
		print_mas_old(d.size5, A5);

	start1 = clock();
	radixSort(A5, d.size5); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size5, A5);

	cout << endl;
	double time5 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num5 = d.size5;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	///////////////////////////////////////////////////////
	print_Radix_TAB_Rand();
	cout << "������ ������� -> " << d.size6 << endl << endl;

	int* A6 = new int[d.size6];
	create_mas_Rand(d.size6, A6);

	if (d.print == 1)
		print_mas_old(d.size6, A6);

	start1 = clock();
	radixSort(A6, d.size6); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size6, A6);

	cout << endl;
	double time6 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num6 = d.size6;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	///////////////////////////////////////////////////////

	int n = 6;

	cout << endl;
	cout << " |----------------------------------------------------------------------------------------------------------|" << endl;
	cout << " |                                                  �������������� ������                                   |" << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;
	cout << " |                            |                ���������� ��������� � �������                               |" << endl;
	cout << " |                            |-----------------------------------------------------------------------------|" << endl;
	cout << " |                            | " << setw(n) << num1 << setw(5) << "     | " << setw(n) << num2 << setw(5) << "     | " << setw(n) << num3 << setw(5) << "     | " << setw(n) << num4 << setw(5) << "     | " << setw(n) << num5 << setw(5) << "     | " << setw(n) << num6 << setw(5) << "     | " << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;
	cout << " |  ����������� c���������    | " << setw(10) << time1 << " | " << setw(10) << time2 << " | " << setw(10) << time3 << " | " << setw(10) << time4 << " | " << setw(10) << time5 << " | " << setw(10) << time6 << " | " << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;


	cout << "\n������� ������� Enter ��� �������� � ����..." << endl;
	_getch();
	system("cls");

}
void Fun_RadixSortUp() {
	Data d;
	cout.setf(ios::fixed);
	cout.precision(6);

	system("cls");
link:

	print_Radix_TAB_Up();
	cout << "������ ������� -> " << d.size1 << endl << endl;

	int* A1 = new int[d.size1];

	create_mas_Up(d.size1, A1);

	if (d.print == 1)
		print_mas_old(d.size1, A1);

	clock_t start1 = clock();
	radixSort(A1, d.size1); // ����������
	clock_t end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size1, A1);

	cout << endl;
	double time1 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num1 = d.size1;


	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	/////////////////////////////////////////////////////////////////////////////
	print_Radix_TAB_Up();
	cout << "������ ������� -> " << d.size2 << endl << endl;

	int* A2 = new int[d.size2];
	create_mas_Up(d.size2, A2);

	if (d.print == 1)
		print_mas_old(d.size2, A2);

	start1 = clock();
	radixSort(A2, d.size2); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size2, A2);

	cout << endl;
	double time2 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num2 = d.size2;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	//////////////////////////////////////////////////////////////////////
	print_Radix_TAB_Up();
	cout << "������ ������� -> " << d.size3 << endl << endl;

	int* A3 = new int[d.size3];
	create_mas_Up(d.size3, A3);

	if (d.print == 1)
		print_mas_old(d.size3, A3);

	start1 = clock();
	radixSort(A3, d.size3); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size3, A3);

	cout << endl;
	double time3 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num3 = d.size3;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	////////////////////////////////////////////////////////////////
	print_Radix_TAB_Up();
	cout << "������ ������� -> " << d.size4 << endl << endl;

	int* A4 = new int[d.size4];
	create_mas_Up(d.size4, A4);

	if (d.print == 1)
		print_mas_old(d.size4, A4);

	start1 = clock();
	radixSort(A4, d.size4); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size4, A4);

	cout << endl;
	double time4 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num4 = d.size4;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	////////////////////////////////////////////////////////
	print_Radix_TAB_Up();
	cout << "������ ������� -> " << d.size5 << endl << endl;

	int* A5 = new int[d.size5];
	create_mas_Up(d.size5, A5);

	if (d.print == 1)
		print_mas_old(d.size5, A5);

	start1 = clock();
	radixSort(A5, d.size5); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size5, A5);

	cout << endl;
	double time5 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num5 = d.size5;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	///////////////////////////////////////////////////////
	print_Radix_TAB_Up();
	cout << "������ ������� -> " << d.size6 << endl << endl;

	int* A6 = new int[d.size6];
	create_mas_Up(d.size6, A6);

	if (d.print == 1)
		print_mas_old(d.size6, A6);

	start1 = clock();
	radixSort(A6, d.size6); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size6, A6);

	cout << endl;
	double time6 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num6 = d.size6;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	///////////////////////////////////////////////////////

	int n = 6;

	cout << endl;
	cout << " |----------------------------------------------------------------------------------------------------------|" << endl;
	cout << " |                                                  ������������ ������                                     |" << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;
	cout << " |                            |                ���������� ��������� � �������                               |" << endl;
	cout << " |                            |-----------------------------------------------------------------------------|" << endl;
	cout << " |                            | " << setw(n) << num1 << setw(5) << "     | " << setw(n) << num2 << setw(5) << "     | " << setw(n) << num3 << setw(5) << "     | " << setw(n) << num4 << setw(5) << "     | " << setw(n) << num5 << setw(5) << "     | " << setw(n) << num6 << setw(5) << "     | " << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;
	cout << " |   ����������� c���������   | " << setw(10) << time1 << " | " << setw(10) << time2 << " | " << setw(10) << time3 << " | " << setw(10) << time4 << " | " << setw(10) << time5 << " | " << setw(10) << time6 << " | " << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;


	cout << "\n������� ������� Enter ��� �������� � ����..." << endl;
	_getch();
	system("cls");

}
void Fun_RadixSortDown() {
	Data d;
	cout.setf(ios::fixed);
	cout.precision(6);

	system("cls");
link:

	print_Radix_TAB_Down();
	cout << "������ ������� -> " << d.size1 << endl << endl;

	int* A1 = new int[d.size1];

	create_mas_Down(d.size1, A1);

	if (d.print == 1)
		print_mas_old(d.size1, A1);

	clock_t start1 = clock();
	radixSort(A1, d.size1); // ����������
	clock_t end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size1, A1);

	cout << endl;
	double time1 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num1 = d.size1;


	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	/////////////////////////////////////////////////////////////////////////////
	print_Radix_TAB_Down();
	cout << "������ ������� -> " << d.size2 << endl << endl;

	int* A2 = new int[d.size2];
	create_mas_Down(d.size2, A2);

	if (d.print == 1)
		print_mas_old(d.size2, A2);

	start1 = clock();
	radixSort(A2, d.size2); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size2, A2);

	cout << endl;
	double time2 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num2 = d.size2;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	//////////////////////////////////////////////////////////////////////
	print_Radix_TAB_Down();
	cout << "������ ������� -> " << d.size3 << endl << endl;

	int* A3 = new int[d.size3];
	create_mas_Down(d.size3, A3);

	if (d.print == 1)
		print_mas_old(d.size3, A3);

	start1 = clock();
	radixSort(A3, d.size3); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size3, A3);

	cout << endl;
	double time3 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num3 = d.size3;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	////////////////////////////////////////////////////////////////
	print_Radix_TAB_Down();
	cout << "������ ������� -> " << d.size4 << endl << endl;

	int* A4 = new int[d.size4];
	create_mas_Down(d.size4, A4);

	if (d.print == 1)
		print_mas_old(d.size4, A4);

	start1 = clock();
	radixSort(A4, d.size4); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size4, A4);

	cout << endl;
	double time4 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num4 = d.size4;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	////////////////////////////////////////////////////////
	print_Radix_TAB_Down();
	cout << "������ ������� -> " << d.size5 << endl << endl;

	int* A5 = new int[d.size5];
	create_mas_Down(d.size5, A5);

	if (d.print == 1)
		print_mas_old(d.size5, A5);

	start1 = clock();
	radixSort(A5, d.size5); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size5, A5);

	cout << endl;
	double time5 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num5 = d.size5;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	///////////////////////////////////////////////////////
	print_Radix_TAB_Down();
	cout << "������ ������� -> " << d.size6 << endl << endl;

	int* A6 = new int[d.size6];
	create_mas_Down(d.size6, A6);

	if (d.print == 1)
		print_mas_old(d.size6, A6);

	start1 = clock();
	radixSort(A6, d.size6); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size6, A6);

	cout << endl;
	double time6 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num6 = d.size6;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	///////////////////////////////////////////////////////

	int n = 6;

	cout << endl;
	cout << " |----------------------------------------------------------------------------------------------------------|" << endl;
	cout << " |                                        ������������ ������ � �������� �������                            |" << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;
	cout << " |                            |                ���������� ��������� � �������                               |" << endl;
	cout << " |                            |-----------------------------------------------------------------------------|" << endl;
	cout << " |                            | " << setw(n) << num1 << setw(5) << "     | " << setw(n) << num2 << setw(5) << "     | " << setw(n) << num3 << setw(5) << "     | " << setw(n) << num4 << setw(5) << "     | " << setw(n) << num5 << setw(5) << "     | " << setw(n) << num6 << setw(5) << "     | " << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;
	cout << " |   ����������� c���������   | " << setw(10) << time1 << " | " << setw(10) << time2 << " | " << setw(10) << time3 << " | " << setw(10) << time4 << " | " << setw(10) << time5 << " | " << setw(10) << time6 << " | " << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;


	cout << "\n������� ������� Enter ��� �������� � ����..." << endl;
	_getch();
	system("cls");


}

void Fun_HeapSortRand() {
	Data d;
	cout.setf(ios::fixed);
	cout.precision(6);

	system("cls");
link:

	print_Heap_TAB_Rand();
	cout << "������ ������� -> " << d.size1 << endl << endl;

	int* A1 = new int[d.size1];

	create_mas_Rand(d.size1, A1);

	if (d.print == 1)
		print_mas_old(d.size1, A1);

	clock_t start1 = clock();
	HeapSort(A1, d.size1); // ����������
	clock_t end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size1, A1);

	cout << endl;
	double time1 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num1 = d.size1;


	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	/////////////////////////////////////////////////////////////////////////////
	print_Heap_TAB_Rand();
	cout << "������ ������� -> " << d.size2 << endl << endl;

	int* A2 = new int[d.size2];
	create_mas_Rand(d.size2, A2);

	if (d.print == 1)
		print_mas_old(d.size2, A2);

	start1 = clock();
	HeapSort(A2, d.size2); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size2, A2);

	cout << endl;
	double time2 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num2 = d.size2;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	//////////////////////////////////////////////////////////////////////
	print_Heap_TAB_Rand();
	cout << "������ ������� -> " << d.size3 << endl << endl;

	int* A3 = new int[d.size3];
	create_mas_Rand(d.size3, A3);

	if (d.print == 1)
		print_mas_old(d.size3, A3);

	start1 = clock();
	HeapSort(A3, d.size3); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size3, A3);

	cout << endl;
	double time3 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num3 = d.size3;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	////////////////////////////////////////////////////////////////
	print_Heap_TAB_Rand();
	cout << "������ ������� -> " << d.size4 << endl << endl;

	int* A4 = new int[d.size4];
	create_mas_Rand(d.size4, A4);

	if (d.print == 1)
		print_mas_old(d.size4, A4);

	start1 = clock();
	HeapSort(A4, d.size4); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size4, A4);

	cout << endl;
	double time4 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num4 = d.size4;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	////////////////////////////////////////////////////////
	print_Heap_TAB_Rand();
	cout << "������ ������� -> " << d.size5 << endl << endl;

	int* A5 = new int[d.size5];
	create_mas_Rand(d.size5, A5);

	if (d.print == 1)
		print_mas_old(d.size5, A5);

	start1 = clock();
	HeapSort(A5, d.size5); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size5, A5);

	cout << endl;
	double time5 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num5 = d.size5;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	///////////////////////////////////////////////////////
	print_Heap_TAB_Rand();
	cout << "������ ������� -> " << d.size6 << endl << endl;

	int* A6 = new int[d.size6];
	create_mas_Rand(d.size6, A6);

	if (d.print == 1)
		print_mas_old(d.size6, A6);

	start1 = clock();
	HeapSort(A6, d.size6); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size6, A6);

	cout << endl;
	double time6 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num6 = d.size6;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	///////////////////////////////////////////////////////

	int n = 6;

	cout << endl;
	cout << " |----------------------------------------------------------------------------------------------------------|" << endl;
	cout << " |                                                  �������������� ������                                   |" << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;
	cout << " |                            |                ���������� ��������� � �������                               |" << endl;
	cout << " |                            |-----------------------------------------------------------------------------|" << endl;
	cout << " |                            | " << setw(n) << num1 << setw(5) << "     | " << setw(n) << num2 << setw(5) << "     | " << setw(n) << num3 << setw(5) << "     | " << setw(n) << num4 << setw(5) << "     | " << setw(n) << num5 << setw(5) << "     | " << setw(n) << num6 << setw(5) << "     | " << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;
	cout << " |  ������������� ����������  | " << setw(10) << time1 << " | " << setw(10) << time2 << " | " << setw(10) << time3 << " | " << setw(10) << time4 << " | " << setw(10) << time5 << " | " << setw(10) << time6 << " | " << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;


	cout << "\n������� ������� Enter ��� �������� � ����..." << endl;
	_getch();
	system("cls");
}
void Fun_HeapSortUp() {
	Data d;
	cout.setf(ios::fixed);
	cout.precision(6);

	system("cls");
link:

	print_Heap_TAB_Up();
	cout << "������ ������� -> " << d.size1 << endl << endl;

	int* A1 = new int[d.size1];

	create_mas_Up(d.size1, A1);

	if (d.print == 1)
		print_mas_old(d.size1, A1);

	clock_t start1 = clock();
	HeapSort(A1, d.size1); // ����������
	clock_t end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size1, A1);

	cout << endl;
	double time1 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num1 = d.size1;


	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	/////////////////////////////////////////////////////////////////////////////
	print_Heap_TAB_Up();
	cout << "������ ������� -> " << d.size2 << endl << endl;

	int* A2 = new int[d.size2];
	create_mas_Up(d.size2, A2);

	if (d.print == 1)
		print_mas_old(d.size2, A2);

	start1 = clock();
	HeapSort(A2, d.size2); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size2, A2);

	cout << endl;
	double time2 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num2 = d.size2;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	//////////////////////////////////////////////////////////////////////
	print_Heap_TAB_Up();
	cout << "������ ������� -> " << d.size3 << endl << endl;

	int* A3 = new int[d.size3];
	create_mas_Up(d.size3, A3);

	if (d.print == 1)
		print_mas_old(d.size3, A3);

	start1 = clock();
	HeapSort(A3, d.size3); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size3, A3);

	cout << endl;
	double time3 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num3 = d.size3;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	////////////////////////////////////////////////////////////////
	print_Heap_TAB_Up();
	cout << "������ ������� -> " << d.size4 << endl << endl;

	int* A4 = new int[d.size4];
	create_mas_Up(d.size4, A4);

	if (d.print == 1)
		print_mas_old(d.size4, A4);

	start1 = clock();
	HeapSort(A4, d.size4); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size4, A4);

	cout << endl;
	double time4 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num4 = d.size4;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	////////////////////////////////////////////////////////
	print_Heap_TAB_Up();
	cout << "������ ������� -> " << d.size5 << endl << endl;

	int* A5 = new int[d.size5];
	create_mas_Up(d.size5, A5);

	if (d.print == 1)
		print_mas_old(d.size5, A5);

	start1 = clock();
	HeapSort(A5, d.size5); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size5, A5);

	cout << endl;
	double time5 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num5 = d.size5;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	///////////////////////////////////////////////////////
	print_Heap_TAB_Up();
	cout << "������ ������� -> " << d.size6 << endl << endl;

	int* A6 = new int[d.size6];
	create_mas_Up(d.size6, A6);

	if (d.print == 1)
		print_mas_old(d.size6, A6);

	start1 = clock();
	HeapSort(A6, d.size6); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size6, A6);

	cout << endl;
	double time6 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num6 = d.size6;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	///////////////////////////////////////////////////////

	int n = 6;

	cout << endl;
	cout << " |----------------------------------------------------------------------------------------------------------|" << endl;
	cout << " |                                                  ������������ ������                                     |" << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;
	cout << " |                            |                ���������� ��������� � �������                               |" << endl;
	cout << " |                            |-----------------------------------------------------------------------------|" << endl;
	cout << " |                            | " << setw(n) << num1 << setw(5) << "     | " << setw(n) << num2 << setw(5) << "     | " << setw(n) << num3 << setw(5) << "     | " << setw(n) << num4 << setw(5) << "     | " << setw(n) << num5 << setw(5) << "     | " << setw(n) << num6 << setw(5) << "     | " << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;
	cout << " |  ������������� ����������  | " << setw(10) << time1 << " | " << setw(10) << time2 << " | " << setw(10) << time3 << " | " << setw(10) << time4 << " | " << setw(10) << time5 << " | " << setw(10) << time6 << " | " << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;


	cout << "\n������� ������� Enter ��� �������� � ����..." << endl;
	_getch();
	system("cls");

}
void Fun_HeapSortDown() {
	Data d;
	cout.setf(ios::fixed);
	cout.precision(6);

	system("cls");
link:

	print_Heap_TAB_Down();
	cout << "������ ������� -> " << d.size1 << endl << endl;

	int* A1 = new int[d.size1];

	create_mas_Down(d.size1, A1);

	if (d.print == 1)
		print_mas_old(d.size1, A1);

	clock_t start1 = clock();
	HeapSort(A1, d.size1); // ����������
	clock_t end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size1, A1);

	cout << endl;
	double time1 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num1 = d.size1;


	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	/////////////////////////////////////////////////////////////////////////////
	print_Heap_TAB_Down();
	cout << "������ ������� -> " << d.size2 << endl << endl;

	int* A2 = new int[d.size2];
	create_mas_Down(d.size2, A2);

	if (d.print == 1)
		print_mas_old(d.size2, A2);

	start1 = clock();
	HeapSort(A2, d.size2); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size2, A2);

	cout << endl;
	double time2 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num2 = d.size2;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	//////////////////////////////////////////////////////////////////////
	print_Heap_TAB_Down();
	cout << "������ ������� -> " << d.size3 << endl << endl;

	int* A3 = new int[d.size3];
	create_mas_Down(d.size3, A3);

	if (d.print == 1)
		print_mas_old(d.size3, A3);

	start1 = clock();
	HeapSort(A3, d.size3); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size3, A3);

	cout << endl;
	double time3 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num3 = d.size3;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	////////////////////////////////////////////////////////////////
	print_Heap_TAB_Down();
	cout << "������ ������� -> " << d.size4 << endl << endl;

	int* A4 = new int[d.size4];
	create_mas_Down(d.size4, A4);

	if (d.print == 1)
		print_mas_old(d.size4, A4);

	start1 = clock();
	HeapSort(A4, d.size4); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size4, A4);

	cout << endl;
	double time4 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num4 = d.size4;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	////////////////////////////////////////////////////////
	print_Heap_TAB_Down();
	cout << "������ ������� -> " << d.size5 << endl << endl;

	int* A5 = new int[d.size5];
	create_mas_Down(d.size5, A5);

	if (d.print == 1)
		print_mas_old(d.size5, A5);

	start1 = clock();
	HeapSort(A5, d.size5); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size5, A5);

	cout << endl;
	double time5 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num5 = d.size5;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	///////////////////////////////////////////////////////
	print_Heap_TAB_Down();
	cout << "������ ������� -> " << d.size6 << endl << endl;

	int* A6 = new int[d.size6];
	create_mas_Down(d.size6, A6);

	if (d.print == 1)
		print_mas_old(d.size6, A6);

	start1 = clock();
	HeapSort(A6, d.size6); // ����������
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size6, A6);

	cout << endl;
	double time6 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\n����� ����������  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num6 = d.size6;

	cout << "\n������� ������� Enter ����� ����������..." << endl;
	_getch();
	system("cls");

	///////////////////////////////////////////////////////

	int n = 6;

	cout << endl;
	cout << " |----------------------------------------------------------------------------------------------------------|" << endl;
	cout << " |                                        ������������ ������ � �������� �������                            |" << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;
	cout << " |                            |                ���������� ��������� � �������                               |" << endl;
	cout << " |                            |-----------------------------------------------------------------------------|" << endl;
	cout << " |                            | " << setw(n) << num1 << setw(5) << "     | " << setw(n) << num2 << setw(5) << "     | " << setw(n) << num3 << setw(5) << "     | " << setw(n) << num4 << setw(5) << "     | " << setw(n) << num5 << setw(5) << "     | " << setw(n) << num6 << setw(5) << "     | " << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;
	cout << " |  ������������� ����������  | " << setw(10) << time1 << " | " << setw(10) << time2 << " | " << setw(10) << time3 << " | " << setw(10) << time4 << " | " << setw(10) << time5 << " | " << setw(10) << time6 << " | " << endl;
	cout << " |----------------------------|-----------------------------------------------------------------------------|" << endl;


	cout << "\n������� ������� Enter ��� �������� � ����..." << endl;
	_getch();
	system("cls");


}
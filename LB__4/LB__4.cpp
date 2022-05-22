#define N 10000

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void FillRand(int* arr);
void FillUp(int* arr);
void FillDown(int* arr);
void show(int* arr);
void swap(int& a, int& b);
void InsertionSort(int* arr);
void ShellSort(int* arr);
void SelectionSort(int* arr);
int increment(long  inc[], long  size);
void ShellInc(int* arr);

int main()
{
	int* arr = new int[N];

	cout.setf(ios::fixed);
	cout.precision(6);

	FillRand(arr);
	//show(arr);
	clock_t start1 = clock();
	InsertionSort(arr);
	clock_t end1 = clock();
	//show(arr);
	cout << setw(25) << "Insertion sort (random): " << setw(10) << (double)(end1 - start1) / CLOCKS_PER_SEC << endl << endl;

	FillUp(arr);
	//show(arr);
	start1 = clock();
	InsertionSort(arr);
	end1 = clock();
	//show(arr);
	cout << setw(25) << "Insertion sort (Up): " << setw(10) << (double)(end1 - start1) / CLOCKS_PER_SEC << endl << endl;

	FillDown(arr);
	//show(arr);
	start1 = clock();
	InsertionSort(arr);
	end1 = clock();
	//show(arr);
	cout << setw(25) << "Insertion sort (Down): " << setw(10) << (double)(end1 - start1) / CLOCKS_PER_SEC << endl << endl;



	FillRand(arr);
	//show(arr);
	clock_t start2 = clock();
	ShellSort(arr);
	clock_t end2 = clock();
	//show(arr);
	cout << setw(25) << "Shell sort (random): " << setw(10) << (double)(end2 - start2) / CLOCKS_PER_SEC << endl;

	FillUp(arr);
	//show(arr);
	start2 = clock();
	ShellSort(arr);
	end2 = clock();
	//show(arr);
	cout << setw(25) << "Shell sort (Up): " << setw(10) << (double)(end2 - start2) / CLOCKS_PER_SEC << endl;

	FillDown(arr);
	//show(arr);
	start2 = clock();
	ShellSort(arr);
	end2 = clock();
	//show(arr);
	cout << setw(25) << "Shell sort (Down): " << setw(10) << (double)(end2 - start2) / CLOCKS_PER_SEC << endl << endl;



	FillRand(arr);
	//show(arr);
	clock_t start3 = clock();
	SelectionSort(arr);
	clock_t end3 = clock();
	//show(arr);
	cout << setw(25) << "Selection sort (random): " << setw(10) << (double)(end3 - start3) / CLOCKS_PER_SEC << endl;

	FillUp(arr);
	//show(arr);
	start3 = clock();
	SelectionSort(arr);
	end3 = clock();
	//show(arr);
	cout << setw(25) << "Selection sort (Up): " << setw(10) << (double)(end3 - start3) / CLOCKS_PER_SEC << endl;

	FillDown(arr);
	//show(arr);
	start3 = clock();
	SelectionSort(arr);
	end3 = clock();
	//show(arr);
	cout << setw(25) << "Selection sort (Down): " << setw(10) << (double)(end3 - start3) / CLOCKS_PER_SEC << endl;

	delete[] arr;
	return 0;
}

void FillRand(int* arr) {
	srand(time(0));
	for (int i = 0; i < N; i++)
		arr[i] = rand() % N;
}
void FillUp(int* arr) {
	for (int i = 0; i < N; i++)
		arr[i] = i;
}
void FillDown(int* arr) {
	for (int i = 0; i < N; i++)
		arr[i] = N - i - 1;
}
void show(int* arr) {
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void InsertionSort(int* arr) {
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
	cout << "count = " << k << endl;
}
//3n^2

//void ShellSort(int* arr)
//{
//	long long k = 0;
//	int d = N / 2, j;
//	while (d > 0)
//	{
//		for (int i = 0; i < N - d; i++)
//		{
//			j = i;
//			while (arr[j] > arr[j + d])
//			{
//				swap(arr[j], arr[j + d]);
//				j--;
//				k += 2;
//			}
//			k += 2;
//		}
//		d /= 2;
//		k += 2;
//	}
//	cout << k << endl;
//}

void ShellSort(int* arr) {
	int temp, s, i, j;
	long long k = 0;
	for (s = N / 2; s > 0; s /= 2)//log(n)
	{
		for (i = s; i < N; ++i)//n-1-log(n)
		{
			for (j = i - s; j >= 0 && arr[j] > arr[j + s]; j -= s)
			{
				swap(arr[j], arr[j + s]);//3
				k += 4;
			}
			k++;
		}
		k++;
	}
	cout << k << endl;
}
//log(n)*(n-1-log(n))*3=4log(n)*n-4log(n)-4log(n)^2

//void SelectionSort(int* arr) {
//	int min_index;
//	long long k = 0;
//	for (int i = 0; i < N - 1; i++)
//	{
//		min_index = i;
//		for (int j = i + 1; j < N; j++)
//		{
//			if (arr[j] < arr[min_index])
//			{
//				min_index = j;
//				k++;
//			}
//			k += 2;
//		}
//		if (min_index != i)
//		{
//			swap(arr[i], arr[min_index]);
//			k++;
//		}
//		k += 2;
//	}
//	cout << k << endl;
//}

void SelectionSort(int* arr) {
	int i, j, min_index;
	long long k = 0;
	for (i = 0; i < N - 1; i++)//n
	{
		min_index = i;//n
		for (j = i + 1; j < N; j++)//((1+n)/2)*n
		{
			if (arr[j] < arr[min_index])//1
			{
				min_index = j;//1
				k += 3;
			}
			k++;
		}
		if (min_index != i)//n
		{
			swap(arr[i], arr[min_index]);//3
			k += 5;
		}
		k += 6;
	}
	cout << k << endl;
}
//n+n+2*(((1+n)/2)*n)+3n=6n+n^2

int increment(long  inc[], long  size) {
	int p1, p2, p3, s;

	p1 = p2 = p3 = 1;
	s = -1;
	do {
		if (++s % 2) {
			inc[s] = 8 * p1 - 6 * p2 + 1;
		}
		else {
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} while (3 * inc[s] < size);

	return s > 0 ? --s : 0;
}
void ShellInc(int* arr) {
	long inc, i, j, seq[40];
	int s;
	s = increment(seq, N);
	while (s >= 0) {
		inc = seq[s--];
		for (i = inc; i < N; i++) {
			int temp = arr[i];
			for (j = i - inc; (j >= 0) && (arr[j] > N); j -= inc)
				arr[j + inc] = arr[j];
			arr[j + inc] = temp;
		}
	}
}
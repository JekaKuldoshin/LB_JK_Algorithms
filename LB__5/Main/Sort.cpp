#include "Main.h"

//�������� ��������� �����
void create_mas_Rand(int size, int A[]) {
	for (int i = 0; i <= (size - 1); i++)
	{
		A[i] = rand() % (size * 5);
	}
}  
//�������� �������������� ������
void create_mas_Up(int size, int A[]) {
	int num = 1;
	for (int i = 0; i < size; i++) { // +
		A[i] = num++;
	}
}  
//�������� ���������������� ������
void create_mas_Down(int size, int A[]) {
	int a = size;
	for (int i = 0; i < size; i++)
	{
		A[i] = a--; // ����������� ��������
	}
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//���������� �����������
void radixSort(int* arr,Data d) {
	int max = arr[0];                //���� ���������� ������ �������� �������
	long long k = 0;
	for (int i = 1; i < d.size; i++) { //������� ������������ �������� �������
		if (arr[i] > max) {
			max = arr[i];
			k += 4;
		}
		k += 3;
	}
	for (int div = 1; max / div > 0; div *= 10) { //��� ������������� ������ ���������� ���������(���-�� ������� ����� ������������� ����� �������)
		countingSort(arr, d.size, div);       //������� ��� ������ ����� � �������
	}

}
void countingSort(int* arr, int N, int div) {
	int output[G];                            //���������� 10 ������� ������ �� ������� ������������ ����� ������� ��� ������ ����� �� 0 �� 9.
	int count[10] = { 0 };

	for (int i = 0; i < N; i++) {
		count[(arr[i] / div) % 10]++;
	}
	for (int i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}

	for (int i = N - 1; i >= 0; i--)
	{
		output[count[(arr[i] / div) % 10] - 1] = arr[i];
		count[(arr[i] / div) % 10]--;
	}

	for (int i = 0; i < N; i++) {
		arr[i] = output[i];
	}
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//������ ����� ���������
void print_TAB_line_search() {
	cout << "------------------------------|" << endl;
	cout << "        �������� �����        |" << endl;
	cout << "------------------------------|" << endl << endl;
}
void print_TAB_barrier_search() {
	cout << "------------------------------|" << endl;
	cout << "       ��������� �����        |" << endl;
	cout << "------------------------------|" << endl << endl;
}
void print_TAB_binary_search() {
	cout << "------------------------------|" << endl;
	cout << "        �������� �����        |" << endl;
	cout << "------------------------------|" << endl << endl;
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//������ ��������
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

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//������ �������
int LinearSearch(int* arr, Data d) {
	int k = 1;
	for (int i = 0; i < d.size; i++) {
		if (arr[i] == d.search) {
			return i;
		}
	}
	return -1;

}
int BarrierSearch(int* arr, Data d)
{
	int k = 1;
	arr = (int*)realloc(arr, (d.size + 1) * sizeof(int));
	arr[d.size + 1] = d.search;
	int i = 0;
	while (arr[i] != d.search) {
		i++;
	}
	return i < d.size ? i : -1;
}
int BinarySearch(int* arr, Data d)
{
	int k = 0;
	radixSort(arr, d);
	int middle,
		low = 0,
		high = d.size;
	while (true) {
		middle = (low + high) / 2;
		if (d.search < arr[middle]) {
			high = middle - 1;
		}
		else if (d.search > arr[middle]) {
			low = middle + 1;
		}
		else {
			return middle;
		}

		if (low > high)
			return -1;
	}
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
�������� ������� ��� �������
void Fun_line_search() {
	Data d;
	int result;

	system("cls");

	print_TAB_line_search();
	cout << "������� ������ ������� -> ";
	cin >> d.size;
	system("cls");

	/////////////////////////////////

	print_TAB_line_search();
	cout << "������ ������� -> " << d.size << endl << endl;

	int* A1 = new int[d.size];

	create_mas_Rand(d.size, A1);
	print_mas_old(d.size, A1);

	cout << "\n\n������� ������� ��� ������ -> ";
	cin >> d.search;
	system("cls");
	
	/////////////////////////////////

	print_TAB_line_search();
	print_mas_old(d.size, A1);
	cout << "\n������� ��� ������ � ������� -> " << d.search << endl;
	result = LinearSearch(A1, d);
	if (result >= 0)
		cout << "\n\n������� ������ ��� ������� -> " << result;
	else
	{
		system("cls");
		cout << "������! ������ ���� �� ������!" << endl;
	}

	cout << endl;

	cout << "\n������� ������� Enter ����� ����������...";
	_getch();
	system("cls");

}
void Fun_barrier_search() {
	Data d;
	int result;

	system("cls");

	print_TAB_barrier_search();
	cout << "������� ������ ������� -> ";
	cin >> d.size;
	system("cls");

	/////////////////////////////////

	print_TAB_barrier_search();
	cout << "������ ������� -> " << d.size << endl << endl;

	int* A1 = new int[d.size];

	create_mas_Rand(d.size, A1);
	print_mas_old(d.size, A1);

	cout << "\n\n������� ������� ��� ������ -> ";
	cin >> d.search;
	system("cls");

	/////////////////////////////////

	print_TAB_barrier_search();
	print_mas_old(d.size, A1);
	cout << "\n������� ��� ������ � ������� -> " << d.search << endl;
	result = BarrierSearch(A1, d);
	if (result >= 0)
		cout << "\n\n������� ������ ��� ������� -> " << result;
	else
	{
		system("cls");
		cout << "������! ������ ���� �� ������!" << endl;
	}

	cout << endl;

	cout << "\n������� ������� Enter ����� ����������...";
	_getch();
	system("cls");

}
void Fun_binary_search() {
	Data d;
	int result;

	system("cls");

	print_TAB_binary_search();
	cout << "������� ������ ������� -> ";
	cin >> d.size;
	system("cls");

	/////////////////////////////////

	print_TAB_binary_search();
	cout << "������ ������� -> " << d.size << endl << endl;

	int* A1 = new int[d.size];

	create_mas_Rand(d.size, A1);
	print_mas_old(d.size, A1);

	cout << "\n\n������� ������� ��� ������ -> ";
	cin >> d.search;
	system("cls");

	/////////////////////////////////

	print_TAB_binary_search();
	print_mas_old(d.size, A1);
	cout << "\n������� ��� ������ � ������� -> " << d.search << endl;
	result = BinarySearch(A1, d);
	print_mas_new(d.size, A1);
	if (result >= 0)
		cout << "\n\n������� ������ ��� ������� -> " << result;
	else
	{
		system("cls");
		cout << "������! ������ ���� �� ������!" << endl;
	}

	cout << endl;

	cout << "\n������� ������� Enter ����� ����������...";
	_getch();
	system("cls");

}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

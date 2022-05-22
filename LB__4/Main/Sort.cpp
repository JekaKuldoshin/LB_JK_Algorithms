#pragma once
#include "Main.h"

void InsertSort(int* arr, int N) {
	int buff = 0; // для хранения перемещаемого значения
	int i, j;

	for (i = 1; i < N; i++)
	{
		buff = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > buff; j--)
			arr[j + 1] = arr[j];

		arr[j + 1] = buff;
	}

}

void create_mas(int size, int A[]) {
	for (int i = 0; i <= (size - 1); i++)
	{
		A[i] = rand() % (size * 5);
	}
}

void print_mas_new(int size, int A[]) {

	cout << "\nМассив после сортировки:\n";
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



void Fun_InsertSort() {
	Data d;
	cout.setf(ios::fixed);
	cout.precision(6);

	system("cls");
	link:
	cout << "------------------------------|" << endl;
	cout << "    Неупорядочнный массив     |" << endl;
	cout << "                              |" << endl;
	cout << "   Сортировка  вставками      |" << endl;
	cout << "------------------------------|" << endl << endl;

	
	cout << "Размер массива -> " << d.size1 << endl << endl;
	
	int* A1 = new int[d.size1];
	
	create_mas(d.size1, A1);

	if (d.print == 1)
	print_mas_old(d.size1, A1);

	clock_t start1 = clock();
	InsertSort(A1, d.size1); // сортировка
	clock_t end1 = clock();

	if (d.print == 1)
	print_mas_new(d.size1,A1);
	
	cout << endl;
	double time1 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\nВремя выполнение  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num1 = d.size1;


	cout << "\nНажмите клавишу Enter чтобы продолжить..." << endl;
	_getch();
	system("cls");

	/////////////////////////////////////////////////////////////////////////////
	cout << "------------------------------|" << endl;
	cout << "    Неупорядочнный массив     |" << endl;
	cout << "                              |" << endl;
	cout << "   Быстрая сортировка Хоара   |" << endl;
	cout << "------------------------------|" << endl << endl;

	cout << "Размер массива -> " << d.size5 << endl << endl;
	
	int* A2 = new int[d.size5];
	create_mas(d.size5, A2);

	if (d.print == 1)
		print_mas_old(d.size5, A2);

	start1 = clock();
	InsertSort(A2, d.size5); // сортировка
	end1 = clock();

	if (d.print == 1)
		print_mas_new(d.size5, A2);

	cout << endl;
	double time2 = ((double)(end1 - start1) / CLOCKS_PER_SEC);
	cout << "\nВремя выполнение  ->  " << (double)(end1 - start1) / CLOCKS_PER_SEC << '\n';
	int num2 = d.size2;

	cout << "\nНажмите клавишу Enter чтобы продолжить..." << endl;
	_getch();
	system("cls");

	////////////////////////////////////////////////////////////////////////
	//cout << "------------------------------|" << endl;
	//cout << "    Неупорядочнный массив     |" << endl;
	//cout << "                              |" << endl;
	//cout << "   Быстрая сортировка Хоара   |" << endl;
	//cout << "------------------------------|" << endl << endl;

	//
	//int size3 = 15;
	//cout << "Размер массива -> " << size3 << endl << endl;
	//
	//int* A3 = new int[size3];
	//for (int i = 0; i <= (size3 - 1); i++)
	//{
	//	A3[i] = rand() % (size3 * 5);
	//	cout << A3[i] << " | ";
	//}
	//

	//quickSort(A3, 0, size3 - 1); // сортировка

	//cout << "\nМассив после сортировки:\n";
	//for (int k = 0; k < size3; k++)
	//{
	//	cout << A3[k] << " | ";
	//}
	//Timer t3;
	//cout << endl;
	//double time3 = t3.elapsed();
	//cout << "\nВремя выполнение  ->  " << time3 << '\n';
	//int num3 = size3;

	//cout << "\nНажмите клавишу Enter чтобы продолжить..." << endl;
	//_getch();
	//system("cls");

	////////////////////////////////////////////////////////////////
	//cout << "------------------------------|" << endl;
	//cout << "    Неупорядочнный массив     |" << endl;
	//cout << "                              |" << endl;
	//cout << "   Быстрая сортировка Хоара   |" << endl;
	//cout << "------------------------------|" << endl << endl;


	//int size4 = 20;
	//cout << "Размер массива -> " << size4 << endl << endl;
	//
	//int* A4 = new int[size4];
	//for (int i = 0; i <= (size4 - 1); i++)
	//{
	//	A4[i] = rand() % (size4 * 5);
	//	cout << A4[i] << " | ";
	//}
	//

	//quickSort(A4, 0, size4 - 1); // сортировка

	//cout << "\nМассив после сортировки:\n";
	//for (int k = 0; k < size4; k++)
	//{
	//	cout << A4[k] << " | ";
	//}
	//Timer t4;
	//cout << endl;
	//double time4 = t4.elapsed();
	//cout << "\nВремя выполнение  ->  " << time4 << '\n';
	//int num4 = size4;

	//cout << "\nНажмите клавишу Enter чтобы продолжить..." << endl;
	//_getch();
	//system("cls");

	////////////////////////////////////////////////////////
	//cout << "------------------------------|" << endl;
	//cout << "    Неупорядочнный массив     |" << endl;
	//cout << "                              |" << endl;
	//cout << "   Быстрая сортировка Хоара   |" << endl;
	//cout << "------------------------------|" << endl << endl;


	//int size5 = 25;
	//cout << "Размер массива -> " << size5 << endl << endl;
	//
	//int* A5 = new int[size5];
	//for (int i = 0; i <= (size5 - 1); i++)
	//{
	//	A5[i] = rand() % (size5 * 5);
	//	cout << A5[i] << " | ";
	//}
	//

	//quickSort(A5, 0, size5 - 1); // сортировка

	//cout << "\nМассив после сортировки:\n";
	//for (int k = 0; k < size5; k++)
	//{
	//	cout << A5[k] << " | ";
	//}
	//Timer t5;
	//cout << endl;
	//double time5 = t5.elapsed();
	//cout << "\nВремя выполнение  ->  " << time5 << '\n';
	//int num5 = size5;

	//cout << "\nНажмите клавишу Enter чтобы продолжить..." << endl;
	//_getch();
	//system("cls");

	///////////////////////////////////////////////////////
	//cout << "------------------------------|" << endl;
	//cout << "    Неупорядочнный массив     |" << endl;
	//cout << "                              |" << endl;
	//cout << "   Быстрая сортировка Хоара   |" << endl;
	//cout << "------------------------------|" << endl << endl;

	//
	//int size6 = 30;
	//cout << "Размер массива -> " << size6 << endl << endl;
	//
	//int* A6 = new int[size6];
	//for (int i = 0; i <= (size6 - 1); i++)
	//{
	//	A6[i] = rand() % (size6 * 5);
	//	cout << A6[i] << " | ";
	//}
	//
	//quickSort(A6, 0, size6 - 1); // сортировка

	//cout << "\nМассив после сортировки:\n";
	//for (int k = 0; k < size6; k++)
	//{
	//	cout << A6[k] << " | ";
	//}
	//Timer t6;
	//cout << endl;
	//double time6 = t6.elapsed();
	//cout << "\nВремя выполнение  ->  " << time6 << '\n';
	//int num6 = size6;

	//cout << "\nНажмите клавишу Enter чтобы продолжить..." << endl;
	//_getch();
	//system("cls");

	///////////////////////////////////////////////////////
	//cout << "------------------------------|" << endl;
	//cout << "    Неупорядочнный массив     |" << endl;
	//cout << "                              |" << endl;
	//cout << "   Быстрая сортировка Хоара   |" << endl;
	//cout << "------------------------------|" << endl << endl;

	//
	//int size7 = 35;
	//cout << "Размер массива -> " << size7 << endl << endl;
	//
	//int* A7 = new int[size7];
	//for (int i = 0; i <= (size7 - 1); i++)
	//{
	//	A7[i] = rand() % (size7 * 5);
	//	cout << A7[i] << " | ";
	//}
	//

	//quickSort(A7, 0, size7 - 1); // сортировка

	//cout << "\nМассив после сортировки:\n";
	//for (int k = 0; k < size7; k++)
	//{
	//	cout << A7[k] << " | ";
	//}
	//Timer t7;
	//cout << endl;
	//double time7 = t7.elapsed();
	//cout << "\nВремя выполнение  ->  " << time7 << '\n';
	//int num7 = size7;

	//cout << "\nНажмите клавишу Enter чтобы продолжить..." << endl;
	//_getch();
	//system("cls");

	///////////////////////////////////////////////////////
	//cout << "------------------------------|" << endl;
	//cout << "    Неупорядочнный массив     |" << endl;
	//cout << "                              |" << endl;
	//cout << "   Быстрая сортировка Хоара   |" << endl;
	//cout << "------------------------------|" << endl << endl;

	//int size8 = 40;
	//cout << "Размер массива -> " << size8 << endl << endl;
	//
	//int* A8 = new int[size8];
	//for (int i = 0; i <= (size8 - 1); i++)
	//{
	//	A8[i] = rand() % (size8 * 5);
	//	cout << A8[i] << " | ";
	//}
	//

	//quickSort(A8, 0, size8 - 1); // сортировка

	//cout << "\nМассив после сортировки:\n";
	//for (int k = 0; k < size8; k++)
	//{
	//	cout << A8[k] << " | ";
	//}
	//Timer t8;
	//cout << endl;
	//double time8 = t8.elapsed();
	//cout << "\nВремя выполнение  ->  " << time8 << '\n';
	//int num8 = size8;

	//cout << "\nНажмите клавишу Enter чтобы продолжить..." << endl;
	//_getch();
	//system("cls");

	///////////////////////////////////////////////////////
	//cout << "------------------------------|" << endl;
	//cout << "    Неупорядочнный массив     |" << endl;
	//cout << "                              |" << endl;
	//cout << "   Быстрая сортировка Хоара   |" << endl;
	//cout << "------------------------------|" << endl << endl;


	//int size9 = 45;
	//cout << "Размер массива -> " << size9 << endl << endl;
	//
	//int* A9 = new int[size9];
	//for (int i = 0; i <= (size9 - 1); i++)
	//{
	//	A9[i] = rand() % (size9 * 5);
	//	cout << A9[i] << " | ";
	//}

	//quickSort(A9, 0, size9 - 1); // сортировка

	//cout << "\nМассив после сортировки:\n";
	//for (int k = 0; k < size9; k++)
	//{
	//	cout << A9[k] << " | ";
	//}
	//Timer t9;
	//cout << endl;
	//double time9 = t9.elapsed();
	//cout << "\nВремя выполнение  ->  " << time9 << '\n';
	//int num9 = size9;

	//cout << "\nНажмите клавишу Enter для получения результатов..." << endl;
	//_getch();
	//system("cls");

	/////////////////////////////////////////////////////
	int n = 6;

	cout << endl;
	cout << " |-------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
	cout << " |                                                                       Неупорядочнный массив                                                     |" << endl;
	cout << " |----------------------------|--------------------------------------------------------------------------------------------------------------------|" << endl;
	cout << " |                            |                                           Количество элементов в массиве                                           |" << endl;
	cout << " |                            |--------------------------------------------------------------------------------------------------------------------|" << endl;
	cout << " |                            | " << setw(n) << num1 << setw(5); /*<< "    /* | " << setw(n) << num2 << setw(5) << "     | " << setw(n) << num3 << setw(5) << "     | " << setw(n) << num4 << setw(5) << "     | " << setw(n) << num5 << setw(5) << "     | " << setw(n) << num6 << setw(5) << "     | " << setw(n) << num7 << setw(5) << "     | " << setw(n) << num8 << setw(5) << "     | " << setw(n) << num9 << setw(5) << "     |" << endl;
	cout << " |----------------------------|--------------------------------------------------------------------------------------------------------------------|" << endl;
	*/cout << " |  Быстрая сортировка Хоара  | " << setw(10) << time1 << " | " << setw(10); /*<< time2 << " | " << setw(10) << time3 << " | " << setw(10) << time4 << " | " << setw(10) << time5 << " | " << setw(10) << time6 << " | " << setw(10) << time7 << " | " << setw(10) << time8 << " | " << setw(10) << time9 << " |" << endl;
	cout << " |----------------------------|--------------------------------------------------------------------------------------------------------------------|" << endl;
*/

	cout << "\nНажмите клавишу Enter для перехода в меню..." << endl;
	_getch();
	system("cls");

}
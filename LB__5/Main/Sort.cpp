#include "Main.h"

//Создание рандомных чисел
void create_mas_Rand(int size, int A[]) {
	for (int i = 0; i <= (size - 1); i++)
	{
		A[i] = rand() % (size * 5);
	}
}  
//Создание упорядоченного масива
void create_mas_Up(int size, int A[]) {
	int num = 1;
	for (int i = 0; i < size; i++) { // +
		A[i] = num++;
	}
}  
//Создание неупорядоченного масива
void create_mas_Down(int size, int A[]) {
	int a = size;
	for (int i = 0; i < size; i++)
	{
		A[i] = a--; // упорядочный наоборот
	}
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//Сортировка поразрядная
void radixSort(int* arr,Data d) {
	int max = arr[0];                //Даем переменной первое значение массива
	long long k = 0;
	for (int i = 1; i < d.size; i++) { //Находим максимальное значение массива
		if (arr[i] > max) {
			max = arr[i];
			k += 4;
		}
		k += 3;
	}
	for (int div = 1; max / div > 0; div *= 10) { //Для многоразового вызова сортировки подсчетом(кол-во вызовов равно максимальному числу массива)
		countingSort(arr, d.size, div);       //Считаем для кажого числа в массиве
	}

}
void countingSort(int* arr, int N, int div) {
	int output[G];                            //Определяем 10 чередей каждая из которых представляет собой сегмент для каждой цифры от 0 до 9.
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
//Печать шапки программы
void print_TAB_line_search() {
	cout << "------------------------------|" << endl;
	cout << "        Линейный поиск        |" << endl;
	cout << "------------------------------|" << endl << endl;
}
void print_TAB_barrier_search() {
	cout << "------------------------------|" << endl;
	cout << "       Барьерный поиск        |" << endl;
	cout << "------------------------------|" << endl << endl;
}
void print_TAB_binary_search() {
	cout << "------------------------------|" << endl;
	cout << "        Бинарный поиск        |" << endl;
	cout << "------------------------------|" << endl << endl;
}
//--------------------------------------
void print_TAB_direct_search() {
	cout << "------------------------------|" << endl;
	cout << "        Прямой поиск          |" << endl;
	cout << "------------------------------|" << endl;
}
void print_TAB_KMP_search() {
	cout << "---------------------------------|" << endl;
	cout << "  Алгоритм Кнута-Морриса-Пратта  |" << endl;
	cout << "---------------------------------|" << endl << endl;
}
void print_TAB_BM_search() {
	cout << "-----------------------------|" << endl;
	cout << "    Алгоритм Бойера-Мура     |" << endl;
	cout << "-----------------------------|" << endl << endl;
}
void print_TAB_RK_search() {
	cout << "-----------------------------|" << endl;
	cout << "   Алгоритм Рабина – Карпа   |" << endl;
	cout << "-----------------------------|" << endl << endl;
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//Печать массивов
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

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//Логика поисков
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
Основные функции для поисков
void Fun_line_search() {
	Data d;
	int result;

	cout.setf(ios::fixed);
	cout.precision(6);

	system("cls");

	print_TAB_line_search();
	cout << "Введите размер массива -> ";
	cin >> d.size;
	system("cls");

	/////////////////////////////////

	print_TAB_line_search();
	cout << "Размер массива -> " << d.size << endl << endl;

	int* A1 = new int[d.size];

	create_mas_Rand(d.size, A1);
	print_mas_old(d.size, A1);

	cout << "\n\nВведите элемент для поиска -> ";
	cin >> d.search;
	system("cls");
	
	/////////////////////////////////

	print_TAB_line_search();
	print_mas_old(d.size, A1);
	cout << "\nЭлемент для поиска в массиве -> " << d.search << endl;

	result = LinearSearch(A1, d);
	if (result >= 0) {
		Timer t1;
		cout << endl;
		double time1 = t1.elapsed();
		cout << "\n\nЭлемент найден под номером -> " << result;
		cout << "\nВремя выполнение  ->  " << time1 << '\n';
	}
	else
	{
		system("cls");
		cout << "Ошибка! Данные были не найдны!" << endl;
	}

	cout << endl;

	cout << "\nНажмите клавишу Enter чтобы продолжить...";
	_getch();
	system("cls");

}
void Fun_barrier_search() {
	Data d;
	int result;

	system("cls");

	print_TAB_barrier_search();
	cout << "Введите размер массива -> ";
	cin >> d.size;
	system("cls");

	/////////////////////////////////

	print_TAB_barrier_search();
	cout << "Размер массива -> " << d.size << endl << endl;

	int* A1 = new int[d.size];

	create_mas_Rand(d.size, A1);
	print_mas_old(d.size, A1);

	cout << "\n\nВведите элемент для поиска -> ";
	cin >> d.search;
	system("cls");

	/////////////////////////////////

	print_TAB_barrier_search();
	print_mas_old(d.size, A1);
	cout << "\nЭлемент для поиска в массиве -> " << d.search << endl;
	result = BarrierSearch(A1, d);
	if (result >= 0) {
	Timer t1;
	cout << endl;
	double time1 = t1.elapsed();
	cout << "\n\nЭлемент найден под номером -> " << result;
	cout << "\nВремя выполнение  ->  " << time1 << '\n';
	}
	else
	{
		system("cls");
		cout << "Ошибка! Данные были не найдны!" << endl;
	}

	cout << endl;

	cout << "\nНажмите клавишу Enter чтобы продолжить...";
	_getch();
	system("cls");

}
void Fun_binary_search() {
	Data d;
	int result;

	system("cls");

	print_TAB_binary_search();
	cout << "Введите размер массива -> ";
	cin >> d.size;
	system("cls");

	/////////////////////////////////

	print_TAB_binary_search();
	cout << "Размер массива -> " << d.size << endl << endl;

	int* A1 = new int[d.size];

	create_mas_Rand(d.size, A1);
	print_mas_old(d.size, A1);

	cout << "\n\nВведите элемент для поиска -> ";
	cin >> d.search;
	system("cls");

	/////////////////////////////////

	print_TAB_binary_search();
	print_mas_old(d.size, A1);
	cout << "\nЭлемент для поиска в массиве -> " << d.search << endl;
	result = BinarySearch(A1, d);
	print_mas_new(d.size, A1);
	if (result >= 0) {
		Timer t1;
		cout << endl;
		double time1 =
			t1.elapsed();
		cout << "\n\nЭлемент найден под номером -> " << result;
		cout << "\nВремя выполнение  ->  " << time1 << '\n';
	}
	else
	{
		system("cls");
		cout << "Ошибка! Данные были не найдны!" << endl;
	}

	cout << endl;

	cout << "\nНажмите клавишу Enter чтобы продолжить...";
	_getch();
	system("cls");

}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
Основные функции для поисков строк
void Fun_STR_direct_search() {
	int menu,result;
	string s, s1;

	link_menu:
	system("cls");
	//print_TAB_direct_search();
	cout << "------------------------------|" << endl;
	cout << "        Прямой поиск          |" << endl;
	cout << "------------------------------|" << endl;
	cout << " 1 - Заполнить с файла        |" << endl;
	cout << " 2 - Заполнить вручную        |" << endl;
	cout << "------------------------------|" << endl << endl;
	cout << "Сделайте свой выбор -> ";
	cin >> menu;
	switch (menu) {
	case 1:
		s = from_the_file(s);
		break;
	case 2:
		system("cls");
		s = create_str(s);
		break;
	default:
		system("cls");
		cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... " << endl;
		_getch();
		goto link_menu;
		break;
	}

	system("cls");
	print_TAB_direct_search();
	cout <<"\n"<< s;

	cout << "\n\nВведите данные для поиска -> ";
	cin >> s1;

	result = DirectSearch(s, s1);

	if (result >= 0) {
		Timer t1;
		cout << endl;
		double time1 = t1.elapsed();
		cout << "\n\nЭлемент найден под номером -> " << result;
		cout << "\nВремя выполнение  ->  " << time1 << '\n';
	}
	else
	{
		system("cls");
		cout << "Ошибка! Данные были не найдны!" << endl;
	}

	cout << "\n\n\nНажмите клавишу Enter чтобы продолжить...";
	_getch();
	system("cls");

}
void Fun_STR_KMP_search() {
	int menu, result;
	string s, s1;

link_menu:
	system("cls");
	//print_TAB_direct_search();
	cout << "-------------------------------|" << endl;
	cout << " Алгоритм Кнута-Морриса-Пратта |" << endl;
	cout << "-------------------------------|" << endl;
	cout << " 1 - Заполнить с файла         |" << endl;
	cout << " 2 - Заполнить вручную         |" << endl;
	cout << "-------------------------------|" << endl << endl;
	cout << "Сделайте свой выбор -> ";
	cin >> menu;
	switch (menu) {
	case 1:
		s = from_the_file(s);
		break;
	case 2:
		system("cls");
		s = create_str(s);
		break;
	default:
		system("cls");
		cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... " << endl;
		_getch();
		goto link_menu;
		break;
	}

	system("cls");
	print_TAB_KMP_search();
	cout << "\n" << s;

	cout << "\n\nВведите данные для поиска -> ";
	cin >> s1;

	result = KMPSearch(s, s1);

	if (result >= 0) {
		Timer t1;
		cout << endl;
		double time1 = t1.elapsed();
		cout << "\n\nЭлемент найден под номером -> " << result;
		cout << "\nВремя выполнение  ->  " << time1 << '\n';
	}
	else
	{
		system("cls");
		cout << "Ошибка! Данные были не найдны!" << endl;
	}

	cout << "\n\n\nНажмите клавишу Enter чтобы продолжить...";
	_getch();
	system("cls");
}
void Fun_STR_BM_search() {
	int menu, result;
	string s, s1;

link_menu:
	system("cls");
	//print_TAB_direct_search();
	cout << "-------------------------------|" << endl;
	cout << "      Алгоритм Бойера-Мура     |" << endl;
	cout << "-------------------------------|" << endl;
	cout << " 1 - Заполнить с файла         |" << endl;
	cout << " 2 - Заполнить вручную         |" << endl;
	cout << "-------------------------------|" << endl << endl;
	cout << "Сделайте свой выбор -> ";
	cin >> menu;
	switch (menu) {
	case 1:
		s = from_the_file(s);
		break;
	case 2:
		system("cls");
		s = create_str(s);
		break;
	default:
		system("cls");
		cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... " << endl;
		_getch();
		goto link_menu;
		break;
	}

	system("cls");
	print_TAB_BM_search();
	cout << "\n" << s;

	cout << "\n\nВведите данные для поиска -> ";
	cin >> s1;

	result = BMSearch(s, s1);
	if (result >= 0) {
		Timer t1;
		cout << endl;
		double time1 = t1.elapsed();
		cout << "\n\nЭлемент найден под номером -> " << result;
		cout << "\nВремя выполнение  ->  " << time1 << '\n';
	}
	else
	{
		system("cls");
		cout << "Ошибка! Данные были не найдны!" << endl;
	}

	cout << "\n\n\nНажмите клавишу Enter чтобы продолжить...";
	_getch();
	system("cls");
}
void Fun_STR_RK_search() {
	int menu, result;
	string s, s1;

link_menu:
	system("cls");

	//print_TAB_direct_search();
	cout << "-------------------------------|" << endl;
	cout << "    Алгоритм Рабина – Карпа    |" << endl;
	cout << "-------------------------------|" << endl;
	cout << " 1 - Заполнить с файла         |" << endl;
	cout << " 2 - Заполнить вручную         |" << endl;
	cout << "-------------------------------|" << endl << endl;
	cout << "Сделайте свой выбор -> ";
	cin >> menu;
	switch (menu) {
	case 1:
		s = from_the_file(s);
		break;
	case 2:
		system("cls");
		s = create_str(s);
		break;
	default:
		system("cls");
		cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... " << endl;
		_getch();
		goto link_menu;
		break;
	}

	system("cls");
	print_TAB_RK_search();
	cout << "\n" << s;

	cout << "\n\nВведите данные для поиска -> ";
	cin >> s1;

    result = RKSearch(s1, s, 33);

	if (result >= 0) {
		Timer t1;
		cout << endl;
		double time1 = t1.elapsed();
		cout << "\n\nЭлемент найден под номером -> " << result;
		cout << "\nВремя выполнение  ->  " << time1 << '\n';
	}
	else
	{
		system("cls");
		cout << "Ошибка! Данные были не найдны!" << endl;
	}

	cout << "\n\n\nНажмите клавишу Enter чтобы продолжить...";
	_getch();
	system("cls");
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\
Функция создания строки
string create_str(string s) {
	int menu1;
	system("cls");
	print_TAB_direct_search();
	cout << "Введите данные для строки -> ";
	cin >> s;

	system("cls");
	cout << "Успех! Данные были заполнены!\n\nНажмите клавишу Enter чтобы продолжить...";
	_getch();

link_menu:
	system("cls");
	cout << "       Прямой поиск        |" << endl;
	cout << "---------------------------|" << endl;
	cout << "1 - Делать запись в файл?  |" << endl;
	cout << "2 - Продолжить...          |" << endl;
	cout << "---------------------------|" << endl;
	cout << "Сделайте свой выбор -> ";
	cin >> menu1;
	switch (menu1) {
	case 1:
		in_file(s);
		break;
	case 2:
		system("cls");
		cout << "Успех! Данные были заполнены!\n\nНажмите клавишу Enter чтобы продолжить...";
		_getch();
		break;
	default:
		system("cls");
		cout << "Ошибка!! Пункт меню отсутствует!!!\nДля перехода в меню нажмите любую клавишу... " << endl;
		_getch();
		goto link_menu;
		break;
	}
	return s;
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\
Функция создания строк с файла
string  from_the_file(string s) {
	system("cls");
	fstream f("Text.txt", ios::in);   //Переменная для работы с файлом, открыли файл
	if (f.is_open()) {                  //Проверка на открытие файла
		while (getline(f, s))
		{
			f >> s;
		}
	}
	else {
		cout << "Ошибка! Файл не найден!";
	}
	f.close();                 //Закрыли файл
	system("cls");
	cout << "Успех! Чтение с файла было выполнено!\n\nНажмите клавишу Enter чтобы продолжить...";
	_getch();
	return s;
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\
Функция записи строк в файл
void in_file(string s) {

	system("cls");
	fstream f("Text.txt", ios::out);   //Переменная для работы с файлом, открыли файл
	f.imbue(std::locale(""));
	if (f.is_open()) {                  //Проверка на открытие файла
			f << s;
	}
	else {
		cout << "Ошибка! Файл не найден!";
	}
	f.close();                 //Закрыли файл
	system("cls");
	cout << "Успех! Запись в файл было выполнено!\n\nНажмите клавишу Enter чтобы продолжить...";
	_getch();

}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\
Логика поисков строк
int DirectSearch(string& s, string key)
{
	int n, k, j;
	int c = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == key[0])
		{
			n = k = i;
			j = 0;
			c += 3;
			while (s[k] == key[j])
			{
				k++;
				j++;
				if (j >= key.size()) {
					cout << "\n\nКоличество переборов = " << c << endl;
					return n;
				}
				c += 4;
			}
		}
		c += 2;
	}
	return -1;
}

int KMPSearch(string& s, string key)
{
	int* P = new int[key.size()];
	prefix(key, P);
	int k,
		l = 0;
	int c = 0;
	for (k = 0; k < s.size(); ) {
		if (s[k] == key[l])
		{
			k++;
			l++;
			if (l == key.size()) {
				cout << "\n\nКоличество переборов = " << c << endl;
				return k - key.size();
			}
			c += 2;
		}
		else  if (l == 0)
		{
			k++;
			if (k == s.size()) {
				cout << "\n\nКоличество переборов = " << c << endl;
				return -1;
			}
			c += 2;
		}
		else if (l != 0) {
			l = P[l - 1];
			c++;
		}
		c++;
	}
	return -1;
}
void prefix(string& s, int*& P)
{
	P[0] = 0;
	int j = 0,
		i;
	for (i = 1; i < s.size();)
		if (s[i] == s[j])
		{
			P[i] = j + 1;
			i++;
			j++;
		}
		else if (j == 0)
		{
			P[i] = 0;
			i++;
		}
		else
			j = P[j - 1];
}

int BMSearch(string txt, string pat) 
{
	int k = 256 * 2;
	int m = pat.size();
	int n = txt.size();
	int badchar[NO_OF_CHARS];
	badCharHeuristic(pat, m, badchar);
	int s = 0;
	while (s <= (n - m))
	{
		int j = m - 1;
		k++;
		while (j >= 0 && pat[j] == txt[s + j]) {
			k++;
			j--;
		}
		if (j < 0)
		{
			cout << "\n\nКоличество переборов = " << k << endl;
			return s;
			//s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
		}
		else {
			s += max(1, j - badchar[txt[s + j]]);
			k++;
		}
		k++;
	}
	return -1;
}
void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS])
{
	int i;
	for (i = 0; i < NO_OF_CHARS; i++)
		badchar[i] = -1;
	for (i = 0; i < size; i++)
		badchar[(int)str[i]] = i;
}

int RKSearch(string s1, string text1, int inputBase) { //n, n, nm //+m
	char s[10001];
	strcpy_s(s, s1.c_str());
	char text[10001];
	strcpy_s(text, text1.c_str());
	int patternLen = strlen(s);
	int textLen = strlen(text);
	int i, j, k = 0;
	int patternHash = 0;
	int textHash = 0;
	int patternLenOut = 0;

	for (i = 0; i < patternLen; i++) {
		patternHash = (s[i]) % inputBase;
		textHash = (text[i]) % inputBase;
		k += 5;
	}

	for (i = 0; i <= textLen - patternLen; i++) {
		if (patternHash == textHash) {
			for (j = 0; j < patternLen; j++) {
				if (text[i + j] != s[j])
					break;
				k += 2;
			}

			if (j == patternLen) {
				cout << "\n\nКоличество переборов = " << k << endl;
				return i;
			}
			k++;
		}

		if (i < textLen - patternLen) {
			textHash = (text[i + patternLen]) % inputBase;
			//k += 3;
			if (textHash < 0) {
				textHash = (textHash + inputBase);
				//k+=3;
			}
			//k += 2;
		}
		k++;
	}
	return -1;
	}

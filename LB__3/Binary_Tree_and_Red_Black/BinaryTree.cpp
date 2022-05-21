#include "BinaryTree.h"

Data::Data(string s, int y, int k) {
	name = s;
	year = y;
	kol = k;
	Left = Right = Parent = nullptr;
}

Tree::Tree() {
	Root = nullptr;
	count = tabs = 0;
}

bool Tree::check() {                 //\\//\\ Функ-я для проверки на пустоту бинарного дерева //\\//\\ 
	if (Root == NULL)
	{
		system("cls");
		cout << "Ошибка! Бинарное дерево отсутствует!!!\n\nНажмите на Enter чтобы продолжить...";
		_getch();
		return false;
	}
	else
	{
		return true;             //Если возврашает True, то мы можем пользоваться всем функционалом программы
	}

}

void Tree::add(string n, int y, int k) {               //\\//\\ Функ-я добавления в бинарное дерево //\\//\\ 
	Data* temp = new Data(n, y, k);           //Создали указатель на данные
	Data* ptr, * ptr1;                       //Указатели на перемещение
	ptr = ptr1 = Root;                      //Прировняли к корню
	while (ptr != 0)                       //Пока не закончатся перемещенные элементы
	{
		ptr1 = ptr;
		if (temp->name < ptr->name)      //Если имя меньше предложенного Name1 < Name2
		{
			ptr = ptr->Left;           //Перемешаем тогда влево
		}
		else                         //Вслучае если Name1 > Name2
		{
			ptr = ptr->Right;      //Перемещаем вправо
		}
	}
	temp->Parent = ptr1;        //Последний элемент становится родителем
	if (ptr1 == 0)             //Если равняется нулю, то есть Бинарное дерево пустое
	{
		Root = temp;         //Элемент становится корнем
	}
	else                   //Случай когда уже есть данные в дереве
	{
		if (temp->name < ptr1->name)         //Если Name1 < Name2
		{
			ptr1->Left = temp;             //Перемешаем тогда влево
		}
		else                             //Вслучае если Name1 > Name2
		{
			ptr1->Right = temp;        //Перемещаем вправо
		}
	}
	count++;                        //Переменная для подсчета
}

void Tree::addByYear(Data* node) {                                  //\\//\\ //Функция для добавления, по Году //\\//\\ 
	Data* temp = new Data(node->name, node->year, node->kol);   //Создали указатель на данные
	Data* ptr, * ptr1;                                         //Указатели на перемещение
	ptr = ptr1 = Root;                                        //Прировняли к корню
	while (ptr != 0)                                         //Пока не закончатся перемещенные элементы
	{
		ptr1 = ptr;
		if (temp->year < ptr->year)             //Если год меньше предложенного Year1 < Year2
		{
			ptr = ptr->Left;                  //Перемешаем тогда влево
		}
		else                                //Вслучае если Year1 > Year2
		{
			ptr = ptr->Right;             //Перемещаем вправо
		}
	}
	temp->Parent = ptr1;               //Последний элемент становится родителем
	if (ptr1 == 0)                    //Если равняется нулю, то есть Бинарное дерево пустое
	{
		Root = temp;			    //Элемент становится корнем
	}
	else                          //Случай когда уже есть данные в дереве
	{
		if (temp->year < ptr1->year)        //Если Year1 < Year2
		{
			ptr1->Left = temp;            //Перемешаем тогда влево
		}
		else                            //Вслучае если Year1 > Year2
		{
			ptr1->Right = temp;       //Перемещаем вправо
		}
	}
	count++;					   //Переменная для подсчета
}

void Tree::add_by_y(string name, int y, int k) {       //\\//\\ Функция для добавления, по Году //\\//\\ 
	Data* n = new Data(name, y, k);        //Создали указатель на данные
	addByYear(n);                         //Передаем в функцию по определению места и вставка
}

void Tree::showForward(Data* n) {            //\\//\\ Функция для вывода бинарного дерева //\\//\\ 
	if (n != 0)    //Пока не закончатся данные
	{
		tabs++;                    //Пробел
		showForward(n->Right);    //Выводим правые данные
		for (int i = 0; i < tabs; i++) cout << "	";                 //Делаем определенное кол-во пробелов
		cout << n->name << " " << n->year << " " << n->kol << endl;   //Выводим данные через пробел
		showForward(n->Left);                                        //Выводим левые данные
		tabs--;
	}
}

void Tree::showF(Data* n) {            //\\//\\ Вывод прямого обхода //\\//\\ 
	if (n != 0)  //Пока не закончатся данные
	{
		cout << n->name << " " << n->year << " " << n->kol << endl;  //Выводим корень
		showF(n->Left);         //Выводим левые данные
		showF(n->Right);       //Выводим правые данные
	}
}

void Tree::showBackward(Data* n) {        //\\//\\ Вывод обратного обхода //\\//\\ 
	if (n != 0) //Пока не закончатся данные
	{
		showBackward(n->Left);      //Выводим левые данные
		showBackward(n->Right);    //Выводим правые данные
		for (int i = 0; i < tabs; i++) cout << "	";                 //Делаем определенное кол-во пробелов
		cout << n->name << " " << n->year << " " << n->kol << endl;   //Выводим данные через пробел
	}
}

void Tree::showSymmetrically(Data* n) {       //\\//\\ Вывод симетричного обхода //\\//\\ 
	if (n != 0)  //Пока не закончатся данные
	{
		showSymmetrically(n->Left);                                   //Выводим левые данные
		for (int i = 0; i < tabs; i++) cout << "	";               //Делаем определенное кол-во пробелов
		cout << n->name << " " << n->year << " " << n->kol << endl; //Выводим данные через пробел
		showSymmetrically(n->Right);							   //Выводим правые данные
	}
}

void Tree::show()                   //\\//\\ Функ-я которая проверяет и обращается к выводу //\\//\\ 
{
	showForward(Root);     //Выводим данные	
}

void Tree::showPreOrder() {            //\\//\\ Промежуточная функция для вывода прямого обхода //\\//\\ 
	system("cls");

	cout << "Печать при прямом обходе |" << endl;
	cout << "-------------------------|\n\n";
	showF(Root);     //Заходим в функ-ю вывода прямого обхода
}

void Tree::showPostOrder() {         //\\//\\ Промежуточная функция для вывода обратного обхода //\\//\\ 
	system("cls");
	cout << "Печать при обратном обходе |" << endl;
	cout << "---------------------------|\n\n";
	showBackward(Root);         //Заходим в функ-ю вывода обратного обхода
}

void Tree::showSymm() {          //\\//\\ Промежуточная функция для вывода симетричного обхода //\\//\\ 

	system("cls");
	cout << "Печать при симетричном обходе |" << endl;
	cout << "------------------------------|\n\n";
	showSymmetrically(Root);         //Заходим в функ-ю вывода симетричного обхода
}

void Tree::delLeft(Data* n) {       //\\//\\ Функ-я удаления левой ветки и зануливам ее //\\//\\ 
	if (n != 0)            //Пока не закончатся данные
	{
		delLeft(n->Left);				//Удаляем левые данные
		delLeft(n->Right);			   //Удаляем правые данные
		n->Parent->Left = nullptr;    //Обнуляем левую ветку и родителя
		n->Parent = 0;
		delete n;
		count--;                   //Уменьшаем кол-во
	}
}

void Tree::delLeftTree() {    //\\//\\ /Функция проверки на пустоту левой ветки //\\//\\ 
	if (Root->Left != 0)	//Пока не закончатся данные
	{
		delLeft(Root->Left);     //Заходим в функ-ю удаления, относительно корня двигаемся влево
	}
}

void Tree::delRight(Data* n) {		//\\//\\ Функ-я удаления правой ветки и зануливам ее //\\//\\ 
	if (n != 0)					 //Пока не закончатся данные
	{
		delRight(n->Right);			  //Удаляем правые данные
		delRight(n->Left);		     //Удаляем левые данные
		n->Parent->Right = nullptr; //Обнуляем левую ветку и родителя
		n->Parent = 0;
		delete n;
		count--;				 //Уменьшаем кол-во
	}
}

void Tree::delRightTree() {		//\\//\\ /Функция проверки на пустоту правой ветки //\\//\\ 
	if (Root->Right != 0)	//Пока не закончатся данные
	{
		delRight(Root->Right);		//Заходим в функ-ю удаления, относительно корня двигаемся вправо
	}
}

void Tree::delTree() {    //\\//\\ Функ-я удаление бинарного дерева //\\//\\ 
	delLeftTree();      //Удаляем левую ветку
	delRightTree();    //Удаляем правую ветку
	Root = nullptr;   //Обнуляем корень
	delete Root;     //Удаляем корень
	count--;        //Уменьшаем кол-во
}

void Tree::makeVectorFromTree(Data* n, vector<Data*>& m) {		 //\\//\\ Создаем и заносим данные в вектор массива для раскраски бинарного дерева //\\//\\ 
	if (n != 0)						//Пока не закончатся данные
	{
		m.push_back(n);                       //Вставляем в конец
		makeVectorFromTree(n->Left, m);      //По левую сторону
		makeVectorFromTree(n->Right, m);    //По правую сторону
	}
}

void Tree::remake() {              //\\//\\ //Функция для создания нового дерева //\\//\\   
	Tree tree;                                   //Новое дерево
	vector<Data*> mas;                          //Массив для данных
	makeVectorFromTree(Root, mas);			   //Заносим данные в вектор
	for (int i = 0; i < mas.size(); i++)      //Исходя из размера
	{
		tree.addByYear(mas[i]);             //Заполняем данные с массива и передаем в функцию
	}
	delTree();                            //Удаляем дерево
	*this = tree;                        //Переносим данные в класс Tree

	cout << "Успех! Создание второго дерева было выполнено! Удаление прошлого дерева было произведенно!\n\nДля перехода в меню нажмите любую клавишу...";
}

void Tree::save(Data* n, string name) {				//\\//\\ Функ-я записи в файл //\\//\\ 
	if (n != 0)		//Пока не закончатся данные
	{
		ofstream fout;												//Файловый вывод
		if (fout.fail()) cout << "Ошибка! Файл не найден!";        //Если не открылся
		fout.open(name, ios::app);                                //Для записи в конец
		fout << n->year << endl << n->kol << endl << n->name << endl;   //Записываем через пробел
		fout.close();                                           //Закрываем
		save(n->Left, name);                                   //Сохраняем для левого элемента
		save(n->Right, name);                                 //Сохраняем для правого элемента
	}
}

void Tree::saveToFile(string name) {        //\\//\\ //Промежуточная функция для записи в файл //\\//\\ 
	ofstream fout;                                        //Файловый вывод
	if (fout.fail()) cout << "Ошибка! Файл не найден!";  //Если не открылся
	fout.open(name, ios::out);
	fout.close();
	save(Root, name);                                 //Переход в функцию по сохранению в файл
}

void Tree::read(Data* n, string name) {            //\\//\\ Функ-я чтения с файла //\\//\\ 
	ifstream fin;                            //Файл на ввод
	fin.open(name);							//Открываем файл 
	if (fin.fail()) cout << "Ошибка! Файл не найден!";  //Если не открылся
	char buf[255];						  //Создаем буферную переменную для хранения данных с файла
	int y, k, i = 1;
	string nam;
	while (fin)
	{
		fin.getline(buf, 255);
		if (i % 3 == 1)
		{
			k = atoi(buf);
			i++;
		}
		else if (i % 3 == 2)
		{
			y = atoi(buf);
			i++;
		}
		else
		{
			nam = string(buf);
			i++;
			add(nam, y, k);
		}
	}
	fin.close();
}

void Tree::readFromFile(string name) {    //\\//\\ Промежуточная функция для чтения с файла //\\//\\ 
	read(Root, name);
}
#include "RBTree.h"

RBTree::RBTree() :root(NULL) {      //\\//\\ КсП //\\//\\ 
	root = nullptr;
}

RBTree::~RBTree() {       //\\//\\ КпоУ //\\//\\ 
	destory(root);
}

void RBTree::insert(int y, int k, string name)                  //\\//\\ Промежуточная функ-я добавления данных в R/B дерево //\\//\\ 
{
	RBData* z = new RBData(y, k, name, Red, NULL, NULL, NULL);
	insert(root, z);                                           //Переход в функцию добавления
};

void RBTree::remove(int y, int k, string name)
{
	RBData* deletenode = search(root, y, k, name);
	if (deletenode != NULL)
		remove(root, deletenode);
}

RBData* RBTree::search(int y, int k, string name)           //\\//\\ Функ-я поиска элемента для дальнейшего удаления //\\//\\ 
{
	return search(root, y, k, name);
}

void RBTree::makeRB(Tree t) {			  //\\//\\ Функ-я раскраски дерева в R/B //\\//\\ 

	vector<Data*> mas;
	t.makeVectorFromTree(t.Root, mas);
	for (int i = 0; i < mas.size(); i++)
	{
		insert(mas[i]->year, mas[i]->kol, mas[i]->name);
	}
}


bool RBTree::checkRB() {             //\\//\\ Функ-я проверки на пустоту бинарного R/B дерева //\\//\\ 
	if (root == NULL)
	{
		system("cls");
		cout << "Ошибка! Бинарное дерево R/D отсутствует!!!\n\nНажмите на Enter чтобы продолжить...";
		_getch();
		return false;
	}
	else
	{
		return true;             //Если возврашает True, то мы можем пользоваться всем функционалом программы
	}
}

void RBTree::printt(RBData* n) {                             //\\//\\ Функ-я вывода //\\//\\ 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (n != 0)					//Пока не закончатся данные
	{
		tabs++;				    //Пробел
		printt(n->right);      //Печатаем правую ветку
		for (int i = 0; i < tabs; i++) cout << "	";    //Делаем определенное кол-во пробелов
		if (n->color == Red)                             //Если цвет красный
		{
			SetConsoleTextAttribute(hConsole, 4);        //Выбираем красный цвет
			cout << n->year << " " << n->kol << " " << n->name << endl;   //Выводим данные через пробел
			SetConsoleTextAttribute(hConsole, 7);      //Выбираем светло-серый цвет
		}
		else      //Цвет другой -> Черный
		{
			SetConsoleTextAttribute(hConsole, 7);        //Выбираем светло-серый цвет
			cout << n->year << " " << n->kol << " " << n->name << endl;    //Выводим данные через пробел
		}
		printt(n->left);      //Выводим левую ветку
		tabs--;				 //Пробел
	}

}



void RBTree::leftRotate(RBData*& root, RBData* x) {      //\\//\\ Левая ветвь //\\//\\ 
	RBData* y = x->right;                 //Создали указатель на данные
	x->right = y->left;                  //Прировняли
	if (y->left != NULL)                //Пока не обойдем все левые элементы
		y->left->parent = x;           //Левый родитель приравниваем к Х

	y->parent = x->parent;           //У прировняли с Х
	if (x->parent == NULL)          //Если равняется нулю, то есть Бинарное дерево пустое
		root = y;                  //Элемент становится корнем
	else {
		if (x == x->parent->left)      //Если Х равняется родителю Левого
			x->parent->left = y;      //Родитель левого равняется У
		else
			x->parent->right = y;   //Родитель правого равняется У
	}
	y->left = x;
	x->parent = y;
};

void RBTree::rightRotate(RBData*& root, RBData* y) {         //\\//\\ Правая ветвь //\\//\\ 
	RBData* x = y->left;                    //Создали указатель на данные
	y->left = x->right;                    //Прировняли
	if (x->right != NULL)                 //Пока не обойдем все правые элементы
		x->right->parent = y;            //Правый родитель приравниваем к У

	x->parent = y->parent;             //Х прировняли с У
	if (y->parent == NULL)			  //Если равняется нулю, то есть Бинарное дерево пустое
		root = x;				     //Элемент становится корнем
	else {
		if (y == y->parent->right)	    //Если У равняется родителю Правого
			y->parent->right = x;      //Родитель правого равняется Х
		else
			y->parent->left = x;     //Родитель левого равняется Х
	}
	x->right = y;
	y->parent = x;
};

void RBTree::insert(RBData*& root, RBData* node)           //\\//\\ Функ-я добавления данных в R/B дерев //\\//\\  
{
	RBData* x = root;                         //Создали указатель на х = корень
	RBData* y = NULL;                        //Создали указатель на У = 0
	while (x != NULL)                       //Пока не закончатся данные
	{
		y = x;                            
		if (node->name > x->name)         //Name1 > Name2
			x = x->right;                //Вправо
		else                            //Name1 < Name2
			x = x->left;               //Влево
	}
	node->parent = y;                //Родителем становится У
	if (y != NULL)                  //Если не пусто
	{
		if (node->name > y->name)       //Name1 > Name2
			y->right = node;		   //Вправо
		else                          //Name1 < Name2
			y->left = node;          //Влево
	}
	else                        //Если пусто
		root = node;           //Элемент становится корнем
	node->color = Red;        //Цвет красный
	InsertFixUp(root, node); //Передаем данные и цвет
};

void RBTree::InsertFixUp(RBData*& root, RBData* node)            //\\//\\ Функ-я для выставления и раскраски R/B //\\//\\ 
{
	RBData* parent;
	parent = node->parent;
	while (node != RBTree::root && parent->color == Red)
	{
		RBData* gparent = parent->parent;
		if (gparent->left == parent)
		{
			RBData* uncle = gparent->right;
			if (uncle != NULL && uncle->color == Red)
			{
				parent->color = Black;
				uncle->color = Black;
				gparent->color = Red;
				node = gparent;
				parent = node->parent;
			}
			else
			{
				if (parent->right == node)
				{
					leftRotate(root, parent);
					swap(node, parent);
				}
				rightRotate(root, gparent);
				gparent->color = Red;
				parent->color = Black;
				break;
			}
		}
		else
		{
			RBData* uncle = gparent->left;
			if (uncle != NULL && uncle->color == Red)
			{
				gparent->color = Red;
				parent->color = Black;
				uncle->color = Black;

				node = gparent;
				parent = node->parent;
			}
			else
			{
				if (parent->left == node)
				{
					rightRotate(root, parent);
					swap(parent, node);
				}
				leftRotate(root, gparent);
				parent->color = Black;
				gparent->color = Red;
				break;
			}
		}
	}
	root->color = Black;
}

void RBTree::destory(RBData*& node)     //\\//\\ Удаление  R/B дерева, работает с деструктором //\\//\\ 
{
	if (node == NULL)
		return;
	destory(node->left);
	destory(node->right);
	delete node;
	node = nullptr;
}

void RBTree::remove(RBData*& root, RBData* node)          //\\//\\ Функ-я удаление узла бинарного дерева R/B //\\//\\ 
{
	RBData* child, * parent;
	RBTColor color;
	// Левый и правый узлы удаленного узла не пусты (не конечные узлы)
	if (node->left != NULL && node->right != NULL)
	{
		RBData* replace = node;
		// Найти узел-преемник (самый нижний левый узел правого поддерева текущего узла)
		replace = node->right;
		while (replace->left != NULL)
		{
			replace = replace->left;
		}
		// Случай, когда удаленный узел не является корневым узлом
		if (node->parent != NULL)
		{
			if (node->parent->left == node)
				node->parent->left = replace;
			else
				node->parent->right = replace;
		}
		// Ситуация с корневым узлом
		else
			root = replace;
		// child - это правильный узел, который заменяет узел и является узлом, который требует последующей корректировки
		// Поскольку замена является преемником, он не может иметь левого дочернего узла
		// Аналогично, у узла-предшественника не может быть правого дочернего узла
		child = replace->right;
		parent = replace->parent;
		color = replace->color;

		// Удаленный узел является родительским узлом замещающего узла (repalce)
		if (parent == node)
			parent = replace;
		else
		{
			// Существование дочернего узла
			if (child != NULL)
				child->parent = parent;
			parent->left = child;

			replace->right = node->right;
			node->right->parent = replace;
		}
		replace->parent = node->parent;
		replace->color = node->color;
		replace->left = node->left;
		node->left->parent = replace;
		if (color == Black)
			removeFixUp(root, child, parent);

		delete node;
		return;
	}
	// Когда в удаленном узле только левый (правый) узел пуст, найдите дочерний узел удаленного узла
	if (node->left != NULL)
		child = node->left;
	else
		child = node->right;

	parent = node->parent;
	color = node->color;
	if (child)
	{
		child->parent = parent;
	}
	// Удаленный узел не является корневым узлом
	if (parent)
	{
		if (node == parent->left)
			parent->left = child;
		else
			parent->right = child;
	}
	// Удаленный узел является корневым узлом
	else
		RBTree::root = child;

	if (color == Black)
	{
		removeFixUp(root, child, parent);
	}
	delete node;

}

void RBTree::removeFixUp(RBData*& root, RBData* node, RBData* parent)
{
	RBData* othernode;
	while ((!node) || node->color == Black && node != RBTree::root)
	{
		if (parent->left == node)
		{
			othernode = parent->right;
			if (othernode->color == Red)
			{
				othernode->color = Black;
				parent->color = Red;
				leftRotate(root, parent);
				othernode = parent->right;
			}
			else
			{
				if (!(othernode->right) || othernode->right->color == Black)
				{
					othernode->left->color = Black;
					othernode->color = Red;
					rightRotate(root, othernode);
					othernode = parent->right;
				}
				othernode->color = parent->color;
				parent->color = Black;
				othernode->right->color = Black;
				leftRotate(root, parent);
				node = root;
				break;
			}
		}
		else
		{
			othernode = parent->left;
			if (othernode->color == Red)
			{
				othernode->color = Black;
				parent->color = Red;
				rightRotate(root, parent);
				othernode = parent->left;
			}
			if ((!othernode->left || othernode->left->color == Black) && (!othernode->right || othernode->right->color == Black))
			{
				othernode->color = Red;
				node = parent;
				parent = node->parent;
			}
			else
			{
				if (!(othernode->left) || othernode->left->color == Black)
				{
					othernode->right->color = Black;
					othernode->color = Red;
					leftRotate(root, othernode);
					othernode = parent->left;
				}
				othernode->color = parent->color;
				parent->color = Black;
				othernode->left->color = Black;
				rightRotate(root, parent);
				node = root;
				break;
			}
		}
	}
	if (node)
		node->color = Black;
}

RBData* RBTree::search(RBData* node, int y, int k, string name) const
{
	if (node == NULL || node->name == name && node->year == y && node->kol == k)
		return node;
	else
		if (name > node->name)
			return search(node->right, y, k, name);
		else
			return search(node->left, y, k, name);
}

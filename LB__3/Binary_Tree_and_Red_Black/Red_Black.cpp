#include "RBTree.h"

void RBTree::insert(int y, int k, string name)
{
	RBData* z = new RBData(y, k, name, Red, NULL, NULL, NULL);
	insert(root, z);
};

void RBTree::remove(int y, int k, string name)
{
	RBData* deletenode = search(root, y, k, name);
	if (deletenode != NULL)
		remove(root, deletenode);
}

RBData* RBTree::search(int y, int k, string name)
{
	return search(root, y, k, name);
}

void RBTree::makeRB(Tree t) {									   //Функ-я раскраски дерева в R/B

	vector<Data*> mas;
	t.makeVectorFromTree(t.Root, mas);
	for (int i = 0; i < mas.size(); i++)
	{
		insert(mas[i]->year, mas[i]->kol, mas[i]->name);
	}
}


bool RBTree::checkRB() {
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

void RBTree::printt(RBData* n) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (n != 0)
	{
		tabs++;
		printt(n->right);
		for (int i = 0; i < tabs; i++) cout << "	";
		if (n->color == Red)
		{
			SetConsoleTextAttribute(hConsole, 4);
			cout << n->year << " " << n->kol << " " << n->name << endl;
			SetConsoleTextAttribute(hConsole, 7);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 7);
			cout << n->year << " " << n->kol << " " << n->name << endl;
		}
		//cout << n->number << " " << n->group << " " << n->name << endl;
		printt(n->left);
		tabs--;
	}

}

RBTree::RBTree() :root(NULL) {
	root = nullptr;
}
// Деструктор
RBTree::~RBTree() {
	destory(root);
}

void RBTree::leftRotate(RBData*& root, RBData* x) {
	RBData* y = x->right;
	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;

	y->parent = x->parent;
	if (x->parent == NULL)
		root = y;
	else {
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
};
//Правая рука
void RBTree::rightRotate(RBData*& root, RBData* y) {
	RBData* x = y->left;
	y->left = x->right;
	if (x->right != NULL)
		x->right->parent = y;

	x->parent = y->parent;
	if (y->parent == NULL)
		root = x;
	else {
		if (y == y->parent->right)
			y->parent->right = x;
		else
			y->parent->left = x;
	}
	x->right = y;
	y->parent = x;
};

void RBTree::insert(RBData*& root, RBData* node)
{
	RBData* x = root;
	RBData* y = NULL;
	while (x != NULL)
	{
		y = x;
		if (node->name > x->name)
			x = x->right;
		else
			x = x->left;
	}
	node->parent = y;
	if (y != NULL)
	{
		if (node->name > y->name)
			y->right = node;
		else
			y->left = node;
	}
	else
		root = node;
	node->color = Red;
	InsertFixUp(root, node);
};

void RBTree::InsertFixUp(RBData*& root, RBData* node)
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

// Уничтожить красные и черные деревья
void RBTree::destory(RBData*& node)
{
	if (node == NULL)
		return;
	destory(node->left);
	destory(node->right);
	delete node;
	node = nullptr;
}

void RBTree::remove(RBData*& root, RBData* node)
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

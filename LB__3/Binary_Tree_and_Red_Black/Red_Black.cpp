#include "RBTree.h"

RBTree::RBTree() :root(NULL) {     //Конструктор
	root = nullptr;
}

RBTree::~RBTree() {        // Деструктор
	destory(root);
}

void RBTree::insert(int n, int g, string name)     // вставка
{
	RBTNode* z = new RBTNode(n, g, name, Red, NULL, NULL, NULL);
	insert(root, z);
};

void RBTree::remove(int n, int g, string name)
{
	RBTNode* deletenode = search(root, n, g, name);
	if (deletenode != NULL)
		remove(root, deletenode);
}

RBTNode* RBTree::search(int n, int g, string name)
{
	return search(root, n, g, name);
}

void RBTree::print() {
	if (root == NULL)
		cout << "empty RBtree\n";
	else
		print(root);
}

void RBTree::p() {
	printt(root);
}

void RBTree::printt(RBTNode* n) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (n != 0)
	{
		tabs++;
		printt(n->right);
		for (int i = 0; i < tabs; i++) cout << "	";
		if (n->color == Red)
		{
			SetConsoleTextAttribute(hConsole, 4);
			cout << n->number << " " << n->group << " " << n->name << endl;
			SetConsoleTextAttribute(hConsole, 7);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 7);
			cout << n->number << " " << n->group << " " << n->name << endl;
		}
		//cout << n->number << " " << n->group << " " << n->name << endl;
		printt(n->left);
		tabs--;
	}
}

void RBTree::preOrder() { // Предзаказ обхода дерева РБ
	if (root == NULL)
		cout << "empty RBtree\n";
	else
		preOrder(root);
};

// Обход дерева RB
void RBTree::inOrder() {
	if (root == NULL)
		cout << "empty RBtree\n";
	else
		inOrder(root);
};

// После обхода дерева RB
void RBTree::postOrder() {
	if (root == NULL)
		cout << "empty RBtree\n";
	else
		postOrder(root);
};

void RBTree::makeRB(Tree t) {
	//RBTree rb;

	vector<Node*> mas;
	t.makeVectorFromTree(t.Root, mas);
	for (int i = 0; i < mas.size(); i++)
	{
		insert(mas[i]->year, mas[i]->num, mas[i]->name);
	}

}

//Оставил
void RBTree::leftRotate(RBTNode*& root, RBTNode* x) {
	RBTNode* y = x->right;
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
void RBTree::rightRotate(RBTNode*& root, RBTNode* y) {
	RBTNode* x = y->left;
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

void RBTree::insert(RBTNode*& root, RBTNode* node)
{
	RBTNode* x = root;
	RBTNode* y = NULL;
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

void RBTree::InsertFixUp(RBTNode*& root, RBTNode* node)
{
	RBTNode* parent;
	parent = node->parent;
	while (node != RBTree::root && parent->color == Red)
	{
		RBTNode* gparent = parent->parent;
		if (gparent->left == parent)
		{
			RBTNode* uncle = gparent->right;
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
			RBTNode* uncle = gparent->left;
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
void RBTree::destory(RBTNode*& node)
{
	if (node == NULL)
		return;
	destory(node->left);
	destory(node->right);
	delete node;
	node = nullptr;
}

void RBTree::remove(RBTNode*& root, RBTNode* node)
{
	RBTNode* child, * parent;
	RBTColor color;
	// Левый и правый узлы удаленного узла не пусты (не конечные узлы)
	if (node->left != NULL && node->right != NULL)
	{
		RBTNode* replace = node;
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

void RBTree::removeFixUp(RBTNode*& root, RBTNode* node, RBTNode* parent)
{
	RBTNode* othernode;
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




RBTNode* RBTree::search(RBTNode* node, int n, int g, string name) const
{
	if (node == NULL || node->name == name && node->group == g && node->number == n)
		return node;
	else
		if (name > node->name)
			return search(node->right, n, g, name);
		else
			return search(node->left, n, g, name);
}
// Вывод детальной информации о двоичном дереве


/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void RBTree::print(RBTNode* node)const {
	if (node == NULL)
		return;
	if (node->parent == NULL)
		cout << node->name << "(" << node->color << ") is root" << endl;
	else if (node->parent->left == node)
	{
		cout << node->name << "(" << node->color << ") is " << node->parent->name << "'s " << "left child" << endl;
	}
	else
	{
		cout << node->name << "(" << node->color << ") is " << node->parent->name << "'s " << "right child" << endl;
	}
	print(node->left);
	print(node->right);
}





/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ПРЯМОЙ
void RBTree::preOrder(RBTNode* tree)const {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (tree != NULL) {
		//cout << tree->name << " ";
		if (tree->color == Red)
		{
			SetConsoleTextAttribute(hConsole, 4);
			cout << tree->number << " " << tree->group << " " << tree->name << "  ";
			SetConsoleTextAttribute(hConsole, 7);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 7);
			cout << tree->number << " " << tree->group << " " << tree->name << "  ";
		}
		preOrder(tree->left);
		preOrder(tree->right);
	}
}


//СИММЕТРИЧНЫЙ
void RBTree::inOrder(RBTNode* tree)const {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (tree != NULL) {
		inOrder(tree->left);
		//cout << tree->name << " ";
		if (tree->color == Red)
		{
			SetConsoleTextAttribute(hConsole, 4);
			cout << tree->number << " " << tree->group << " " << tree->name << "  ";
			SetConsoleTextAttribute(hConsole, 7);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 7);
			cout << tree->number << " " << tree->group << " " << tree->name << "  ";
		}
		inOrder(tree->right);
	}
}


//ОБРАТНЫЙ
void RBTree::postOrder(RBTNode* tree)const {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (tree != NULL) {
		postOrder(tree->left);
		postOrder(tree->right);
		//cout << tree->name << " ";
		if (tree->color == Red)
		{
			SetConsoleTextAttribute(hConsole, 4);
			cout << tree->number << " " << tree->group << " " << tree->name << "  ";
			SetConsoleTextAttribute(hConsole, 7);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 7);
			cout << tree->number << " " << tree->group << " " << tree->name << "  ";
		}
	}
}
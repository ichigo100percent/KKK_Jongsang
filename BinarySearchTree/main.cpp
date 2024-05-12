#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	Node(int _val)
		: data(_val)
		, left(nullptr)
		, right(nullptr)
	{
	}
	int data;
	Node* left;
	Node* right;
};

class BinarySearchTree
{
public:
	BinarySearchTree() : m_root(nullptr) {}

	void insert(int _val)
	{
		m_root = recursiveAddNode(m_root, _val);
	}

	bool find(int _val)
	{
		Node* cur = m_root;

		while (cur != nullptr)
		{
			if (cur->data == _val)
				return true;

			if (cur->data > _val)
				cur = cur->left;
			else
				cur = cur->right;
		}
		return false;
	}

	void remove(int _val)
	{
		recusiveDeleteNode(m_root, _val);
	}

	void show()
	{
		inorderTraversal(m_root);
	}

	void levelOrder()
	{
		if (m_root == nullptr)
			return;

		queue<Node*> q;
		q.push(m_root);

		while (!q.empty())
		{
			Node* cur = q.front();
			q.pop();

			cout << cur->data << " ";

			if (cur->left != nullptr)
				q.push(cur->left);
			if (cur->right != nullptr)
				q.push(cur->right);
		}
	}

private:
	Node* recursiveAddNode(Node* _root, int _val)
	{
		if (!_root)
			return new Node(_val);

		if (_root->data > _val)
			_root->left = recursiveAddNode(_root->left, _val);
		else
			_root->right = recursiveAddNode(_root->right, _val);

		return _root;
	}

	void inorderTraversal(Node* _root)
	{
		if (_root == nullptr)
			return;

		inorderTraversal(_root->left);
		cout << _root->data << " ";
		inorderTraversal(_root->right);
	}

	Node* findMinNode(Node* _root)
	{
		while (_root->left != nullptr)
		{
			_root = _root->left;
		}
		return _root;
	}

	Node* recusiveDeleteNode(Node* _root, int _val)
	{
		if (_root == nullptr)
			return nullptr;

		if (_root->data > _val)
			_root->left = recusiveDeleteNode(_root->left, _val);
		else if (_root->data < _val)
			_root->right = recusiveDeleteNode(_root->right, _val);
		else
		{
			// 자식이 없는 경우 노드를 삭제
			if (_root->left == nullptr && _root->right == nullptr) {
				delete _root;
				_root = nullptr;
			}
			else if (_root->left == nullptr)
			{
				Node* temp = _root->right;
				delete _root;
				return temp;
			}
			else if (_root->right == nullptr)
			{
				Node* temp = _root->left;
				delete _root;
				return temp;
			}
			else
			{
				//자식노드가 두개가 있는 경우
				Node* temp = findMinNode(_root->right); //오른쪽 최소값을 루트에 대입
				_root->data = temp->data;
				_root->right = recusiveDeleteNode(_root->right, temp->data); //다시 삭제하러 출발
			}
		}
		return _root;
	}

private:
	Node* m_root;
};

int main()
{
	BinarySearchTree t;

	t.insert(5);
	t.insert(3);
	t.insert(7);

	t.show();

	t.remove(6);

	cout << "\n";

	t.show();

	t.levelOrder();

	return 0;
}


/*
struct Node
{
	Node(int _val)
		: data(_val)
		, left(nullptr)
		, right(nullptr)
	{
	}

	int data;
	Node* left;
	Node* right;
};

class Tree
{
public:
	Tree()
		: m_root(nullptr)
	{

	}

	void insert(int _val)
	{
		m_root = reculsiveAddNode(m_root, _val);
	}

	void remove(int _val)
	{
		reculsiveDeleteNode(m_root, _val);
	}

	bool find(int _val)
	{
		Node* cur = m_root;

		while (cur != nullptr)
		{
			if (cur->data == _val)
				return true;

			if (cur->data > _val)
				cur = cur->left;
			else
				cur = cur->right;
		}

		return false;
	}

	void print()
	{
		inorderTraversal(m_root);
	}

private:
	Node* reculsiveAddNode(Node* _root, int _val)
	{
		if (_root == nullptr)
			return new Node(_val);

		if (_root->data > _val)
			_root->left = reculsiveAddNode(_root->left, _val);
		else
			_root->right = reculsiveAddNode(_root->right, _val);

		return _root;
	}

	Node* reculsiveDeleteNode(Node* _root, int _val)
	{
		if (_root == nullptr)
			return nullptr;

		if (_root->data > _val)
			_root->left = reculsiveDeleteNode(_root->left, _val);
		else if (_root->data < _val)
			_root->right = reculsiveDeleteNode(_root->right, _val);
		else
		{
			if (_root->left == nullptr && _root->right == nullptr)
			{
				delete _root;
				return nullptr;
			}
			else if (_root->left == nullptr)
			{
				Node* temp = _root->right;
				delete _root;
				_root = nullptr;
				return temp;
			}
			else if (_root->right == nullptr)
			{
				Node* temp = _root->left;
				delete _root;
				_root = nullptr;
				return temp;
			}
			else
			{
				Node* temp = findMinNode(_root->right);
				_root->data = temp->data;
				_root->right = reculsiveDeleteNode(_root->right, temp->data);
			}
		}

		return _root;
	}

	Node* findMinNode(Node* _root)
	{
		while (_root->left != nullptr)
		{
			_root = _root->left;
		}
		return _root;
	}

	void inorderTraversal(Node* _root)
	{
		if (_root == nullptr)
			return;

		inorderTraversal(_root->left);
		cout << _root->data << " ";
		inorderTraversal(_root->right);
	}
private:
	Node* m_root;
};


int main()
{
	Tree t;

	t.insert(5);
	t.insert(3);
	t.insert(7);
	t.insert(1);
	t.insert(4);
	t.insert(6);
	t.insert(8);

	t.print();

	t.remove(5);

	cout << "\n";

	t.print();

	if (t.find(7))
	{
		cout << "찾았습니다" << endl;
	}
	else
		cout << "못 찾았습니다." << endl;

	return 0;
}
*/

//주소 이전 안되는 이유
/*
struct Node
{
	Node(int _val)
		: data(_val)
		, left(nullptr)
		, right(nullptr)
	{
	}
	int data;
	Node* left;
	Node* right;
};


class BinarySearchTree
{
public:
	BinarySearchTree() : m_root(nullptr) {}

	void insert(int _val)
	{
		m_root = recursiveAddNode(m_root, _val);
	}

	bool find(int _val)
	{
		Node* cur = m_root;

		while (cur != nullptr)
		{
			if (cur->data == _val)
				return true;

			if (cur->data > _val)
				cur = cur->left;
			else
				cur = cur->right;
		}
		return false;
	}

	void remove(int _val)
	{
		recusiveDeleteNode(m_root, _val);
	}

	void show()
	{
		inorderTraversal(m_root);
	}

private:
	Node* recursiveAddNode(Node* _root, int _val)
	{
		if (!_root)
			return new Node(_val);

		if (_root->data > _val)
			_root->left = recursiveAddNode(_root->left, _val);
		else
			_root->right = recursiveAddNode(_root->right, _val);

		return _root;
	}

	void inorderTraversal(Node* _root)
	{
		if (_root == nullptr)
			return;

		inorderTraversal(_root->left);
		cout << _root->data << " ";
		inorderTraversal(_root->right);
	}

	Node* findMinNode(Node* _root)
	{
		while (_root->left != nullptr)
		{
			_root = _root->left;
		}
		return _root;
	}

	Node* recusiveDeleteNode(Node* _root, int _val)
	{
		if (_root == nullptr)
			return nullptr;

		else if (_root->data > _val)
			_root->left = recusiveDeleteNode(_root->left, _val);
		else if (_root->data < _val)
			_root->right = recusiveDeleteNode(_root->right, _val);
		else
		{
			// 자식이 없는 경우 노드를 삭제
			if (_root->left == nullptr && _root->right == nullptr) {
				delete _root;
				_root = nullptr;
			}
			else if (_root->left == nullptr)
			{
				Node* temp = _root->right;
				delete _root;
				return temp;
			}
			else if (_root->right == nullptr)
			{
				Node* temp = _root->left;
				delete _root;
				return temp;
			}
			else
			{
				//자식노드가 두개가 있는 경우
				Node* temp = findMinNode(_root->right); //오른쪽 최소값을 루트에 대입

				if (_root->data == temp->data)
				{
					return _root;
				}
				Node* tempN = _root;
				Node* tempL = _root->left;
				Node* tempR = _root->right;
				//_root = std::move(temp);
				_root = temp;
				_root->left = tempL;
				_root->right = tempR;
				tempN = recusiveDeleteNode(tempR, temp->data); //다시 삭제하러 출발
			}
		}
		if (_root->data == _val)
		{
			return _root;
		}
		return _root;
	}

private:
	Node* m_root;
};

int main()
{
	BinarySearchTree t;

	t.insert(5);
	t.insert(3);
	t.insert(7);
	t.insert(6);
	t.insert(8);

	t.remove(5);

	t.show();

	return 0;
}
*/


//루키스
struct Node
{
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;

	int data;
};

class Bst
{
public:
	void Print() { Print(_root); }
	void Print(Node* node)
	{
		if (node == nullptr)
			return;
		Print(node->left);
		cout << node->data << "  ";
		Print(node->right);
	}

	void Insert(int data)
	{
		Node* newNode = new Node();
		newNode->data = data;

		if (_root == nullptr)
		{
			_root = newNode;
			return;
		}

		Node* node = _root;
		Node* parent = nullptr;

		while (node)	
		{
			parent = node;
			if (data < node->data)
				node = node->left;
			else
				node = node->right;
		}

		newNode->parent = parent;

		if (data < parent->data)
			parent->left = newNode;
		else
			parent->right = newNode;
	}

	Node* Search(Node* node, int data)
	{
		if (node == nullptr || data == node->data)
			return node;

		if (data < node->data)
			return Search(node->left, data);
		else
			return Search(node->right, data);

	}

	Node* Min(Node* node)
	{
		if (node == nullptr)
			return nullptr;

		while (node->left)
		{
			node = node->left;
		}
		return node;
	}

	void Replace(Node* a, Node* b)
	{
		if (a->parent == nullptr)
			_root = b;
		else if (a == a->parent->left)
			a->parent->left = b;
		else
			a->parent->right = b;

		if (b)
			b->parent = a->parent;

		delete a;
	}

	void Delete(int data)
	{
		Node* dNode = Search(_root, data);
		Delete(dNode);
	}
	void Delete(Node* node)
	{
		if (node == nullptr)
			return;

		if (node->left == nullptr)
			Replace(node, node->right);
		else if (node->right == nullptr)
			Replace(node, node->left);
		else
		{
			Node* rNode = Min(node->right);
			node->data = rNode->data;
			Delete(rNode);
		}
	}

private:
	Node* _root = nullptr;
};
int main()
{
	Bst b;
	b.Insert(50);
	b.Insert(30);
	b.Insert(10);
	b.Insert(40);
	b.Insert(70);
	b.Insert(60);

	b.Print();

	b.Delete(30);
	b.Print();
}
#include <iostream>

using namespace std;

typedef struct Node
{
	int value;
	struct Node* NextNode = NULL;
	struct Node* prevNode = NULL;

}Node;

Node* head = NULL;
Node* tail = NULL;
int g_Count = 0;

Node* CreateNode();
void insertNear();
void print();
void removeNode();
void removeAll();


//int main()
//{
//	int num;
//
//	while (1)
//	{
//		system("cls");
//		cout << "번호 입력: ";
//		cin >> num;
//
//		switch (num)
//		{
//		case 1:
//			insertNear();
//			break;
//		case 2:
//			print();
//			break;
//		case 3:
//			removeNode();
//			break;
//		case 4:
//			removeAll();
//			break;
//
//		}
//		system("pause");
//	}
//}


Node* CreateNode()
{
	Node* newNode = new Node;

	newNode->NextNode = newNode->prevNode = NULL;

	cout << "정수 입력: ";

	cin >> newNode->value;

	return newNode;
}

void insertNear()
{
	Node* newNode;

	newNode = CreateNode();

	if (head == nullptr)
	{
		head = tail = newNode;
		return;
	}

	tail->NextNode = newNode;
	newNode->prevNode = tail;
	tail = newNode;
}

void print()
{
	Node* curNode = head;

	if (head == nullptr)
	{
		cout << "저장된 노드가 없습니다." << endl;

		return;
	}
	
	cout << curNode->value << ' ';

	while (curNode != nullptr)
	{
		curNode = curNode->NextNode;

		if(curNode !=nullptr)
			cout << curNode->value << ' ';
	}

	cout << endl;
}

void removeNode()
{
	Node* delNode = nullptr, * curNode = nullptr;

	int delNum;

	cout << "삭제할 정수를 입력하시오: ";
	cin >> delNum;

	if (head == nullptr)
		return;

	if (head->value == delNum)
	{
		delNode = head;
		head = head->NextNode;

		delete delNode;

		cout << "첫 노드 삭제" << endl;
		return;
	}

	curNode = head;

	while (curNode->NextNode != nullptr)
	{
		delNode = curNode->NextNode;

		if (delNode->value == delNum)
		{
			curNode->NextNode = delNode->NextNode;

			delete delNode;

			cout << "중간 노드 삭제 " << delNum << endl;
		}
		if (curNode->NextNode != nullptr)
			curNode = curNode->NextNode;
	}
}

void removeAll()
{
	Node* delNode = head;

	while (head !=nullptr)
	{
		head = head->NextNode;
		
		delete delNode;

		delNode = head;
	}

	tail = nullptr;
}

void sort(Node* pNode, int count)
{

}
#include <iostream>
#include <string.h>
#include <list>

#define SIZE 100

using namespace std;


class StudentList
{
private:
	Node* head;
	Node* tail;
	int size;

public:
	StudentList()
		:size(0)
	{
		head = new Node();
		tail = new Node();

		head->next = tail;
		tail->prev = head;
	}

	void push_back(string name, const int& value)
	{
		add(tail, name, value);
	}

	//void remove(int value)
	//{
	//	Node* delNode, * curNode, * nextNode;
	//	

	//	if(head->next == nullptr || tail->prev == nullptr)
	//	{
	//		return;
	//	}

	//	curNode = head;

	//	while (curNode != nullptr)
	//	{
	//		delNode = curNode->next;

	//		if (delNode->data == value)
	//		{
	//			curNode->next = delNode->next;
	//			nextNode = curNode->next;

	//			curNode->prev = nextNode;
	//			nextNode->prev = curNode;

	//			delete delNode;

	//			cout << "학생 삭제: " << value << endl;
	//		}
	//		if (curNode->next != nullptr)
	//		{
	//			curNode = curNode->next;
	//		}
	//	}
	//}

private:
	Node* add(Node* before, string name, const int& value)
	{
		Node* newNode = new Node(name, value);
		Node* prevNode = before->prev;

		prevNode->next = newNode;
		newNode->prev = prevNode;

		newNode->next = before;
		before->prev = newNode;

		size++;

		return newNode;
	}

	

};

//int main()
//{
//	StudentList a;
//
//	a.push_back("이종상", 200);
//	a.push_back("홍길동", 100);
//	a.push_back("이설아", 300);
//
//	//a.remove(100);
//
//	
//}
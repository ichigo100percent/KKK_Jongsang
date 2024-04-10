#include <iostream>
#include <vector>
#include <time.h>
//#include <stack>
//#include <queue>
using namespace std;

struct Node
{
	Node() {}
	Node(int _data)
		: data(_data)
		, next(nullptr)
		, prev(nullptr)
	{

	}
	int data;
	Node* next;
	Node* prev;
};

class Queue
{
public:
	Queue()
		: head(nullptr)
		, tail(nullptr)
	{

	}

	void push(int value)
	{
		if (head == nullptr)
		{
			Node* buff = new Node(value);
			head = buff;
			tail = buff;
		}
		else
		{
			tail->next = new Node(value);
			tail = tail->next;
		}
	}

	void pop()
	{
		Node* delBuff = head;
		head = head->next;
		delete delBuff;
	}

	int top()
	{
		return head->data;
	}

private:
	Node* head;
	Node* tail;
};

class Stack
{
public:
	Stack()
		: head(nullptr)
		, tail(nullptr)
	{

	}
	void push(int value)
	{
		Node* buff = new Node(value);
		buff->next = head;
		head = buff;
	}

	void pop()
	{
		Node* delBuff = head;
		head = head->next;
		delete delBuff;
	}

	int top()
	{
		return head->data;
	}

private:
	Node* head;
	Node* tail;
};

class List
{
public:
	List()
		: head(nullptr)
		, tail(nullptr)
	{

	}

	void push_back(int value)
	{
		if (head == nullptr)
		{
			head = new Node(value);
			tail = head;
		}
		else
		{
			tail->next = new Node(value);
			//tail->prev = tail;
			tail->next->prev = tail;
			tail = tail->next;
		}
	}

	void print()
	{
		Node* buff = head;

		while (buff != nullptr)
		{
			cout << buff->data << ' ';
			buff = buff->next;
		}
	}

private:
	Node* head;
	Node* tail;
};

int main()
{

	Stack s;

	s.push(1);
	s.push(2);
	s.push(3);

	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();

	Queue q;

	q.push(1);
	q.push(2);
	q.push(3);

	cout << q.top() << endl;
	q.pop();
	cout << q.top() << endl;
	q.pop();
	cout << q.top() << endl;
	q.pop();

	List l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.print();

	return 0;
}
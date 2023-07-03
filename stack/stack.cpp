#include <iostream>

struct Node
{
	int value;
	Node* next;
	Node* prev;
};

Node* head;
Node* tail;

void push_back(Node** _head, Node** _tail, int _data);
//void sort(Node** _head);
//void insert_sort(Node** _head, Node* newNode);
void bubble_sort(Node** _head, Node** _tail);
void print();

int main()
{
	push_back(&head, &tail, 3);
	push_back(&head, &tail, 2);
	push_back(&head, &tail, 1);

	//sort(&head);
	bubble_sort(&head, &tail);

	print();
}

void print()
{
	Node* curNode = head;

	while (curNode != nullptr)
	{
		std::cout << curNode->value << ' ';

		curNode = curNode->next;
	}
}

void push_back(Node** _head, Node** _tail, int _data)
{
	Node* newNode = new Node;

	newNode->value = _data;

	if (*_head == nullptr)
	{
		*_head = newNode;
		*_tail = newNode;

		return;
	}

	(*_tail)->next = newNode;
	newNode->prev = *_tail;

	*_tail = newNode;
}

void bubble_sort(Node** _head, Node** _tail)
{
	int temp;
	Node* p;

	while (*_head != *_tail)
	{
		p = *_head;

		do
		{
			if (p->value > p->next->value)
			{
				temp = p->value;
				p->value = p->next->value;
				p->next->value = p->value;
			}
			p = p->next;
		} while (p != *_tail);

		*_tail = (*_tail)->prev;
	}
}
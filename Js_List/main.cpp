#include "std.h"

struct Node
{
	int value;
	unique_ptr<Node> next = nullptr;
};

unique_ptr<Node> head = nullptr;

std::unique_ptr<Node> CreateNode(int _value)
{
	unique_ptr<Node> newNode = make_unique<Node>();

	newNode->value = _value;

	return newNode;
}

void push_back(int _value)
{
	unique_ptr<Node> newNode = CreateNode(_value);

	if (head == nullptr)
	{
		head = move(newNode);
		return;
	}

	Node* currentNode = head.get();

	while (currentNode->next != nullptr)
	{
		currentNode = currentNode->next.get();
	}
	currentNode->next = move(newNode);
}

void Print()
{
	for (auto i = head.get();
		i != nullptr;
		i = i->next.get())
	{
		cout << i->value << " ";
	}
}

int main()
{
	push_back(1);
	push_back(2);

	push_back(3);

	Print();
}
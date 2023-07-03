#include <iostream>
#include <fstream>
#include <string>


using namespace std;



//template <typename T>
class List
{
public:
	List()
		:head(nullptr), tail(nullptr), size(0)
	{

	}

	void push_back(const int& _value)
	{
		Node* newNode = create(&head, &tail, _value);

		tail->next = newNode;
		newNode->prev = tail;

		tail = newNode;

		size++;
	}

	void push_front(const int& _value)
	{
		Node* newNode = create(&head, &tail, _value);

		head->prev = newNode;
		newNode->next = head;

		head = newNode;

		size++;
	}

	void print()
	{
		Node* curNode = head;

		while (curNode != nullptr)
		{
			cout << curNode->value << ' ';

			curNode = curNode->next;
		}
	}

	void delete_node(const int& _value)
	{
		Node* delNode, * curNode, * nextNode;

		curNode = head;

		if (head == nullptr)
		{
			return;
		}

		//첫번째 노드번호인가
		if (curNode->value == _value)
		{
			head = head->next;

			delete curNode;

			return;
		}
		//그외
		while (curNode != nullptr)
		{
			delNode = curNode->next;

			if (delNode->value == _value)
			{
				//curNode->next = delNode->next;
				nextNode = delNode->next;
				nextNode->prev = curNode;
				curNode->next = nextNode;

				delete delNode;

				return;
			}
			curNode = curNode->next;
		}
	}

private:
	Node* create(Node** _head, Node** _tail, const int& _value)
	{
		Node* newNode = new Node(_value);

		if (*_head == nullptr)
		{
			*_head = newNode;
			*_tail = newNode;

			return newNode;
		}
		//(*_tail)->next = newNode;
		//newNode->prev = *_tail;

		//*_tail = newNode;

		return newNode;
	}

private:
	Node* head;
	Node* tail;
	int	 size;
};

int main()
{
	List p;

	p.push_back(1);
	p.push_back(3);
	p.push_back(2);

	p.print();
}
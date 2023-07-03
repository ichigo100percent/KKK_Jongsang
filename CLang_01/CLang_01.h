
#pragma once

#include <iostream>
#include <fstream>
#include <string>




//template <typename T>
class List
{
public:
	List()
		:head(nullptr), tail(nullptr), size(0)
	{

	}

	void push_back(const int& _value, const string& _name)
	{
		Node* newNode = create(&head, &tail, _value, _name);

		tail->next = newNode;
		newNode->prev = tail;

		tail = newNode;

		size++;
	}

	void push_front(const int& _value, const string& _name)
	{
		Node* newNode = create(&head, &tail, _value, _name);

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
			cout << curNode->value << endl;

			cout << curNode->name << endl;

			curNode = curNode->next;

		}
	}

	void delete_node(const int& _value)
	{
		Node* delNode, * curNode, *nextNode;

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

			size--;

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

				size--;

				return;
			}
			curNode = curNode->next;
		}
	}

	void sort(Node** head)
	{

	}

	void save(const string& _name)
	{
		ofstream writeFile;
		Node* curNode = head;

		writeFile.open(_name);

		if (writeFile.is_open())
		{
			while (curNode != nullptr)
			{
				writeFile << curNode->value << ' ' << curNode->name << ' ';

				curNode = curNode->next;
			}
			writeFile.close();
		}
	}

	void load(const string& _name)
	{
		ifstream readFile;
		Node* newNode = new Node();

		readFile.open(_name);

		if (readFile.is_open())
		{
			while (1)
			{
				if (readFile.eof()-1)
				{
					break;
				}

				readFile >> newNode->value >> newNode->name;
				

				push_back(newNode->value, newNode->name);
			}
			readFile.close();
		}
	}

private:
	Node* create(Node** _head, Node** _tail, const int& _value, const string& _name)
	{
		Node* newNode = new Node();

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
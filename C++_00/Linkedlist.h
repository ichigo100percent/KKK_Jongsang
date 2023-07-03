#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "student.h"
#include "Node.h"


template <typename T>
class List
{
public:
	List()
		:head(), tail(nullptr)
	{
		
	}

	void push_back(T* _data);

	void push_front(T* _data);

	void Print_list();

	void find_Node(const std::string& _name);

	void delete_node(const std::string& _name);

	//void save(const string& _name)
	//{
	//	ofstream writeFile;
	//	Node* curNode = head;

	//	writeFile.open(_name);

	//	if (writeFile.is_open())
	//	{
	//		while (curNode != nullptr)
	//		{
	//			writeFile << curNode->value << ' ' << curNode->name << ' ';

	//			curNode = curNode->next;
	//		}
	//		writeFile.close();
	//	}
	//}

	
	//friend std::ostream& operator << (std::ostream& out, const Node<student>& _n)
	//{
	//	out << _n.data->getsubject() << ' ';

	//	return out;
	//}
	

private:
	Node<T>* create(Node<T>** _head, Node<T>** _tail, T* _data);

public:
	Node<T> head;
	Node<T>* tail;
	static int size;
};

template<typename T>
int List<T>::size = 0;


template<typename T>
Node<T>* List<T>::create(Node<T>** _head, Node<T>** _tail, T* _data)
{
	Node<T>* newNode = new Node<T>;

	newNode->data = _data;

	if (*_head == nullptr)
	{
		*_head = newNode;
		*_tail = newNode;

		return newNode;
	}

	
	return newNode;
}

template<typename T>
void List<T>::push_back(T* _data)
{
	Node<T>* newNode = create(&head, &tail, _data);

	tail->next = newNode;
	newNode->prev = tail;

	tail = newNode;

	size++;
}

template<typename T>
void List<T>::push_front(T* _data)
{

}

template<typename T>
inline void List<T>::Print_list()
{
	Node<T>* curNode = head;

	if (head == nullptr)
	{
		return;
	}

	for (curNode; curNode != nullptr; curNode = curNode->next)
	{
		std::cout << curNode->data;
	}
}


template<>
void List<student>::Print_list()
{
	//Node<student>* curNode = head;

	//if (curNode == nullptr)
	//{
	//	return;
	//}

	//for (curNode; curNode != nullptr; curNode = curNode->next)
	//{
	//	curNode->data->getsubject();
	//}

	Node<student>* curNode = head;

	while (curNode != nullptr)
	{
		curNode->data->getsubject();

		curNode = curNode->next;
	}

}

template<>
void List<student>::find_Node(const std::string& _name)
{
	Node<student>* curNode = head;

	if (head == nullptr)
	{
		return;
	}

	for (curNode; curNode != nullptr; curNode = curNode->next)
	{
		if (curNode->data->getName() == _name)
		{
			curNode->data->getsubject();
			return;
		}
		
	}
}

template<>
void List<student>::delete_node(const std::string& _name)
{
	Node<student>* delNode, * curNode, * nextNode;

	curNode = head;

	if (head == nullptr)
	{
		return;
	}

	//첫번째 노드번호인가
	if (curNode->data->getName() == _name)
	{
		head = head->next;

		delete curNode;

		return;
	}
	//그외
	while (curNode != nullptr)
	{
		delNode = curNode->next;

		if (curNode->data->getName() == _name)
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


template<typename T>
std::ostream& operator << (std::ostream& out, const Node<student>& _n)
{

}

//template<typename T>
//void List<T>::Print()
//{
//	for (Node<T>* curNode = head; curNode != nullptr; curNode = curNode->next)
//	{
//		curNode->data->print();
//	}
//}

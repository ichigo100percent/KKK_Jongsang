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

	void all_delete();

	void bubble_sort();

	
	//friend std::ostream& operator << (std::ostream& out, const Node<student>& _n)
	//{
	//	out << _n.data->getsubject() << ' ';

	//	return out;
	//}
	

private:
	Node<T>* create(Node<T>** _head, Node<T>** _tail, T* _data);

public:
	Node<T>* head;
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
	//Node* newNode = create(&head, &tail, _value);

	//head->prev = newNode;
	//newNode->next = head;

	//head = newNode;

	//size++;
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

	//Node<student>* curNode = head;

	//while (curNode != nullptr)
	//{
	//	curNode->data->getsubject();

	//	curNode = curNode->next;
	//}

	if (head == nullptr)
	{
		return;
	}

	Node<student>* curNode = head;

	for (int i = 0; i < size; i++)
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


	if (head == nullptr)
	{
		return;
	}

	//첫번째 노드번호인가
	if (head->data->getName() == _name)
	{
		Node<student>* temp;

		temp = head;

		head = head->next;

		delete temp;

		size--;

		return;
	}
	//그외
	//while (curNode != nullptr)
	//{
	//	delNode = curNode->next;

	//	if (curNode->data->getName() == _name)
	//	{
	//		//curNode->next = delNode->next;
	//		nextNode = delNode->next;
	//		nextNode->prev = curNode;
	//		curNode->next = nextNode;

	//		delete delNode;

	//		return;
	//	}
	//	curNode = curNode->next;
	//}

	curNode = head;

	for (int i = 0; i < size; i++)
	{
		if (curNode->next != nullptr)
		{
			delNode = curNode->next;
		}
		else
		{
			delNode = curNode;
			curNode = curNode->prev;
		}

		if (delNode->data->getName() == _name)
		{
			if (delNode->next != nullptr)
			{
				nextNode = delNode->next;
			}
			//마지막 노드일 경우
			else
			{
				tail = curNode;

				delete delNode;

				size--;

				return;
			}
			nextNode->prev = curNode;
			curNode->next = nextNode;

			delete delNode;

			size--;

			return;
		}
		curNode = curNode->next;
	}
}

template<>
void List<student>::all_delete()
{
	if (head == nullptr)
	{
		return;
	}

	Node<student>* deletNode, *curNode;

	curNode = head;

	for (int i = 0; i < size; i++)
	{
		deletNode = curNode;

		curNode = curNode->next;

		delete deletNode;

		size--;
	}

	size = 0;
	head->next = nullptr;
	head->prev = nullptr;
}

template<>
void List<student>::bubble_sort()
{
	Node<student>* cur = head;


	for (int i = 0; i < size && cur != nullptr; i++)
	{
		Node<student>* cur2 = cur;

		while (cur2->next != nullptr)
		{
			if (cur2->data->getTotal() > cur2->next->data->getTotal())
			{
				int temp = cur2->data->getTotal();

				cur2->data->m_Total = cur2->next->data->getTotal();

				cur2->next->data->m_Total = temp;

			}
			cur2 = cur2->next;
		}
		cur = head;
	}
}


template<typename T>
std::ostream& operator << (std::ostream& out, const Node<student>& _n)
{

}


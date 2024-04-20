#pragma once
#include <iostream>

template <typename T>
struct Node
{
	Node(T _data)
		: data(_data)
		, next(nullptr)
		, prev(nullptr)
	{

	}

	T data;
	Node<T>* next;
	Node<T>* prev;
};

template <typename T>
class List
{
public:
	List()
		: m_head(nullptr)
		, m_tail(nullptr)
	{

	}
	~List()
	{
		Node<T>* current = m_head;
		while (current != nullptr)
		{
			Node<T>* next = current->next;
			delete current;
			current = next;
		}
	}

	Node<T>* create(T _data)
	{
		Node<T>* newNode = new Node<T>(_data);
		return newNode;
	}
	void push_back(Node<T>* _data)
	{
		if (m_head == nullptr)
		{
			m_head = _data;
			m_tail = m_head;
		}
		else
		{
			m_tail->next = _data;
			m_tail->next->prev = m_tail;
			m_tail = m_tail->next;
		}
	}
	void print()
	{
		Node<T>* currentNode = m_head;

		while (currentNode != nullptr)
		{
			std::cout << currentNode->data;
			currentNode = currentNode->next;
		}
	}

private:
	Node<T>* m_head;
	Node<T>* m_tail;
};

//template <typename T>
//class List
//{
//public:
//	List()
//		: m_head(nullptr)
//		, m_tail(nullptr)
//	{
//
//	}
//
//	~List()
//	{
//		Node<T>* current = m_head;
//		while (current != nullptr)
//		{
//			Node<T>* next = current->next;
//			delete current;
//			current = next;
//		}
//	}
//
//	Node<T>* create(T _data)
//	{
//		Node<T>* newNode = new Node<T>(_data);
//		return newNode;
//	}
//
//	void push_back(Node<T>* _data)
//	{
//		if (m_head == nullptr)
//		{
//			m_head = _data;
//			m_tail = m_head;
//		}
//		else
//		{
//			m_tail->next = _data;
//			_data->prev = m_tail;
//			m_tail = _data;
//		}
//	}
//
//	void print()
//	{
//		Node<T>* currentNode = m_head;
//
//		while (currentNode != nullptr)
//		{
//			std::cout << currentNode->data;
//			currentNode = currentNode->next;
//		}
//	}
//
//private:
//	Node<T>* m_head;
//	Node<T>* m_tail;
//};
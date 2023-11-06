#pragma once
#include <iostream>


template <class T>
class Node
{
public:
	T		DATA;
	Node*	m_pNext;
	Node*	m_pPrev;

	Node()
	{
		//DATA = -1;
		m_pNext = nullptr;
		m_pPrev = nullptr;
	}
};

template <class T>
class LinkedList
{
public:
	int		 m_iCounter = 0;
	Node<T>* m_pHead = nullptr;
	Node<T>* m_pTail = nullptr;

public:
	LinkedList();
	~LinkedList();

	Node<T>* newNode(T data);
	void Add(T* pNewNode);
	void ForwardAdd(Node<T>* pNewNode);
	void BackwardAdd(Node<T>* pNewnode);
	void Show();
	void ReverseShow();
	void AllDelete();
	int  size();
};


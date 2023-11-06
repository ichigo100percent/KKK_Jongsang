#include "LinkedList.h"

template<class T>
TLinkedList<T>::TLinkedList()
{
	m_pHead = new TNode<T>;
	m_pTail = new TNode<T>;
	m_pHead->m_pNext = m_pTail;
	m_pHead->m_pPrev = nullptr;
	m_pTail->m_pNext = nullptr;
	m_pTail->m_pPrev = m_pHead;
}

template<class T>
TLinkedList<T>::~TLinkedList()
{
	AllDelete();
}

template<class T>
TNode<T>* TLinkedList<T>::NewNode(T iData)
{
	TNode<T>* pNewNode = new TNode<T>;
	pNewNode->DATA = iData;
	return pNewNode;
}

template<class T>
void TLinkedList<T>::BackwardAdd(TNode<T>* pNewNode)
{
	TNode<T>* pPrev = m_pTail->m_pPrev;

	pPrev->m_pNext = pNewNode;
	pNewNode->m_pPrev = pPrev;

	pNewNode->m_pNext = m_pTail;
	m_pTail->m_pPrev = pNewNode;
}

template<class T>
void TLinkedList<T>::ForwardAdd(TNode<T>* pNewNode)
{
	TNode<T>* pNext = m_pHead->m_pNext;

	m_pHead->m_pNext = pNewNode;
	pNewNode->m_pPrev = m_pHead;

	pNewNode->m_pNext = pNext;
	pNewNode->m_pPrev = pNewNode;
}

template<class T>
void TLinkedList<T>::Show()
{
	for (TNode<T>*	pNode = m_pHead->m_pNext;
					pNode != m_pTail;
					pNode = pNode->m_pNext)
	{
		std::cout << pNode->DATA << std::endl;
	}
}

template<class T>
void TLinkedList<T>::ReverseShow()
{
	for (TNode<T>*	pNode = m_pTail->m_pPrev;
					pNode != m_pHead;
					pNode = pNode->m_pPrev)
	{
		std::cout << pNode->DATA << std::endl;
	}
}

template<class T>
void TLinkedList<T>::AllDelete()
{
	TNode<T>* pNode = m_pHead;
	while (pNode != nullptr)
	{
		TNode<T>* pDelNode = pNode;
		pNode = pNode->m_pNext;
		delete pDelNode;
	}
}
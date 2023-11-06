#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList()
{
	m_pHead = new Node<T>;
	m_pTail = new Node<T>;
	m_pHead->m_pNext = m_pTail;
	m_pHead->m_pPrev = nullptr;
	m_pTail->m_pNext = nullptr;
	m_pTail->m_pPrev = m_pHead;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	AllDelete();
}

template<class T>
Node<T>* LinkedList<T>::newNode(T iData)
{
	Node<T>* pNewNode = new Node<T>;
	pNewNode->DATA = iData;
	return pNewNode;
}

template<class T>
void LinkedList<T>::Add(T* pNewData)
{
	Node<T> pNewNode = new Node<T>();
	pNewNode->DATA = *pNewData;

	Node<T>* pPrev = m_pTail->m_pPrev;
	pPrev->m_pNext = pNewNode;
	pNewNode->m_pPrev = pPrev;

	pNewNode->m_pNext = m_pTail;
	m_pTail->m_pPrev = pNewNode;

	m_iCounter++;
}

template<class T>
void LinkedList<T>::BackwardAdd(Node<T>* pNewNode)
{
	Node<T>* pPrev = m_pTail->m_pPrev;

	pPrev->m_pNext = pNewNode;
	pNewNode->m_pPrev = pPrev;

	pNewNode->m_pNext = m_pTail;
	m_pTail->m_pPrev = pNewNode;

	m_iCounter++;
}

template<class T>
void LinkedList<T>::ForwardAdd(Node<T>* pNewNode)
{
	Node<T>* pPrev = m_pHead->m_pNext;

	pPrev->m_pNext = pNewNode;
	pNewNode->m_pPrev = pPrev;

	pNewNode->m_pNext = m_pTail;
	m_pTail->m_pPrev = pNewNode;

	m_iCounter++;
}

template<class T>
void LinkedList<T>::Show()
{
	for (Node<T> pNode = m_pHead->m_pNext;
				 Node != m_pTail;	
			     pNode = pNode->m_pNext)
	{
		std::cout << pNode->DATA << std::endl;
	}
}

template<class T>
void LinkedList<T>::ReverseShow()
{
	for (Node<T>* pNode = m_pTail->m_pPrev;
				  pNode != m_pHead;
				  pNode = pNode->m_pPrev)
	{
		std::cout << pNode->DATA << std::endl;
	}
}

template<class T>
int LinkedList<T>::size()
{
	int iCnt = 0;
	for(Node<T>* pNode= m_pHead->m_pNext;
				 pNode != m_pTail; 
				 pNode= pNode->m_pNext)
	{
		iCnt++;
	}
	return iCnt;
}
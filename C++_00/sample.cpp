//#include "StudentManager.h"

#include <iostream>
#include "StudentManager.h"

//using namespace std;
//
//template <typename T>
//struct Node
//{
//	T* data;
//	
//	Node* next;
//	Node* prev;
//};
//
//
//class student
//{
//public:
//	int mat;
//	int kor;
//	int eng;
//
//	int total;
//
//public:
//	void set_value(int _mat, int _kor, int _eng)
//	{
//		mat = _mat;
//		kor = _kor;
//		eng = _eng;
//
//		total = _mat + _kor + _eng;
//	}
//
//	int get_total()
//	{
//		return total;
//	}
//
//};
//
//class List
//{
//public:
//	List() 
//	{
//		head = nullptr;
//		tail = nullptr;
//	}
//
//	Node<student>* create(Node<student>** _head, Node<student>** _tail, student* _s)
//	{
//		Node<student>* newS = new Node<student>;
//
//		newS->data = _s;
//
//		if (*_head == nullptr)
//		{
//			*_head = newS;
//			*_tail = newS;
//
//			return newS;
//		}
//
//		return newS;
//	}
//
//	void push_back(student* _data)
//	{
//		Node<student>* newS = create(&head, &tail, _data);
//
//		tail->next = newS;
//		newS->prev = tail;
//
//		tail = newS;
//	}
//
//public:
//
//	Node<student>* head;
//	Node<student>* tail;
//};
//
//class studentM
//{
//public:
//	List m_list;
//
//
//public:
//	student* newStudent()
//	{
//		student* newS = new student;
//
//		newS->set_value(rand() % 100, rand() % 100, rand() % 100);
//
//		return newS;
//	}
//
//	void add()
//	{
//		student* st = newStudent();
//		m_list.push_back(st);
//	}
//};


int main()
{
	

	StudentManager M;

	M.run();


	return 0;

}
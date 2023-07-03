#pragma once

template <typename T>
class Node
{
public:
	Node();
	~Node();

public:
	T* data;
	Node* next;
	Node* prev;

	//friend std::ostream& operator << (std::ostream& out, const Node<T>& _n)
	//{
	//	return out;
	//}
	//friend std::ostream& operator << (std::ostream& out, const Node<student>& _n)
	//{
	//	out << _n.data->getsubject() << ' ';
	//	return out;
	//}
};

template<typename T>
Node<T>::Node()
{
	data = nullptr;
	next = nullptr;
	prev = nullptr;
}

template<typename T>
Node<T>::~Node()
{
	//if (data != nullptr)
	//{
	//	delete data;
	//	data = nullptr;
	//}
}

#include "std.h"

class Student
{
public:
    Student(string _name, int _kor, int _eng, int _math)
        : m_sName(_name)
        , m_iKor(_kor)
        , m_iEng(_eng)
        , m_iMath(_math)
    {

    }
    friend ostream& operator<<(ostream& os, const Student& _student)
    {
        os << _student.m_sName << ' ' 
            << _student.m_iKor << ' ' 
            << _student.m_iEng << ' ' 
            << _student.m_iMath << endl;
        return os;
    }

public:
    string m_sName;
    int m_iKor;
    int m_iEng;
    int m_iMath;
};


int main()
{
   
    List<Student> list;

    Student* s1 = new Student("ÀÌ", 100, 100, 100);
    Student* s2 = new Student("±è", 100, 100, 100);
    Student* s3 = new Student("¹Ú", 100, 100, 100);

    list.push_back(s1);
    list.push_back(s2);
    list.push_back(s3);

    list.print();

    return 0;
}


/*
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
	Node* next;
	Node* prev;
};

template <typename T>
class List
{
public:
	List()
		: head(nullptr)
		, tail(nullptr)
	{

	}

	void push_back(T _data)
	{
		if (head == nullptr)
		{
			head = new Node<T>(_data);
			tail = head;
		}
		else
		{
			tail->next = new Node<T>(_data);
			tail->next->prev = tail;
			tail = tail->next;
		}
	}

	void print()
	{
		Node<T>* buff = head;
		while (buff != nullptr)
		{
			cout << buff->data << " ";
			buff = buff->next;
		}
	}

private:
	Node<T>* head;
	Node<T>* tail;
};

int main()
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	l.print();

	return 0;
}
*/
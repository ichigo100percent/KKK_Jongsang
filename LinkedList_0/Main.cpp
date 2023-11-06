#include "LinkedList.cpp"

struct Student
{
	int iID;
	int iKor;
	
	Student& operator<<(int i)
	{
		std::cout << iKor + i << std::endl;
		return *this;
	}

	Student& operator<<(float i)
	{
		std::cout << iKor + i << std::endl;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Student& t)
	{
		os << t.iID << " " << t.iKor << std::endl;
		return os;
	}
};

TLinkedList<Student> list;

int main()
{
	Student a0;
	a0.iID = 999;
	a0.iKor = 100;
	a0 << 1 << 11.0f;

	for (int i = 0; i < 5; i++)
	{
		Student tStudent;
		tStudent.iID = i;
		tStudent.iKor = i * 10;
		list.BackwardAdd(list.NewNode(tStudent));
		//list.ForwardAdd(list.NewNode(tStudent));
	}
	list.Show();
	list.ReverseShow();
}
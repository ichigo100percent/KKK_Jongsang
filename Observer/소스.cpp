#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Animal
{
public:
	virtual void bark()
	{
		cout << " " << endl;
	}
};

class Dog : public Animal
{
public:
	void bark()override
	{
		cout << "�۸�" << endl;
	}
};


int main()
{
	Animal* a = new Animal();

	Dog* b = new Dog();

	a->bark();

	// a�� Dog*�� dynamic_cast�Ͽ� Ÿ�� ����
	Dog* dogA = dynamic_cast<Dog*>(a);

	if (dogA) {
		// Ÿ���� ���������� ����Ǿ��ٸ� Dog�� bark ȣ��
		dogA->bark();
	}
	else {
		cout << "Dynamic cast failed" << endl;
	}

	delete a;
	delete b;

}
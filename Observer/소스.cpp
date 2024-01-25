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
		cout << "멍멍" << endl;
	}
};


int main()
{
	Animal* a = new Animal();

	Dog* b = new Dog();

	a->bark();

	// a를 Dog*로 dynamic_cast하여 타입 변경
	Dog* dogA = dynamic_cast<Dog*>(a);

	if (dogA) {
		// 타입이 정상적으로 변경되었다면 Dog의 bark 호출
		dogA->bark();
	}
	else {
		cout << "Dynamic cast failed" << endl;
	}

	delete a;
	delete b;

}
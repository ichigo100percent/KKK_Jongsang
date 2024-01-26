#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Animal
{
public:
	virtual void bark() = 0;
};

class Dog : public Animal
{
public:
	void bark() override
	{
		cout << "港港" << endl;
	}
};

class Cat : public Animal
{
public:
	void bark() override
	{
		cout << "具克" << endl;
	}
};

vector<Animal*> vec = {};

template<typename T>
T* GetAnimal()
{
	T* ani = nullptr;

	for (auto element : vec)
	{
		ani = dynamic_cast<T*>(element);

		if (ani)
		{
			break;
		}
	}

	return ani;
}

int main()
{
	Animal* dog = new Dog();
	Animal* cat = new Cat();

	vec.push_back(dog);
	vec.push_back(cat);

	Dog* dog2 = GetAnimal<Dog>();

	if (dog2)
	{
		dog2->bark();
	}
	else
	{
		cout << "null ptr" << endl;
	}
}
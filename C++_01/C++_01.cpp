#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class base
{
public:
	virtual void dosometing()
	{
		cout << "base method" << endl;
	}
};

class derived : public base
{
public:
	virtual void dosometing() override
	{
		dosometing();
		cout << "derived methoed" << endl;
	}
};

int main()
{
	derived d2;
	d2.dosometing();
}
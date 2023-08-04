#include "Utils.h"

int main()
{
	int a;
	int b = 10;
	int c = 20;

	a = min(b, c);

	std::cout << a << std::endl;

	a = b > c ? b : c;

	std::cout << a << std::endl;

	a = max(b, c);

	std::cout << a << std::endl;

	a = randstep(b, c);

	std::cout << a;
}

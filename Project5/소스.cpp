#include <iostream>
#include <functional>
#include <string>
#include <conio.h>
#include <algorithm>
#include <vector>
#include <memory>

using namespace std;

bool badValue(int x)
{
    if (x == 0)
    {
        std::cout << "same 0" << std::endl;
        return true;
    }
    return false;
}

int main()
{
    struct S
    {
        int a;
        int b;
    };

    cout << sizeof(S);

    return 0;
}
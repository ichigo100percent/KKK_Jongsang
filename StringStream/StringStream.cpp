#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


int main()
{
    string str1;
    string str2;
    stringstream ss;

    getline(cin, str1);
    ss << str1;

    vector<string> vec{};

    while (getline(ss, str2, ','))
    {
        vec.push_back(str2);
    }

    for (auto& e : vec)
    {
        cout << e << endl;
    }
    return 0;
}
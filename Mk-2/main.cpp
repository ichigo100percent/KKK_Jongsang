#include <iostream>
#include <list>
#include <vector>
#include <set>;
#include <unordered_set>
using namespace std;

int main() 
{
	set<pair<int, string>> s;

	s.insert({ 1,"이종상" });
	s.insert({ 1,"이종상" });

	for (auto& n : s)
	{
		cout << n.first << " " << n.second << " ";
	}

	return 0;
}
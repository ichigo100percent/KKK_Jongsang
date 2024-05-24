//#include <iostream>
//#include <random>
//using namespace std;
//
//
//int main()
//{
//	std::random_device rd;
//	std::mt19937 gen(rd());
//	std::uniform_int_distribution<int> dist(0, 99);
//
//	for (size_t i = 0; i < 100; i++)
//	{
//		int randValue = dist(gen);
//		cout << randValue << endl;
//	}
//	return 0;
//}

#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include <memory>
#include <typeinfo>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

int main()
{
	// 시드 생성
	auto seed = chrono::system_clock::now().time_since_epoch().count();

	// 시드를 사용하여 엔진 초기화
	mt19937 rng(seed);

	// 분포 선택
	uniform_int_distribution<int> dist(1, 100);

	vector<int> vec = {};

	for (int i = 0; i < 100; i++)
	{
		vec.push_back(dist(rng));
	}

	for (auto& e : vec)
	{
		cout << e << " ";
	}
	cout << '\n';

	sort(vec.begin(), vec.end());

	for (auto& e : vec)
	{
		cout << e << " ";
	}
	cout << '\n';

	shuffle(vec.begin(), vec.end(), rng);

	for (auto& e : vec)
	{
		cout << e << " ";
	}
	cout << '\n';

	auto func = bind(dist, rng);

	generate(vec.begin(), vec.end(), func);

	for (auto& e : vec)
	{
		cout << e << " ";
	}
	cout << '\n';
	cout << '\n';

	vector<int> vec2{};
	transform(vec.begin(), vec.end(), back_inserter(vec2),
		[](int i)->int
		{
			return i * 2;
		});

	for (auto& e : vec2)
	{
		cout << e << " ";
	}
	cout << '\n';

	return 0;
}
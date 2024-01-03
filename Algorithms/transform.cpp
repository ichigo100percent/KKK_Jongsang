#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
transform() :

목적: 주어진 범위의 각 원소를 변형(transform)하여 다른 범위에 저장한다.
사용 예제 : 범위의 각 원소를 제곱하여 다른 범위에 저장하는 것과 같은 변형 작업에 유용하다.
특이 사항 : 변형 작업을 수행하는 함수자(함수 객체)를 사용할 수 있다.
*/

//int 타입 컨테이너에 원소를 채우는 함수 템플릿
//이때 컨테이너는 반드시 push_back()을 제공해야 한다.
template <typename Container>
void populateContainer(Container& cont)
{
	int num;

	while (true)
	{
		cout << "Enter a number (0 to quit): ";
		cin >> num;
		if (num == 0)
		{
			break;
		}
		cont.push_back(num);
	}
}

/*
int main()
{
	vector<int> myVector{ 2, 4, 6, 8, 10 };

	//populateContainer(myVector);


	cout << "The vector contains:" << endl;
	for (const auto& i : myVector)
	{
		cout << i << " ";
	}
	cout << endl;

	transform(begin(myVector), end(myVector), begin(myVector), [](int i) {return i + 100; });

	cout << "The vector contains:" << endl;
	for (const auto& i : myVector) { cout << i << " "; }
	cout << endl;

	// 입력 벡터
	std::vector<int> input = { 1, 2, 3, 4, 5 };

	// 출력 벡터
	std::vector<int> output;

	// 각 원소를 제곱하여 결과를 출력 벡터에 저장
	std::transform(input.begin(), input.end(), std::back_inserter(output), [](int x) { return x * x; });

	// 결과 출력
	std::cout << "Original vector: ";
	for (int x : input) {
		std::cout << x << ' ';
	}
	std::cout << "\nSquared vector: ";
	for (int x : output) {
		std::cout << x << ' ';
	}
	std::cout << std::endl;

	return 0;
}
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
transform() :

����: �־��� ������ �� ���Ҹ� ����(transform)�Ͽ� �ٸ� ������ �����Ѵ�.
��� ���� : ������ �� ���Ҹ� �����Ͽ� �ٸ� ������ �����ϴ� �Ͱ� ���� ���� �۾��� �����ϴ�.
Ư�� ���� : ���� �۾��� �����ϴ� �Լ���(�Լ� ��ü)�� ����� �� �ִ�.
*/

//int Ÿ�� �����̳ʿ� ���Ҹ� ä��� �Լ� ���ø�
//�̶� �����̳ʴ� �ݵ�� push_back()�� �����ؾ� �Ѵ�.
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

	// �Է� ����
	std::vector<int> input = { 1, 2, 3, 4, 5 };

	// ��� ����
	std::vector<int> output;

	// �� ���Ҹ� �����Ͽ� ����� ��� ���Ϳ� ����
	std::transform(input.begin(), input.end(), std::back_inserter(output), [](int x) { return x * x; });

	// ��� ���
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
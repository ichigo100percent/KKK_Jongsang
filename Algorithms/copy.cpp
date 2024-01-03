#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
copy():

����: �־��� ������ �� ���Ҹ� �ٸ� ������ �����Ѵ�.
��� ����: �ϳ��� ���Ϳ��� �ٸ� ���ͷ� ���� ������ �� ����Ѵ�.
Ư�� ����: ���� ��� ������ ����� ũ��� �̸� �Ҵ�Ǿ� �־�� �Ѵ�.
*/

//int Ÿ�� �����̳ʿ� ���Ҹ� ä��� �Լ� ���ø�
//�̶� �����̳ʴ� �ݵ�� push_back()�� �����ؾ� �Ѵ�.
template<typename Container>
void populateCantainer(Container& cont)
{
	int num;

	while (true)
	{
		cout << "Enter a number (0 to quit)";
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
	vector<int> vec1, vec2;
	populateCantainer(vec1);

	vec2.resize(size(vec1));

	//copy(cbegin(vec1), cend(vec1), begin(vec2));

	copy_backward(cbegin(vec1), cend(vec1), end(vec2));

	for (const auto& i : vec2)
	{
		cout << i << " ";
	}

	return 0;
}
*/
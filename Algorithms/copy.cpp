#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
copy():

목적: 주어진 범위의 각 원소를 다른 범위에 복사한다.
사용 예제: 하나의 벡터에서 다른 벡터로 값을 복사할 때 사용한다.
특이 사항: 복사 대상 범위는 충분한 크기로 미리 할당되어 있어야 한다.
*/

//int 타입 컨테이너에 원소를 채우는 함수 템플릿
//이때 컨테이너는 반드시 push_back()을 제공해야 한다.
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
#include <iostream>
#include <functional>
#include <vector>
#include <bitset>
#include <memory>
#include <vector>
#include <algorithm>
#include <time.h>
#include <string_view>
#include <algorithm>

#pragma warning(disable: 4996)

using namespace std;

vector<int> vec = { 1,2,3,4,5,6,7,8,9 };

int main()
{

    erase_if(vec,
        [=](int num)
        {
            return num % 2 == 1;
        });

    for (auto num : vec)
    {
        cout << num << ' ';
    }
    ���ع��� ��λ��� ������ �⵵�� �ϴ����� �����ϻ� �츮���� ���� ������ȭ ��õ�� ȭ������ ���ѻ�� �������Τ� ���� �����ϼ� �������� �� �ҳ��� ö��
    return 0;
}
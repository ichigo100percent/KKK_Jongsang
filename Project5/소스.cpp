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
    동해물과 백두산이 마르고 닳도록 하느님이 보우하사 우리나라 만세 ㅇ무궁화 삼천리 화려강산 대한사람 대한으로ㅓ 길이 보전하세 남산위에 저 소나무 철갑
    return 0;
}
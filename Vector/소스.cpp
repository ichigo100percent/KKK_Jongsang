#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec = { 1,10,100,1000 };

	for (auto element : vec)
	{
		cout << element << " ";
	}

	auto it = std::find(vec.begin(), vec.end(), 100);

	if (it != vec.end())
	{
		vec.erase(it);
	}
	else
	{
		cout << "fail" << endl;
	}

	for (auto element : vec)
	{
		cout << element << " ";
	}
}

#include <iostream>
#include <vector>

using namespace std;

class CopyConstructor
{
private:
    int value;
    //int* p = nullptr;
public:

    CopyConstructor() :value(999) {
        cout << " CopyConstructor() 기본생성자" << endl;
    }

    CopyConstructor(const int data) {
        cout << "CopyConstructor(int data) 기본 생성자" << endl;
        value = data;
    }

    CopyConstructor(const CopyConstructor& copy) {
        this->value = copy.value;
        cout << "CopyConstructor(const CopyConstructor& copy) 복사 생성자" << endl;
    }
    void operator = (const CopyConstructor& copy) {
        this->value = copy.value;
        cout << "대입 연산자 " << endl;

    }

    //이동생성자의 함수에 noexcept가 붙은 경우 안붙은 경우를 잘 확인해야한다.
    CopyConstructor(const CopyConstructor&& copy) {
        this->value = std::move(copy.value);
        // copy.p = nullptr;
        cout << " CopyConstructor(CopyConstructor&& copy)  이동 생성자" << endl;
    }

    void operator= (CopyConstructor&& copy) {
        this->value = copy.value;
        cout << "이동 대입 연산자" << endl;
    }

    ~CopyConstructor() {
        cout << "소멸자 " << endl;
    }


};


/*
벡터 사용법
https://eteo.tistory.com/504

https://openmynotepad.tistory.com/10
pubh_back은 객체를 집어넣는 형식으로 객체가 없이 삽입을 할려면 임시 객체 (rvalue)가 있어야한다.

*/

int main()
{
    cout << "========== vector<CopyConstructor> init_vector 객체 생성 ==========" << endl;
    vector<CopyConstructor> init_vector;

    cout << "reserve(100)로 용량(capacity)을 미리 확보  " << endl;
    init_vector.reserve(100);

    cout << "vector<CopyConstructor> init_vector1(1, 5) " << endl;
    vector<CopyConstructor> init_vector1(0, 5);    //크기가1이고 모든 값이 5인 벡터 생성
    cout << endl << endl;

    cout << "  vector<CopyConstructor> init_vector2(5, 3) " << endl;
    vector<CopyConstructor> init_vector2(5, 3);    //크기가5이고 모든 값이 3인 벡터 생성
    /* std::vector의 생성자가 호출되어, 크기가 5이고 각 요소가 3으로 초기화된 CopyConstructor타입의 벡터를 생성한다.
    여기서 중요한 점은 3이 CopyConstructor 타입의 임시 객체를 생성하기 위해 사용된다는 점이다.
    이 임시 객체는 벡터의 모든 요소를 초기화 하는데 사용한다.

    ① 3을 인자로 받는 CopyConstructor 타입 객체의 일반 생성자가 호출 되어 임시 객체가 생성된다.
    이 과정은 딱 한번 발생한다.

    ② 이 후 임시 객체는 벡터의 모든 요소(총 5개)를 초기화 하기위해 사용된다. 각 요소를 초기화 할 때마다 복사 생성자가 호출된다.
    따라서, 복사 생성자는 5번 호출된다.
    */
    cout << endl << endl;

    cout << " std::vector<CopyConstructor> init_vector3 = { 0, 1, 2} " << endl;
    std::vector<CopyConstructor> init_vector3 = { 0, 1, 2 };
    cout << endl << endl;
    /*
    ① 초기화 리스트 내의 각각의 값{ 0, 1, 2}은 CopyConstructor 타입의 객체를 생성하기 위해 사용된다.
    이 때, 각 값에 대해 일반생성자가 호출된다. 벡터가 3개로 구성되어있으므로, 총 3번 발생한다.
    ② 최신 C++ 표준에서는 이 과정에서 가능한 이동 생성자를 우선적으로 사용할려고 한다. 따라서
    CopyConstructor(const CopyConstructor&& copy) noexcept이 있으면 이동 생성자가 실행된다.
    없으면 복사생성자가 실행되는데 복사 생성자가 3번 호출된다.

    ③ 객체를 생성하기 위해 사용된 일반생성자 소멸을 위한 소멸자 3번 호출

    */
    cout << "init_vector.push_back(CopyConstructor()) " << endl;
    init_vector.push_back(CopyConstructor(3));
    cout << endl << endl;

    /*
    CopyConstructor(3)를 통해 임시 객체를 하나 생성 => 기본 생성자 호출
    임시 객체를 이동생성자를 통해 push_back함수 내부에 임시 객체를 만들어 냈다. -> 이동 생성사 호출
    vector객체에 삽입
    push_back을 빠져나온 후 CopyConstructor(3)를 통해 만들어진 임시 객체 소멸
    */

    cout << "init_vector.push_back(8) " << endl;
    init_vector.push_back(8);
    init_vector.push_back(3);
    cout << endl << endl;


    cout << "    init_vector.emplace_back(1)" << endl;
    init_vector.emplace_back(1);
    /*
    emplace_back함수에 CopyConstructor객체를 만들 수 있는 인자를 넘김 (아직 생성자 안만듬 넘기기만함)
    emplace_back 내부에서 임시객체가 생성되고 삽입
    벡터에 객체를 삽입
    */
    cout << endl << endl;


    //5 -> CopyConstructor(5) -> CopyConstructor(temp) -> std::move(CopyConstructor)


    cout << "========== vector<CopyConstructor> Copy_vector 객체 생성 ==========";
    vector<CopyConstructor> Copy_vector;    //빈 벡터 생성
    cout << endl << endl;
    /* vector<CopyConstructor> Copy_vector가 실행될 떄 CopyConstructor 타입을 저장할 수 있는 빈 벡터 Copy_vector가 생성된다.
    이 시점에는 CopyConstructor타입의 객체가 생성되지 않았다. 따라서 생성자 호출은 하지 않는다*/

    Copy_vector.push_back(1);
    Copy_vector.push_back(2);
    Copy_vector.push_back(3);
    Copy_vector.push_back(4);

    /*
    ①첫 번째 Copy_vector.push_back(1)
    기본 생성자: 1을 인자로 받는 CopyConstructor 타입 객체의 일반 생성자가 생성(호출)
    이동 생성자: 생성된 객체는 임시객체로 쓰기 위한 객체이므로, 임시객체를 vector에 저장
    소멸자: 임시 객체가 소멸된다.

    ② 두 번째 Copy_vector.push_back(2)
    기본 생성자: 2를 인자로 받는 CopyConstructor 타입 객체의 일반 생성자가 생성(호출)

    vector가 용량(capacity)를 재할당해야하는 경우
    이동 생성자: 새 객체를 임시 저장소에 이동시키기 때문에 이동 생성자 호출
    복사 생성자: 첫 번요소를 새로운 메모리 위치로 복사

    소멸자 호출: 첫 번째 요소의 이전 인스턴스가 소멸된다.
    소멸자 호출: 임시 객체가 소멸된다.

    ③ 세 번째 push_back(3)
    기본 생성자: 3를 인자로 받는 CopyConstructor 타입 객체의 일반 생성자가 생성(호출)
    vector가 용량(capacity)를 재할당해야하는 경우
    이동 생성자: 새 객체를 임시 저장소에 이동시켜하기 때문에 이동 생성자 호출
    복사 생성자: 첫 번째 요소를 새로운 메모리 위치로 복사한다.
    복사 생성자: 두 번째 요소를 새로운 메모리 위치로 복사한다.

    소멸자 호출: 첫 번째 요소의 이전 인스턴스가 소멸된다.
    소멸자 호출: 두 번째 요소의 이전 인스턴스가 소멸된다.
    소멸자 호출: 임시 객체가 소멸된다.


    ④  네 번째 push_back(3)
    기본 생성자 CopyConstructor(int data) 호출: 4를 인자로 받아 객체를 생성.

    vector가 다시 용량을 재할당해야 하는 경우
    이동 생성자 CopyConstructor(CopyConstructor&& copy) 호출: 새 객체를 임시 저장소에 이동.
    복사 생성자 CopyConstructor(const CopyConstructor& copy) 호출: 첫 번째 요소를 새로운 메모리 위치로 복사.
    복사 생성자 CopyConstructor(const CopyConstructor& copy) 호출: 두 번째 요소를 새로운 메모리 위치로 복사.
    복사 생성자 CopyConstructor(const CopyConstructor& copy) 호출: 세 번째 요소를 새로운 메모리 위치로 복사.

    소멸자 호출: 첫 번째 요소의 이전 인스턴스가 소멸.
    소멸자 호출: 두 번째 요소의 이전 인스턴스가 소멸.
    소멸자 호출: 세 번째 요소의 이전 인스턴스가 소멸.
    소멸자 호출: 임시 객체가 소멸.

    같은 과정을 계속 반복된다고 보면된다.
    이게 끝이라 중요한 부분이 있다. 어느 순간 부터 vector가 자동으로 capacity를 조절해주는데
    capacity가 1.5배씩 늘어나게 된다.
    capacity가 늘어나서     vector가 다시 용량을 재할당을 안해도 될때는
    기본생성자가 호출되고 이동생성자가 호출된 다음 소멸자가 호출되는걸 볼 수 있다.

    이 과정을 통해 vector가 용량(capacity)을 재할당해야하는 경우는 복사가 일어나는걸 볼 수 있고
    용량이 넉넉하다면 복사가 안 일어난다는걸 알 수 있다.
    */


    Copy_vector.emplace(Copy_vector.end(), 4);
    Copy_vector.insert(Copy_vector.end(), 5);

    cout << endl << endl;

    cout << "========== CopyConstructor copCon(4)객체 생성 ==========";
    CopyConstructor copCon(4);
    cout << endl << endl;
    vector<int> vec;

}
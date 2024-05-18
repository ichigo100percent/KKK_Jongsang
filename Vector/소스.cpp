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
        cout << " CopyConstructor() �⺻������" << endl;
    }

    CopyConstructor(const int data) {
        cout << "CopyConstructor(int data) �⺻ ������" << endl;
        value = data;
    }

    CopyConstructor(const CopyConstructor& copy) {
        this->value = copy.value;
        cout << "CopyConstructor(const CopyConstructor& copy) ���� ������" << endl;
    }
    void operator = (const CopyConstructor& copy) {
        this->value = copy.value;
        cout << "���� ������ " << endl;

    }

    //�̵��������� �Լ��� noexcept�� ���� ��� �Ⱥ��� ��츦 �� Ȯ���ؾ��Ѵ�.
    CopyConstructor(const CopyConstructor&& copy) {
        this->value = std::move(copy.value);
        // copy.p = nullptr;
        cout << " CopyConstructor(CopyConstructor&& copy)  �̵� ������" << endl;
    }

    void operator= (CopyConstructor&& copy) {
        this->value = copy.value;
        cout << "�̵� ���� ������" << endl;
    }

    ~CopyConstructor() {
        cout << "�Ҹ��� " << endl;
    }


};


/*
���� ����
https://eteo.tistory.com/504

https://openmynotepad.tistory.com/10
pubh_back�� ��ü�� ����ִ� �������� ��ü�� ���� ������ �ҷ��� �ӽ� ��ü (rvalue)�� �־���Ѵ�.

*/

int main()
{
    cout << "========== vector<CopyConstructor> init_vector ��ü ���� ==========" << endl;
    vector<CopyConstructor> init_vector;

    cout << "reserve(100)�� �뷮(capacity)�� �̸� Ȯ��  " << endl;
    init_vector.reserve(100);

    cout << "vector<CopyConstructor> init_vector1(1, 5) " << endl;
    vector<CopyConstructor> init_vector1(0, 5);    //ũ�Ⱑ1�̰� ��� ���� 5�� ���� ����
    cout << endl << endl;

    cout << "  vector<CopyConstructor> init_vector2(5, 3) " << endl;
    vector<CopyConstructor> init_vector2(5, 3);    //ũ�Ⱑ5�̰� ��� ���� 3�� ���� ����
    /* std::vector�� �����ڰ� ȣ��Ǿ�, ũ�Ⱑ 5�̰� �� ��Ұ� 3���� �ʱ�ȭ�� CopyConstructorŸ���� ���͸� �����Ѵ�.
    ���⼭ �߿��� ���� 3�� CopyConstructor Ÿ���� �ӽ� ��ü�� �����ϱ� ���� ���ȴٴ� ���̴�.
    �� �ӽ� ��ü�� ������ ��� ��Ҹ� �ʱ�ȭ �ϴµ� ����Ѵ�.

    �� 3�� ���ڷ� �޴� CopyConstructor Ÿ�� ��ü�� �Ϲ� �����ڰ� ȣ�� �Ǿ� �ӽ� ��ü�� �����ȴ�.
    �� ������ �� �ѹ� �߻��Ѵ�.

    �� �� �� �ӽ� ��ü�� ������ ��� ���(�� 5��)�� �ʱ�ȭ �ϱ����� ���ȴ�. �� ��Ҹ� �ʱ�ȭ �� ������ ���� �����ڰ� ȣ��ȴ�.
    ����, ���� �����ڴ� 5�� ȣ��ȴ�.
    */
    cout << endl << endl;

    cout << " std::vector<CopyConstructor> init_vector3 = { 0, 1, 2} " << endl;
    std::vector<CopyConstructor> init_vector3 = { 0, 1, 2 };
    cout << endl << endl;
    /*
    �� �ʱ�ȭ ����Ʈ ���� ������ ��{ 0, 1, 2}�� CopyConstructor Ÿ���� ��ü�� �����ϱ� ���� ���ȴ�.
    �� ��, �� ���� ���� �Ϲݻ����ڰ� ȣ��ȴ�. ���Ͱ� 3���� �����Ǿ������Ƿ�, �� 3�� �߻��Ѵ�.
    �� �ֽ� C++ ǥ�ؿ����� �� �������� ������ �̵� �����ڸ� �켱������ ����ҷ��� �Ѵ�. ����
    CopyConstructor(const CopyConstructor&& copy) noexcept�� ������ �̵� �����ڰ� ����ȴ�.
    ������ ��������ڰ� ����Ǵµ� ���� �����ڰ� 3�� ȣ��ȴ�.

    �� ��ü�� �����ϱ� ���� ���� �Ϲݻ����� �Ҹ��� ���� �Ҹ��� 3�� ȣ��

    */
    cout << "init_vector.push_back(CopyConstructor()) " << endl;
    init_vector.push_back(CopyConstructor(3));
    cout << endl << endl;

    /*
    CopyConstructor(3)�� ���� �ӽ� ��ü�� �ϳ� ���� => �⺻ ������ ȣ��
    �ӽ� ��ü�� �̵������ڸ� ���� push_back�Լ� ���ο� �ӽ� ��ü�� ����� �´�. -> �̵� ������ ȣ��
    vector��ü�� ����
    push_back�� �������� �� CopyConstructor(3)�� ���� ������� �ӽ� ��ü �Ҹ�
    */

    cout << "init_vector.push_back(8) " << endl;
    init_vector.push_back(8);
    init_vector.push_back(3);
    cout << endl << endl;


    cout << "    init_vector.emplace_back(1)" << endl;
    init_vector.emplace_back(1);
    /*
    emplace_back�Լ��� CopyConstructor��ü�� ���� �� �ִ� ���ڸ� �ѱ� (���� ������ �ȸ��� �ѱ�⸸��)
    emplace_back ���ο��� �ӽð�ü�� �����ǰ� ����
    ���Ϳ� ��ü�� ����
    */
    cout << endl << endl;


    //5 -> CopyConstructor(5) -> CopyConstructor(temp) -> std::move(CopyConstructor)


    cout << "========== vector<CopyConstructor> Copy_vector ��ü ���� ==========";
    vector<CopyConstructor> Copy_vector;    //�� ���� ����
    cout << endl << endl;
    /* vector<CopyConstructor> Copy_vector�� ����� �� CopyConstructor Ÿ���� ������ �� �ִ� �� ���� Copy_vector�� �����ȴ�.
    �� �������� CopyConstructorŸ���� ��ü�� �������� �ʾҴ�. ���� ������ ȣ���� ���� �ʴ´�*/

    Copy_vector.push_back(1);
    Copy_vector.push_back(2);
    Copy_vector.push_back(3);
    Copy_vector.push_back(4);

    /*
    ��ù ��° Copy_vector.push_back(1)
    �⺻ ������: 1�� ���ڷ� �޴� CopyConstructor Ÿ�� ��ü�� �Ϲ� �����ڰ� ����(ȣ��)
    �̵� ������: ������ ��ü�� �ӽð�ü�� ���� ���� ��ü�̹Ƿ�, �ӽð�ü�� vector�� ����
    �Ҹ���: �ӽ� ��ü�� �Ҹ�ȴ�.

    �� �� ��° Copy_vector.push_back(2)
    �⺻ ������: 2�� ���ڷ� �޴� CopyConstructor Ÿ�� ��ü�� �Ϲ� �����ڰ� ����(ȣ��)

    vector�� �뷮(capacity)�� ���Ҵ��ؾ��ϴ� ���
    �̵� ������: �� ��ü�� �ӽ� ����ҿ� �̵���Ű�� ������ �̵� ������ ȣ��
    ���� ������: ù ����Ҹ� ���ο� �޸� ��ġ�� ����

    �Ҹ��� ȣ��: ù ��° ����� ���� �ν��Ͻ��� �Ҹ�ȴ�.
    �Ҹ��� ȣ��: �ӽ� ��ü�� �Ҹ�ȴ�.

    �� �� ��° push_back(3)
    �⺻ ������: 3�� ���ڷ� �޴� CopyConstructor Ÿ�� ��ü�� �Ϲ� �����ڰ� ����(ȣ��)
    vector�� �뷮(capacity)�� ���Ҵ��ؾ��ϴ� ���
    �̵� ������: �� ��ü�� �ӽ� ����ҿ� �̵������ϱ� ������ �̵� ������ ȣ��
    ���� ������: ù ��° ��Ҹ� ���ο� �޸� ��ġ�� �����Ѵ�.
    ���� ������: �� ��° ��Ҹ� ���ο� �޸� ��ġ�� �����Ѵ�.

    �Ҹ��� ȣ��: ù ��° ����� ���� �ν��Ͻ��� �Ҹ�ȴ�.
    �Ҹ��� ȣ��: �� ��° ����� ���� �ν��Ͻ��� �Ҹ�ȴ�.
    �Ҹ��� ȣ��: �ӽ� ��ü�� �Ҹ�ȴ�.


    ��  �� ��° push_back(3)
    �⺻ ������ CopyConstructor(int data) ȣ��: 4�� ���ڷ� �޾� ��ü�� ����.

    vector�� �ٽ� �뷮�� ���Ҵ��ؾ� �ϴ� ���
    �̵� ������ CopyConstructor(CopyConstructor&& copy) ȣ��: �� ��ü�� �ӽ� ����ҿ� �̵�.
    ���� ������ CopyConstructor(const CopyConstructor& copy) ȣ��: ù ��° ��Ҹ� ���ο� �޸� ��ġ�� ����.
    ���� ������ CopyConstructor(const CopyConstructor& copy) ȣ��: �� ��° ��Ҹ� ���ο� �޸� ��ġ�� ����.
    ���� ������ CopyConstructor(const CopyConstructor& copy) ȣ��: �� ��° ��Ҹ� ���ο� �޸� ��ġ�� ����.

    �Ҹ��� ȣ��: ù ��° ����� ���� �ν��Ͻ��� �Ҹ�.
    �Ҹ��� ȣ��: �� ��° ����� ���� �ν��Ͻ��� �Ҹ�.
    �Ҹ��� ȣ��: �� ��° ����� ���� �ν��Ͻ��� �Ҹ�.
    �Ҹ��� ȣ��: �ӽ� ��ü�� �Ҹ�.

    ���� ������ ��� �ݺ��ȴٰ� ����ȴ�.
    �̰� ���̶� �߿��� �κ��� �ִ�. ��� ���� ���� vector�� �ڵ����� capacity�� �������ִµ�
    capacity�� 1.5�辿 �þ�� �ȴ�.
    capacity�� �þ��     vector�� �ٽ� �뷮�� ���Ҵ��� ���ص� �ɶ���
    �⺻�����ڰ� ȣ��ǰ� �̵������ڰ� ȣ��� ���� �Ҹ��ڰ� ȣ��Ǵ°� �� �� �ִ�.

    �� ������ ���� vector�� �뷮(capacity)�� ���Ҵ��ؾ��ϴ� ���� ���簡 �Ͼ�°� �� �� �ְ�
    �뷮�� �˳��ϴٸ� ���簡 �� �Ͼ�ٴ°� �� �� �ִ�.
    */


    Copy_vector.emplace(Copy_vector.end(), 4);
    Copy_vector.insert(Copy_vector.end(), 5);

    cout << endl << endl;

    cout << "========== CopyConstructor copCon(4)��ü ���� ==========";
    CopyConstructor copCon(4);
    cout << endl << endl;
    vector<int> vec;

}
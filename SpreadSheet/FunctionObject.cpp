#include <string>

using namespace std;

class FunctionObject
{
public:
	int operator() (int param); //�Լ� ȣ�� ������
	void operator() (string_view) {}
	int doSquare(int param);    //�Ϲ� �޼���
};

//�����ε��� �Լ� ȣ�� �������� ���� �ڵ�
int FunctionObject::operator() (int param)
{
	return doSquare(param);
}

//�Ϲ� �޼����� ���� �ڵ�
int FunctionObject::doSquare(int parm)
{
	return parm * parm;
}

/*
int main()
{
	int x = 3, xSquared, xSquardAgain;

	FunctionObject sqare;

	xSquared = sqare(x);				//�Լ� ȣ�� �����ڸ� ȣ���Ѵ�.
	xSquardAgain = sqare.doSquare(x);	//�Ϲ� �޼��带 ȣ���Ѵ�.

}
*/
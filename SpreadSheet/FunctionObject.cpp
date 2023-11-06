#include <string>

using namespace std;

class FunctionObject
{
public:
	int operator() (int param); //함수 호출 연산자
	void operator() (string_view) {}
	int doSquare(int param);    //일반 메서드
};

//오버로딩한 함수 호출 연산자의 구현 코드
int FunctionObject::operator() (int param)
{
	return doSquare(param);
}

//일반 메서드의 구현 코드
int FunctionObject::doSquare(int parm)
{
	return parm * parm;
}

/*
int main()
{
	int x = 3, xSquared, xSquardAgain;

	FunctionObject sqare;

	xSquared = sqare(x);				//함수 호출 연사자를 호출한다.
	xSquardAgain = sqare.doSquare(x);	//일반 메서드를 호출한다.

}
*/
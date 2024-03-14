#pragma once
#include <iostream>
#include <vector>

using namespace std;


//커맨드
class Command
{
public:
	virtual void Excute() = 0;
};

//리시버
class Computer
{
public:
	void TurnOn()
	{
		cout << "컴퓨터 켜짐" << endl;
	}

	void TurnOff()
	{
		cout << "컴퓨터 꺼짐" << endl;
	}
};

//커맨드 생성
class TurnOn : public Command
{
public:
	TurnOn(Computer* _computer) : pComputer(_computer) {}

	void Excute() override
	{
		pComputer->TurnOn();
	}

private:
	Computer* pComputer;
};


class TurnOff : public Command
{
public:
	TurnOff(Computer* _computer) : pComputer(_computer) {}

	void Excute() override
	{
		pComputer->TurnOff();
	}

private:
	Computer* pComputer;
};

//인보커(호출자)
class Controller
{
public:
	void Set(Command* _command)
	{
		pCommand = _command;
	}

	void Press() { pCommand->Excute(); }

private:
	Command* pCommand;
};
#pragma once
#include <iostream>
#include <vector>

using namespace std;


//Ŀ�ǵ�
class Command
{
public:
	virtual void Excute() = 0;
};

//���ù�
class Computer
{
public:
	void TurnOn()
	{
		cout << "��ǻ�� ����" << endl;
	}

	void TurnOff()
	{
		cout << "��ǻ�� ����" << endl;
	}
};

//Ŀ�ǵ� ����
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

//�κ�Ŀ(ȣ����)
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
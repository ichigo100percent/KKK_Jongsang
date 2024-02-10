#pragma once
#include <iostream>
#include <vector>

using namespace std;

//commnad interface
class Command
{
public:
	virtual void excute() = 0;
};

//Receiver
class Light
{
public:
	void turnOn()
	{
		cout << "Light is On" << endl;
	}
	void turnOff()
	{
		cout << "Light is Off" << endl;
	}
};

//COncrete Command
class TurnOnLightCommand : public Command
{
private:
	Light* light;

public:
	TurnOnLightCommand(Light* l) : light(l) {}

	void excute() override
	{
		light->turnOn();
	}
};

class TurnOffLightCommand : public Command
{
private:
	Light* light;
public:
	TurnOffLightCommand(Light* l) : light(l) {}

	void excute() override
	{
		light->turnOff();
	}
};

//Invoke
class RemoteControl
{
private:
	Command* command;

public:
	void SetCommand(Command* cmd)
	{
		command = cmd;
	}

	void pressButton()
	{
		command->excute();
	}
};



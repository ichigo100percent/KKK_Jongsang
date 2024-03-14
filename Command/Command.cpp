#include "Command.h"


int main()
{
	Computer* computer = new Computer();

	Command* turnOn = new TurnOn(computer);
	Command* turnOff = new TurnOff(computer);

	Controller* controller = new Controller();
	controller->Set(turnOn);
	controller->Press();

	controller->Set(turnOff);
	controller->Press();

	return 0;
}
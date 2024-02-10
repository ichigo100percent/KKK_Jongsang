#include "Command.h"


int main()
{
	Light* livingRoomLight = new Light();
	Command* turnOnCmd = new TurnOnLightCommand(livingRoomLight);
	Command* turnOffCmd = new TurnOffLightCommand(livingRoomLight);

	RemoteControl* remote = new RemoteControl();
	remote->SetCommand(turnOnCmd);
	remote->pressButton();


	remote->SetCommand(turnOffCmd);
	remote->pressButton();
 }
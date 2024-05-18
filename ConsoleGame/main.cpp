#include "Mgr.h"
#include "Console.h"

#include <time.h>
using namespace Js;
using namespace std;


Mgr m;

int main()
{
	srand(time(NULL));
	SetConsoleSize(30, 30);
	SetCursor(FALSE);
	m.Init();

	m.Update();

	SetCursor(TRUE);
	system("pause");
	return 0;
}

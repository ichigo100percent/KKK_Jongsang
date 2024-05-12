#include "Management.h"

using namespace Js;

int main()
{
	Management m;
	m.Init();
	m.Update();
	m.release();

	return 0;
}
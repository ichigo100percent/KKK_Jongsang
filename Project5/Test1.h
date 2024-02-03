#pragma once
#include "std.h"

extern int a;

shared_ptr<int> fun2(int _num)
{
	return make_shared<int>(_num);
}

unique_ptr<int> fun3(int _num)
{
	unique_ptr<int> p = make_unique<int>(_num);

	return p;
}
#include "Test.h"
#include <array>
#include <format>;
#include <utility>;
#include <memory>

bool Test::Init()
{
	//std::shared_ptr<int> pI = std::make_shared<int[]>(5);
	std::shared_ptr<int[]> pI(new int[5]); // �迭�� �ʱ�ȭ�ϴ� ���

	pI.get()[0] = 1;

	cout << pI[0];

	return true;
}

bool Test::Update()
{
	return true;
}

bool Test::End()
{
	return true;
}

Game;
#pragma once
#include "Component.h"

class Leaf1 : public Component
{
private:
	std::wstring name;
	

public:
	Leaf1(const std::wstring& _name) : name(_name) {}

	void showInfo() override
	{
		std::wcout << "File1: " << name << std::endl;
	}
};

//class Leaf2 : public Component
//{
//private:
//	std::wstring name;
//
//
//public:
//	Leaf2(const std::wstring& _name) : name(_name) {}
//
//	void showInfo() override
//	{
//		std::wcout << "File2: " << name << std::endl;
//	}
//};
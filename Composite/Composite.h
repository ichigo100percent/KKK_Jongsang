#pragma once
#include "Component.h"
#include <vector>
#include <memory>

class Composite : public Component
{
private:
	std::wstring name;
	std::vector<std::unique_ptr<Component>> components;

public:
	Composite(const std::wstring& _name) : name(_name) {}

	void addComponent(std::unique_ptr<Component> _component)
	{
		components.push_back(std::move(_component));
	}

	void showInfo() override
	{
		std::wcout << "Composite: " << name << endl;
		for (const auto& component : components)
		{
			component->showInfo();
		}

	}

};
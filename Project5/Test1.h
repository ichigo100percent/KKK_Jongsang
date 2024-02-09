#pragma once
#include "std.h"



enum class Type
{
	texture,
	script,
	end = 16,
};

class component
{
public:
	component(Type _type) : m_type(_type) {}
	virtual ~component() {}

	Type GetType() { return m_type; }

private:
	Type m_type;

};

class texture : public component
{
public:
	texture() : component(Type::texture) {}
	~texture() {}
};

class script : public component
{
public:
	script() : component(Type::script) {}
	~script() {}

};
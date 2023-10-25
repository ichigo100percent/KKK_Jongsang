#pragma once
#include <iostream>
#include <optional>

using namespace std;

class Stack
{
public:
	//Stack() = default;
	Stack();
	virtual ~Stack() = default;

	void    init();
	void	push(int value);
	int		pop();
	void	print();

private:
	int*				m_stack;
	//optional<int>		m_value;
	//optional<int> 		m_size;
	const static int	m_size = 3;
	int 				m_top;
};


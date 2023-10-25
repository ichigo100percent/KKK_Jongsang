#include "Stack.h"

Stack::Stack()
{
	init();
}

void Stack::init()
{
	m_stack = new int[m_size];
	m_top = 0;
}

void Stack::push(int value)
{
	if (m_top >= m_size)
	{
		cout << "stack overflow" << endl;
		return;
	}

	m_stack[m_top] = value;

	m_top++;
}

int Stack::pop()
{
	if (m_top < 0)
	{
		cout << "stack underflow" << endl;
		return 1;
	}

	cout << m_stack[m_top - 1] << endl;

	return m_stack[m_top--];
}

void Stack::print()
{
	//while (m_top > 0)
	//{
	//	cout << m_stack[--m_top] << endl;
	//}

	for (int i = m_top - 1; i >= 0; i--)
	{
		cout << m_stack[i] << endl;
	}
}

#include <iostream>
#include <functional>

struct Event
{
	void operator=(std::function<void()> _fun)
	{
		m_Event = std::move(_fun);
	}

	void operator()()
	{
		if (m_Event)
			m_Event();
	}

	std::function<void()> m_Event;
};

void test()
{
	std::cout << "gd" << std::endl;
}

int main()
{
	Event e;
	Event e2;

	e2.m_Event = std::move(test);

	e = e2;

	return 0;
}
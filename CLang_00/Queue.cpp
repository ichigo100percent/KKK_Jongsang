#include "Queue.h"

Queue::Queue()
{
	front = rear = -1;
}

void Queue::enqueue(int value)
{
	if (isfull())
	{
		cout << "stack overflow" << endl;
		return;
	}
	else if (isempty())
	{
		front = rear = 0;
	}
	else
	{
		rear = (rear + 1) % MAX_SIZE;
	}

	m_queue[rear] = value;
}

int Queue::dequeue()
{
	if (isempty())
	{
		cout << "queue is empty" << endl;
		return -1;
	}

	int value = m_queue[front];

	if (front == rear)
	{
		front = rear = -1;
	}
	else
	{
		front = (front + 1) % MAX_SIZE;
	}

	return value;
}

void Queue::frint()
{
	while (!isempty())
	{
		cout << dequeue() << endl;
	}
}

bool Queue::isfull()
{
	return (rear + 1) % MAX_SIZE == front;
}

bool Queue::isempty()
{
	return front == -1;
}

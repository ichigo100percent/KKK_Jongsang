#include "CLang_01.h"

void Queue::Enqueue(int data)
{
	item[++rear] = data;
}

int Queue::Dequeue()
{
	return item[front++];
}

int Queue::Size()
{
	return (rear - front + 1);
}

bool Queue::isEmpty()
{
	if (front > rear)
	{
		return true;
	}
	return false;
}

bool Queue::isFull()
{
	if (Size() > MAX_SIZE)
	{
		return true;
	}
	return false;
}

void Queue::Display()
{
	if (!isEmpty())
	{
		for (size_t i = front; i < rear; i++)
		{
			std::cout << item[i] << std::endl;
		}
	}
	else
	{
		std::cout << "Queue Underflow" << std::endl;
	}
}


#include <iostream>
#include <cstring>

//#define MAX_SIZE 10

class Queue
{
	int MAX_SIZE = 10;

public:
	Queue() //기본 생성자
	{
		item = new int[MAX_SIZE];

		for (size_t i = 0; i < MAX_SIZE; i++)
		{
			item[i] = 0;
		}
	}

	Queue(int iSize)
		:MAX_SIZE(iSize)
	{
		item = new int[MAX_SIZE];

		for (size_t i = 0; i < MAX_SIZE; i++)
		{
			item[i] = 0;
		}
	}

	Queue(const Queue& queue)
	{
		//옅은 복사
		//item = queue.item;

		//깊은 복사
		item = new int[MAX_SIZE];
		for (size_t i = 0; i < MAX_SIZE; i++)
		{
			item[i] = queue.item[i];
		}
		rear = queue.rear;
		front = queue.front;
	}
	~Queue()
	{
		delete[] item;
	}

public:
	void Enqueue(int data);
	int	 Dequeue();
	int  Size();
	bool isEmpty();
	bool isFull();
	void Display();

private:
	int* item = nullptr;
	int  rear = -1;
	int  front = 0;
};
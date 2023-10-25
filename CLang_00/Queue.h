#include <iostream>

#define MAX_SIZE 3

using namespace std;

class Queue
{
public:
	Queue();
	virtual ~Queue() = default;

	void enqueue(int value);
	int  dequeue();
	void frint();

private:
	bool isfull();
	bool isempty();

	int m_queue[MAX_SIZE];
	int front;
	int rear;
};
#include <iostream>
#include <vector>

using namespace std;


class Heap
{
public:
	Heap()
		: m_heap{}
	{
	}

	void insert(int _val)
	{
		m_heap.push_back(_val);
		heapifyUP(m_heap.size() - 1);
	}

	int pop()
	{
		if (m_heap.empty())
			return -1;

		int max = m_heap[0];
		m_heap[0] = m_heap.back();
		m_heap.pop_back();

		heapifyDown(0);

		return max;
	}

private:
	void heapifyUP(int _index)
	{
		int parentIndex = (_index - 1) / 2;

		while (_index > 0 && m_heap[_index] > m_heap[parentIndex])
		{
			swap(m_heap[_index], m_heap[parentIndex]);
			_index = parentIndex;
			parentIndex = (_index - 1) / 2;
		}
	}

	void heapifyDown(int _index)
	{
		int childLeftIndex = _index * 2 + 1;
		int childRightIndex = _index * 2 + 2;
		int LargestIndex = _index;

		if (m_heap.size() > childLeftIndex && m_heap[LargestIndex] < m_heap[childLeftIndex])
		{
			LargestIndex = childLeftIndex;
		}
		if (m_heap.size() > childRightIndex && m_heap[LargestIndex] < m_heap[childRightIndex])
		{
			LargestIndex = childRightIndex;
		}

		if (_index != LargestIndex)
		{
			swap(m_heap[_index], m_heap[LargestIndex]);
			heapifyDown(LargestIndex);
		}
	}

private:
	vector<int> m_heap;
};

int main()
{
	Heap h;
	h.insert(5);
	h.insert(1);
	h.insert(60);
	h.insert(20);
	h.insert(50);

	h.pop();

	return 0;
}
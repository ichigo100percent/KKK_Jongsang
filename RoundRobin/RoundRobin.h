#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>

//����Ʈ�� ��� ���ҿ� ���� ������ ���� �κ� �����ٸ��� �����Ѵ�.
template <typename T>
class RoundRobin
{
public:
	//ȿ���� ���̱� ���� ������ ���� ������ Ŭ���̾�Ʈ�� �޴´�.
	RoundRobin(size_t numExpected = 0);
	virtual ~RoundRobin() = default;

	//���԰� �� ������ �����Ѵ�.
	RoundRobin(const RoundRobin& src) = delete;
	RoundRobin& operator=(const RoundRobin& rhs) = delete;

	//�̵� �����ڿ� �̵� ���� �����ڸ� ��������� ����Ʈ�� �����Ѵ�.
	RoundRobin(RoundRobin&& src) = default;
	RoundRobin& operator=(RoundRobin&& rhs) = default;

	//���Ҹ� ����Ʈ ���� �߰��Ѵ�.
	//getNext() ���̿� ȣ��� �� �ִ�.
	void add(const T& element);

	//operator== �����ڸ� ȣ���� ��� 
	//�Ȱ��ٰ� �Ǵܵ� ù ��° ���Ҹ� �����Ѵ�.
	//getNext() ���̿� ȣ��� �� �ִ�.
	void remove(const T& element);

	//����Ʈ�� ���� �� ���Ҹ� �����Ѵ�. ù ��° ���Һ��� �����ؼ� ������
	//���ҿ� �ٴٸ��� �ٽ� ù ��° ��ҷ� ���ƿ´�.
	//�̶� �߰��� �߰��ǰų� ������ ���ҵ� �ݿ��Ѵ�.
	T& getNext();

private:
	std::vector<T> mElement;
	typename std::vector<T>::iterator mCurrentElement;
};

template<typename T>
RoundRobin<T>::RoundRobin(size_t numExpected)
{
	//Ŭ���̾�Ʈ�� ������ ��ŭ ������ Ȯ���Ѵ�
	mElement.reserve(numExpected);

	//���Ұ� �ּ� �ϳ� ���� ������ ������� �ʴ���
	//�ϴ� mCurrentElement�� �ʱ�ȭ�صд�.
	//there's at least one element.
	mCurrentElement = begin(mElement);
}

//�� ���Ҵ� �׻� �������� �߰��Ѵ�.
template <typename T>
void RoundRobin<T>::add(const T& element)
{
	//���Ҹ� �������� �߰��ϴ��� push_back()�� ȣ���� �����
	//vector�� ���Ҵ�Ǽ� mCurrentElement �ݺ��ڰ� ��ȿȭ�� �� �ִ�.
	//������ �����Ϸ��� �ݺ����� ���� ������ ����� �ִ��� Ȱ���Ѵ�.
	//iterator features to save out spot
	int pos = mCurrentElement - begin(mElement);

	//���Ҹ� �߰��Ѵ�
	mElement.push_back(element);

	//�ݺ��ڸ� �׻� ������ ���·� �����ϵ��� �����Ѵ�
	mCurrentElement = begin(mElement) + pos;
}

template <typename T>
void RoundRobin<T>::remove(const T& element)
{
	for (auto it = begin(mElement); it != end(mElement); ++it)
	{
		if (*it == element)
		{
			//mCurrentElement �ݺ��ڰ� �����ϴ� ���Ұ� ������ ����� ���� ���Ҹ�
			//����Ű�� ���� �� ���Ҹ� �����ϸ� mCurrentElement �ݺ��ڰ� ��ȿȭ�ȴ�.
			//������ �� ���� ������ ��ġ�� �����Ϸ���
			//�ݺ����� ���� ������ ����� Ȱ���Ѵ�.
			int newPos;

			if (mCurrentElement == end(mElement) - 1 && mCurrentElement == it)
			{
				//mCurrentElement�� ����Ʈ�� ������ ���Ҹ� ����Ű�� ���¿���
				//�� ���Ҹ� �����Ϸ� �ϹǷ� �ٽ� ù ��° ���ҷ� ��ġ�� �̵���Ų��.
				//the beginning
				newPos = 0;
			}
			else if (mCurrentElement <= it)
			{
				//�׷��� �ʰ� mCurrentElement�� �����Ϸ��� ���ҳ� �� ���� ���Ҹ�
				//����Ű�� �ִٸ� ��ġ�� ������ ����.
				newPos = mCurrentElement - begin(mElement);
			}
			else
			{
				//�տ� ���� �� ��� ��� �ش���� �ʴ´ٸ�
				//�� ĭ ���� �� ��ġ�� �ȴ�.
				newPos = mCurrentElement - begin(mElement) - 1;
			}

			//���Ҹ� �����Ѵ�. (���ϰ��� �����Ѵ�.)
			mElement.erase(it);

			//�ݺ��ڰ� ������ ���¸� �����ϵ��� �����Ѵ�.
			mCurrentElement = begin(mElement) + newPos;

			return;
		}
	}
}

template <typename T>
T& RoundRobin<T>::getNext()
{
	//���� ���Ұ� ��� �ִ������� Ȯ����.
	if (mElement.empty())
	{
		throw std::out_of_range("No elements in the list");
	}

	//���� ����(������ ����)�� �����ϵ��� �����صд�.
	auto& toReturn = *mCurrentElement;

	//�ݺ��ڸ� ���� ���� ���� ����(modulo, ������) ������ �̿��Ͽ� ������Ų��.
	++mCurrentElement;
	if (mCurrentElement == end(mElement))
	{
		mCurrentElement = begin(mElement);
	}

	//���ҿ� ���� ���۷����� �����Ѵ�.
	return  toReturn;
}
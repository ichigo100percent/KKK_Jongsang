#pragma once
#include <cstddef>
#include <stdexcept>
#include <memory>


template <typename T>
class Array
{
public:
	//�ʿ信 ���� ũ�Ⱑ �����ϴ� �迭�� ����Ʈ ũ��� �����Ѵ�.
	Array();
	virtual ~Array();

	//���԰� �� ���� ����� ������� �ʴ´�.
	Array<T>& operator=(const Array<T>& rhs) = delete;
	Array(const Array<T>& src) = delete;

	T& operator[](size_t x);
	const T& operator[](size_t x) const;

	//�ε��� x�� �ִ� ���� �����Ѵ�. �ε��� x ������ ���Ұ� ������ 
	//out_of_rang �ͼ����� ������.
	const T& getElementAt(size_t x, const T& value);

	//�ε��� x ������ ���� �����Ѵ�. �ε��� x�� ���� �迭�� ũ�⸦ �����
	//������ �� �Ҵ��Ѵ�.
	void setElementAt(size_t x, const T& value);

	size_t getSize() const;

private:
	static const size_t kAllocSize = 4;
	void resize(size_t newSize);
	T* mElements = nullptr;
	size_t mSize = 0;
};

template<typename T>
inline Array<T>::Array()
{
	mSize = kAllocSize;
	mElements = new T[mSize]{}; //���Ҹ� 0���� �ʱ�ȭ�Ѵ�.
}

template<typename T>
inline Array<T>::~Array()
{
	delete[] mElements;
	mElements = nullptr;
}

template<typename T>
inline T& Array<T>::operator[](size_t x)
{
	if (x >= mSize)
	{
		//Ŭ���̾�Ʈ�� ��û�� ���� �ڷ� kAllocSize��ŭ ������ �Ҵ��Ѵ�.
		resize(x + kAllocSize);
	}

	return mElements[x];
}

template<typename T>
inline const T& Array<T>::operator[](size_t x) const
{
	if (x >= mSize)
	{
		throw std::out_of_range("");
	}
	return mElements[x];
}

template<typename T>
inline const T& Array<T>::getElementAt(size_t x, const T& value)
{
	if (x >= mSize)
	{
		throw std::out_of_range("");
	}
	return mElements[x];
}

template<typename T>
inline void Array<T>::setElementAt(size_t x, const T& value)
{
	if (x >= mSize)
	{
		//Ŭ���̾�Ʈ�� ��û�� ���� �ڷ� kAllocSize��ŭ ������ �Ҵ��Ѥ�.
		resize(x + kAllocSize);
	}
	mElements[x] = value;
}

template<typename T>
inline size_t Array<T>::getSize() const
{
	return mSize;
}

template<typename T>
inline void Array<T>::resize(size_t newSize)
{
	//�� ū �迭�� �����Ѵ�. ���� 0���� �ʱ�ȭ�Ѵ�.
	auto newArray = std::make_unique<T[]>(newSize);

	//���� ������ �迭�� �ݵ�� ����(mSize)���� Ŀ�� �Ѵ�.
	for (size_t i = 0; i < mSize; i++)
	{
		newArray[i] = mElements[i];
	}

	//���� �迭�� �����ϰ� �� �迭�� �����Ѵ�.
	delete[] mElements;
	mSize = newSize;
	mElements = newArray.release();
}

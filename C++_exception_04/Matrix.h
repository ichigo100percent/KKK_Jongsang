#pragma once

#include <cstddef>
#include <iostream>
#include <new>
#include <exception>

template <typename T>
class Matrix
{
public:
	Matrix(size_t width, size_t height);
	virtual ~Matrix();

private:
	void cleanup();

	size_t m_Width = 0;
	size_t m_Height = 0;
	T** m_Matrix = nullptr;
};

template<typename T>
inline Matrix<T>::Matrix(size_t width, size_t height)
{
	m_Matrix = new T * [width] {}; //�迭�� 0���� �ʱ�ȭ�Ѵ�.

	//m_Width�� m_Height ����� ������ �̴ϼŶ������� �ʱ�ȭ�ϸ� �� �ȴ�.
	//�տ� ���� mMatrix�� ���������� �Ҵ����� ���� �ʱ�ȭ�ؾ� �ϱ� �����̴�.
	m_Width = width;
	m_Height = height;

	try
	{
		for (size_t i = 0; i < width; ++i)
		{
			m_Matrix[i] = new T[height];
		}
	}
	catch (...)
	{
		std::cerr << "Exception caught in constructor, cleaning up..." << std::endl;
		cleanup();
		//�߻��� �ͼ����� ��� bad_alloc �ͼ��� �ȿ� ��ø��Ų��.
		std::throw_with_nested(std::bad_alloc());
	}
}

template<typename T>
inline Matrix<T>::~Matrix()
{
	cleanup();
}

template<typename T>
inline void Matrix<T>::cleanup()
{
	for (size_t i = 0; i < m_Width; ++i)
	{
		delete[] m_Matrix[i];
	}
	delete[] m_Matrix;
	m_Matrix = nullptr;
	m_Width = m_Height = 0;
}

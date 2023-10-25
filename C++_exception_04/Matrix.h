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
	m_Matrix = new T * [width] {}; //배열을 0으로 초기화한다.

	//m_Width와 m_Height 멤버를 생성자 이니셔랄이저로 초기화하면 안 된다.
	//앞에 나온 mMatrix를 성공적으로 할당했을 때만 초기화해야 하기 때문이다.
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
		//발생한 익셉션을 모두 bad_alloc 익셉션 안에 중첩시킨다.
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

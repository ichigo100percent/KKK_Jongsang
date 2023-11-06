#pragma once

template <typename T>
class Pointer
{
public:
	Pointer(T* ptr);
	virtual ~Pointer();

	//���԰� �� ���� ����� ������� �ʴ´�.
	Pointer(const Pointer<T>& src) = delete;
	Pointer<T>& operator=(const Pointer<T>& rhs) = delete;

	T& operator*();
	const T& operator*() const;

	T* operator->();
	const T* operator->() const;

	operator bool() const;
 
private:
	T* mPtr = nullptr;
};

template<typename T>
inline Pointer<T>::Pointer(T* ptr) : mPtr(ptr)
{
}

template<typename T>
inline Pointer<T>::~Pointer()
{
	delete mPtr;
	mPtr = nullptr;
}

template<typename T>
inline T& Pointer<T>::operator*()
{
	return *mPtr;
}

template<typename T>
inline const T& Pointer<T>::operator*() const
{
	return *mPtr;
}

template<typename T>
inline T* Pointer<T>::operator->()
{
	return mPtr;
}

template<typename T>
inline const T* Pointer<T>::operator->() const
{
	return mPtr;
}

template<typename T>
inline Pointer<T>::operator bool() const
{
	return mPtr != nullptr;
}




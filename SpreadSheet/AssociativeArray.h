#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <stdexcept>

template <typename T>
class AssociativeArray
{
public:
	virtual ~AssociativeArray() = default;

	T& operator[](std::string_view key);
	const T& operator[](std::string_view key) const;

private:
	class Element
	{
	public:
		Element(std::string_view key, const T& value)
			:mKey(key), mValue(value) {}
		std::string mKey;
		T mValue;
	};

	std::vector<Element> mData;
};

template<typename T>
inline T& AssociativeArray<T>::operator[](std::string_view key)
{
	//키가 이미 있는지 확인한다.
	for (auto& element : mData)
	{
		if (element.mKey == key)
			return element.mValue;
	}

	//이 부분에 도달했다면 키가 존재하지 않는다는 뜻이므로 키를 추가한다.
	mData.push_back(Element(key, T()));
	//방금 추가한 값에 대한 레퍼런스를 리턴한다.
	return mData.back().mValue;
}

template<typename T>
inline const T& AssociativeArray<T>::operator[](std::string_view key) const
{
	for (auto& element : mData)
	{
		if (element.mKey == key)
		{
			return element.mValue;
		}
	}
	throw std::invalid_argument(std::string(key.data()) + " dosen't exist");
}



/*
#include "AssociativeArray.h"
#include <iostream>

using namespace std;

int main()
{
	AssociativeArray<int> myArray;
	myArray["Key 1"] = 11;
	myArray["Key 2"] = 22;
	myArray["Key 3"] = 33;

	try {
		cout << myArray["Key 1"] << endl;
		cout << myArray["Key 2"] << endl;

		// const operator[]를 테스트한다.
		const AssociativeArray<int>& c = myArray;
		cout << c["Key 3"] << endl;
		cout << c["Key 4"] << endl;
	}
	catch (const invalid_argument& ex) {
		cout << "Caught exception: " << ex.what() << endl;
	}

	return 0;
}
*/
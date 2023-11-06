#include "SpreadsheetCell.h"
#include <stdexcept>
#include <iostream>

using namespace std;

SpreadsheetCell::SpreadsheetCell(double initialValue)
	:mValue(initialValue)
{
}

SpreadsheetCell::SpreadsheetCell(std::string_view initialValue)
	:mValue(stringToDouble(initialValue))
{
}

void SpreadsheetCell::set(double inValue)
{
	mValue = inValue;
}

void SpreadsheetCell::set(std::string_view inString)
{
	mValue = stringToDouble(inString);
}

std::string SpreadsheetCell::doubleToString(double inValue)
{
	return to_string(inValue);
}

double SpreadsheetCell::stringToDouble(std::string_view inString)
{
	return strtod(inString.data(), nullptr);
}

SpreadsheetCell& SpreadsheetCell::operator+=(const SpreadsheetCell& rhs)
{
	set(getValue() + rhs.getValue());
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator-=(const SpreadsheetCell& rhs)
{
	set(getValue() - rhs.getValue());
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator*=(const SpreadsheetCell& rhs)
{
	set(getValue() * rhs.getValue());
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator/=(const SpreadsheetCell& rhs)
{
	if (rhs.getValue() == 0)
	{
		throw invalid_argument("Divide by zero");
	}
	set(getValue() / rhs.getValue());
	return *this;
}

SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return SpreadsheetCell(lhs.getValue() + rhs.getValue());
}

SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return SpreadsheetCell(lhs.getValue() - rhs.getValue());
}

SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return SpreadsheetCell(lhs.getValue() * rhs.getValue());
}

SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return SpreadsheetCell(lhs.getValue() / rhs.getValue());
}

bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() == rhs.getValue()); 
}

bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() < rhs.getValue());
}

bool operator>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() > rhs.getValue());
}

bool operator!=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() != rhs.getValue());
}

bool operator<=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() <= rhs.getValue());
}

bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() >= rhs.getValue());
}

std::ostream& operator<<(std::ostream& ostr, const SpreadsheetCell& cell)
{
	ostr << cell.getValue();
	return ostr;
}

std::istream& operator>>(istream& istr, SpreadsheetCell& cell)
{
	double value;
	istr >> value;
	cell.set(value);
	return istr;
}

SpreadsheetCell SpreadsheetCell::operator-() const
{
	return SpreadsheetCell(-getValue());
}

SpreadsheetCell& SpreadsheetCell::operator++()
{
	set(getValue() + 1);
	return *this;
}

SpreadsheetCell SpreadsheetCell::operator++(int)
{
	auto oldCell(*this); //증가 전의 값을 저장한다.
	++(*this);			 //선행 증가 연산으로 값을 증가시킨다.
	return oldCell;		 //증가 전의 값을 리턴한다.
}

SpreadsheetCell& SpreadsheetCell::operator--()
{
	set(getValue() - 1);
	return *this;
}

SpreadsheetCell SpreadsheetCell::operator--(int)
{
	auto oldCell(*this);
	--(*this);
	return oldCell;
}
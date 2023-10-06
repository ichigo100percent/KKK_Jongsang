#include "SpreadSheetCell.h"

SpreadSheetCell::SpreadSheetCell(double initialValue)
{
	setValue(initialValue);
}

SpreadSheetCell::SpreadSheetCell(string_view initialValue)
{
	setString(initialValue);
}

SpreadSheetCell::SpreadSheetCell(const SpreadSheetCell& src)
	:mValue(src.mValue)
{
}

void SpreadSheetCell::setValue(double inValue)
{
	mValue = inValue;
}

double SpreadSheetCell::getValue() const
{
	mNumAccesses++;
	return mValue;
}

void SpreadSheetCell::setString(string_view inString)
{
	mValue = stringToDouble(inString);
}

string SpreadSheetCell::getString() const
{
	mNumAccesses++;
	return doubleToString(mValue);
}

void SpreadSheetCell::set(double inValue)
{
	mValue = inValue;
}

void SpreadSheetCell::set(std::string_view inString)
{
	mValue = stringToDouble(inString);
}

SpreadSheetCell SpreadSheetCell::add(const SpreadSheetCell& cell) const
{
	return SpreadSheetCell(getValue() + cell.getValue());
}

SpreadSheetCell& SpreadSheetCell::operator=(const SpreadSheetCell& rhs)
{
	mValue = rhs.mValue;
	return *this;
}

SpreadSheetCell SpreadSheetCell::operator+(const SpreadSheetCell& cell) const
{
	return SpreadSheetCell(getValue() + cell.getValue());
}

SpreadSheetCell& SpreadSheetCell::operator+=(const SpreadSheetCell& rhs)
{
	set(getValue() + rhs.getValue());
	return *this;
}

SpreadSheetCell& SpreadSheetCell::operator-=(const SpreadSheetCell& rhs)
{
	set(getValue() - rhs.getValue());
	return *this;
}

SpreadSheetCell& SpreadSheetCell::operator*=(const SpreadSheetCell& rhs)
{
	set(getValue() * rhs.getValue());
	return *this;
}

SpreadSheetCell& SpreadSheetCell::operator/=(const SpreadSheetCell& rhs)
{
	set(getValue() / rhs.getValue());
	return *this;
}

std::string SpreadSheetCell::doubleToString(double inValue)
{
	return to_string(inValue);
}

double SpreadSheetCell::stringToDouble(string_view inString)
{
	return strtod(inString.data(), nullptr);
}

SpreadSheetCell operator+(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return SpreadSheetCell(lhs.getValue() + rhs.getValue());
}

SpreadSheetCell operator-(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return SpreadSheetCell();
}

SpreadSheetCell operator*(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return SpreadSheetCell();
}

SpreadSheetCell operator/(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return SpreadSheetCell();
}

bool operator==(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return (lhs.getValue() == rhs.getValue());
}

bool operator<(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return (lhs.getValue() < rhs.getValue());
}

bool operator>(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return (lhs.getValue() > rhs.getValue());
}

bool operator!=(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return (lhs.getValue() != rhs.getValue());
}

bool operator<=(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return (lhs.getValue() <= rhs.getValue());
}

bool operator>=(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs)
{
	return (lhs.getValue() >= rhs.getValue());
}
#pragma once
#include <iostream>
#include <string>
#include <string_view>

using namespace std;

SpreadSheetCell operator+(const SpreadSheetCell& lhs,
	const SpreadSheetCell& rhs)
{
	return SpreadSheetCell(lhs.getValue() + rhs.getValue());
}

class SpreadSheetCell
{
public:
	SpreadSheetCell() = default;
	SpreadSheetCell(double initialValue);
	SpreadSheetCell(string_view initialValue);
	SpreadSheetCell(const SpreadSheetCell& src);
	explicit SpreadSheetCell(std::string_view initialValue);

	void setValue(double inValue);
	double getValue() const;

	void setString(string_view inString);
	string getString() const;

	void set(double inValue);
	void set(std::string_view inString);
	SpreadSheetCell add(const SpreadSheetCell& cell) const;

	SpreadSheetCell& operator= (const SpreadSheetCell& rhs);
	SpreadSheetCell operator+(const SpreadSheetCell& cell) const;

	SpreadSheetCell& operator+=(const SpreadSheetCell& rhs);
	SpreadSheetCell& operator-=(const SpreadSheetCell& rhs);
	SpreadSheetCell& operator*=(const SpreadSheetCell& rhs);
	SpreadSheetCell& operator/=(const SpreadSheetCell& rhs);

private:
	//string doubleToString(double inValue) const;
	//double stringToDouble(string_view inString) const;

	static std::string doubleToString(double inValue);
	static double stringToDouble(string_view inString);

	double mValue;
	mutable size_t mNumAccesses = 0;
};


SpreadSheetCell operator+(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
SpreadSheetCell operator-(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
SpreadSheetCell operator*(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
SpreadSheetCell operator/(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
bool operator==(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
bool operator<(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
bool operator>(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
bool operator!=(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
bool operator<=(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
bool operator>=(const SpreadSheetCell& lhs, const SpreadSheetCell& rhs);
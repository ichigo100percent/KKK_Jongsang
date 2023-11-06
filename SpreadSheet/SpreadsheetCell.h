#pragma once

#include <cstddef>
#include <string>
#include <string_view>

class SpreadsheetCell
{
public:
	SpreadsheetCell() = default;
	SpreadsheetCell(double initialValue);
	explicit SpreadsheetCell(std::string_view initialValue);

	void set(double inValue);
	void set(std::string_view inString);

	double getValue() const { nNumAccesses++; return mValue; }
	std::string getString() const { nNumAccesses++; return doubleToString(mValue); }

	static std::string doubleToString(double inValue);
	static double stringToDouble(std::string_view inString);

	SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);
	SpreadsheetCell operator-() const;
	SpreadsheetCell& operator++(); //선행증가
	SpreadsheetCell operator++(int); //후행증가
	SpreadsheetCell& operator--();
	SpreadsheetCell operator--(int);

private:
	double mValue;
	mutable size_t nNumAccesses = 0;
};


SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator!=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator<=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
std::ostream& operator<<(std::ostream& ostr, const SpreadsheetCell& cell);
std::istream& operator>>(std::istream& istr, SpreadsheetCell& cell);
#pragma once
#include <string>
#include <string_view>

using namespace std;

class SpreadSheetCell
{
public:
	SpreadSheetCell() = default;
	SpreadSheetCell(double initialValue);
	SpreadSheetCell(string_view initialValue);
	SpreadSheetCell(const SpreadSheetCell& src);

	void setValue(double inValue);
	double getValue() const;

	void setString(string_view inString);
	string getString() const;

	SpreadSheetCell& operator= (const SpreadSheetCell& rhs);

private:
	string doubleToString(double inValue) const;
	double stringToDouble(string_view inString) const;

	double mValue;
};


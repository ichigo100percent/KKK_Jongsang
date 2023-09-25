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
	return mValue;
}

void SpreadSheetCell::setString(string_view inString)
{
	mValue = stringToDouble(inString);
}

string SpreadSheetCell::getString() const
{
	return doubleToString(mValue);
}

SpreadSheetCell& SpreadSheetCell::operator=(const SpreadSheetCell& rhs)
{
	mValue = rhs.mValue;
	return *this;
}

string SpreadSheetCell::doubleToString(double inValue) const
{
	return to_string(inValue);
}

double SpreadSheetCell::stringToDouble(string_view inString) const
{
	return strtod(inString.data(), nullptr);
}

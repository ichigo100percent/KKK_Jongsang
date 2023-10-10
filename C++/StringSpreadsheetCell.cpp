#include "StringSpreadsheetCell.h"


using namespace std;


void StringSpreadsheetCell::set(string_view inString)
{
	mValue = inString;
}

string StringSpreadsheetCell::getString() const
{
	//mValue가 실젯값이 있으면 그 값을 리턴하고, 그렇지 않으면 공백 스트링을 리턴한다.
	return mValue.value_or("");
}
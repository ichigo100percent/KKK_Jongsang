#pragma once

#include "SpreadSheet.h"
#include <optional>

class DoubleSpreadsheetCell : public SpreadsheetCell
{
public:
	virtual void set(double inDouble);
	virtual void set(std::string_view inString) override;
	virtual std::string getString() const override;

private:
	
};


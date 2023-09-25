#pragma once
#include <cstddef>
#include <stdexcept>
#include "SpreadSheetCell.h"

class SpreadSheet
{
public:
	SpreadSheet(size_t width, size_t height);
	SpreadSheet(const SpreadSheet& src);
	~SpreadSheet();
	void setCellAt(size_t x, size_t y, const SpreadSheetCell& cell);
	SpreadSheetCell& getCellAt(size_t x, size_t y);

	SpreadSheet& operator=(const SpreadSheet& rhs);

private:
	//bool inRange(size_t value, size_t upper) const;
	void verifyCoordinate(size_t x, size_t y) const;

	size_t mWidth = 0;
	size_t mHeight = 0;
	SpreadSheetCell** mCells = nullptr;
};


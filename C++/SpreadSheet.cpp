#include "SpreadSheet.h"

//p357
SpreadSheet::SpreadSheet(size_t width, size_t height)
	:mWidth(width), mHeight(height)
{
	mCells = new SpreadSheetCell * [mWidth];

	for (size_t i = 0; i < mWidth; i++)
	{
		mCells[i] = new SpreadSheetCell[mHeight];
	}
}

SpreadSheet::SpreadSheet(const SpreadSheet& src)
	:SpreadSheet(src.mWidth, src.mHeight)
{
	for (size_t i = 0; i < mWidth; i++)
	{
		for (size_t j = 0; j < mHeight; j++)
		{
			mCells[i][j] = src.mCells[i][j];
		}
	}
}

SpreadSheet::~SpreadSheet()
{
	for (size_t i = 0; i < mWidth; i++)
	{
		delete [] mCells[i];
	}
	delete [] mCells;
	mCells = nullptr;
}

void SpreadSheet::setCellAt(size_t x, size_t y, const SpreadSheetCell& cell)
{
	verifyCoordinate(x, y);
	mCells[x][y] = cell;
}

SpreadSheetCell& SpreadSheet::getCellAt(size_t x, size_t y)
{
	//if (!inRange(x, mWidth) || !inRange(y, mHeight))
	//{
	//	throw out_of_range("");
	//}
	verifyCoordinate(x, y);
	return mCells[x][y];
}

SpreadSheet& SpreadSheet::operator=(const SpreadSheet& rhs)
{
	//�ڽ��� �����ϴ��� Ȯ���Ѵ�.
	if (this == &rhs)
	{
		return *this;
	}

	//���� �޸𸮸� �����Ѵ�.
	for (size_t i = 0; i < mWidth; i++)
	{
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;

	//�޸𸮸� ���� �Ҵ��Ѵ�.
	mWidth = rhs.mWidth;
	mHeight = rhs.mHeight;

	mCells = new SpreadSheetCell * [mWidth];
	for (size_t i = 0; i < mWidth; i++)
	{
		mCells[i] = new SpreadSheetCell[mHeight];
	}

	//�����͸� �����Ѵ�
	for (size_t i = 0; i < mWidth; i++)
	{
		for (rsize_t j = 0; j < mHeight; j++)
		{
			mCells[i][j] = rhs.mCells[i][j];
		}
	}

	return *this;
}

void SpreadSheet::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth || y >= mHeight)
	{
		throw out_of_range("");
	}
}

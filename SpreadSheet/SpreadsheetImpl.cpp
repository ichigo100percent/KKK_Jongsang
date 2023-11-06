#include "SpreadsheetImpl.h"

#include <stdexcept>
#include <utility>
#include <algorithm>

size_t Spreadsheet::Impl::sCounter;

Spreadsheet::Impl::Impl(const SpreadsheetApplication& theApp, size_t width, size_t height)
	:mId(sCounter++), mWidht(std::min(width, Spreadsheet::kMaxWidth)), mHeight(std::min(height, Spreadsheet::kMaxHeight)), mTheApp(theApp)
{
	mCells = new SpreadsheetCell * [mWidht];
	for (size_t i = 0; i < mWidht; i++)
	{
		mCells[i] = new SpreadsheetCell[mHeight];
	}
}

Spreadsheet::Impl::~Impl()
{
	for (size_t i = 0; i < mWidht; i++)
	{
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;
}

Spreadsheet::Impl::Impl(const Impl& src)
	:Impl(src.mTheApp, src.mWidht, src.mHeight)
{
	for (size_t i = 0; i < mWidht; i++)
	{
		for (size_t j = 0; j < mHeight; j++)
		{
			mCells[i][j] = src.mCells[i][j];
		}
	}
}

void Spreadsheet::Impl::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidht || y >= mHeight)
	{
		throw std::out_of_range("");
	}
}

void Spreadsheet::Impl::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell)
{
	verifyCoordinate(x, y);
	mCells[x][y] = cell;
}

SpreadsheetCell& Spreadsheet::Impl::getCellAt(size_t x, size_t y)
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}

void Spreadsheet::Impl::swap(Impl& other) noexcept
{
	using std::swap;

	swap(mWidht, other.mWidht);
	swap(mHeight, other.mHeight);
	swap(mCells, other.mCells);
}

Spreadsheet::Impl& Spreadsheet::Impl::operator=(const Impl& rhs)
{
	//�ڽ��� �����ϴ��� Ȯ���Ѵ�.
	if (this == &rhs)
	{
		return *this;
	}

	//���� �� �¹ٲٱ� (copy and swap)���� ����
	Impl temp(rhs); //��� �۾��� �ӽ� �ν��Ͻ����� ó���Ѵ�.
	swap(temp);     //���ܸ� �߻����� �ʴ� �������θ� ó���Ѵ�.
	return *this;
}

size_t Spreadsheet::Impl::getId() const
{
	return mId;
}
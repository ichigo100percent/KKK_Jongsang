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
	//자신을 대입하는지 확인한다.
	if (this == &rhs)
	{
		return *this;
	}

	//복제 후 맞바꾸기 (copy and swap)패턴 적용
	Impl temp(rhs); //모든 작업을 임시 인스턴스에서 처리한다.
	swap(temp);     //예외를 발생하지 않는 연산으로만 처리한다.
	return *this;
}

size_t Spreadsheet::Impl::getId() const
{
	return mId;
}
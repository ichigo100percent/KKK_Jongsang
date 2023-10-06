#include "SpreadSheet.h"

//p357
SpreadSheet::SpreadSheet(size_t width, size_t height, const SpreadSheetApplication& theApp)
	: mId(sCounter++)
	, mWidth(std::min(width, kMaxWidth))
	, mHeight(std::min(height, kMaxHegiht))
	, mTheApp(theApp)
{
	mCells = new SpreadSheetCell * [mWidth];

	for (size_t i = 0; i < mWidth; i++)
	{
		mCells[i] = new SpreadSheetCell[mHeight];
	}
}

SpreadSheet::SpreadSheet(const SpreadSheet& src)
	:SpreadSheet(src.mWidth, src.mHeight, src.mTheApp)
{
	for (size_t i = 0; i < mWidth; i++)
	{
		for (size_t j = 0; j < mHeight; j++)
		{
			mCells[i][j] = src.mCells[i][j];
		}
	}
}

SpreadSheet::SpreadSheet(SpreadSheet&& src) noexcept
	:SpreadSheet()
{
	swap(*this, src);
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
	return const_cast<SpreadSheetCell&>(std::as_const(*this).getCellAt(x, y));
}

const SpreadSheetCell& SpreadSheet::getCellAt(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}

SpreadSheet& SpreadSheet::operator=(SpreadSheet&& rhs) noexcept
{
	SpreadSheet temp(std::move(rhs));
	swap(*this, temp);

	return *this;
}

size_t SpreadSheet::getId() const
{
	return mId;
}

SpreadSheet& SpreadSheet::operator=(const SpreadSheet& rhs)
{
	//자신을 대입하는지 확인한다.
	if (this == &rhs)
	{
		return *this;
	}

	////기존 메모리를 해제한다.
	//for (size_t i = 0; i < mWidth; i++)
	//{
	//	delete[] mCells[i];
	//}
	//delete[] mCells;
	//mCells = nullptr;

	////메모리를 새로 할당한다.
	//mWidth = rhs.mWidth;
	//mHeight = rhs.mHeight;

	//mCells = new SpreadSheetCell * [mWidth];
	//for (size_t i = 0; i < mWidth; i++)
	//{
	//	mCells[i] = new SpreadSheetCell[mHeight];
	//}

	////데이터를 복제한다
	//for (size_t i = 0; i < mWidth; i++)
	//{
	//	for (rsize_t j = 0; j < mHeight; j++)
	//	{
	//		mCells[i][j] = rhs.mCells[i][j];
	//	}
	//}

	SpreadSheet temp(rhs);		//모든 작업을 임시 인스턴스에서 처리한다.
	swap(*this, temp);			//익셉션을 발생하지 않는 연산으로만 작업을 처리한다.

	return *this;
}

void SpreadSheet::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth || y >= mHeight)
	{
		throw out_of_range("");
	}
}

void SpreadSheet::cleanup() noexcept
{
	for (size_t i = 0; i < mWidth; i++)
	{
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;
	mWidth = mHeight = 0;
}

void SpreadSheet::moveFrom(SpreadSheet& src) noexcept
{
	//객체 데이터 멤버를 이동시킨다.
	mName = std::move(src.mName);

	//이동대상:
	//데이터에 대한 얕은 복제
	mWidth = src.mWidth;
	mHeight = src.mHeight;
	mCells = src.mCells;

	//소유권이 이전됐기 때문에 소스 객체를 리셋한다.
	src.mWidth = 0;
	src.mHeight = 0;
	src.mCells = nullptr;
}

void swap(SpreadSheet& first, SpreadSheet& second) noexcept
{
	using std::swap;

	swap(first.mWidth, second.mWidth);
	swap(first.mHeight, second.mHeight);
	swap(first.mCells, second.mCells);
}



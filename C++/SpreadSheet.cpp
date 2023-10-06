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
	//�ڽ��� �����ϴ��� Ȯ���Ѵ�.
	if (this == &rhs)
	{
		return *this;
	}

	////���� �޸𸮸� �����Ѵ�.
	//for (size_t i = 0; i < mWidth; i++)
	//{
	//	delete[] mCells[i];
	//}
	//delete[] mCells;
	//mCells = nullptr;

	////�޸𸮸� ���� �Ҵ��Ѵ�.
	//mWidth = rhs.mWidth;
	//mHeight = rhs.mHeight;

	//mCells = new SpreadSheetCell * [mWidth];
	//for (size_t i = 0; i < mWidth; i++)
	//{
	//	mCells[i] = new SpreadSheetCell[mHeight];
	//}

	////�����͸� �����Ѵ�
	//for (size_t i = 0; i < mWidth; i++)
	//{
	//	for (rsize_t j = 0; j < mHeight; j++)
	//	{
	//		mCells[i][j] = rhs.mCells[i][j];
	//	}
	//}

	SpreadSheet temp(rhs);		//��� �۾��� �ӽ� �ν��Ͻ����� ó���Ѵ�.
	swap(*this, temp);			//�ͼ����� �߻����� �ʴ� �������θ� �۾��� ó���Ѵ�.

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
	//��ü ������ ����� �̵���Ų��.
	mName = std::move(src.mName);

	//�̵����:
	//�����Ϳ� ���� ���� ����
	mWidth = src.mWidth;
	mHeight = src.mHeight;
	mCells = src.mCells;

	//�������� �����Ʊ� ������ �ҽ� ��ü�� �����Ѵ�.
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



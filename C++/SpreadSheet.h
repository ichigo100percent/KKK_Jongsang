#pragma once
#include <cstddef>
#include <stdexcept>
#include <utility>
#include <vector>
#include <algorithm>
#include "SpreadSheetCell.h"

class SpreadSheetApplication; //포워드 선언

class SpreadSheet
{
public:
	class Cell;

public:
	SpreadSheet() = default;
	SpreadSheet(size_t width, size_t height,
				const SpreadSheetApplication& theApp);
	//SpreadSheet(const SpreadSheet& src) = delete;
	SpreadSheet(const SpreadSheet& src);
	SpreadSheet(SpreadSheet&& src) noexcept; //이동 생성자
	~SpreadSheet();
	void setCellAt(size_t x, size_t y, const SpreadSheetCell& cell);
	SpreadSheetCell& getCellAt(size_t x, size_t y);
	const SpreadSheetCell& getCellAt(size_t x, size_t y) const;

	SpreadSheet& operator=(const SpreadSheet& rhs);
	//SpreadSheet& operator=(const SpreadSheet& rhs) = delete;
	SpreadSheet& operator=(SpreadSheet&& rhs) noexcept; //이동 대입 연산자
	friend void swap(SpreadSheet& first, SpreadSheet& second) noexcept;
	size_t getId() const;

private:
	//bool inRange(size_t value, size_t upper) const;
	void verifyCoordinate(size_t x, size_t y) const;
	void cleanup() noexcept;
	void moveFrom(SpreadSheet& src) noexcept;

	size_t mWidth = 0;
	size_t mHeight = 0;
	SpreadSheetCell** mCells = nullptr;
	std::string mName;
	static inline size_t sCounter = 0;
	size_t mId = 0;

	static const size_t kMaxHegiht = 100;
	static const size_t kMaxWidth = 100;

	const SpreadSheetApplication& mTheApp;
};



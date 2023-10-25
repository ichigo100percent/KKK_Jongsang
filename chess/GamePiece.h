#pragma once

#include <cstddef>

class GamePiece {};

class GameBoard
{
public:
	//제네릭 GameBoard. 사용자가 크기를 지정한다.
	explicit GameBoard(size_t width = kDefaultHeight, size_t height = kDefaultHeight);
	//복제 생성자
	GameBoard(const GameBoard& src);
	virtual ~GameBoard() noexcept;
	//대입연산자
	GameBoard& operator=(const GameBoard& rhs);

	GamePiece& at(size_t x, size_t y);
	const GamePiece& at(size_t x, size_t y) const;

	size_t getWidth() const noexcept { return mWidth; }
	size_t getHeight() const noexcept { return mHeight; }

	static const size_t kDefaultWidth = 100;
	static const size_t kDefaultHeight = 100;

	friend void swap(GameBoard& first, GameBoard& second) noexcept;

private:
	void cleanup() noexcept;
	void verifyCoordinate(size_t x, size_t y) const;

	//게임 말을 동적으로 저장하는 객체
	GamePiece** mCells = nullptr;
	size_t mWidth = 0, mHeight = 0;
};
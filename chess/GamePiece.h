#pragma once

#include <cstddef> 
#include <vector>
#include <memory>

class GamePiece
{
public:
	virtual std::unique_ptr<GamePiece> clone() const = 0;
};

class GameBoard
{
public:
	explicit GameBoard(size_t )

private:
	void verifyCoordinate(size_t x, size_t y) const;

	std::vector<std::vector<std::unique_ptr<GamePiece>>> mCell;
	size_t mWidth, mHeight;
};

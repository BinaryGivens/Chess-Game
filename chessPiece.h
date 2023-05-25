#pragma once
class chessPiece
{
public:
	int moveCount;
	chessPiece(bool);
	virtual bool move(int, int, int, int, chessPiece***) = 0;
	bool getPlayerType() const;
	virtual ~chessPiece();
private:
	bool color;
};
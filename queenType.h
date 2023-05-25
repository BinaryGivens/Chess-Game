#include "chessPiece.h"

class queenType : public chessPiece
{
public:
	queenType(bool);
	bool move(int, int, int, int, chessPiece***);
	~queenType();
};
#include "chessPiece.h"

class knightType : public chessPiece
{
public:
	knightType(bool);
	bool move(int, int, int, int, chessPiece***);
	~knightType();
};
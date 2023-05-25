#include "chessPiece.h"

class pawnType : public chessPiece
{
public:
	pawnType(bool);
	bool move(int, int, int, int, chessPiece***);
	~pawnType();
};
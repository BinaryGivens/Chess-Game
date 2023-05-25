#include "chessPiece.h"

class bishopType : public chessPiece
{
public:
	bishopType(bool);
	bool move(int, int, int, int, chessPiece***);
	~bishopType();
};
#include "chessPiece.h"

class rookType : public chessPiece
{
public:
	rookType(bool);
	bool move(int, int, int, int, chessPiece***);
	~rookType();
};
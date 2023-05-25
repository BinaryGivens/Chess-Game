#include "chessPiece.h"

class kingType : public chessPiece
{
public:
	kingType(bool);
	bool move(int, int, int, int, chessPiece***);
	~kingType();
};
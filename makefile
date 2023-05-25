# Make file for virtual functions assignment

OBJS	= main.o chessPiece.o queenType.o rookType.o bishopType.o knightType.o pawnType.o kingType.o #Board.o
CC		= g++
CCFLAGS	= -Wall -Wextra -pedantic -std=c++11
MAIN_DEPS	= queenType.h rookType.h bishopType.h knightType.h pawnType.h kingType.h #Board.h
LEAGUE_DEPS = team.h

all: main

main: $(OBJS)
	$(CC) $(CCFLAGS) -o chess $(OBJS)

main.o:	main.cpp
	$(CC) $(CCFLAGS) -c main.cpp $(MAIN_DEPS)

chessPiece.o: chessPiece.cpp
	$(CC) $(CCFLAGS) -c chessPiece.cpp

queenType.o: queenType.cpp queenType.h
	$(CC) $(CCFLAGS) -c queenType.cpp

kingType.o: kingType.cpp kingType.h
	$(CC) $(CCFLAGS) -c kingType.cpp

pawnType.o: pawnType.cpp pawnType.h
	$(CC) $(CCFLAGS) -c pawnType.cpp
	
rookType.o: rookType.cpp rookType.h
	$(CC) $(CCFLAGS) -c rookType.cpp

bishopType.o: bishopType.cpp bishopType.h
	$(CC) $(CCFLAGS) -c bishopType.cpp

knightType.o: knightType.cpp knightType.h
	$(CC) $(CCFLAGS) -c knightType.cpp

# Board.o: Board.cpp Board.h
# 	$(CC) $(CCFLAGS) -c Board.cpp      

# -----
# clean by removing object files.

clean:
	rm $(OBJS) chess

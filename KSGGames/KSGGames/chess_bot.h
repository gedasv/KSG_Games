#pragma once

#include "chess_rules.h"
#include <vector>

struct changedMap
{
	Square* realSquare;
	Square changedSquare;
};

struct move
{
	float value;
	int fromTo;
};

void resetBoard(changedMap primeBoard[8][8], changedMap BoardToChange[8][8]);
void basicMove(changedMap Board[8][8], int xFrom, int yFrom, int xTo, int yTo);

float calcPos(changedMap Board[8][8], bool whitesMove);
float nextBot(changedMap Board[8][8], bool whitesMove, int turnsAhead);
float nextEnemy(changedMap Board[8][8], bool whitesMove, int turnsAhead);

bool generateMove(changedMap Board[8][8], bool whitesMove, int &fromTo);
bool legalMove(changedMap Board[8][8], int xFrom, int yFrom, int xTo, int yTo, bool whitesMove);
bool pieceHere(changedMap Board[8][8], int x, int y);
bool teamPieceHere(changedMap Board[8][8], int x, int y, bool whiteTeam);
bool nextBotMove(Square Board[8][8], bool whitesMove, int turnsAhead);
bool ableToMove(Square Board[8][8], bool whitesMove);
#include "chess_bot.h"
#include "chess_rules.h"
#include <vector>

bool nextBotMove(Square Board[8][8], bool whitesMove, int turnsAhead)
{
	changedMap newMap1[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			newMap1[i][j].realSquare = &Board[i][j];
		}
	}

	turnsAhead--;
	int fromTo = 0;
	std::vector<move> Moves;
	while (generateMove(newMap1, whitesMove, fromTo))
	{
		Moves.push_back({ nextEnemy(newMap1, whitesMove, turnsAhead), fromTo });
		//Moves.push_back({ calcPos(newMap1, whitesMove), fromTo });

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				newMap1[i][j].realSquare = &Board[i][j];
			}
		}
	}

	int id;
	float best = -9999;
	for (int i = 0; i < Moves.size(); i++)
	{
		if (Moves[i].value > best)
		{
			id = i;
			best = Moves[i].value;
		}
	}

	if (Moves.size() > 0) {
		int xFrom = Moves[id].fromTo / 1000;
		int yFrom = (Moves[id].fromTo - (xFrom * 1000)) / 100;
		int xTo = (Moves[id].fromTo - (xFrom * 1000) - (yFrom * 100)) / 10;
		int yTo = Moves[id].fromTo - int(Moves[id].fromTo / 10) * 10;

		if (otherMove(Board, xFrom, yFrom, xTo, yTo, whitesMove) || elPass(Board, xFrom, yFrom, xTo, yTo, whitesMove) || castling(Board, xFrom, yFrom, xTo, yTo, whitesMove)) {}
		return true;
	}

	else return false;
}

float calcPos(changedMap Board[8][8], bool whitesMove)
{
	float pos = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::string type;
			std::string team;

			if (Board[i][j].realSquare != NULL)
			{
				Square sqr = *Board[i][j].realSquare;
				type = sqr.Type();
				team = sqr.Team();
			}

			else
			{
				type = Board[i][j].changedSquare.Type();
				team = Board[i][j].changedSquare.Team();
			}

			if (team != "neutral")
			{
				float numb = 0;

				if (type == "King") numb = 1000;
				else if (type == "Queen") numb = 9;
				else if (type == "Rook") numb = 5;
				else if (type == "Bishop") numb = 3.25;
				else if (type == "Knight") numb = 3;
				else if (type == "Pawn" && j == 7) numb = 9;
				else if (type == "Pawn") numb = 1;

				if (type == "King")
				{
					if (i == 0 || i == 7 || j == 0 || j == 7) numb += 0.15F;
					else if (i == 1 || i == 6 || j == 1 || j == 6) numb += 0.05F;
					else if (i == 2 || i == 5 || j == 2 || j == 5) numb += -0.05F;
					else numb += -0.15F;
				}

				else
				{
					if (i == 0 || i == 7 || j == 0 || j == 7) numb += -0.15F;
					else if (i == 1 || i == 6 || j == 1 || j == 6) numb += -0.05F;
					else if (i == 2 || i == 5 || j == 2 || j == 5) numb += 0.05F;
					else numb += 0.15F;
				}

				if ((team == "white" && !whitesMove) || (team == "black" && whitesMove)) numb *= -1;

				pos += numb;
			}
		}
	}

	return pos;
}

bool generateMove(changedMap Board[8][8], bool whitesMove, int &fromTo)
{
	for (int xFrom = fromTo / 1000; xFrom < 8; xFrom++)
	{
		int yFrom;
		if (xFrom == fromTo / 1000) yFrom = (fromTo - (fromTo / 1000) * 1000) / 100;
		else yFrom = 0;
		for (; yFrom < 8; yFrom++)
		{
			Square obj;
			if (Board[xFrom][yFrom].realSquare == NULL) obj = Board[xFrom][yFrom].changedSquare;
			else obj = *Board[xFrom][yFrom].realSquare;

			if ((whitesMove && obj.Team() == "white") || (!whitesMove && obj.Team() == "black"))
			{
				int xTo, yTo;

				if (obj.Type() == "Pawn")
				{
					if (xFrom == (fromTo / 1000) && yFrom == (fromTo - (fromTo / 1000) * 1000) / 100)
					{
						xTo = (fromTo % 100) / 10 + 1;
						yTo = (fromTo % 10);
					}

					else
					{
						xTo = xFrom - 1;
						if (obj.Team() == "black") yTo = yFrom + 1;
						else yTo = yFrom - 1;
					}

					for (; xTo-2 < xFrom && abs(yTo - yFrom) < 2; xTo++)
					{
						if (xTo < 8 && xTo > -1)
						{
							bool enemyTeam = !whitesMove;

							if (xTo == xFrom)
							{
								if (legalMove(Board, xFrom, yFrom, xTo, yTo, whitesMove))
								{
									fromTo = (1000 * xFrom) + (100 * yFrom) + (10 * xTo) + yTo;
									return true;
								}
							}

							else if(legalMove(Board, xFrom, yFrom, xTo, yTo, whitesMove))
							{
								fromTo = (1000 * xFrom) + (100 * yFrom) + (10 * xTo) + yTo;
								return true;
							}
						}
					}

					if (((obj.Team() == "white" && yFrom == 6) || (obj.Team() == "black" && yFrom == 1)) && yTo != 3 && yTo != 4)
					{
						if (obj.Team() == "black") yTo = 3;
						else yTo = 4;

						if (legalMove(Board, xFrom, yFrom, xFrom, yTo, whitesMove))
						{
							fromTo = (1000 * xFrom) + (100 * yFrom) + (10 * xFrom) + yTo;
							return true;
						}
					}
				}

				else
				{
					if (xFrom == (fromTo / 1000) && yFrom == (fromTo - (fromTo / 1000) * 1000) / 100)
					{
						xTo = (fromTo % 100) / 10;
						yTo = (fromTo % 10) + 1;
					}

					else
					{
						xTo = 0;
						yTo = 0;
					}

					for (; xTo < 8; xTo++)
					{
						for (; yTo < 8; yTo++)
						{
							if (legalMove(Board, xFrom, yFrom, xTo, yTo, whitesMove))
							{
								fromTo = (1000 * xFrom) + (100 * yFrom) + (10 * xTo) + yTo;
								return true;
							}
						}
						yTo = 0;
					}
				}
			}
		}
	}

	return false;
}

void resetBoard(changedMap primeBoard[8][8], changedMap BoardToChange[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (primeBoard[i][j].realSquare == NULL) BoardToChange[i][j].realSquare = &primeBoard[i][j].changedSquare;
			else BoardToChange[i][j].realSquare = primeBoard[i][j].realSquare;
		}
	}
}

float nextBot(changedMap Board[8][8], bool whitesMove, int turnsAhead)
{
	std::vector<float> Values;
	int fromTo = 0;
	changedMap changedBoard[8][8]; resetBoard(Board, changedBoard);

	whitesMove = !whitesMove;

	turnsAhead--;

	while (generateMove(changedBoard, whitesMove, fromTo))
	{
		Values.push_back(nextEnemy(changedBoard, whitesMove, turnsAhead));
		resetBoard(Board, changedBoard);
	}

	float best = -9999;
	for (int i = 0; i < Values.size(); i++)
	{
		if (Values[i] > best)
		{
			best = Values[i];
		}
	}

	if (Values.size() == 0) best = 9999;

	return best;
}

float nextEnemy(changedMap Board[8][8], bool whitesMove, int turnsAhead)
{
	std::vector<float> Values;
	changedMap changedBoard[8][8]; resetBoard(Board, changedBoard);
	int fromTo = 0;
	bool move = whitesMove;
	whitesMove = !whitesMove;

	while (generateMove(changedBoard, whitesMove, fromTo))
	{
		if (turnsAhead == 0) Values.push_back(calcPos(changedBoard, move));
		else Values.push_back(nextBot(changedBoard, whitesMove, turnsAhead));
		resetBoard(Board, changedBoard);
	}

	float worst = 9999;
	for (int i = 0; i < Values.size(); i++)
	{
		if (Values[i] < worst)
		{
			worst = Values[i];
		}
	}

	if (Values.size() == 0) worst = -9999;

	return worst;
}

bool legalMove(changedMap Board[8][8], int xFrom, int yFrom, int xTo, int yTo, bool whitesMove)
{
	Square TestBoard[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Board[i][j].realSquare != NULL) TestBoard[i][j] = *Board[i][j].realSquare;
			else TestBoard[i][j] = Board[i][j].changedSquare;
		}
	}

	if (firstCheckUp(TestBoard, xFrom, yFrom, xTo, yTo, whitesMove))
	{
		if ((elPass(TestBoard, xFrom, yFrom, xTo, yTo, whitesMove) || castling(TestBoard, xFrom, yFrom, xTo, yTo, whitesMove) || otherMove(TestBoard, xFrom, yFrom, xTo, yTo, whitesMove)) && !checkAfter(TestBoard, whitesMove))
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					Square test = *Board[i][j].realSquare;
					if (test.Team() != TestBoard[i][j].Team() || test.Type() != TestBoard[i][j].Team() || test.Moved() != TestBoard[i][j].Moved())
					{
						Board[i][j].realSquare = NULL;
						Board[i][j].changedSquare = TestBoard[i][j];
					}
				}
			}

			return true;
		}
	}

	return false;
}

bool pieceHere(changedMap Board[8][8], int x, int y)
{
	Square obj;

	if (Board[x][y].realSquare == NULL) obj = Board[x][y].changedSquare;
	else obj = *Board[x][y].realSquare;

	if (obj.Team() == "neutral" || obj.Team() == "") return false;
	return true;
}

bool teamPieceHere(changedMap Board[8][8], int x, int y, bool whiteTeam)
{
	Square obj;

	if (Board[x][y].realSquare == NULL) obj = Board[x][y].changedSquare;
	else obj = *Board[x][y].realSquare;

	if ((obj.Team() == "white" && whiteTeam) || (obj.Team() == "black" && !whiteTeam)) return true;
	return false;
}

void basicMove(changedMap Board[8][8], int xFrom, int yFrom, int xTo, int yTo)
{
	Square objFrom, objTo;

	if (Board[xFrom][yFrom].realSquare == NULL) objFrom = Board[xFrom][yFrom].changedSquare;
	else objFrom = *Board[xFrom][yFrom].realSquare;

	if (Board[xTo][yTo].realSquare == NULL) objTo = Board[xTo][yTo].changedSquare;
	else objTo = *Board[xTo][yTo].realSquare;

	objTo = objFrom;
	objFrom.SetTeam("neutral");
	objFrom.SetType("");

	Board[xFrom][yFrom].realSquare = NULL;
	Board[xFrom][yFrom].changedSquare = objFrom;

	Board[xTo][yTo].realSquare = NULL;
	Board[xTo][yTo].changedSquare = objTo;
}

bool ableToMove(Square Board[8][8], bool whitesMove)
{
	changedMap newMap1[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			newMap1[i][j].realSquare = &Board[i][j];
		}
	}

	int fromTo = 0;
	if (generateMove(newMap1, whitesMove, fromTo))
	{
		return true;
	}

	return false;
}
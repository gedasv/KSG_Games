#include "chess_rules.h"
#include <string>
#include <fstream>

bool jumpOver(Square Board[8][8], int xFrom, int yFrom, int xTo, int yTo)
{
	if (abs(xTo - xFrom) == abs(yFrom - yTo))
	{
		int diff = abs(xTo - xFrom);

		if ((xFrom > xTo && yFrom > yTo) || (xFrom < xTo && yFrom < yTo)) {

			if (xFrom > xTo)
			{
				xFrom = xTo;
				yFrom = yTo;
			}

			for (int i = 1; i < diff; i++)
			{
				if (Board[xFrom + i][yFrom + i].Team() != "neutral")
				{
					return true;
				}
			}
		}

		else
		{
			if (xFrom > xTo) 
			{
				xFrom = xTo;
				yFrom = yTo;
			}

			for (int i = 1; i < diff; i++)
			{
				if (Board[xFrom + i][yFrom - i].Team() != "neutral")
				{
					return true;
				}
			}
		}

		return false;
	}
	else if (xTo == xFrom || yTo == yFrom)
	{
		if (xTo == xFrom)
		{
			if (yTo > yFrom)
			{
				int help = yTo;
				yTo = yFrom;
				yFrom = help;
			}
			for (int i = 1; i < abs(yFrom - yTo); i++)
			{
				if (Board[xTo][yTo + i].Team() != "neutral") return true;
			}
		}

		else
		{
			if (xTo > xFrom)
			{
				int help = xTo;
				xTo = xFrom;
				xFrom = help;
			}
			for (int i = 1; i < abs(xFrom - xTo); i++)
			{
				if (Board[xTo+i][yTo].Team() != "neutral") return true;
			}
		}

		return false;
	}

	return true;
}
bool checkAfter(Square Board[8][8],  bool whiteCheck)
{
	std::string team;
	bool found = false;
	bool whitesMove = whiteCheck;
	int xTo, yTo;

	if (whiteCheck) team = "white";
	else team = "black";

	for (int i = 0; i < 8 && !found; i++)
	{
		for (int j = 0; j < 8 && !found; j++)
		{
			if (Board[i][j].Team() != team && Board[i][j].Team() != "neutral" && Board[i][j].Type() == "King")
			{
				xTo = i;
				yTo = j;
				found = true;
			}
		}
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Board[i][j].Team() == team)
			{
				if (firstCheckUp(Board, i, j, xTo, yTo, whitesMove))
				{
					if (otherMove(Board, i, j, xTo, yTo, whitesMove) || elPass(Board, i, j, xTo, yTo, whitesMove))
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}
bool firstCheckUp(Square Board[8][8], int xFrom, int yFrom, int xTo, int yTo, bool whitesMove)
{
	if (Board[xFrom][yFrom].Team() != Board[xTo][yTo].Team() &&
		((whitesMove && Board[xFrom][yFrom].Team() == "white") || (!whitesMove && Board[xFrom][yFrom].Team() == "black")))
	{
		return true;
	}

	return false;
}
bool otherMove(Square Board[8][8], int xFrom, int yFrom, int xTo, int yTo, bool &whitesMove)
{
	if (Board[xFrom][yFrom].Type() == "Rook" || Board[xFrom][yFrom].Type() == "Queen")
	{
		if (!jumpOver(Board, xFrom, yFrom, xTo, yTo))
		{
			if (xFrom == xTo || yFrom == yTo)
			{
				kirtimas(Board[xFrom][yFrom], Board[xTo][yTo], whitesMove);
				Board[xTo][yTo].Move();
				return true;
			}
		}
	}
	if (Board[xFrom][yFrom].Type() == "Bishop" || Board[xFrom][yFrom].Type() == "Queen")
	{
		if (!jumpOver(Board, xFrom, yFrom, xTo, yTo))
		{
			if (abs(xFrom - xTo) == abs(yFrom - yTo))
			{
				kirtimas(Board[xFrom][yFrom], Board[xTo][yTo], whitesMove);
				return true;
			}
		}
	}
	else if (Board[xFrom][yFrom].Type() == "Pawn")
	{
		if (!jumpOver(Board, xFrom, yFrom, xTo, yTo))
		{
			if (xFrom == xTo)
			{
				if (Board[xTo][yTo].Team() == "neutral")
				{
					if (Board[xFrom][yFrom].Team() == "white")
					{
						if (yFrom == 6)
						{
							if (yFrom - yTo == 1 || yFrom - yTo == 2)
							{
								kirtimas(Board[xFrom][yFrom], Board[xTo][yTo], whitesMove);
								if ((yFrom - yTo) == 2) { Board[xTo][yTo].Move(); }
								return true;
							}
						}
						else if (yFrom - yTo == 1)
						{
							kirtimas(Board[xFrom][yFrom], Board[xTo][yTo], whitesMove);
							return true;
						}
					}

					else
					{
						if (yFrom == 1)
						{
							if (yTo - yFrom == 1 || yTo - yFrom == 2)
							{
								kirtimas(Board[xFrom][yFrom], Board[xTo][yTo], whitesMove);
								if ((yTo - yFrom) == 2) { Board[xTo][yTo].Move(); }
								return true;
							}
						}
						else if (yTo - yFrom == 1)
						{
							kirtimas(Board[xFrom][yFrom], Board[xTo][yTo], whitesMove);
							return true;
						}
					}
				}
			}
			else if (abs(xFrom - xTo) == 1 && abs(yFrom - yTo) == 1)
			{
				if (Board[xFrom][yFrom].Team() == "white")
				{
					if (yFrom > yTo && Board[xTo][yTo].Team() == "black")
					{
						kirtimas(Board[xFrom][yFrom], Board[xTo][yTo], whitesMove);
						return true;
					}
				}
				else
				{
					if (yFrom < yTo && Board[xTo][yTo].Team() == "white")
					{
						kirtimas(Board[xFrom][yFrom], Board[xTo][yTo], whitesMove);
						return true;
					}
				}
			}
		}
	}
	else if (Board[xFrom][yFrom].Type() == "King")
	{
		if (abs(xFrom - xTo) <= 1 && abs(yFrom - yTo) <= 1)
		{
			kirtimas(Board[xFrom][yFrom], Board[xTo][yTo], whitesMove);
			Board[xTo][yTo].Move();
			return true;
		}
	}
	else if (Board[xFrom][yFrom].Type() == "Knight")
	{
		if ((abs(xFrom - xTo) == 2 && abs(yFrom - yTo) == 1) || (abs(xFrom - xTo) == 1 && abs(yFrom - yTo) == 2))
		{
			kirtimas(Board[xFrom][yFrom], Board[xTo][yTo], whitesMove);
			return true;
		}
	}

	return false;
}
bool elPass(Square Board[8][8], int xFrom, int yFrom, int xTo, int yTo, bool &whitesMove)
{
	if (Board[xTo][yTo].Team() == "neutral" && Board[xFrom][yFrom].Type() == "Pawn" && abs(xTo - xFrom) == 1 && abs(yTo - yFrom) == 1)
	{
		if (Board[xFrom][yFrom].Team() == "white")
		{
			if (Board[xTo][yTo + 1].Type() == "Pawn" && Board[xTo][yTo + 1].Team() == "black" && Board[xTo][yTo + 1].Moved())
			{
				kirtimas(Board[xFrom][yFrom], Board[xTo][yTo], whitesMove);
				Board[xTo][yTo + 1].SetTeam("neutral");
				return true;
			}
		}

		else
		{
			if (Board[xTo][yTo - 1].Type() == "Pawn" && Board[xTo][yTo - 1].Team() == "white" && Board[xTo][yTo - 1].Moved())
			{
				kirtimas(Board[xFrom][yFrom], Board[xTo][yTo], whitesMove);
				Board[xTo][yTo - 1].SetTeam("neutral");
				return true;
			}
		}
	}

	return false;
}
bool castling(Square Board[8][8], int xFrom, int yFrom, int xTo, int yTo, bool &whitesMove)
{
	if (Board[xFrom][yFrom].Type() == "King" && !Board[xFrom][yFrom].Moved() && yFrom == yTo && abs(xFrom - xTo) == 2)
	{
		int rookX;
		if (xFrom < xTo) rookX = 7;
		else rookX = 0;

		if (Board[rookX][yFrom].Team() != "neutral" && Board[rookX][yFrom].Type() == "Rook" && !Board[rookX][yFrom].Moved() && !jumpOver(Board, rookX, yFrom, xTo, yFrom) && !checkAfter(Board, !whitesMove))
		{
			Square Test_Board[8][8]; copyArr(Board, Test_Board);
			Test_Board[(xTo + xFrom) / 2][yFrom] = Test_Board[xFrom][yFrom];

			Test_Board[xFrom][yFrom].SetTeam("neutral");
			Test_Board[xFrom][yFrom].SetType("");
			Test_Board[xFrom][yFrom].ResetMove();

			if (!checkAfter(Test_Board, !whitesMove))
			{

				Test_Board[xTo][yTo] = Test_Board[(xTo + xFrom) / 2][yTo];

				Test_Board[(xTo + xFrom) / 2][yTo].SetTeam("neutral");
				Test_Board[(xTo + xFrom) / 2][yTo].SetType("");
				Test_Board[(xTo + xFrom) / 2][yTo].ResetMove();

				if (!checkAfter(Test_Board, !whitesMove))
				{
					Test_Board[xTo][yTo].Move();

					int newX;
					if (rookX > xTo) newX = xTo-1;
					else newX = xTo+1;

					Test_Board[newX][yTo] = Test_Board[rookX][yFrom];
					Test_Board[newX][yTo].Move();

					Test_Board[rookX][yFrom].SetTeam("neutral");
					Test_Board[rookX][yFrom].SetType("");
					Test_Board[rookX][yFrom].ResetMove();

					copyArr(Test_Board, Board);
					whitesMove = !whitesMove;
					
					return true;
				}
			}
		}
	}

	return false;
}
bool endPawn(Square Board[8][8], bool whitesMove)
{
	int lineY;

	if (whitesMove) lineY = 7;
	else lineY = 0;

	for (int i = 0; i < 8; i++)
	{
		if (Board[i][lineY].Type() == "Pawn")
		{
			return true;
		}
	}

	return false;
}

void clearMoved(Square Board[8][8], bool whitesMove)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (((Board[i][j].Team() == "black" && !whitesMove) || (Board[i][j].Team() == "white" && whitesMove)) && Board[i][j].Type() == "Pawn") Board[i][j].ResetMove();
		}
	}
}
void copyArr(Square Board[8][8], Square A_Board[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			A_Board[i][j] = Board[i][j];
		}
	}
}
void kirtimas(Square &A, Square &B, bool &whitesMove)
{
	B = A;

	A.SetTeam("neutral");
	A.ResetMove();
	A.SetType("");

	whitesMove = !whitesMove;
}

std::string changeEndPawn(Square Board[8][8], std::string name)
{
	std::string place;
	for (int i = 0; i < 8; i += 7)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Board[j][i].Type() == "Pawn")
			{
				Board[j][i].SetType(name);
				Board[j][i].Move();

				place = std::to_string(j) + std::to_string(i);

				return place;
			}
		}
	}

	return "";
}
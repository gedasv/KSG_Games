 #pragma once

#include <string>
#include <fstream>

public class Square
{
private:
	std::string type, team;
	bool moved = false;

public:
	void SetType(std::string setTo) { type = setTo; };
	void SetTeam(std::string teamName) { team = teamName; };
	void Move() { moved = true; };
	void ResetMove() { moved = false; };

	std::string Team() { return team; };
	std::string Type() { return type; };
	bool Moved() { return moved; };
};

bool jumpOver(Square Board[8][8], int xFrom, int yFrom, int xTo, int yTo);
bool firstCheckUp(Square Board[8][8], int xFrom, int yFrom, int xTo, int yTo, bool whitesMove);
bool otherMove(Square Board[8][8], int xFrom, int yFrom, int xTo, int yTo, bool &whitesMove);
bool elPass(Square Board[8][8], int xFrom, int yFrom, int xTo, int yTo, bool &whitesMove);
bool castling(Square Board[8][8], int xFrom, int yFrom, int xTo, int yTo, bool &whitesMove);
bool checkAfter(Square Board[8][8], bool whiteCheck);
bool endPawn(Square Board[8][8], bool whitesMove);

void copyArr(Square Board[8][8], Square A_Board[8][8]);
//void printMap(Square Board[8][8]);
void clearMoved(Square Board[8][8], bool whitesMove);
void kirtimas(Square &A, Square &B, bool &whitesMove);

std::string changeEndPawn(Square Board[8][8], std::string name);
#include "Game1.h"

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

class chess_piece
{
private:
	std::string name;
public:
	std::string Name() { return name; };
	void setName(std::string a) { name = a; };
};

#endif // !CHESS_PIECE_H

void Board_Init(chess_piece arr[][8])
{
	arr[0][0].setName("black_rook_l");
	arr[0][1].setName("black_knight_l");
	arr[0][2].setName("black_bishop_l");
	arr[0][3].setName("black_queen");
	arr[0][4].setName("black_king");
	arr[0][5].setName("black_bishop_r");
	arr[0][6].setName("black_knight_r");
	arr[0][7].setName("black_rook_r");

	std::string name = "_pawn_";
	for (int i = 0; i < 8; i++)
	{
		arr[1][i].setName("black" + name + std::to_string(i));
	}
	for (int i = 0; i < 8; i++)
	{
		arr[6][i].setName("white" + name + std::to_string(i));
	}

	arr[7][0].setName("white_rook_l");
	arr[7][1].setName("white_knight_l");
	arr[7][2].setName("white_bishop_l");
	arr[7][3].setName("white_queen");
	arr[7][4].setName("white_king");
	arr[7][5].setName("white_bishop_r");
	arr[7][6].setName("white_knight_r");
	arr[7][7].setName("white_rook_r");
}
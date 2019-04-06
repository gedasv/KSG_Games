#pragma once

#include <string>
#include <fstream>

public class Tile
{
private:
	bool hasBomb = false;
	int number = 0;
	int x = 0, y = 0;

public:
	bool hasFlag = false;
	bool isOpen = false;


	Tile(int x1, int y1) {
		x = x1;
		y = y1;
	}

};
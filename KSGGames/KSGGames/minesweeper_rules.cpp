#include "minesweeper_rules.h"
#include "Minesweeper.h"

using namespace System;

void Tile::reset() {
	bomb = false;
	flag = false;
	opened = false;
}
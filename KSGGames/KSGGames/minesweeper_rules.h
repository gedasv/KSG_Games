#pragma once

#include <string>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::Drawing;

public class Tile
{
private:
	bool bomb = false;
	bool opened = false;
	bool flag = false;

public:
	bool hasBomb() { return bomb; }
	bool isOpen() { return opened; }
	bool hasFlag() { return flag; }

	void setBomb(bool set) { bomb = set; }
	void setOpen(bool set) { opened = set; }
	void setFlag(bool set) { flag = set; }
};
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class piece
{
private :
	string name;
public:
	string Name() { return name; };
	string setName(string a) { name = a; };
};

/*void asdasdafasfsa(piece &arr[8][8])
{
	arr[0][0].setName("black_rook_l");
	arr[0][1].setName("black_knight_l");
	arr[0][2].setName("black_bishop_l");
	arr[0][3].setName("black_queen");
	arr[0][4].setName("black_king");
	arr[0][5].setName("black_bishop_r");
	arr[0][6].setName("black_knight_r");
	arr[0][7].setName("black_rook_r");

}*/
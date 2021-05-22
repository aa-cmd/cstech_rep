#include "config.h"
#include "chess.h"

using namespace std;

string coord[8][8];

map<char, int> chesspieces{
    {'p', 1},
    {'a', 3},
    {'f', 3},
    {'k', 5},
    {'v', 9},
    {'s', 100},
};

void subtractFromSum(char c, float *sumb, float *sums, int val)
{
    switch (c)
    {
    case 'b':
        *sums -= float(val) / 2;
        break;
    case 's':
        *sumb -= float(val) / 2;
        break;
    }
}

bool matchSituation(int x, int y, float *sumb, float *sums, string str)
{
    string tmp = "";

    bool isClash = false;
    if (!(x > 7 || x < 0 || y > 7 || y < 0))
    {
        tmp = coord[x][y];
        if (tmp[0] != 'x')
        {
            isClash = true;
            if (str[1] != tmp[1])
            {
                switch (tmp[0])
                {
                case 'p':
                    subtractFromSum(str[1], sumb, sums, 1);
                    break;
                case 'a':
                    subtractFromSum(str[1], sumb, sums, 3);
                    break;
                case 'f':
                    subtractFromSum(str[1], sumb, sums, 3);
                    break;
                case 'k':
                    subtractFromSum(str[1], sumb, sums, 5);
                    break;
                case 'v':
                    subtractFromSum(str[1], sumb, sums, 9);
                    break;
                case 's':
                    subtractFromSum(str[1], sumb, sums, 100);
                    break;
                }
            }
        }
    }
    return isClash;
}

map<pair<int, char>, string> chessCoord;

void Piece::setxPos(int x)
{
    xPos = x;
}

void Piece::setyPos(int y)
{
    yPos = y;
}

Piece::Piece(int x, int y)
{
    xPos = x;
    yPos = y;
}

// Piece::~Piece(){}

void KnightPiece::posMov(string *str, float *sumb, float *sums, int x_pos, int y_pos)
{

    xPos = x_pos;
    yPos = y_pos;

    matchSituation(xPos + 2, yPos + 1, sumb, sums, *str);
    matchSituation(xPos + 2, yPos - 1, sumb, sums, *str);
    matchSituation(xPos - 2, yPos + 1, sumb, sums, *str);
    matchSituation(xPos - 2, yPos - 1, sumb, sums, *str);
    matchSituation(xPos + 1, yPos + 2, sumb, sums, *str);
    matchSituation(xPos - 1, yPos + 2, sumb, sums, *str);
    matchSituation(xPos + 1, yPos - 2, sumb, sums, *str);
    matchSituation(xPos - 1, yPos - 2, sumb, sums, *str);
}

KnightPiece::KnightPiece()
{
    cout << "Constructor for KnightPiece" << endl;
}

KnightPiece::~KnightPiece() {}

void KnightPiece::setxPos(int x)
{
    Piece::setxPos(x);
}

void KnightPiece::setyPos(int y)
{
    Piece::setyPos(y);
}

BishopPiece::BishopPiece()
{
    cout << "Constructor for BishopPiece" << endl;
}
BishopPiece::~BishopPiece() {}

void BishopPiece::posMov(string *str, float *sumb, float *sums, int x_pos, int y_pos)
{
    xPos = x_pos;
    yPos = y_pos;

    for (int i = 1; i < 8; i++)
    {
        if (matchSituation(xPos + i, yPos + i, sumb, sums, *str))
            break;
    }

    for (int i = 1; i < 8; i++)
    {
        if (matchSituation(xPos - i, yPos + i, sumb, sums, *str))
            break;
    }

    for (int i = 1; i < 8; i++)
    {
        if (matchSituation(xPos - i, yPos - i, sumb, sums, *str))
            break;
    }

    for (int i = 1; i < 8; i++)
    {
        if (matchSituation(xPos + i, yPos - i, sumb, sums, *str))
            break;
    }
}

void BishopPiece::setxPos(int x)
{
    Piece::setxPos(x);
}

void BishopPiece::setyPos(int y)
{
    Piece::setyPos(y);
}

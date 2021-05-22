#include "chess.h"

using namespace std;

map<char, int> chesspieces{
    {'p', 1},
    {'a', 3},
    {'f', 3},
    {'k', 5},
    {'v', 9},
    {'s', 100},
};



void subtractFromSum(char c, int *sumb, int *sums, int val)
{
    switch (c)
    {
    case 'b':
        *sumb -= val / 2;
        break;
    case 's':
        *sums -= val / 2;
        break;
    }
}

bool matchSituation(int x, int y, int *sumb, int *sums, string str)
{

    bool isClash = false;
    if (!(x > 7 || x < 0 || y > 7 || y < 0))
    {
        if (str[0] != 'x')
        {
            switch (str[0])
            {
            case 'p':
                subtractFromSum(str[1], sumb, sums, 1);
                isClash = true;
                break;
            case 'a':
                subtractFromSum(str[1], sumb, sums, 3);
                isClash = true;
                break;
            case 'f':
                subtractFromSum(str[1], sumb, sums, 3);
                isClash = true;
                break;
            case 'k':
                subtractFromSum(str[1], sumb, sums, 5);
                isClash = true;
                break;
            case 'v':
                subtractFromSum(str[1], sumb, sums, 9);
                isClash = true;
                break;
            case 's':
                subtractFromSum(str[1], sumb, sums, 100);
                isClash = true;
                break;
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


void KnightPiece::posMov(string *str, int *sumb, int *sums)
{

    matchSituation(xPos + 2, yPos + 1, sumb, sums, *str);
    matchSituation(xPos + 2, yPos - 1, sumb, sums, *str);
    matchSituation(xPos - 2, yPos + 1, sumb, sums, *str);
    matchSituation(xPos - 2, yPos - 1, sumb, sums, *str);
    matchSituation(yPos + 2, xPos + 1, sumb, sums, *str);
    matchSituation(yPos + 2, xPos - 1, sumb, sums, *str);
    matchSituation(yPos - 2, xPos + 1, sumb, sums, *str);
    matchSituation(yPos - 2, xPos - 1, sumb, sums, *str);
}


KnightPiece::KnightPiece()
{
    cout<<"Constructor for KnightPiece"<<endl;
}

KnightPiece::~KnightPiece(){}

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
     cout<<"Constructor for BishopPiece"<<endl;
}
BishopPiece::~BishopPiece(){}

void BishopPiece::posMov(string *str, int *sumb, int *sums)
{
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



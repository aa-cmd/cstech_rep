#include "config.h"
#include "chess.h"

using namespace std;

map <char, int> chesspieces {
    {'p', 1},
    {'a', 3},
    {'f', 3},
    {'k', 5},
    {'v', 9},
    {'s', 100},
};



map<pair<int, char>, string> chessCoord;
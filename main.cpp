
#include "config.h"
#include "chess.h"

using namespace std;

stringstream ss;
int count, sumb, sums;
string str;

void summationPieces(char c, int *sumb, int *sums, int val)
{
    switch (c)
    {
    case 'b':
        *sumb += val;
        break;
    case 's':
        *sums += val;
        break;
    }
}

int main(int argc, char *argv[])
{
    // string fn = argv[1];

    // cout << fn << endl;
    ifstream f("board1.txt");

    if (f.is_open() && f.good())
    {
        cout << "File is open!\nContains:\n";
        string row = "";
        while (getline(f, row))
        {
            cout << row << endl;
            ss << row;
            while (ss >> str)
            {
                if (str[0] != 'x')
                {
                    switch (str[0])
                    {
                    case 'p':
                        summationPieces(str[1], &sumb, &sums, 1);
                        break;
                    case 'a':
                        summationPieces(str[1], &sumb, &sums, 3);
                        break;
                    case 'f':
                        summationPieces(str[1], &sumb, &sums, 3);
                        break;
                    case 'k':
                        summationPieces(str[1], &sumb, &sums, 5);
                        break;
                    case 'v':
                        summationPieces(str[1], &sumb, &sums, 9);
                        break;
                    case 's':
                        summationPieces(str[1], &sumb, &sums, 100);
                        break;
                    }
                }
            }
            ss.clear();
        }
    }
    else
    {
        cout << "Failed to open file...";
    }
}
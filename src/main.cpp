
#include "config.h"
#include "chess.h"

using namespace std;

stringstream ss;
float sumb, sums;
int row_cnt = 0, col_cnt = 0;
string coord[8][8];
string str, calc_str;

static void summationPieces(char c, float *sumb, float *sums, int val)
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
    KnightPiece Knight;
    BishopPiece Bishop;

    string fn = "board2.txt";//argv[1];

    cout << fn << endl;
    ifstream f(fn);

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
                coord[row_cnt][col_cnt] = str;
                

                if (str[0] != 'x')
                {
                    switch (str[0])
                    {
                    case 'p':
                        summationPieces(str[1], &sumb, &sums, 1);
                        break;
                    case 'a':
                        summationPieces(str[1], &sumb, &sums, 3);
                        Knight.posMov(&coord[row_cnt][col_cnt], &sumb, &sums);
                        break;
                    case 'f':
                        summationPieces(str[1], &sumb, &sums, 3);
                        Bishop.posMov(&coord[row_cnt][col_cnt], &sumb, &sums);
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

                col_cnt++;
            }
            ss.clear();
            row_cnt++;
            col_cnt = 0;
        }
    }
    else
    {
        cout << "Failed to open file..."<<endl;;
    }

    for (int i = 0; i < row_cnt; i++)
    {
        for (int j = 0; j < col_cnt; j++)
        {
            calc_str = coord[i][j];

            if (calc_str[0] != 'x')
            {
                switch (calc_str[0])
                {
                case 'a':
                    Knight.posMov(&coord[row_cnt][col_cnt], &sumb, &sums);
                    break;
                case 'f':
                    Bishop.posMov(&coord[row_cnt][col_cnt], &sumb, &sums);
                    break;
                }
            }
        }
    }
    printf("White's total point: %3.1f\n", sumb);
    printf("Black's total point: %3.1f\n", sums);
}
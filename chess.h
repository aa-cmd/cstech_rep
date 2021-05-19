

#ifndef CHESS_H_
#define CHESS_H_

class Piece
{
public:
    Piece() {}
    ~Piece() {}
    virtual void move();
};

// extern map<char, int> chesspieces;

class KnightPiece : public Piece
{
public:
    KnightPiece() {}
    ~KnightPiece() {}

    void move()
    {
    }
};




#endif
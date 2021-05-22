#ifndef CHESS_H
#define CHESS_H


class Piece
{

public:
    int xPos, yPos;
    Piece(){}
    Piece(int x, int y);
    ~Piece(){}
    virtual void posMov(std::string *, float *, float *) = 0;
    virtual void setxPos(int) = 0;
    virtual void setyPos(int) = 0;
};



class KnightPiece : public Piece
{
public:
    KnightPiece();
    ~KnightPiece();

    void posMov(std::string *, float *, float *);
    void setxPos(int);
    void setyPos(int);
    
};

class BishopPiece : public Piece
{
public:
    BishopPiece();
    ~BishopPiece();

    void posMov(std::string *, float *, float *);
    void setxPos(int);
    void setyPos(int);
};

#endif //CHESS_H
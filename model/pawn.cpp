#include "pawn.h"

Pawn::Pawn(bool color, QPoint &coordinate, QObject * parent): APiece(color, coordinate, parent)
{
    QString iconPath = QString(":/pieces/").append((color)?("white"):("black")).append("/pawn");
    icon = new QSvgRenderer(iconPath, this);
}

Pawn::~Pawn(void)
{

}

bool Pawn::isMoveValid(Chessboard *chessboard, QPoint & target)
{
    return false;
}

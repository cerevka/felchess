#include "rook.h"

Rook::Rook(bool color, QPoint &coordinate, QObject * parent): APiece(color, coordinate, parent)
{
    QString iconPath = QString(":/pieces/").append((color)?("white"):("black")).append("/rook");
    icon = new QSvgRenderer(iconPath, this);
}

Rook::~Rook(void)
{

}

bool Rook::isMoveValid(Chessboard *chessboard, QPoint & target)
{
    return false;
}

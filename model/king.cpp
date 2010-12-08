#include "king.h"

King::King(bool color, QPoint &coordinate, QObject * parent): APiece(color, coordinate, parent)
{
    QString iconPath = QString(":/pieces/").append((color)?("white"):("black")).append("/king");
    icon = new QSvgRenderer(iconPath, this);
}

King::~King(void)
{

}

bool King::isMoveValid(Chessboard *chessboard, QPoint & target)
{
    return false;
}

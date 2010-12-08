#include "knight.h"

Knight::Knight(bool color, QPoint &coordinate, QObject * parent): APiece(color, coordinate, parent)
{
    QString iconPath = QString(":/pieces/").append((color)?("white"):("black")).append("/knight");
    icon = new QSvgRenderer(iconPath, this);
}

Knight::~Knight(void)
{

}

bool Knight::isMoveValid(Chessboard *chessboard, QPoint & target)
{
    return false;
}

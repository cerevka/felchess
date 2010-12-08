#include "queen.h"

Queen::Queen(bool color, QPoint &coordinate, QObject * parent): APiece(color, coordinate, parent)
{
    QString iconPath = QString(":/pieces/").append((color)?("white"):("black")).append("/queen");
    icon = new QSvgRenderer(iconPath, this);
}

Queen::~Queen(void)
{

}

bool Queen::isMoveValid(Chessboard *chessboard, QPoint & target)
{
    return false;
}

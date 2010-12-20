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
    bool allow = false;

    // Podminka overujici validitu tahu dle pravidel.
    if ((abs(coordinate.x() - target.x()) == 1 && abs(coordinate.y() - target.y()) == 2) ||
        (abs(coordinate.x() - target.x()) == 2 && abs(coordinate.y() - target.y()) == 1))
    {
        allow = true;
    }

    return allow;
}

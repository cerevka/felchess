#include "king.h"

King::King(bool color, QPoint coordinate, QObject * parent): APiece(color, coordinate, parent)
{
    QString iconPath = QString(":/pieces/").append((color)?("white"):("black")).append("/king");
    icon = new QSvgRenderer(iconPath, this);
}

King::~King(void)
{

}

bool King::isMoveValid(Chessboard *chessboard, QPoint & target)
{
    Q_UNUSED(chessboard);
    bool allow = false;

    // Podminka overujici validitu tahu podle pravidel.
    if (abs(coordinate.x() - target.x()) < 2 && abs(coordinate.y() - target.y()) < 2)
    {
        allow = true;
    }
    return allow;
}

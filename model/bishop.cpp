#include "bishop.h"

Bishop::Bishop(bool color, QPoint &coordinate, QObject * parent): APiece(color, coordinate, parent)
{
    QString iconPath = QString(":/pieces/").append((color)?("white"):("black")).append("/bishop");
    icon = new QSvgRenderer(iconPath, this);
}

Bishop::~Bishop(void)
{

}

bool Bishop::isMoveValid(Chessboard *chessboard, QPoint &target)
{
    return false;
}

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
    bool allow = false;

    if (color == true)
    {
        // Bila figura.
        if (chessboard->isEmpty(target))
        {
            // Cilove policko je prazdne.
            if (target == QPoint (coordinate.x(), coordinate.y() - 1))
            {
                allow = true;
            }
            // Z prvni rady muze o dve.
            if (coordinate.y() == 6 && target == QPoint (coordinate.x(), coordinate.y() - 2))
            {
                if (chessboard->isEmpty(QPoint (coordinate.x(), coordinate.y() - 1)))
                {
                    allow = true;
                }
            }
        }
        else {
            // Cilove policko je plne.
            if ((target == QPoint(coordinate.x() - 1, coordinate.y() -1)) ||
                (target == QPoint(coordinate.x() + 1, coordinate.y() -1)))
            {
                allow = true;
            }
        }
    }
    else
    {
        // Cerna figura.
        if (chessboard->isEmpty(target))
        {
            // Cilove pole je prazdne.
            if (target == QPoint (coordinate.x(), coordinate.y() + 1))
            {
                allow = true;
            }

            // Z prvni rady muze o dve.
            if (coordinate.y() == 1 && target == QPoint (coordinate.x(), coordinate.y() + 2))
            {
                if (chessboard->isEmpty(QPoint (coordinate.x(), coordinate.y() + 1)))
                {
                    allow = true;
                }
            }
        }
        else
        {
            // Cilove pole je plne.
            if ((target == QPoint (coordinate.x() - 1, coordinate.y() + 1)) ||
                (target == QPoint (coordinate.x() + 1, coordinate.y() + 1)))
            {
                allow = true;
            }
        }
    }

    return allow;
}

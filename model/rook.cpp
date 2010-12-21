#include "rook.h"

Rook::Rook(bool color, QPoint coordinate, QObject * parent): APiece(color, coordinate, parent)
{
    QString iconPath = QString(":/pieces/").append((color)?("white"):("black")).append("/rook");
    icon = new QSvgRenderer(iconPath, this);
}

Rook::~Rook(void)
{

}

bool Rook::isMoveValid(Chessboard *chessboard, QPoint & target)
{
    bool allow = false;
    bool block = false;

    // Podminka kontrolujici validitu tahu dle pravidel.
    if (coordinate.x() == target.x() || coordinate.y() == target.y()) {

        // Je treba overit, zda v ceste nestoji prekazky.

        // Kontroluje vodorovny smer.
        if (coordinate.x() == target.x())
        {
            if (coordinate.y() < target.y())
            {
                for (int i = coordinate.y() + 1; i < target.y(); i++)
                {
                    if (chessboard->isEmpty(QPoint (coordinate.x(), i)) == false)
                    {
                        block = true;
                        break;
                    }
                }
            }
            else
            {
                for (int i = coordinate.y() - 1; i > target.y(); i--)
                {
                    if (chessboard->isEmpty(QPoint (coordinate.x(), i)) == false)
                    {
                        block = true;
                        break;
                    }
                }
            }
        }

        // Kontroluje svisly smer.
        if (coordinate.y() == target.y())
        {
            if (coordinate.x() < target.x())
            {
                for (int i = coordinate.x() + 1; i < target.x(); i++)
                {
                    if (chessboard->isEmpty(QPoint (i, coordinate.y())) == false)
                    {
                        block = true;
                        break;
                    }
                }

            }
            else
            {
                for (int i = coordinate.x() - 1; i > target.x(); i--)
                {
                    if (chessboard->isEmpty(QPoint (i, coordinate.y())) == false)
                    {
                        block = true;
                        break;
                    }
                }

            }
        }


        if (block == false)
        {
            allow = true;
        }

    }

    return allow;
}

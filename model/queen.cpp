#include "queen.h"

Queen::Queen(bool color, QPoint coordinate, QObject * parent): APiece(color, coordinate, parent)
{
    QString iconPath = QString(":/pieces/").append((color)?("white"):("black")).append("/queen");
    icon = new QSvgRenderer(iconPath, this);
}

Queen::~Queen(void)
{

}

bool Queen::isMoveValid(Chessboard *chessboard, QPoint & target)
{
    bool allow = false;
    bool block = false;

    // Podminka overujici validitu tahu podle pravidel.
    if ( ( ( coordinate.x() == target.x() ) || ( coordinate.y() == target.y() ) ) ||
         ( abs( coordinate.x() - target.x() ) == abs( coordinate.y() - target.y() ) ) )
    {

        // Dale je treba overit, zda nic nestoji v ceste.

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

        // Konstroluje smer sikmo vpravo dolu.
        if (coordinate.x() < target.x() && coordinate.y() < target.y())
        {
            for (int i = 1; i < (target.x() - coordinate.x()); i++)
            {
                if (chessboard->isEmpty(QPoint (coordinate.x() + i, coordinate.y() + 1)) == false)
                {
                    block = true;
                    break;
                }
            }

        }

        // Kontroluje smer sikmo vlevo nahoru.
        if (coordinate.x() > target.x() && coordinate.y() > target.y())
        {
            for (int i = 1; i < (coordinate.x() - target.x()); i++)
            {
                if (chessboard->isEmpty(QPoint (coordinate.x() - i, coordinate.y() - i)) == false)
                {
                    block = true;
                    break;
                }
            }
        }

        // Kontroluje smer sikmo vpravo nahoru.
        if (coordinate.x() < target.x() && coordinate.y() > target.y())
        {
            for (int i = 1; i < (target.x() - coordinate.x()); i++)
            {
                if (chessboard->isEmpty(QPoint (coordinate.x() + i, coordinate.y() - i)) == false)
                {
                    block = true;
                    break;
                }
            }
        }

        // Konstroluje smer sikmo vlevo dolu.
        if (coordinate.x() > target.x() && coordinate.y() < target.y())
        {
            for (int i = 1; i < (coordinate.x() - target.x()); i++)
            {
                if (chessboard->isEmpty(QPoint (coordinate.x() - i, coordinate.y() + i)) == false)
                {
                    block = true;
                    break;
                }
            }
        }

        // Nebyla-li nalezena zadna prekazka, tah je validni.
        if (block == false)
        {
            allow = true;
        }

    }

    return allow;
}

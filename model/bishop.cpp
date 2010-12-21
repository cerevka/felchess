#include "bishop.h"

Bishop::Bishop(bool color, QPoint coordinate, QObject * parent): APiece(color, coordinate, parent)
{
    QString iconPath = QString(":/pieces/").append((color)?("white"):("black")).append("/bishop");
    icon = new QSvgRenderer(iconPath, this);
}

Bishop::~Bishop(void)
{

}

bool Bishop::isMoveValid(Chessboard *chessboard, QPoint &target)
{
    bool allow = false;
    bool block = false;

    // Podminka overujici validitu tahu podle pravidel.
    if (abs(coordinate.x() - target.x()) == abs(coordinate.y() - target.y()))
    {
        // Dale je treba overit, zda figurce nic nestoji v ceste.

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

        // Nebyla-li nalezena zadna prekazka, je tah validni.
        if (block == false)
        {
            allow = true;
        }

    }


    return allow;
}

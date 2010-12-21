#ifndef KNIGHT_H
#define KNIGHT_H

#include "apiece.h"
#include "chessboard.h"

class Chessboard;

/**
  * Jezdec.
  */
class Knight : public APiece
{
public:

    /**
      * Vytvori jezdce.
      * @param color Barva jezdce. True = bila, false = cerna.
      * @param coordniate Pozice jezdce.
      * @param * parent Ukazatel na rodice.
      */
    explicit Knight(bool color, QPoint coordinate, QObject * parent = 0);

    /**
      * Znici jezdce.
      */
    virtual ~Knight(void);

protected:

    /**
      * Doimplementovana abstraktni metoda predka. Rozhodne, zda je
      * tah validni.
      * @param * chessboard Sachovnice, na ktere se ma tah provest.
      * @param target Souradnice, na kterou se ma figura presunout.
      * @return True = tah je validni. False = tah neni validni.
      */
    virtual bool isMoveValid(Chessboard * chessboard, QPoint & target);
};

#endif // KNIGHT_H

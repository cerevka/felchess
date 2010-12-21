#ifndef KING_H
#define KING_H

#include "apiece.h"
#include "chessboard.h"

class Chessboard;

/**
  * Kral.
  */
class King : public APiece
{
public:

    /**
      * Vytvori krale.
      * @param color Barva krale. True = bila, false = cerna.
      * @param coordniate Pozice krale.
      * @param * parent Ukazatel na rodice.
      */
    explicit King(bool color, QPoint coordinate, QObject * parent = 0);

    /**
      * Znici krale.
      */
    virtual ~King(void);

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

#endif // KING_H

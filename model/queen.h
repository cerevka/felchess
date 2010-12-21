#ifndef QUEEN_H
#define QUEEN_H

#include "apiece.h"
#include "chessboard.h"

class Chessboard;

/**
  * Kralovna.
  */
class Queen : public APiece
{
public:

    /**
      * Vytvori kralovnu.
      * @param color Barva kralovny. True = bila, false = cerna.
      * @param coordniate Pozice kralovny.
      * @param * parent Ukazatel na rodice.
      */
    explicit Queen(bool color, QPoint coordinate, QObject * parent = 0);

    /**
      * Znici kralovnu.
      */
    virtual ~Queen(void);

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

#endif // QUEEN_H

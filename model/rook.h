#ifndef ROOK_H
#define ROOK_H

#include "apiece.h"
#include "chessboard.h"

class Chessboard;

/**
  * Vez.
  */
class Rook : public APiece
{
public:

    /**
      * Vytvori vez.
      * @param color Barva veze. True = bila, false = cerna.
      * @param coordniate Pozice veze.
      * @param * parent Ukazatel na rodice.
      */
    explicit Rook(bool color, QPoint coordinate, QObject * parent = 0);

    /**
      * Znici vez.
      */
    virtual ~Rook(void);

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

#endif // ROOK_H

#ifndef PAWN_H
#define PAWN_H

#include "apiece.h"
#include "chessboard.h"
#include <QDebug>

class Chessboard;

/**
  * Pesak.
  */
class Pawn : public APiece
{
public:

    /**
      * Vytvori pesaka.
      * @param color Barva pesaka. True = bila, false = cerna.
      * @param coordniate Pozice pesaka.
      * @param * parent Ukazatel na rodice.
      */
    explicit Pawn(bool color, QPoint coordinate, QObject * parent = 0);

    /**
      * Znici pesaka.
      */
    virtual ~Pawn(void);

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

#endif // PAWN_H

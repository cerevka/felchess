#ifndef BISHOP_H
#define BISHOP_H

#include "apiece.h"

/**
  * Strelec.
  */
class Bishop : public APiece
{
public:

    /**
      * Vytvori strelce.
      * @param color Barva strelce. True = bila, false = cerna.
      * @param coordniate Pozice strelce.
      * @param * parent Ukazatel na rodice.
      */
    explicit Bishop(bool color, QPoint & coordinate, QObject * parent = 0);

    /**
      * Znici strelce.
      */
    virtual ~Bishop(void);

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

#endif // BISHOP_H

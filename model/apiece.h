#ifndef APIECE_H
#define APIECE_H

#include <QObject>
#include <QPoint>
#include <QtSvg/QSvgRenderer>
#include <cmath>


#include "chessboard.h"

/**
  * Abstraktní figurka. Obsahuje implementaci zakladnich figurek,
  * ovsem ma i ciste virtualni metody, ktere je treba doimplementovat
  * v jednotlivych figurkach.
  */
class APiece: public QObject
{
    Q_OBJECT

public:

    /**
      * Kontruktor figury.
      * @param color Barva figurky. True = bila, false = cerna.
      * @param coordinate Souradnice, na kterych je figurka na sachovnici.
      * @param * parent Ukazatel na rodice.
      */
    explicit APiece(bool color, QPoint coordinate, QObject * parent = 0);

    /**
      * Desktruktor figury.
      */
    virtual ~APiece(void);

    /**
      * Rozhodne, zda je tah validni.
      * @param * chessboard Sachovnice, na ktere se ma tah provest.
      * @param target Souradnice, na kterou se ma figura presunout.
      * @return True = tah je validni. False = tah neni validni.
      */
    virtual bool isMoveValid(Chessboard * chessboard, QPoint & target) = 0;

    /**
      * Vrati nactenou SVG ikonu k vykresleni.
      * @return SVG ikona pripravena k vykresleni.
      */
    virtual QSvgRenderer * getIcon(void);

    /**
      * Vrati souradnice pole, na kterem je figura.
      * @return Souřadnice figury.
      */
    virtual QPoint & getCoordinate();


protected:

    /**
      * Barva figurky. True = bila, false = cerna.
      */
    bool color;

    /**
      * Pozice figury.
      */
    QPoint coordinate;

    /**
      * Ikona figury.
      */
    QSvgRenderer * icon;
};

#endif // APIECE_H

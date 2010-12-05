#ifndef APIECE_H
#define APIECE_H

#include <QObject>
#include <QPoint>
#include <QtSvg/QSvgRenderer>

class APiece: public QObject
{
    Q_OBJECT

public:


    /**
      * Vytvoreni figurky.
      */
    explicit APiece(bool color, QPoint coordinate, QObject * parent = 0);

    /**
      * Desktruktor figury.
      */
    virtual ~APiece(void);

    /**
      * Rozhodne, zda je tah validni.
      * @param chessboard Sachovnice, na ktere se ma ta provest.
      * @param target Souradnice, na ktere se ma figura presunout.
      */
    virtual bool isMoveValid(void) = 0;

    /**
      * Vrati nactou SVG ikonu k vykresleni.
      * @return SVG pripravene k vykresleni.
      */
    virtual QSvgRenderer * getIcon(void);

    /**
      * Vrati souradnice pole, na kterem je figura.
      */
    virtual QPoint & getCoordinate();


protected:

    /**
      * Barva figurky: true = bila, false = cerna.
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

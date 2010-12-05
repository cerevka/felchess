#ifndef PAINTER2D_H
#define PAINTER2D_H

#include "apainter.h"

class Painter2D : public APainter
{
public:

    /**
      * Vytvoreni kreslitka pro 2D zobrazeni.
      * @param *widget Widget na kresleni.
      */
    explicit Painter2D(QGLWidget * widget);

    /**
      * Zniceni kreslitka.
      */
    virtual ~Painter2D();


    /**
      * Kresleni trojuhlenika.
      */
    virtual void paintTriangle();


    /**
      * Kresleni 2D sachovnice.
      */
    virtual void drawChessboard();

    /**
      * Vykresleni SVG figurky.
      */
    virtual void drawPiece(QPainter * painter, APiece * piece);

};

#endif // PAINTER2D_H

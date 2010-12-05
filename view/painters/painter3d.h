#ifndef PAINTER3D_H
#define PAINTER3D_H

#include "apainter.h"

class Painter3D : public APainter
{
public:
    explicit Painter3D(QGLWidget * widget);

    /**
      * Kresleni trojuhlenika.
      */
    virtual void paintTriangle();

    virtual void drawChessboard();

    /**
      * Vykresleni figurky.
      */
    virtual void drawPiece(QPainter * painter, APiece * piece);
};

#endif // PAINTER3D_H

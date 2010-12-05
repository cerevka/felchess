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
};

#endif // PAINTER3D_H

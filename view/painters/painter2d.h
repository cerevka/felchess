#ifndef PAINTER2D_H
#define PAINTER2D_H

#include "apainter.h"

class Painter2D : public APainter
{
public:
    Painter2D(QGLWidget * widget);

    /**
      * Kresleni trojuhlenika.
      */
    void paintTriangle();
};

#endif // PAINTER2D_H

#ifndef PAINTER3D_H
#define PAINTER3D_H

#include "apainter.h"

class Painter3D : public APainter
{
public:
    Painter3D(QGLWidget * widget);

    /**
      * Kresleni trojuhlenika.
      */
    void paintTriangle();
};

#endif // PAINTER3D_H

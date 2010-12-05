#ifndef PAINTER_H
#define PAINTER_H

#include "apainter.h"
#include "painter2d.h"
#include "painter3d.h"

/**
  * Strategy trida pro vyber konkretni implementace kreslitka.
  */
class Painter : public APainter
{
public:

    enum Mode {MODE_2D, MODE_3D};

    /**
      * Vytvoreni kreslitka. Rozhoduje o volbe implementace.
      */
    Painter(QGLWidget * widget, Mode mode);

    /**
      * Zniceni kreslitka a konkretni instance kreslitka.
      */
    ~Painter();

    /**
      * Kresleni trojuhlenika.
      */
    void paintTriangle();

private:

    /**
      * Ukazatel na konkretni kreslitko.
      */
    APainter * painter;
};

#endif // PAINTER_H

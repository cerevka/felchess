#ifndef PAINTER_H
#define PAINTER_H

#include <QPainter>

/**
  * Kreslitko na platno.
  */
class Painter : public QPainter
{    
public:

    /**
      * Vytvoreni kreslitka.
      */
    explicit Painter(void);

    /**
      * Zniceni kreslitka.
      */
    virtual ~Painter(void);

    /**
      * Nakresleni sachovnice.
      */
    void drawChessboard(void);

};

#endif // PAINTER_H

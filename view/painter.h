#ifndef PAINTER_H
#define PAINTER_H

#include <QPainter>
#include <QDebug>
#include "../model/apiece.h"

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

    /**
      * Vykresleni figurky.
      * @param piece Ukazatel na figurku.
      */
    void drawPiece(APiece * piece);
};


#endif // PAINTER_H

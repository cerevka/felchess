#ifndef APAINTER_H
#define APAINTER_H

#include <QObject>
#include <QtOpenGL>

#include "../../model/apiece.h"

/**
  * Abstraktni trida specifikujici rozhrani vsech kreslitek.
  */
class APainter : public QObject
{
    Q_OBJECT

public:

    /**
      * Vsechna kreslitka musi volat kontruktor predka a predat
      * mu odkaz na kreslici widget.
      */
    explicit APainter(QGLWidget * widget) {
        this->widget = widget;
    }

    /**
      * Kresleni trojuhlenika.
      */
    virtual void paintTriangle() = 0;

    /**
      * Vykresleni sachovnice.
      */
    virtual void drawChessboard() = 0;

    /**
      * Vykresleni figurky.
      */
    virtual void drawPiece(QPainter * painter, APiece * piece) = 0;

protected:

    /**
      * Ukazatel na kreslici widget.
      */
    QGLWidget * widget;

};

#endif // APAINTER_H

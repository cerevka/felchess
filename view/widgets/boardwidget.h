#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include <QtOpenGL/QGLWidget>
#include <QtOpenGL/qgl.h>
#include <QColor>
#include <QtSvg/QtSvg>

#include <QDebug>

#include "../painters/painter.h"
#include "../../model/apiece.h"
#include "../../model/king.h"

class King;

/**
  * Widget po vykreslovani sachovnice za pomoci OpenGL.
  */
class BoardWidget : public QGLWidget
{
    Q_OBJECT
public:

    /**
      * Vytvoreni noveho OpenGL widgetu pro herni plochu.
      * @param *parent Ukazatel na rodice/vlastnika.
      */
    explicit BoardWidget(QWidget *parent = 0);

    /**
      * Zniceni OpenGL widgetu.
      */
    virtual ~BoardWidget(void);

protected:

    /**
      * Prestineni funkce inicializace OpenGL.
      */
    virtual void initializeGL(void);

    /**
      * Prestineni funkce zmeny velikosti.
      * @param width Nova sirka widgetu.
      * @param height Nova vyska widgetu.
      */
    virtual void resizeGL(int width, int height);

    /**
      * Prestineni funkce na kresleni na widget.
      */
    virtual void paintGL(void);

    /**
      * Zpracovani kliku mysi do hraci plochy.
      */
    virtual void mousePressEvent(QMouseEvent * event);

private:
    /**
      * Ukazatel na kreslitko.
      */
    Painter * glPainter;

private slots:

    /**
      * Prelozi widget.
      */
    void retranslateSlot(void);



};

#endif // BOARDWIDGET_H

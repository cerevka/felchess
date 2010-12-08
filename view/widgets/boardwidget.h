#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include <QColor>
#include <QtSvg/QtSvg>

#include <QDebug>

#include "../../model/apiece.h"
#include "../../model/king.h"

class King;

/**
  * Widget po vykreslovani sachovnice za pomoci OpenGL.
  */
class BoardWidget : public QWidget
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
      * Prestineni funkce zmeny velikosti.
      * @param width Nova sirka widgetu.
      * @param height Nova vyska widgetu.
      */
    virtual void resize(int width, int height);

    /**
      * Prestineni funkce na kresleni na widget.
      */
    virtual void paint(void);

    /**
      * Zpracovani kliku mysi do hraci plochy.
      */
    virtual void mousePressEvent(QMouseEvent * event);

private:

private slots:

    /**
      * Prelozi widget.
      */
    void retranslateSlot(void);



};

#endif // BOARDWIDGET_H

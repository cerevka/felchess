#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QtGui>
#include <QtSvg/QtSvg>
#include <QPoint>

#include "../painter.h"
#include "../../model/apiece.h"

/**
  * Widget po vykreslovani hraci plochy..
  */
class BoardWidget : public QWidget
{
    Q_OBJECT
public:

    /**
      * Vytvoreni noveho widgetu pro herni plochu.
      * @param *parent Ukazatel na rodice/vlastnika.
      */
    explicit BoardWidget(QWidget * parent = 0);

    /**
      * Zniceni OpenGL widgetu.
      */
    virtual ~BoardWidget(void);

protected:


    /**
      * Prestineni funkce zmeny velikosti.
      * @param event Udalost o zmene velikosti.
      */
    virtual void resizeEvent(QResizeEvent * event);

    /**
      * Prestineni funkce na kresleni na widget.
      * @param event Udalost o prekresleni.
      */
    virtual void paintEvent(QPaintEvent * event);

    /**
      * Zpracovani kliku mysi do hraci plochy.
      * @param event Udalost o kliku mysi.
      */
    virtual void mousePressEvent(QMouseEvent * event);

signals:

    void boardClickedSignal(QPoint point);

private:

    /**
      * Kreslitko na platno.
      */
    Painter painter;

    /**
      * Kolekce figurek, ktere ma vykreslovat na sachovnici.
      */
    QList<APiece *> pieceList;

    /**
      * Vykresli vsechny figurky v kolekci.
      */
    void drawAllPieces(void);


private slots:

    /**
      * Prelozi widget.
      */
    void retranslateSlot(void);

    /**
      * Prida figurku do kolekce mezi vykreslovane.
      */
    void addPieceSlot(APiece * piece);

    void updateGUISlot(void);

    void removePieceSlot(APiece * piece);



};

#endif // BOARDWIDGET_H

#ifndef CENTERWIDGET_H
#define CENTERWIDGET_H

#include <QtGui>
#include <QWidget>

#include "view/widgets/boardwidget.h"
#include "view/widgets/infowidget.h"
#include "view/widgets/chatwidget.h"



/**
  * Centralni widget tvorici vnitrek hlavniho okna.
  */
class CenterWidget : public QWidget
{
    Q_OBJECT
public:

    /**
      * Vytvoreni centralniho widgetu.
      * @param *parent Ukazatel na rodice/vlastnika.
      */
    explicit CenterWidget(QWidget *parent = 0);

    /**
      * Zniceni centralniho widgetu.
      */
    virtual ~CenterWidget(void);

private:

    /**
      * Hlavni layout pro centralni widget.
      */
    QHBoxLayout * layout;

    /**
      * Layout pro pravy sloupec.
      */
    QVBoxLayout * rightLayout;

    /**
      * Widget s hraci plochou.
      */
    BoardWidget * boardWidget;

    /**
      * Widget s informace o hre.
      */
    InfoWidget * infoWidget;

    /**
      * Chatovaci widget.
      */
    ChatWidget * chatWidget;

private slots:

    /**
      * Prelozi widget.
      */
    void retranslateSlot(void);
};

#endif // CENTERWIDGET_H

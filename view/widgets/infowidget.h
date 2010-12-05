#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QTabWidget>


/**
  * Hlavni informacni widget se zalozkami s informacemi
  * o prubehu hry.
  */
class InfoWidget : public QTabWidget
{
    Q_OBJECT
public:

    /**
      * Vytvori informacni widget.
      * @param *parent Ukazatel na rodice/vlastnika.
      */
    explicit InfoWidget(QWidget *parent = 0);

    /**
      * Znici informacni widget.
      */
    virtual ~InfoWidget();

private:

    /**
      * Zalozka s historii tahu.
      */
    QWidget * historyTab;

    /**
      * Zalozka se scorem.
      */
    QWidget * scoreTab;

    /**
      * Zalozka s vyrazenymi figurami.
      */
    QWidget * figureTab;

private slots:

    /**
      * Prelozi widget.
      */
    void retranslateSlot(void);

};

#endif // INFOWIDGET_H

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

private slots:

    /**
      * Prelozi widget.
      */
    void retranslateSlot(void);

};

#endif // INFOWIDGET_H

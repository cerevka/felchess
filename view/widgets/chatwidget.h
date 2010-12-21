#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QtGui>

/**
  * Chatovaci widget majici na starosti komunikaci mezi hraci,
  * pripadne vypis systemovych hlaseni.
  */
class ChatWidget : public QWidget
{
    Q_OBJECT
public:

    /**
      * Vytvoreni chatovaciho widgetu.
      * @param *parent Ukazatel na rodice/vlastnika.
      */
    explicit ChatWidget(QWidget *parent = 0);

    /**
      * Zniceni chatovaciho widgetu.
      */
    virtual ~ChatWidget(void);

private:

    /**
      * Hlavni layout widgetu.
      */
    QVBoxLayout * layout;

    /**
      * Pole pro prijate zpravy.
      */
    QTextEdit * chatView;

    /**
      * Pole pro psani zprav.
      */
    QLineEdit * messageEdit;

    /**
      * Tlacitko pro odeslani zpravu.
      */
    QPushButton * sendButton;

    /**
      * Layout pro ovladani widgetu.
      */
    QHBoxLayout * buttonLayout;

private slots:

    /**
      * Prelozi widget.
      */
    void retranslateSlot(void);

};

#endif // CHATWIDGET_H

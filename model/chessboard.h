#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QObject>

/**
  * Sachovnice. Slouzi hlavne jako vyhledavaci mapa pro
  * vyhodnocovani tahu.
  */
class Chessboard : QObject
{
    Q_OBJECT

public:

    /**
      * Vytvori sachovnici.
      * @param parent Ukazatel na rodice.
      */
    explicit Chessboard(QObject * parent = 0);

    /**
      * Znici sachovnici.
      */
    virtual ~Chessboard(void);
};

#endif // CHESSBOARD_H

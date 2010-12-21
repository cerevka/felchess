#ifndef CHESSBOARD_H
#define CHESSBOARD_H



#include <QObject>
#include <QPoint>

#include "apiece.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "pawn.h"
#include "rook.h"

class King;
class Queen;
class Bishop;
class Knight;
class Pawn;
class Rook;


/**
  * Sachovnice. Slouzi hlavne jako vyhledavaci mapa pro
  * vyhodnocovani tahu.
  */
class Chessboard : public QObject
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

    bool isEmpty(QPoint target);

    void addPiece(APiece * piece);

    bool isMoveValid(QPoint source, QPoint target);

    void movePiece(QPoint source, QPoint target);

    APiece * getPiece(QPoint coordinates);

private:

    /**
      *
      */
    APiece * board[8][8];

signals:

    void removePieceSignal(APiece * piece);

};

#endif // CHESSBOARD_H

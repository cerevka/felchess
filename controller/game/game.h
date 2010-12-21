#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QDebug>

#include "model/chessboard.h"
#include "../network/server.h"
#include "../network/client.h"
#include "../network/network.h"
#include "../network/networkinterface.h"


/**
  * Samotna logika cele hry. Singleton.
  */
class Game : public QObject
{
    Q_OBJECT

public:

    /**
      * Vrati instanci hry.
      */
    static Game * getInstance();

    /**
      * Znici hru.
      */
    virtual ~Game(void);

    /**
      * Vrati, zda se jiz hrae.
      */
    bool getStarted(void) {
        return started;
    }

    void startGame(void) {
        qDebug() << "Game started.";
        started = true;
    }

private:

    /**
      * Uchovava ukazatel na hru.
      */
    static Game * game;

    /**
      * Priznak, zda je rozehrana hra.
      */
    bool started;

    /**
      * Priznak, ktery hrac hraje.
      * Server = white = true;
      * Client = black = false;
      */
    bool player;

    bool playingPlayer;

    /**
      * Ukazatel na objekt starajici se o sachovnici.
      */
    Chessboard * chessboard;

    /**
      * Soukromy konstruktor hry - instanci lze ziskat pouze pres
      * getInstance().
      */
    explicit Game(QObject * parent = 0);


    /**
      * Prida figuru do hry.
      */
    void addPiece(APiece * piece);

    /**
      * Umisti figury na sachovnici. Rozmisteni figur rozhodne
      * podle toho, jaky je hrac.
      */
    void placePieces(void);

    APiece * selectedPiece;

signals:

    /**
      * Signal nesouci informace o pridavane figure.
      * @param piece* Vkladana figura.
      */
    void addPieceSignal(APiece * piece);

    /**
      * Vyzve gui k prekresleni hrani plochy.
      */
    void updateGUISignal(void);

    void movePieceSignal(QPoint source, QPoint target);

    void removePieceSignal(APiece * piece);

public slots:

    /**
      * Slot zahajujici hru.
      */
    bool startGameSlot(bool _player, QString _ip, QString _port);

    void boardClickedSlog(QPoint point);

    void moveSlot(QPoint source, QPoint target);

    void removePieceSlot(APiece * piece);


};

#endif // GAME_H

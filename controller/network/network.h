#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include "networkinterface.h"
#include "../game/game.h"

class Game;


/**
  * Zapouzdreni serveru ci klienta pro jednotny pristup
  * k síťovému spojení.
  */
class Network : public QThread
{

    Q_OBJECT

public:

    /**
      * Vytvoreni nove sitove komunikace v novem threadu.
      * @param _network* Objekt pro sitovou komunikaci.
      * @param parent* Rodic objektu.
      */
    explicit Network(NetworkInterface * _network, QObject * parent = 0);

    /**
      * Zniceni sitoveho rozhrani.
      */
    virtual ~Network();

    /**
      * Definuje cinnost vlakna - spusti smycku udalosti.
      */
    void run(void);

private:

    /**
      * Instance objektu pro komunikaci.
      */
    NetworkInterface * network;

signals:

    /**
      * Signal s novou zpravou.
      */
    void newPacketReceivedSignal(QByteArray _packet);

    void movePieceSignal(QPoint source, QPoint target);

public slots:

    /**
      * Odesle paket.
      */
    void sendPacketSlot(QPoint source, QPoint target);

    void newPacketRecievedSlot(QByteArray packet);



};

#endif // NETWORK_H

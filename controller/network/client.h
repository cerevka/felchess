#ifndef CLIENT_H
#define CLIENT_H

#include "networkinterface.h"
#include "../game/game.h"

class Game;


class Client : public NetworkInterface
{
    Q_OBJECT
public:

    /**
      * Vytvoreni klienta.
      */
    explicit Client(QString _address, int _port, QObject *parent = 0);

    /**
      * Zniceni klienta.
      */
    virtual ~Client();

    virtual void sendPacket(QByteArray _packet);

private slots:

    void connected(void);





};

#endif // CLIENT_H

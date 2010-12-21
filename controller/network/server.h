#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkProxy>

#include "networkinterface.h"

#include "../game/game.h"



class Server : public NetworkInterface
{
    Q_OBJECT

public:

    Server(int _port, QObject * parent = 0);

    virtual ~Server();

    virtual void sendPacket(QByteArray _package);

private:

    /**
      * Poslouchajici socket.
      */
    QTcpServer * serverSocket;

signals:

    /**
      * Signal nesouci prave odeslany packet.
      */
    void sentPacketSignal(QByteArray _packet);

private slots:

    /**
      * Zpracuje pripojeni klienta.
      */
    void newClientSlot(void);




};

#endif // SERVER_H

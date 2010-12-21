#include "server.h"

Server::Server(int _port, QObject *parent) : NetworkInterface(parent)
{
    // Vytvori se serverovy socket.
    serverSocket = new QTcpServer(this);

    // Zakaze se proxy.
    serverSocket->setProxy(QNetworkProxy::NoProxy);

    // Nastavi se maximalni pocet klientu - staci jeden.
    serverSocket->setMaxPendingConnections(1);

    bool listening = serverSocket->listen(QHostAddress::Any, _port);

    if (listening)
    {
        qDebug() << "Server is ready on port: " << _port;
    }

    // Napoji se signaly serveru.

    // Obsluha noveho klienta.
    connect(serverSocket, SIGNAL(newConnection()), this, SLOT(newClientSlot()));


}

Server::~Server()
{
    socket->close();
    serverSocket->close();
}

void Server::newClientSlot()
{
    if (Game::getInstance()->getStarted() == false)
    {
        // Klient se prijde jen tehdy, pokud jeste hra nezacala.
        socket = serverSocket->nextPendingConnection();
        qDebug() << "New client was connected.";
        Game::getInstance()->startGame();
    } else {
        // Pokud se jiz hraje, klient se odmitne.
        socket = serverSocket->nextPendingConnection();
        socket->disconnectFromHost();
        qDebug() << "Client was refused.";
    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(incomingPacket()));

}

void Server::sendPacket(QByteArray _packet)
{
    socket->write(_packet);
    //emit sentPacketSignal(_packet);
}


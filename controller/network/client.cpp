#include "client.h"

Client::Client(QString _address, int _port, QObject *parent) :  NetworkInterface(parent)
{
    socket = new QTcpSocket(this);

    socket->connectToHost(_address, _port);

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));

}

Client::~Client()
{

}

void Client::sendPacket(QByteArray _packet)
{
    socket->write(_packet);
}

void Client::connected()
{
    Game::getInstance()->startGame();
    connect(socket, SIGNAL(readyRead()), this, SLOT(incomingPacket()));
}

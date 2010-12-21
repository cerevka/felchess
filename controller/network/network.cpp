#include "network.h"

Network::Network(NetworkInterface * _network, QObject * parent) : QThread(parent)
{
    network = _network;

    connect(_network, SIGNAL(newPacketRecievedSignal(QByteArray)), this, SLOT(newPacketRecievedSlot(QByteArray)));
    connect(this, SIGNAL(movePieceSignal(QPoint,QPoint)), Game::getInstance(), SLOT(moveSlot(QPoint,QPoint)));
    connect(Game::getInstance(), SIGNAL(movePieceSignal(QPoint,QPoint)), this, SLOT(sendPacketSlot(QPoint, QPoint)));
}

Network::~Network()
{
    delete network;
}

void Network::run(void)
{
    exec();
}

void Network::sendPacketSlot(QPoint source, QPoint target)
{
    QByteArray packet;

    packet.append(source.x());
    packet.append(source.y());
    packet.append(target.x());
    packet.append(target.y());

    network->sendPacket(packet);
}

void Network::newPacketRecievedSlot(QByteArray packet)
{
    int x1 = packet[0];
    int y1 = packet[1];
    int x2 = packet[2];
    int y2 = packet[3];

    emit movePieceSignal(QPoint (x1, y1), QPoint (x2, y2));
}




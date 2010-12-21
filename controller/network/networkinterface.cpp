#include "networkinterface.h"

NetworkInterface::NetworkInterface(QObject *parent) :
    QObject(parent)
{

}

NetworkInterface::~NetworkInterface()
{

}

void NetworkInterface::incomingPacket()
{
    QByteArray packet = socket->readAll();
    emit newPacketRecievedSignal(packet);

}

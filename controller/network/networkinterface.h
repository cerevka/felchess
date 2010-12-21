#ifndef NETWORKINTERFACE_H
#define NETWORKINTERFACE_H

#include <QObject>
#include <QTcpSocket>


// Definuje spolecne rozhrani pro server a klienta.
class NetworkInterface : public QObject
{
    Q_OBJECT
public:
    explicit NetworkInterface(QObject *parent = 0);
    virtual ~NetworkInterface();

    /**
      * Odeslani dat v poli znaku.
      * @param packet Odesilane pole znaku.
      */
    virtual void sendPacket(QByteArray _package) = 0;

protected:
    /**
      * Klientsky socket.
      */
    QTcpSocket * socket;

signals:

    void newPacketRecievedSignal(QByteArray packet);

private slots:

    void incomingPacket(void);

};

#endif // NETWORKINTERFACE_H

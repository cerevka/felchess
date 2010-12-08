#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>

/**
  * Zapouzdreni serveru ci klienta pro jednotny pristup
  * k síťovému spojení.
  */
class Network : QObject
{
    Q_OBJECT

public:
    explicit Network(QObject * parent = 0);
    virtual ~Network();
};

#endif // NETWORK_H

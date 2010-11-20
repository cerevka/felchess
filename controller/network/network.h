#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>

class Network : QObject
{
    Q_OBJECT

public:
    Network(QObject * parent = 0);
    virtual ~Network();
};

#endif // NETWORK_H

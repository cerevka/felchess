#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QObject>

class Chessboard : QObject
{
    Q_OBJECT

public:
    explicit Chessboard(QObject * parent = 0);

    virtual ~Chessboard();
};

#endif // CHESSBOARD_H

#ifndef GAME_H
#define GAME_H

#include <QObject>

class Game : public QObject
{
    Q_OBJECT

public:
    explicit Game(QObject * parent = 0);
    virtual ~Game();
};

#endif // GAME_H

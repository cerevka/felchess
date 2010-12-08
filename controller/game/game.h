#ifndef GAME_H
#define GAME_H

#include <QObject>


/**
  * Samotna logika cele hry.
  */
class Game : public QObject
{
    Q_OBJECT

public:
    explicit Game(QObject * parent = 0);
    virtual ~Game(void);
};

#endif // GAME_H

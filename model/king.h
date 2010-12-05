#ifndef KING_H
#define KING_H

#include "apiece.h"

class King : public APiece
{
public:
    explicit King(bool color, QPoint & coordinate, QObject * parent = 0);

    virtual ~King();

protected:
    virtual bool isMoveValid();
};

#endif // KING_H

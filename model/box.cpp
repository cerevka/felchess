#include "box.h"

Box::Box(QObject *parent) :
    QObject(parent)
{
    flag = Box::NONE;
    piece = NULL;
}

Box::~Box()
{

}

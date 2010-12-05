#include "apiece.h"

APiece::APiece(bool color, QPoint coordinate, QObject * parent): QObject(parent)
{
    this->color = color;
    this->coordinate = coordinate;
}

APiece::~APiece()
{

}

QSvgRenderer * APiece::getIcon(void)
{
    return icon;
}

QPoint & APiece::getCoordinate()
{
    return coordinate;
}

#include "apiece.h"

APiece::APiece(bool color, QPoint coordinate, QObject * parent): QObject(parent)
{
    this->color = color;
    this->coordinate = coordinate;
}

APiece::~APiece(void)
{

}

QSvgRenderer * APiece::getIcon(void)
{
    return icon;
}

QPoint & APiece::getCoordinate(void)
{
    return coordinate;
}

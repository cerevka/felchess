#include "painter.h"

Painter::Painter(QGLWidget *widget, Mode mode) : APainter(widget)
{
    if (mode == Painter::MODE_2D)
    {
        painter = new Painter2D(widget);
    } else
    {
        painter = new Painter3D(widget);
    }

}

Painter::~Painter()
{
    delete painter;
}

void Painter::paintTriangle()
{
    painter->paintTriangle();
}

void Painter::drawChessboard()
{
    painter->drawChessboard();
}

void Painter::drawPiece(QPainter * painter, APiece * piece)
{
    this->painter->drawPiece(painter, piece);
}

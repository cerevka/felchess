#include "painter3d.h"

Painter3D::Painter3D(QGLWidget * widget): APainter(widget)
{
}

void Painter3D::paintTriangle()
{
    glBegin(GL_TRIANGLES);
    widget->qglColor(QColor::fromRgb(0, 255, 0));
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(0.0, 1.0, -1.0);
    glEnd();

}

void Painter3D::drawChessboard()
{

}

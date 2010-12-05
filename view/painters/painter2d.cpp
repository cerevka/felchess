#include "painter2d.h"

Painter2D::Painter2D(QGLWidget * widget): APainter(widget)
{
}

void Painter2D::paintTriangle()
{
    glBegin(GL_TRIANGLES);
    widget->qglColor(QColor::fromRgb(255, 0, 0));
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(0.0, 1.0, -1.0);
    glEnd();

}

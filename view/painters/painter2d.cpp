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

void Painter2D::drawChessboard()
{
    // Barva policka - true = bila, false = cerna.
    bool color = true;

    // Presun souradnic do leveho horniho rohu hodne dozadu.
    glTranslatef(-1.0, 0.75, 0.999);

    // Posun po radcich.
    for (int y = 0; y < 8; y++) {
        // Posun po sloupcich.
        for (int x = 0; x < 8; x++) {
            if (color) {
                // Nastavi se bila barva.
               widget->qglColor(QColor::fromRgb(255, 255, 255));
           } else {
               // Nastavi se cerna barva.
               widget->qglColor(QColor::fromRgb(70, 70, 70));
           }
           // Nakresledni policka.
           glRectf(0.0, 0.0, 0.25, 0.25);
           // Posun po ose x.
           glTranslatef(0.25, 0.0, 0.0);
           // Negace barvy pro dalsi policko.
           color = !color;
        }
        // Negace barvy pro dalsi radek.
        color = !color;
        // Posun na zacatek dalsiho radku.
        glTranslatef(-2.0, -0.25, 0.0);
    }
}

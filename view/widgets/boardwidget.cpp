#include "boardwidget.h"

BoardWidget::BoardWidget(QWidget *parent): QGLWidget(parent)
{
    // Aktivace double bufferingu a hloukoveho bufferu.
    setFormat(QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer));

    // Nastaveni velikosti widgetu.
    setMinimumSize(400, 400);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Propoji se signal na preklad s hlavnim oknem.
    connect(parent->parent(), SIGNAL(retranslateSignal()), this, SLOT(retranslateSlot()));
}

BoardWidget::~BoardWidget(void)
{

}

void BoardWidget::initializeGL(void)
{
    // Zapnuti hloubkoveho bufferu.
    glEnable(GL_DEPTH_TEST);

    // Nastaveni barvy pozadi.
    qglClearColor(QColor::fromRgb(242, 241, 240));

    // Vymazani bufferu.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void BoardWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);

    // Upravi se velikost vykreslovane oblasti.
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    // Matice pro pozici pozorovatele...
    glMatrixMode(GL_PROJECTION);
    // ... se vynuluje na jednotkovou.
    glLoadIdentity();
    // Prepne se zpet na matici pro transformaci objektu.
    glMatrixMode(GL_MODELVIEW);
}

void BoardWidget::paintGL(void)
{
    // Vycisteni bufferu.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Matice pro transformace objektu...
    glMatrixMode(GL_MODELVIEW);
    // ... se vynuluje na jednotkovou.
    glLoadIdentity();

    // Vytvori se kreslitko.
    Painter painter(this, Painter::MODE_3D);

    painter.paintTriangle();

    /*
    glBegin(GL_TRIANGLES);
    qglColor(QColor::fromRgb(100, 23, 120));
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(0.0, 1.0, -1.0);
    glEnd();
    */
}

void BoardWidget::retranslateSlot(void)
{

}

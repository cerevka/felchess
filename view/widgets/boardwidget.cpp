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
    // Znici se kreslitko vytvorene pri inicializaci OpenGL.
    delete painter;

}

void BoardWidget::initializeGL(void)
{
    // Zapnuti hloubkoveho bufferu.
    glEnable(GL_DEPTH_TEST);

    // Nastaveni barvy pozadi.
    qglClearColor(QColor::fromRgb(242, 241, 240));

    // Vymazani bufferu.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Vytvori se kreslitko.
    painter = new Painter(this, Painter::MODE_2D);

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

    painter->paintTriangle();
}

void BoardWidget::retranslateSlot(void)
{

}

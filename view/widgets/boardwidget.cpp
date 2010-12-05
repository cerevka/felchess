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
    delete glPainter;

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
    glPainter = new Painter(this, Painter::MODE_2D);
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

    resize(side, side);
}

void BoardWidget::paintGL(void)
{
    QPainter painter(this);

    // Vycisteni bufferu.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Matice pro transformace objektu...
    glMatrixMode(GL_MODELVIEW);
    // ... se vynuluje na jednotkovou.
    glLoadIdentity();

    glPainter->drawChessboard();

    QSvgRenderer * renderer = new QSvgRenderer(QString(":/pieces/white/archer"));
    painter.setRenderHint(QPainter::Antialiasing);

    QPixmap pixmap(width()/8, height()/8);
    pixmap.fill(Qt::transparent);
    QPainter pixPainter(&pixmap);
    renderer->render(&pixPainter);


    painter.save();

    //painter.drawTiledPixmap(50, 0, pixmap.width(), pixmap.height(), pixmap);;

    //renderer->render(&painter);


   QPoint point(3, 3);
   APiece * piece = new King(false, point, this);
   glPainter->drawPiece(&painter, piece);

   painter.restore();
  painter.end();

}

void BoardWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << event->x() << " " << event->y();
    qDebug() << (event->x() / (width() / 8)) << " " << (event->y() / (width() / 8));
}

void BoardWidget::retranslateSlot(void)
{

}

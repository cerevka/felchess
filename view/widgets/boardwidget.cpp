#include "boardwidget.h"

BoardWidget::BoardWidget(QWidget *parent): QWidget(parent)
{    
    // Nastaveni velikosti widgetu.
    setMinimumSize(400, 400);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Propoji se signal na preklad s hlavnim oknem.
    connect(parent->parent(), SIGNAL(retranslateSignal()), this, SLOT(retranslateSlot()));
}

BoardWidget::~BoardWidget(void)
{

}

void BoardWidget::resizeEvent(QResizeEvent * event)
{
    int side = qMin(event->size().width(), event->size().height());
    resize(side, side);
}

void BoardWidget::paintEvent(QPaintEvent * event)
{
    painter.begin(this);
    painter.setViewport(0, 0, width()-1, height()-1);

    painter.drawChessboard();

    painter.end();
}

void BoardWidget::mousePressEvent(QMouseEvent *event)
{
    int size = width() / 8.3;
    // Posun x kvuli levemu pruhu vedle sachovnice.
    int x = event->x() - size / 3;
    int y = event->y();

    if (x > 0 && y < 8*size) {
       qDebug() << "x: " << x << " y: " << y;
       qDebug() << "polex: " << x / size << " poley: " << y / size;
    }
}

void BoardWidget::retranslateSlot(void)
{

}

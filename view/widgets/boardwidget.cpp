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

void BoardWidget::resize(int width, int height)
{
    int side = qMin(width, height);   

    //resize(side, side);
}

void BoardWidget::paint(void)
{


}

void BoardWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << event->x() << " " << event->y();
    qDebug() << (event->x() / (width() / 8)) << " " << (event->y() / (width() / 8));
}

void BoardWidget::retranslateSlot(void)
{

}

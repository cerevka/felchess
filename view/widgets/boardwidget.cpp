#include "boardwidget.h"

BoardWidget::BoardWidget(QWidget *parent): QWidget(parent)
{    
    // Nastaveni velikosti widgetu.
    setMinimumSize(400, 400);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Propoji se signal na preklad s hlavnim oknem.
    connect(parent->parent(), SIGNAL(retranslateSignal()), this, SLOT(retranslateSlot()));

    QPoint point(5,6);
    APiece * piece = new Knight(true, point);
    pieceList.append(piece);

    QPoint point1(3,2);
    APiece * piece1 = new Knight(false, point1);
    pieceList.append(piece1);
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
    Q_UNUSED(event);

    // Inicializuje se kreslitko.
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setViewport(0, 0, width()-1, height()-1);

    // Vykresli se sachovnice.
    painter.drawChessboard();

    // Vykresli se figurky.
    drawAllPieces();

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

void BoardWidget::drawAllPieces(void)
{
    QListIterator<APiece *> iterator(pieceList);
    while (iterator.hasNext()) {
        painter.drawPiece(iterator.next());
    }

}

void BoardWidget::addPieceSlot(APiece * piece)
{
    pieceList.append(piece);
}

void BoardWidget::retranslateSlot(void)
{

}

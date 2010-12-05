#include "infowidget.h"

InfoWidget::InfoWidget(QWidget *parent) : QTabWidget(parent)
{
    setMinimumSize(250, 200);

    // Propoji se signal na preklad s hlavnim oknem.
    connect(parent->parent(), SIGNAL(retranslateSignal()), this, SLOT(retranslateSlot()));
}

InfoWidget::~InfoWidget(void)
{

}

void InfoWidget::retranslateSlot(void)
{

}

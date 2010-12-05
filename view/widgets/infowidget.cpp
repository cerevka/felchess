#include "infowidget.h"

InfoWidget::InfoWidget(QWidget *parent) : QTabWidget(parent)
{
    setMinimumSize(250, 200);

    // Vytvori se zalozky.
    historyTab = new QWidget(this);
    scoreTab = new QWidget(this);
    figureTab = new QWidget(this);

    addTab(historyTab, tr("historyTab"));
    addTab(scoreTab, tr("scoreTab"));
    addTab(figureTab, tr("figureTab"));


    // Propoji se signal na preklad s hlavnim oknem.
    connect(parent->parent(), SIGNAL(retranslateSignal()), this, SLOT(retranslateSlot()));
}

InfoWidget::~InfoWidget(void)
{

}

void InfoWidget::retranslateSlot(void)
{
    setTabText(0, tr("historyTab"));
    setTabText(1, tr("scoreTab"));
    setTabText(2, tr("figureTab"));
}

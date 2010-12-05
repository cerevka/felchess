#include "centerwidget.h"

CenterWidget::CenterWidget(QWidget *parent) : QWidget(parent)
{
    // Pripravi se hlavni layout centralniho widgetu.
    layout = new QHBoxLayout();

    // Pripravi se layout nalevo.
    boardWidget = new BoardWidget(this);
    layout->addWidget(boardWidget);


    // Pripravi se layout napravo.
    rightLayout = new QVBoxLayout();
    infoWidget = new InfoWidget(this);
    chatWidget = new ChatWidget(this);
    rightLayout->addWidget(infoWidget);
    rightLayout->addWidget(chatWidget);
    rightLayout->setAlignment(Qt::AlignRight);

    // Pravy layout se zaradi do hlavniho a nastavi se vlastnictvi.
    layout->addLayout(rightLayout);

    // Widgetu se nastavi layout a prevezme ho do vlastnictvi.
    setLayout(layout);

    // Propoji se signal na preklad s hlavnim oknem.
    connect(parent, SIGNAL(retranslateSignal()), this, SLOT(retranslateSlot()));
}

CenterWidget::~CenterWidget(void)
{

}

void CenterWidget::retranslateSlot(void)
{

}

#include "chatwidget.h"

ChatWidget::ChatWidget(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout();

    setMinimumSize(250, 200);

    // Vlastnici prvku se nastavi automaticky pri addLayout a addWidget.

    chatView = new QTextEdit();
    chatView->setReadOnly(true);
    layout->addWidget(chatView);

    buttonLayout = new QHBoxLayout();
    messageEdit = new QLineEdit();
    buttonLayout->addWidget(messageEdit);
    sendButton = new QPushButton();
    buttonLayout->addWidget(sendButton);

    // Layout s tlacitky se zaradi do hlavniho layotu a re-parentuji
    // se tak vsechny jeho prvky.
    layout->addLayout(buttonLayout);

    // Hlavni layout se nastavi a vlastni ho widget.
    setLayout(layout);

    // Propoji se signal na preklad s hlavnim oknem.
    connect(parent->parent(), SIGNAL(retranslateSignal()), this, SLOT(retranslateSlot()));
}

ChatWidget::~ChatWidget(void)
{

}

void ChatWidget::retranslateSlot(void) {
    sendButton->setText(tr("chatSendButton"));

}

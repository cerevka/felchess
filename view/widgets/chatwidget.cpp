#include "chatwidget.h"

ChatWidget::ChatWidget(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);

    setMinimumSize(250, 200);

    chatView = new QTextEdit();
    chatView->setReadOnly(true);
    layout->addWidget(chatView);

    buttonLayout = new QHBoxLayout();
    messageEdit = new QLineEdit();
    buttonLayout->addWidget(messageEdit);
    sendButton = new QPushButton();
    buttonLayout->addWidget(sendButton);

    layout->addLayout(buttonLayout);

    setLayout(layout);

    // Propoji se signal na preklad s hlavnim oknem.
    connect(parent->parent(), SIGNAL(retranslateSignal()), this, SLOT(retranslateSlot()));
}

ChatWidget::~ChatWidget(void)
{
    delete chatView;
    delete messageEdit;
    delete sendButton;
    delete buttonLayout;

}

void ChatWidget::retranslateSlot(void) {
    sendButton->setText(tr("chatSendButton"));

}

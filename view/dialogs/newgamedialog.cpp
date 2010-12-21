#include "newgamedialog.h"

NewGameDialog::NewGameDialog(QWidget *parent) :
    QDialog(parent)
{
    layout = new QVBoxLayout();

    buttonGroup = new QButtonGroup(this);
    radioLayout = new QHBoxLayout();

    serverRadioButton = new QRadioButton(tr("ngdialog:server"));
    serverRadioButton->setChecked(true);
    buttonGroup->addButton(serverRadioButton, 1);
    radioLayout->addWidget(serverRadioButton);
    clientRadioButton = new QRadioButton(tr("ngdialog:client"));
    buttonGroup->addButton(clientRadioButton, 2);
    radioLayout->addWidget(clientRadioButton);

    radioWidget = new QWidget();
    radioWidget->setLayout(radioLayout);
    layout->addWidget(radioWidget);

    editLayout = new QFormLayout();

    ipLabel = new QLabel(tr("ngdialog:ipLabel"));
    ipLineEdit = new QLineEdit();
    ipLineEdit->setDisabled(true);
    ipLineEdit->setText("127.0.0.1");
    editLayout->addRow(ipLabel, ipLineEdit);
    portLabel = new QLabel(tr("ngdialog:portLabel"));
    portLineEdit = new QLineEdit();
    portLineEdit->setText("1234");
    editLayout->addRow(portLabel, portLineEdit);

    editWidget = new QWidget();
    editWidget->setLayout(editLayout);
    layout->addWidget(editWidget);

    buttonLayout = new QHBoxLayout();

    okButton = new QPushButton(tr("ngdialog:okButton"));
    buttonLayout->addWidget(okButton);
    stornoButton = new QPushButton(tr("ngdialog:stornoButton"));
    buttonLayout->addWidget(stornoButton);

    buttonWidget = new QWidget();
    buttonWidget->setLayout(buttonLayout);
    layout->addWidget(buttonWidget);


    setLayout(layout);   
    setWindowTitle(tr("ngdialog:title"));
    setFixedSize(300, 200);

    connect(parent, SIGNAL(retranslateSignal()), this, SLOT(retranslateSlot()));
    connect(buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(disableIPSlot(int)));
    connect(okButton, SIGNAL(clicked()), this, SLOT(okButtonSlot()));
    connect(stornoButton, SIGNAL(clicked()), this, SLOT(stornoButtonSlot()));
    connect(this, SIGNAL(okButtonSignal(bool, QString, QString)), parent, SLOT(startGameSlot(bool, QString, QString)));
    setModal(true);
}

NewGameDialog::~NewGameDialog()
{

}

void NewGameDialog::retranslateSlot()
{
    serverRadioButton->setText(tr("ngdialog:server"));
    clientRadioButton->setText(tr("ngdialog:client"));
    ipLabel->setText(tr("ngdialog:ipLabel"));
    portLabel->setText(tr("ngdialog:portLabel"));
    okButton->setText(tr("ngdialog:okButton"));
    stornoButton->setText(tr("ngdialog:stornoButton"));
    setWindowTitle(tr("ngdialog:title"));
}

void NewGameDialog::disableIPSlot(int buttonId)
{
    if (buttonId == 1) {
        // Bylo kliknuto na server.
        ipLineEdit->setDisabled(true);
    } else {
        ipLineEdit->setDisabled(false);
    }
}

void NewGameDialog::okButtonSlot(void)
{
    bool network;
    if (serverRadioButton->isChecked() == true)
    {
        // Je zaskrtnut server.
        network = true;
    }
    else
    {
        // Je zaskrtnut klient.
        network = false;

    }
    emit okButtonSignal(network, ipLineEdit->text(), portLineEdit->text());
    close();
}

void NewGameDialog::stornoButtonSlot(void)
{
    close();
}





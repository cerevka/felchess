#ifndef NEWGAMEDIALOG_H
#define NEWGAMEDIALOG_H

#include <QtGui>

class NewGameDialog : public QDialog
{
    Q_OBJECT
public:
    explicit NewGameDialog(QWidget *parent = 0);

    virtual ~NewGameDialog(void);

private:

    QVBoxLayout * layout;
    QHBoxLayout * radioLayout;
    QWidget * radioWidget;
    QFormLayout * editLayout;
    QWidget * editWidget;
    QHBoxLayout * buttonLayout;
    QWidget * buttonWidget;

    QButtonGroup * buttonGroup;
    QRadioButton * serverRadioButton;
    QRadioButton * clientRadioButton;

    QLabel * ipLabel;
    QLineEdit * ipLineEdit;
    QLabel * portLabel;
    QLineEdit * portLineEdit;

    QPushButton * okButton;
    QPushButton * stornoButton;

private slots:

    void retranslateSlot(void);

    void disableIPSlot(int buttonId);

    void okButtonSlot(void);

    void stornoButtonSlot(void);

signals:

    void okButtonSignal(bool network, QString ip, QString port);



};

#endif // NEWGAMEDIALOG_H

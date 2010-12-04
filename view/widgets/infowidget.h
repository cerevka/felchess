#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QWidget>

class InfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit InfoWidget(QWidget *parent = 0);

    virtual ~InfoWidget();

};

#endif // INFOWIDGET_H

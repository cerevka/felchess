#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>

class BoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BoardWidget(QWidget *parent = 0);

    virtual ~BoardWidget();

};

#endif // BOARDWIDGET_H

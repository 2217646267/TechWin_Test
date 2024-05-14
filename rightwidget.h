#ifndef RIGHTWIDGET_H
#define RIGHTWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "mybtn.h"

class RightWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RightWidget(QWidget *parent = nullptr);

public slots:
    void BtnSlots();

protected:
    bool eventFilter(QObject *watched, QEvent *event)override;
private:
    void Init();

private:
    QPushButton* EventBtn = nullptr;
    MyBtn* btn = nullptr;
    int eventId = 0;

};

#endif // RIGHTWIDGET_H

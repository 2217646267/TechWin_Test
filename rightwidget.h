#ifndef RIGHTWIDGET_H
#define RIGHTWIDGET_H

#include <QWidget>

class RightWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RightWidget(QWidget *parent = nullptr);

private:
    void Init();
};

#endif // RIGHTWIDGET_H

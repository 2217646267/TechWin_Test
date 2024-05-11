#ifndef PAINTERWIDGET_H
#define PAINTERWIDGET_H

#include <QWidget>
#include <QPainter>

class PainterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PainterWidget(QWidget *parent = nullptr);

signals:
protected:
     void paintEvent(QPaintEvent *event)Q_DECL_OVERRIDE;
};

#endif // PAINTERWIDGET_H

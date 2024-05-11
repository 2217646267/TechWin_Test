#include "painterwidget.h"

PainterWidget::PainterWidget(QWidget *parent)
    : QWidget{parent}
{

}


void PainterWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    // 设置画笔颜色
    painter.setPen(QColor(0, 160, 230));

    // 设置字体：微软雅黑、点大小50、斜体
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPointSize(50);
    font.setItalic(true);
    painter.setFont(font);
    // 反走样
    painter.setRenderHint(QPainter::Antialiasing, true);

    // 设置画刷颜色
    painter.setBrush(QColor(255, 160, 90));

    // 绘制圆
    painter.drawEllipse(QPointF(120, 100), 40, 40);

    // 绘制文本
    painter.drawText(rect(), Qt::AlignCenter, "Qt");
}

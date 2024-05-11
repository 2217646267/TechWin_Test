#include "mybtn.h"
#include <QMouseEvent>
#include <QDebug>

MyBtn::MyBtn(QWidget *parent)
    : QPushButton{parent}
{
    setFixedSize(170,50);
}

void MyBtn::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {

        m_pressTime = QTime::currentTime(); // 记录鼠标按下的时间
    }
}
void MyBtn::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        int elapsed = m_pressTime.msecsTo(QTime::currentTime()); // 计算鼠标按下到释放的时间差
        if(elapsed >= 500) // 判断时间差是否超过0.5秒
        {
            qDebug() << "Long press";
            this->setText(QString("x%1,y%2").arg(pos().x()).arg(QString("%1").arg(pos().y())) );
        }
        else
        {
            qDebug() << "Click";
            this->setText("");
        }
    }
}


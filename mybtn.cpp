#include "mybtn.h"
#include <QMouseEvent>
#include <QDebug>

MyBtn::MyBtn(QWidget *parent)
    : QPushButton{parent}
{
    setFixedSize(170,50);
    setMouseTracking(true);
    m_eventId = QEvent::registerEventType(QEvent::User + 1);

}
#if 1
bool MyBtn::event(QEvent* ev)
{
    if (ev->type() ==  GetEventId()) {
        qDebug() << " QEvent::My_event";
        show();
        return QWidget::event(ev);
    }

    return QWidget::event(ev);
}
#endif

void MyBtn::showEvent(QShowEvent *ev)
{
    if (ev->type() ==  GetEventId()) {
        qDebug() << " showEvent";
    }
}
void MyBtn::mousePressEvent(QMouseEvent* event)
{
    qDebug() << GetEventId();
    if (event->type() ==  GetEventId()) {
        qDebug() << " QEvent::mousePressEvent";
    }
    else  if(event->button() == Qt::LeftButton)
    {
        qDebug() << " mousePressEvent::My_event";
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

int MyBtn::GetEventId()
{
    return m_eventId;
}


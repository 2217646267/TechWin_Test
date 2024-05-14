#include "rightwidget.h"
#include <QBoxLayout>
#include <QDebug>
#include "mybtn.h"
#include "painterwidget.h"
#include <QMouseEvent>
#include <QApplication>

 RightWidget::RightWidget(QWidget *parent)
    : QWidget{parent}
{
    Init();
    connect(EventBtn, &QPushButton::clicked, this, &RightWidget::BtnSlots);
}

void RightWidget::Init()
{
    this->setFixedSize(240,600);

    QVBoxLayout* pMainLayout = new QVBoxLayout(this);
    pMainLayout->setContentsMargins(30, 30, 0, 0);

    btn = new MyBtn(this);
    pMainLayout->addWidget(btn);
    btn->installEventFilter(this);

    EventBtn = new QPushButton(this);
    EventBtn->setText("eventbtn");
    EventBtn->installEventFilter(this);

    //画笔
    PainterWidget* pPainterWidget = new PainterWidget(this);
    pMainLayout->addWidget(pPainterWidget);

    this->setLayout(pMainLayout);
}

void RightWidget::BtnSlots()
{
    eventId = btn->GetEventId();
    QEvent* myEvent = new QEvent(QEvent::Type(eventId));
#if 0
    int result = QApplication::sendEvent(btn, myEvent);
     qDebug() << "sendEvent()"<< result << eventId;
#else
     QApplication::postEvent(btn, myEvent, Qt::HighEventPriority);
     qDebug() << "postEvent()"<< eventId;
#endif
}

#if 1
bool RightWidget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == btn) {
        if( event->type()== eventId)
        {
            qDebug() << "eventFilter::My_event";
            return QWidget::eventFilter(obj, event);
            //return true;
        }
    }
    return QWidget::eventFilter(obj, event);

}
#endif



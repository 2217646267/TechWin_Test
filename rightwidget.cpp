#include "rightwidget.h"
#include <QBoxLayout>
#include <QDebug>
#include "mybtn.h"
#include "painterwidget.h"

 RightWidget::RightWidget(QWidget *parent)
    : QWidget{parent}
{
    Init();

}

void RightWidget::Init()
{
    this->setFixedSize(240,600);

    QVBoxLayout* pMainLayout = new QVBoxLayout(this);
    pMainLayout->setContentsMargins(30, 30, 0, 0);

    //按钮
    MyBtn* btn = new MyBtn(this);
    pMainLayout->addWidget(btn);

    //画笔
    PainterWidget* pPainterWidget = new PainterWidget(this);
    pMainLayout->addWidget(pPainterWidget);

/*
    connect(btn,&QPushButton::released,[&]{
        qDebug()<< "Qt::LeftButton";
    });
*/
    this->setLayout(pMainLayout);


}

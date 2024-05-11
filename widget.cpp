#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include "checkboxwidget.h"
#include "rightwidget.h"
#include <QBoxLayout>
#include <QStackedWidget>
#include <QLabel>
#include <QFont>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    Init();
}

void Widget::Init()
{
    //标题
    QLabel* pTipLabel = new QLabel(this);
    pTipLabel->setFixedSize(180, 50);
    pTipLabel->setText(QString::fromLocal8Bit("我的作业"));
    QFont ft;
    ft.setPointSize(15);
    pTipLabel->setFont(ft);
    pTipLabel->move(30,0);
    pTipLabel->setStyleSheet("color:rgb(0, 0, 0);");

    //图标
    QLabel* pICon = new QLabel(this);
    QString strFilePath = "://github.png";//图标位置自行调整
    QIcon icon = QIcon(strFilePath);
    QPixmap m_pic = icon.pixmap(icon.actualSize(QSize(80, 80)));
    pICon->setPixmap(m_pic);
    pICon->setFixedSize(80,80);
    pICon->move(25,50);

    //主要界面
    CheckboxWidget* pLeftWidget = new CheckboxWidget(this);
    RightWidget* pRightWidget = new RightWidget(this);

    QHBoxLayout* pMainLayout = new QHBoxLayout(this);
    pMainLayout->setContentsMargins(0, 0, 0, 0);
    pMainLayout->addWidget(pLeftWidget);
    pMainLayout->addWidget(pRightWidget);

    this->setLayout(pMainLayout);
}

Widget::~Widget()
{
    delete ui;
}


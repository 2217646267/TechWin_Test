#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include "checkboxwidget.h"
#include "rightwidget.h"
#include <QBoxLayout>
#include <QStackedWidget>
#include <QLabel>
#include <QFont>
#include <QTableView>
#include <QHeaderView>
#include "tablemodel.h"
#include "checkboxdelegate.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    Init();
    InitDate();
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
    bool bShow = false;
    pTipLabel->setVisible(bShow);
    pICon->setVisible(bShow);
    pLeftWidget->setVisible(bShow);
    pRightWidget->setVisible(bShow);
}

void Widget::InitDate()
{
    QFile qss("/home/liangtuqin/Qt_Project/demo/Demo_1/Myqss.qss");
    if (qss.open(QFile::ReadOnly)){
        qDebug() << qss.readAll();
        qApp->setStyleSheet( qss.readAll());
    }

    QTableView *pTableView = new QTableView(this);
    pTableView->setFixedSize(500,400);
    TableModel *pModel = new TableModel(this);
    CheckBoxDelegate *pDelegate = new CheckBoxDelegate(this);

    // 设置单行选中、最后一列拉伸、表头不高亮、无边框等
    pTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    pTableView->horizontalHeader()->setStretchLastSection(true);
    pTableView->horizontalHeader()->setHighlightSections(false);
    pTableView->verticalHeader()->setVisible(false);
    pTableView->setShowGrid(true);
    pTableView->setFrameShape(QFrame::NoFrame);
    pTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    pTableView->setModel(pModel);
    pTableView->setItemDelegate(pDelegate);

    // 加载数据、更新界面
    QList<FileRecord> recordList;
    for (int i = 0; i < 6; ++i)
    {
        FileRecord record;
        record.bChecked = false;
        record.strFilePath = QString("E:/Qt/image_%1.png").arg(i + 1);
        recordList.append(record);
    }
    pModel->updateData(recordList);

}

Widget::~Widget()
{
    delete ui;
}


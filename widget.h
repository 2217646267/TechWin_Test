#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

private:
    void Init();
    void InitConnect();

private:
    QVector<QCheckBox*> m_CheckboxVct;
    int m_number = 0;
    QCheckBox* m_pPaterBox = nullptr;

};
#endif // WIDGET_H

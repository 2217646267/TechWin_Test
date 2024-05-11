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

};
#endif // WIDGET_H

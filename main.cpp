#include "widget.h"

#include <QApplication>
#include <QDebug>
#define DELEAGTE_MODE 0

#if DELEAGTE_MODE
class ITelco
{
public:
    virtual ~ITelco(){};
    virtual void Recharge(int nMoney) = 0;
};

class CMCC : public ITelco
{
public:
    void Recharge(int nMoney)
    {
        qDebug() << "Recharge" << nMoney;
    }
};

class Proxy : ITelco
{
public:
    Proxy(){};

    void Recharge(int nMoney)
    {
        if(nMoney >= 50)
        {
            if(m_pCMCC == nullptr)
            {
                CMCC* m_pCMCC = new CMCC;
                m_pCMCC->Recharge(nMoney);
            }
        }
        else
        {
            qDebug() << "Sorry,too little money";
        }

    }
private:
    CMCC* m_pCMCC = nullptr;
private:
    ~Proxy(){delete m_pCMCC;};
};

#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#if DELEAGTE_MODE
    Proxy* proxy = new Proxy;
    proxy->Recharge(50);

    if(proxy != nullptr)
    {
        delete(proxy);
        proxy = nullptr;
    }
#endif
    Widget w;
    w.show();
    return a.exec();
}

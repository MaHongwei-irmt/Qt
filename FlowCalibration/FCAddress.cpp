#include "FCAddress.h"
#include "ui_FCAddress.h"
/***********************************************************************************************************
界面功能：设置传感器设备地址
按确定保存设置端口地址，按取消则不保存设置的地址。
************************************************************************************************************/
FCAddress::FCAddress(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FCAddress)
{
    ui->setupUi(this);
    InitUI();
    InitConnect();
}

FCAddress::~FCAddress()
{
    delete ui;
}
/***********************************************************************************************************
 函数名：InitUI()
 函数功能：UI界面初始化
 函数参数：无
 函数返回值：无
************************************************************************************************************/
void FCAddress::InitUI()
{
    QFont Ft("Microsoft YaHei");
    Ft.setPointSize(12);
    ui->tbnOK->setFont(Ft);
    ui->tbnOK->setAutoRaise(true);
    ui->tbnOK->setIcon(ImageFileOK);
    ui->tbnOK->setIconSize(ImageFileOK.size());
    ui->tbnOK->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->tbnCancel->setFont(Ft);
    ui->tbnCancel->setAutoRaise(true);
    ui->tbnCancel->setIcon(ImageFileCancel);
    ui->tbnCancel->setIconSize(ImageFileCancel.size());
    ui->tbnCancel->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->le1->setFont(Ft);
    ui->le2->setFont(Ft);
    ui->le3->setFont(Ft);
    ui->le4->setFont(Ft);
    ui->le5->setFont(Ft);
    ui->le6->setFont(Ft);
    ui->le7->setFont(Ft);
    ui->le8->setFont(Ft);
    ui->le9->setFont(Ft);
    ui->le10->setFont(Ft);
    ui->le11->setFont(Ft);
    ui->le12->setFont(Ft);
}
/***********************************************************************************************************
 函数名：InitConnect()
 函数功能：确认取消信号与槽的连接
 函数参数：无
 函数返回值：无
************************************************************************************************************/
void FCAddress::InitConnect()
{
    connect(ui->tbnOK,SIGNAL(clicked(bool)),this,SLOT(OnOk()));
    connect(ui->tbnCancel,SIGNAL(clicked(bool)),this,SLOT(OnCancel()));
}
/***********************************************************************************************************
 函数名：exec()
 函数功能：消息循环函数重载，使用QEventLoop进行消息循环堵塞，点击确认或者取消退出。
 函数参数：无
 函数返回值：无
************************************************************************************************************/
int FCAddress::exec()
{
    this->setWindowModality(Qt::ApplicationModal);//类似于阻塞
    show();
    m_eventLoop = new QEventLoop(this);
    m_eventLoop->exec();
    return 0;
}
void FCAddress::OnOk()
{
   Address.push_back(ui->le1->text().toInt());
   Address.push_back(ui->le2->text().toInt());
   Address.push_back(ui->le3->text().toInt());
   Address.push_back(ui->le4->text().toInt());
   Address.push_back(ui->le5->text().toInt());
   emit SendAddress(Address);
   Address.pop_back();
   Address.pop_back();
   Address.pop_back();
   Address.pop_back();
   Address.pop_back();
   this->close();
}
void FCAddress::OnCancel()
{
   this->close();
}
void FCAddress::closeEvent(QCloseEvent *event)
{
    if(m_eventLoop!=NULL)
    {
        m_eventLoop->exit();
    }
    event->accept();
    //event->ignore();
}


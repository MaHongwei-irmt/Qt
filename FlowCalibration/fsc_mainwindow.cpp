#include "fsc_mainwindow.h"
#include "ui_fsc_mainwindow.h"

#include <QFile>
#include <QtCore/QCoreApplication>
#include <QSettings>
#include <QDebug>



QVector <fsc_para_ini> fsc_global::para_ini;
QTcpSocket* fsc_global::sktTcp[SOCKET_NUMBER];
QString    fsc_global::ip_PLC;
QString    fsc_global::ip_RS_Server;
int fsc_global::port_number[SOCKET_NUMBER];



FSC_MainWindow::FSC_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mainTimer(new QTimer(this)),
    ui(new Ui::FSC_MainWindow)
{
    ui->setupUi(this);

//----------------------------------------------------------------
    ParaInit();

//---------------------------曲线-----------------------------


//-------------------------------------------------------------------
    PlotInit();


//-------------------------------------------------------------------

    sktConMapper = new QSignalMapper();
    sktDisconMapper = new QSignalMapper();
    sktErrMapper = new QSignalMapper();
    sktReadMapper = new QSignalMapper();

    for( int i = 0; i < SOCKET_NUMBER; i++)
    {
        fsc_global::sktTcp[i] = new QTcpSocket();

        connect(fsc_global::sktTcp[i], SIGNAL(connected()), sktConMapper, SLOT(map()));

        sktConMapper->setMapping(fsc_global::sktTcp[i], i);


        connect(fsc_global::sktTcp[i], SIGNAL(disconnected()), sktDisconMapper, SLOT(map()));


        sktDisconMapper->setMapping(fsc_global::sktTcp[i], i);



        connect(fsc_global::sktTcp[i], SIGNAL(error(QAbstractSocket::SocketError)), sktErrMapper, SLOT(map()));


        sktErrMapper->setMapping(fsc_global::sktTcp[i], i);



    }

    connect(sktConMapper, SIGNAL(mapped(int)), this, SLOT(sktScale_connect_suc(int)));
    connect(sktDisconMapper, SIGNAL(mapped(int)), this, SLOT(sktScale_connect_dis(int)));
    connect(sktErrMapper, SIGNAL(mapped(int)), this, SLOT(sktScale_error(int)));


    sktConed[0] = false;
    fsc_global::sktTcp[0]->connectToHost(QHostAddress(fsc_global::ip_PLC), fsc_global::port_number[0]);

    QDateTime time = QDateTime::currentDateTime();   //获取当前时间

    sktConCommandTime[0] = time.toTime_t();   //将当前时间转为时间戳

    for (int i = 1; i < SOCKET_NUMBER; i++)
    {
        sktConed[i] = false;
        fsc_global::sktTcp[i]->connectToHost(QHostAddress(fsc_global::ip_RS_Server), fsc_global::port_number[i]);


        time = QDateTime::currentDateTime();
        sktConCommandTime[i] = time.toTime_t();
    }




//-------------------------------------------------------------------

    ui->lineEdit_scale_show->setAlignment(Qt::AlignRight);


    connect(ui->lineEdit_scale_show_1,SIGNAL(clicked(bool)),this,SLOT(on_tbnSysDevCheck_clicked()));

    connect(mainTimer,SIGNAL(timeout()),this,SLOT(mainTimerUpdate()));


    mainTimer->start(1000);

}

void FSC_MainWindow::mainTimerUpdate()
{
    static int j = 1;

    if(j % 5 == 0)
    {
        for (int i = 0; i < SOCKET_NUMBER; i++)
        {
            if (sktConed[i] == false)
            {

                fsc_global::sktTcp[i]->abort();
                fsc_global::sktTcp[i]->connectToHost(QHostAddress(fsc_global::ip_RS_Server), fsc_global::port_number[i]);


                qDebug() << QString::number(i);
            }
        }
    }





    j++;

}

void FSC_MainWindow::sktScale_connect_suc(int i)
{
    QMessageBox::information(this, "show", QString::number(i) + " con");

    sktConed[i] = true;

}

void FSC_MainWindow::sktScale_connect_dis(int i)
{
    QMessageBox::information(this, "show",  QString::number(i) + " discon");

    fsc_global::sktTcp[i]->abort();

    fsc_global::sktTcp[i]->connectToHost(QHostAddress(fsc_global::ip_RS_Server), fsc_global::port_number[i]);

    sktConed[i] = false;

}

void FSC_MainWindow::sktScale_error(QAbstractSocket::SocketError, int i)
{
        QMessageBox::information(this, "show", "err");

    switch(fsc_global::sktTcp[i]->error())
    {
//        case QAbstractSocket::RemoteHostClosedError://客户端断开
//            {
//                QString hostAddress = fsc_global::sktScale->QAbstractSocket::peerAddress().toString();
//                ui->m_display->insertPlainText(tr("客户端[%1]断开连接\r\n").arg(hostAddress));
//                break;
//            }
        default:
            {
                QMessageBox::information(this, "show", fsc_global::sktTcp[SOCKET_SCALE_INDEX]->errorString());
                break;
            }
    }
}


void FSC_MainWindow::ParaInit()
{
    QSettings *configIni = new QSettings("para.ini", QSettings::IniFormat);


    fsc_global::ip_PLC = configIni->value("IP_ADDRESS/PLC" ).toString();
    fsc_global::ip_RS_Server = configIni->value("IP_ADDRESS/RS_SERVER" ).toString();


    fsc_global::port_number[0] = 5200;
    fsc_global::port_number[1] = 2100;
    fsc_global::port_number[2] = 4000;
    fsc_global::port_number[3] = 40010;
    fsc_global::port_number[4] = 4002;
    fsc_global::port_number[5] = 4003;
    fsc_global::port_number[6] = 4004;
    fsc_global::port_number[7] = 4005;
    fsc_global::port_number[8] = 4006;
    fsc_global::port_number[9] = 4007;
    fsc_global::port_number[10] = 4008;
    fsc_global::port_number[11] = 4009;
    fsc_global::port_number[12] = 4010;
    fsc_global::port_number[13] = 4011;
    fsc_global::port_number[14] = 4012;
    fsc_global::port_number[15] = 4013;



    qDebug() << fsc_global::ip_PLC;
    qDebug() << fsc_global::ip_RS_Server;


    int i = 1;
    fsc_para_ini tmp;

    ui->comboBox_SensorTypeName->clear();

    while (configIni->value( "sensor_type_" + QString::number(i) +"/type_name" ).toString() != "")
    {

        tmp.type_name = configIni->value( "sensor_type_" + QString::number(i) +"/type_name" ).toString();
        qDebug() << tmp.type_name;





        tmp.span_ml_per_min = configIni->value( "sensor_type_" + QString::number(i) +"/span_ml_per_min" ).toFloat();

        tmp.span_100_cal = configIni->value( "sensor_type_" + QString::number(i) +"/100_percent_position_to_be_calibrate" ).toBool();
        tmp.span_90_cal = configIni->value( "sensor_type_" + QString::number(i) +"/90_percent_position_to_be_calibrate" ).toBool();
        tmp.span_80_cal = configIni->value( "sensor_type_" + QString::number(i) +"/80_percent_position_to_be_calibrate" ).toBool();
        tmp.span_70_cal = configIni->value( "sensor_type_" + QString::number(i) +"/70_percent_position_to_be_calibrate" ).toBool();
        tmp.span_60_cal = configIni->value( "sensor_type_" + QString::number(i) +"/60_percent_position_to_be_calibrate" ).toBool();
        tmp.span_50_cal = configIni->value( "sensor_type_" + QString::number(i) +"/50_percent_position_to_be_calibrate" ).toBool();
        tmp.span_40_cal = configIni->value( "sensor_type_" + QString::number(i) +"/40_percent_position_to_be_calibrate" ).toBool();
        tmp.span_30_cal = configIni->value( "sensor_type_" + QString::number(i) +"/30_percent_position_to_be_calibrate" ).toBool();
        tmp.span_20_cal = configIni->value( "sensor_type_" + QString::number(i) +"/20_percent_position_to_be_calibrate" ).toBool();
        tmp.span_10_cal = configIni->value( "sensor_type_" + QString::number(i) +"/20_percent_position_to_be_calibrate" ).toBool();


        tmp.span_100_check = configIni->value( "sensor_type_" + QString::number(i) +"/100_percent_position_to_be_verify" ).toBool();
        tmp.span_90_check = configIni->value( "sensor_type_" + QString::number(i) +"/90_percent_position_to_be_verify" ).toBool();
        tmp.span_80_check = configIni->value( "sensor_type_" + QString::number(i) +"/80_percent_position_to_be_verify" ).toBool();
        tmp.span_70_check = configIni->value( "sensor_type_" + QString::number(i) +"/70_percent_position_to_be_verify" ).toBool();
        tmp.span_60_check = configIni->value( "sensor_type_" + QString::number(i) +"/60_percent_position_to_be_verify" ).toBool();
        tmp.span_50_check = configIni->value( "sensor_type_" + QString::number(i) +"/50_percent_position_to_be_verify" ).toBool();
        tmp.span_40_check = configIni->value( "sensor_type_" + QString::number(i) +"/40_percent_position_to_be_verify" ).toBool();
        tmp.span_30_check = configIni->value( "sensor_type_" + QString::number(i) +"/30_percent_position_to_be_verify" ).toBool();
        tmp.span_20_check = configIni->value( "sensor_type_" + QString::number(i) +"/20_percent_position_to_be_verify" ).toBool();
        tmp.span_10_check = configIni->value( "sensor_type_" + QString::number(i) +"/10_percent_position_to_be_verify" ).toBool();


        tmp.span_100_correct = configIni->value( "sensor_type_" + QString::number(i) +"/100_percent_position_to_be_correct" ).toBool();
        tmp.span_90_correct = configIni->value( "sensor_type_" + QString::number(i) +"/90_percent_position_to_be_correct" ).toBool();
        tmp.span_80_correct = configIni->value( "sensor_type_" + QString::number(i) +"/80_percent_position_to_be_correct" ).toBool();
        tmp.span_70_correct = configIni->value( "sensor_type_" + QString::number(i) +"/70_percent_position_to_be_correct" ).toBool();
        tmp.span_60_correct = configIni->value( "sensor_type_" + QString::number(i) +"/60_percent_position_to_be_correct" ).toBool();
        tmp.span_50_correct = configIni->value( "sensor_type_" + QString::number(i) +"/50_percent_position_to_be_correct" ).toBool();
        tmp.span_40_correct = configIni->value( "sensor_type_" + QString::number(i) +"/40_percent_position_to_be_correct" ).toBool();
        tmp.span_30_correct = configIni->value( "sensor_type_" + QString::number(i) +"/30_percent_position_to_be_correct" ).toBool();
        tmp.span_20_correct = configIni->value( "sensor_type_" + QString::number(i) +"/20_percent_position_to_be_correct" ).toBool();
        tmp.span_10_correct = configIni->value( "sensor_type_" + QString::number(i) +"/10_percent_position_to_be_correct" ).toBool();




        fsc_global::para_ini.append(tmp);

        ui->comboBox_SensorTypeName->addItem(tmp.type_name);

        i++;

    }


    on_comboBox_SensorTypeName_currentIndexChanged(0);


    delete configIni;

}

void FSC_MainWindow::PlotInit()
{
    //---------------------------曲线-----------------------------
        int iGraphIndex = 0;


        //ui->widget->setBackground(QBrush(Qt::black));

         //设定右上角图形标注可见
         ui->MyCustomPlot->legend->setVisible(true);

         //设定右上角图形标注的字体
         ui->MyCustomPlot->legend->setFont(QFont("Helvetica", 8));

        QVector<double> x(101),y(101);

         //图形为y=x^3
         for(int i=0; i<101; i++)
         {
            x[i] = i/5.0-10;
            y[i] = x[i]*x[i]*x[i] * x[i] * x[i];//qPow(x[i],3)
         }

         //添加图形
         ui->MyCustomPlot->addGraph();

         //设置画笔
         ui->MyCustomPlot->graph(0)->setPen(QPen(Qt::red));

         //设置画刷,曲线和X轴围成面积的颜色
         //ui->MyCustomPlot->graph(0)->setBrush(QBrush(QColor(255,255,0)));

         //设置右上角图形标注名称
         ui->MyCustomPlot->graph(0)->setName("天平");

         //传入数据，setData的两个参数类型为double
         ui->MyCustomPlot->graph(0)->setData(x,y);

        QVector<double> temp(20);
        QVector<double> temp1(20);

         //图形为y = 100*x;
         for(int i=0;i<20;i++)
         {
            temp[i] = i;
            temp1[i] = 1000*i+10;
         }

         //添加图形
         ui->MyCustomPlot->addGraph();

         //设置画笔
         ui->MyCustomPlot->graph(1)->setPen(QPen(Qt::blue));

         //设置画刷,曲线和X轴围成面积的颜色
         //ui->widget->graph(1)->setBrush(QBrush(QColor(0,255,0)));

         //传入数据
         ui->MyCustomPlot->graph(1)->setData(temp,temp1);

         /*-------------------------------------------*/
         //画动态曲线时，传入数据采用addData，通过定时器多次调用，并在之后调用ui->widget->replot();
         //动态曲线可以通过另一种设置坐标的方法解决坐标问题：
         //setRange ( double position, double size, Qt::AlignmentFlag alignment )
         //参数分别为：原点，偏移量，对其方式，有兴趣的读者可自行尝试，欢迎垂询
         /*-------------------------------------------*/

         //设置右上角图形标注名称
         ui->MyCustomPlot->graph(1)->setName("标准流量");












         iGraphIndex = 2;


         QVector<double> t(1);
         QVector<double> tl(1);


         for (iGraphIndex = 2; iGraphIndex <= 4; iGraphIndex++)
         {

              t[0] = 30;
              tl[0] = 0;

              //添加图形
              ui->MyCustomPlot->addGraph();

              //设置画笔
              ui->MyCustomPlot->graph(iGraphIndex)->setPen(QPen(Qt::black));

              //设置画刷,曲线和X轴围成面积的颜色
              //ui->widget->graph(1)->setBrush(QBrush(QColor(0,255,0)));

              //传入数据：
              ui->MyCustomPlot->graph(iGraphIndex)->setData(t,tl);

              /*-------------------------------------------*/
              //画动态曲线时，传入数据采用addData，通过定时器多次调用，并在之后调用ui->widget->replot();
              //动态曲线可以通过另一种设置坐标的方法解决坐标问题：
              //setRange ( double position, double size, Qt::AlignmentFlag alignment )
              //参数分别为：原点，偏移量，对其方式，有兴趣的读者可自行尝试，欢迎垂询
              /*-------------------------------------------*/

              //设置右上角图形标注名称
              //ui->MyCustomPlot->graph(iGraphIndex)->setName(QString::number(iGraphIndex,10));


             if(iGraphIndex == 3) ui->MyCustomPlot->graph(iGraphIndex)->setName(ui->comboBox_PlotSenSel->currentText() + "流量");
             if(iGraphIndex == 4) ui->MyCustomPlot->graph(iGraphIndex)->setName(ui->comboBox_PlotSenSel->currentText() + "流速");

              if(iGraphIndex == 2)
              {

                  ui->MyCustomPlot->graph(iGraphIndex)->setName("标准流速");
                  ui->MyCustomPlot->graph(iGraphIndex)->setPen(QPen(Qt::blue));
              }
         }

















         //设置X轴文字标注
         ui->MyCustomPlot->xAxis->setLabel("time");


         //设置Y轴文字标注
         ui->MyCustomPlot->yAxis->setLabel("temp/shidu");

         //设置X轴坐标范围
         //ui->MyCustomPlot->xAxis->setRange(-20,20);

         //设置Y轴坐标范围
        // ui->MyCustomPlot->yAxis->setRange(-1100,1100);

         //在坐标轴右侧和上方画线，和X/Y轴一起形成一个矩形
         ui->MyCustomPlot->axisRect()->setupFullAxesBox();


         //QFont Ft("Microsoft YaHei");
         //Ft.setPointSize(12);

         //ui->MyCustomPlot->addGraph();
         //ui->MyCustomPlot->graph(0)->setName(tr("Name"));

         ui->MyCustomPlot->xAxis->setLabel(tr("采样点时序"));
         ui->MyCustomPlot->yAxis->setLabel(tr("天平质量/流量/流速"));
         ui->MyCustomPlot->rescaleAxes(true);
         ui->MyCustomPlot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom);



           ui->MyCustomPlot->replot();

    //-------------------------------------------------------------------
}


void FSC_MainWindow::PlotReplay()
{
    //---------------------------曲线-----------------------------
        int iGraphIndex = 0;


        //ui->widget->setBackground(QBrush(Qt::black));

         //设定右上角图形标注可见
         ui->MyCustomPlot->legend->setVisible(true);

         //设定右上角图形标注的字体
         ui->MyCustomPlot->legend->setFont(QFont("Helvetica", 8));

        QVector<double> x(101),y(101);

         //图形为y=x^3
         for(int i=0; i<101; i++)
         {
            x[i] = i/5.0-10;
            y[i] = x[i]*x[i]*x[i] * x[i] * x[i];//qPow(x[i],3)
         }

         //添加图形
         //ui->MyCustomPlot->addGraph();

         //设置画笔
         ui->MyCustomPlot->graph(0)->setPen(QPen(Qt::red));

         //设置画刷,曲线和X轴围成面积的颜色
         //ui->MyCustomPlot->graph(0)->setBrush(QBrush(QColor(255,255,0)));

         //设置右上角图形标注名称
         ui->MyCustomPlot->graph(0)->setName("天平");

         //传入数据，setData的两个参数类型为double
         ui->MyCustomPlot->graph(0)->setData(x,y);

        QVector<double> temp(20);
        QVector<double> temp1(20);

         //图形为y = 100*x;
         for(int i=0;i<20;i++)
         {
            temp[i] = i;
            temp1[i] = 1000*i+10;
         }

         //添加图形
         //ui->MyCustomPlot->addGraph();

         //设置画笔
         ui->MyCustomPlot->graph(1)->setPen(QPen(Qt::blue));

         //设置画刷,曲线和X轴围成面积的颜色
         //ui->widget->graph(1)->setBrush(QBrush(QColor(0,255,0)));

         //传入数据
         ui->MyCustomPlot->graph(1)->setData(temp,temp1);

         /*-------------------------------------------*/
         //画动态曲线时，传入数据采用addData，通过定时器多次调用，并在之后调用ui->widget->replot();
         //动态曲线可以通过另一种设置坐标的方法解决坐标问题：
         //setRange ( double position, double size, Qt::AlignmentFlag alignment )
         //参数分别为：原点，偏移量，对其方式，有兴趣的读者可自行尝试，欢迎垂询
         /*-------------------------------------------*/

         //设置右上角图形标注名称
         ui->MyCustomPlot->graph(1)->setName("标准流量");












         iGraphIndex = 2;


         QVector<double> t(1);
         QVector<double> tl(1);


         for (iGraphIndex = 2; iGraphIndex <= 4; iGraphIndex++)
         {

              t[0] = 30;
              tl[0] = 0;

              //添加图形
              //ui->MyCustomPlot->addGraph();

              //设置画笔
              ui->MyCustomPlot->graph(iGraphIndex)->setPen(QPen(Qt::black));

              //设置画刷,曲线和X轴围成面积的颜色
              //ui->widget->graph(1)->setBrush(QBrush(QColor(0,255,0)));

              //传入数据：
              ui->MyCustomPlot->graph(iGraphIndex)->setData(t,tl);

              /*-------------------------------------------*/
              //画动态曲线时，传入数据采用addData，通过定时器多次调用，并在之后调用ui->widget->replot();
              //动态曲线可以通过另一种设置坐标的方法解决坐标问题：
              //setRange ( double position, double size, Qt::AlignmentFlag alignment )
              //参数分别为：原点，偏移量，对其方式，有兴趣的读者可自行尝试，欢迎垂询
              /*-------------------------------------------*/

              //设置右上角图形标注名称
              //ui->MyCustomPlot->graph(iGraphIndex)->setName(QString::number(iGraphIndex,10));


             if(iGraphIndex == 3) ui->MyCustomPlot->graph(iGraphIndex)->setName(ui->comboBox_PlotSenSel->currentText() + "流量");
             if(iGraphIndex == 4) ui->MyCustomPlot->graph(iGraphIndex)->setName(ui->comboBox_PlotSenSel->currentText() + "流速");

              if(iGraphIndex == 2)
              {

                  ui->MyCustomPlot->graph(iGraphIndex)->setName("标准流速");
                  ui->MyCustomPlot->graph(iGraphIndex)->setPen(QPen(Qt::blue));
              }
         }

















         //设置X轴文字标注
         ui->MyCustomPlot->xAxis->setLabel("time");


         //设置Y轴文字标注
         ui->MyCustomPlot->yAxis->setLabel("temp/shidu");

         //设置X轴坐标范围
         //ui->MyCustomPlot->xAxis->setRange(-20,20);

         //设置Y轴坐标范围
        // ui->MyCustomPlot->yAxis->setRange(-1100,1100);

         //在坐标轴右侧和上方画线，和X/Y轴一起形成一个矩形
         ui->MyCustomPlot->axisRect()->setupFullAxesBox();


         //QFont Ft("Microsoft YaHei");
         //Ft.setPointSize(12);

         //ui->MyCustomPlot->addGraph();
         //ui->MyCustomPlot->graph(0)->setName(tr("Name"));

         ui->MyCustomPlot->xAxis->setLabel(tr("采样点时序"));
         ui->MyCustomPlot->yAxis->setLabel(tr("天平质量/流量/流速"));
         ui->MyCustomPlot->rescaleAxes(true);
         ui->MyCustomPlot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom);



           ui->MyCustomPlot->replot();

    //-------------------------------------------------------------------
}

QString FSC_MainWindow::ConnectQStringAndNum(QString str, int i)//给定一个字符串和一个数字，把他俩连起来。
{
 QString str_i;
 str_i.sprintf("%d",i);
 return(str+str_i);
}

FSC_MainWindow::~FSC_MainWindow()
{
    delete ui;
}


void FSC_MainWindow::on_tbnSysDevCheck_clicked()
{

    ui->textBrow_sysdev_ckeck_info->setText("");

    QString tmp = ui->textBrow_sysdev_ckeck_info->toPlainText();


    ui->textBrow_sysdev_ckeck_info->setText(tmp + "1\n");


    tmp = ui->textBrow_sysdev_ckeck_info->toPlainText();
    ui->textBrow_sysdev_ckeck_info->setText(tmp + "1\n");

    tmp = ui->textBrow_sysdev_ckeck_info->toPlainText();
    ui->textBrow_sysdev_ckeck_info->setText(tmp + "1\n");


    tmp = ui->textBrow_sysdev_ckeck_info->toPlainText();
    ui->textBrow_sysdev_ckeck_info->setText(tmp + "1\n");

    tmp = ui->textBrow_sysdev_ckeck_info->toPlainText();
    ui->textBrow_sysdev_ckeck_info->setText(tmp + "1\n");


    tmp = ui->textBrow_sysdev_ckeck_info->toPlainText();
    ui->textBrow_sysdev_ckeck_info->setText(tmp + "1\n");

    tmp = ui->textBrow_sysdev_ckeck_info->toPlainText();
    ui->textBrow_sysdev_ckeck_info->setText(tmp + "1\n");


}

void FSC_MainWindow::on_tbnManualCheckDev_clicked()
{
    Dialog_CheckDev *ChkDev = new Dialog_CheckDev();

    ChkDev->exec();
}

void FSC_MainWindow::on_comboBox_PlotSenSel_currentIndexChanged(const QString &arg1)
{
    PlotReplay();
}


void FSC_MainWindow::on_comboBox_SensorTypeName_currentIndexChanged(int index)
{

    ui->leFlowSpeed_SensorSpan->setText(QString::number(fsc_global::para_ini.at(index).span_ml_per_min));

    ui->checkBox_100SpanCal->setChecked(fsc_global::para_ini.at(index).span_100_cal);
    ui->checkBox_90SpanCal->setChecked(fsc_global::para_ini.at(index).span_90_cal);
    ui->checkBox_80SpanCal->setChecked(fsc_global::para_ini.at(index).span_80_cal);
    ui->checkBox_70SpanCal->setChecked(fsc_global::para_ini.at(index).span_70_cal);
    ui->checkBox_60SpanCal->setChecked(fsc_global::para_ini.at(index).span_60_cal);
    ui->checkBox_50SpanCal->setChecked(fsc_global::para_ini.at(index).span_50_cal);
    ui->checkBox_40SpanCal->setChecked(fsc_global::para_ini.at(index).span_40_cal);
    ui->checkBox_30SpanCal->setChecked(fsc_global::para_ini.at(index).span_30_cal);
    ui->checkBox_20SpanCal->setChecked(fsc_global::para_ini.at(index).span_20_cal);
    ui->checkBox_10SpanCal->setChecked(fsc_global::para_ini.at(index).span_10_cal);



    ui->checkBox_100SpanCheck->setChecked(fsc_global::para_ini.at(index).span_100_check);
    ui->checkBox_90SpanCheck->setChecked(fsc_global::para_ini.at(index).span_90_check);
    ui->checkBox_80SpanCheck->setChecked(fsc_global::para_ini.at(index).span_80_check);
    ui->checkBox_70SpanCheck->setChecked(fsc_global::para_ini.at(index).span_70_check);
    ui->checkBox_60SpanCheck->setChecked(fsc_global::para_ini.at(index).span_60_check);
    ui->checkBox_50SpanCheck->setChecked(fsc_global::para_ini.at(index).span_50_check);
    ui->checkBox_40SpanCheck->setChecked(fsc_global::para_ini.at(index).span_40_check);
    ui->checkBox_30SpanCheck->setChecked(fsc_global::para_ini.at(index).span_30_check);
    ui->checkBox_20SpanCheck->setChecked(fsc_global::para_ini.at(index).span_20_check);
    ui->checkBox_10SpanCheck->setChecked(fsc_global::para_ini.at(index).span_10_check);




    ui->checkBox_100SpanModify->setChecked(fsc_global::para_ini.at(index).span_100_correct);
    ui->checkBox_90SpanModify->setChecked(fsc_global::para_ini.at(index).span_90_correct);
    ui->checkBox_80SpanModify->setChecked(fsc_global::para_ini.at(index).span_80_correct);
    ui->checkBox_70SpanModify->setChecked(fsc_global::para_ini.at(index).span_70_correct);
    ui->checkBox_60SpanModify->setChecked(fsc_global::para_ini.at(index).span_60_correct);
    ui->checkBox_50SpanModify->setChecked(fsc_global::para_ini.at(index).span_50_correct);
    ui->checkBox_40SpanModify->setChecked(fsc_global::para_ini.at(index).span_40_correct);
    ui->checkBox_30SpanModify->setChecked(fsc_global::para_ini.at(index).span_30_correct);
    ui->checkBox_20SpanModify->setChecked(fsc_global::para_ini.at(index).span_20_correct);
    ui->checkBox_10SpanModify->setChecked(fsc_global::para_ini.at(index).span_10_correct);
}


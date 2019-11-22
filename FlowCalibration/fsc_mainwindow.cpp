#include "fsc_mainwindow.h"
#include "ui_fsc_mainwindow.h"

#include <QFile>
#include <QtCore/QCoreApplication>
#include <QSettings>
#include <QDebug>
#include <math.h>

QVector <fsc_para_ini>  fsc_global::para_ini;
QTcpSocket*             fsc_global::sktTcp[SOCKET_NUMBER];
QString                 fsc_global::ip_PLC;
QString                 fsc_global::ip_RS_Server;
quint16                 fsc_global::port_number[SOCKET_NUMBER];
QString                 fsc_global::ip[SOCKET_NUMBER];

FSC_MainWindow::FSC_MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::FSC_MainWindow),
    mainLoopTimer(new QTimer(this))
{
    ui->setupUi(this);

    ParaInit();
    PlotInit();
    DataInit();
    SocketInit();

    connect(mainLoopTimer, SIGNAL(timeout()), this, SLOT(mainLoop()));
    mainLoopTimer->start(100);
}

FSC_MainWindow::~FSC_MainWindow()
{
    delete ui;
}

void FSC_MainWindow::ParaInit(void)
{
    QSettings *configIni = new QSettings("para.ini", QSettings::IniFormat);

    fsc_global::ip_PLC = configIni->value("IP_ADDRESS/PLC" ).toString();
    fsc_global::ip_RS_Server = configIni->value("IP_ADDRESS/RS_SERVER" ).toString();

    fsc_global::ip[0] = fsc_global::ip_PLC;
    for (int i = 1; i < SOCKET_NUMBER; i++)
    {
        fsc_global::ip[i] = fsc_global::ip_RS_Server;
    }

    fsc_global::port_number[0] = 2100;
    fsc_global::port_number[1] = 4001;
    fsc_global::port_number[2] = 4002;
    fsc_global::port_number[3] = 4003;
    fsc_global::port_number[4] = 4004;
    fsc_global::port_number[5] = 4005;
    fsc_global::port_number[6] = 4006;
    fsc_global::port_number[7] = 4007;
    fsc_global::port_number[8] = 4008;
    fsc_global::port_number[9] = 4009;
    fsc_global::port_number[10] = 4010;
    fsc_global::port_number[11] = 4011;
    fsc_global::port_number[12] = 4012;
    fsc_global::port_number[13] = 4013;
    fsc_global::port_number[14] = 4014;
    fsc_global::port_number[15] = 4015;
    fsc_global::port_number[16] = 4016;

    FSCLOG << fsc_global::ip_PLC;
    FSCLOG << fsc_global::ip_RS_Server;


    int i = 1;
    fsc_para_ini tmp;

    ui->comboBox_SensorTypeName->clear();

    while (configIni->value( "sensor_type_" + QString::number(i) +"/type_name" ).toString() != "")
    {

        tmp.type_name = configIni->value( "sensor_type_" + QString::number(i) +"/type_name" ).toString();
        FSCLOG << tmp.type_name;

        tmp.span_ml_per_min = configIni->value( "sensor_type_" + QString::number(i) +"/span_ml_per_min" ).toDouble();

        tmp.span10_cal[0] = configIni->value( "sensor_type_" + QString::number(i) +"/10_percent_position_to_be_calibrate" ).toBool();
        tmp.span10_cal[1] = configIni->value( "sensor_type_" + QString::number(i) +"/20_percent_position_to_be_calibrate" ).toBool();
        tmp.span10_cal[2] = configIni->value( "sensor_type_" + QString::number(i) +"/30_percent_position_to_be_calibrate" ).toBool();
        tmp.span10_cal[3] = configIni->value( "sensor_type_" + QString::number(i) +"/40_percent_position_to_be_calibrate" ).toBool();
        tmp.span10_cal[4] = configIni->value( "sensor_type_" + QString::number(i) +"/50_percent_position_to_be_calibrate" ).toBool();
        tmp.span10_cal[5] = configIni->value( "sensor_type_" + QString::number(i) +"/60_percent_position_to_be_calibrate" ).toBool();
        tmp.span10_cal[6] = configIni->value( "sensor_type_" + QString::number(i) +"/70_percent_position_to_be_calibrate" ).toBool();
        tmp.span10_cal[7] = configIni->value( "sensor_type_" + QString::number(i) +"/80_percent_position_to_be_calibrate" ).toBool();
        tmp.span10_cal[8] = configIni->value( "sensor_type_" + QString::number(i) +"/90_percent_position_to_be_calibrate" ).toBool();
        tmp.span10_cal[9] = configIni->value( "sensor_type_" + QString::number(i) +"/100_percent_position_to_be_calibrate" ).toBool();

        tmp.span10_check[0] = configIni->value( "sensor_type_" + QString::number(i) +"/10_percent_position_to_be_verify" ).toBool();
        tmp.span10_check[1] = configIni->value( "sensor_type_" + QString::number(i) +"/20_percent_position_to_be_verify" ).toBool();
        tmp.span10_check[2] = configIni->value( "sensor_type_" + QString::number(i) +"/30_percent_position_to_be_verify" ).toBool();
        tmp.span10_check[3] = configIni->value( "sensor_type_" + QString::number(i) +"/40_percent_position_to_be_verify" ).toBool();
        tmp.span10_check[4] = configIni->value( "sensor_type_" + QString::number(i) +"/50_percent_position_to_be_verify" ).toBool();
        tmp.span10_check[5] = configIni->value( "sensor_type_" + QString::number(i) +"/60_percent_position_to_be_verify" ).toBool();
        tmp.span10_check[6] = configIni->value( "sensor_type_" + QString::number(i) +"/70_percent_position_to_be_verify" ).toBool();
        tmp.span10_check[7] = configIni->value( "sensor_type_" + QString::number(i) +"/80_percent_position_to_be_verify" ).toBool();
        tmp.span10_check[8] = configIni->value( "sensor_type_" + QString::number(i) +"/90_percent_position_to_be_verify" ).toBool();
        tmp.span10_check[9] = configIni->value( "sensor_type_" + QString::number(i) +"/100_percent_position_to_be_verify" ).toBool();

        tmp.span10_correct[0] = configIni->value( "sensor_type_" + QString::number(i) +"/10_percent_position_to_be_correct" ).toBool();
        tmp.span10_correct[1] = configIni->value( "sensor_type_" + QString::number(i) +"/20_percent_position_to_be_correct" ).toBool();
        tmp.span10_correct[3] = configIni->value( "sensor_type_" + QString::number(i) +"/30_percent_position_to_be_correct" ).toBool();
        tmp.span10_correct[3] = configIni->value( "sensor_type_" + QString::number(i) +"/40_percent_position_to_be_correct" ).toBool();
        tmp.span10_correct[4] = configIni->value( "sensor_type_" + QString::number(i) +"/50_percent_position_to_be_correct" ).toBool();
        tmp.span10_correct[5] = configIni->value( "sensor_type_" + QString::number(i) +"/60_percent_position_to_be_correct" ).toBool();
        tmp.span10_correct[6] = configIni->value( "sensor_type_" + QString::number(i) +"/70_percent_position_to_be_correct" ).toBool();
        tmp.span10_correct[7] = configIni->value( "sensor_type_" + QString::number(i) +"/80_percent_position_to_be_correct" ).toBool();
        tmp.span10_correct[8] = configIni->value( "sensor_type_" + QString::number(i) +"/90_percent_position_to_be_correct" ).toBool();
        tmp.span10_correct[9] = configIni->value( "sensor_type_" + QString::number(i) +"/100_percent_position_to_be_correct" ).toBool();

        fsc_global::para_ini.append(tmp);

        ui->comboBox_SensorTypeName->addItem(tmp.type_name);

        i++;
    }

    on_comboBox_SensorTypeName_currentIndexChanged(0);

    delete configIni;

}

void FSC_MainWindow::PlotInit(void)
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

void FSC_MainWindow::DataInit(void)
{
    ui->lineEdit_scale_show->setText("NaN");
    ui->lineEdit_scale_flow->setText("NaN");

    ui->lineEdit_stdFM_sum->setText("NaN");
    ui->lineEdit_stdFM_flow->setText("NaN");



    showScaleSum = -100000.012;// static_cast<double>(nanf(""));
    showScaleFlow = static_cast<double>(nanf(""));
    showSTDFMSum = static_cast<double>(nanf(""));
    showSTDFMFlow = static_cast<double>(nanf(""));

    for (int i = 0; i < SCALE_NUMBER; i++)
    {
        showFMSum[i] = static_cast<double>(nanf(""));
        showFMFlow[i] = static_cast<double>(nanf(""));
    }

    ui->lineEdit_FM_1->setText(QString::number(showScaleSum, 'f', 3));
    ui->lineEdit_FM_2->setText("NaN");
    ui->lineEdit_FM_3->setText("NaN");
    ui->lineEdit_FM_4->setText("NaN");
    ui->lineEdit_FM_5->setText("NaN");
    ui->lineEdit_FM_6->setText("NaN");
    ui->lineEdit_FM_7->setText("NaN");
    ui->lineEdit_FM_8->setText("NaN");
    ui->lineEdit_FM_9->setText("NaN");
    ui->lineEdit_FM_10->setText("NaN");
    ui->lineEdit_FM_11->setText("NaN");
    ui->lineEdit_FM_12->setText("NaN");

    ui->lineEdit_FM_1_flow->setText("NaN");
    ui->lineEdit_FM_2_flow->setText("NaN");
    ui->lineEdit_FM_3_flow->setText("NaN");
    ui->lineEdit_FM_4_flow->setText("NaN");
    ui->lineEdit_FM_5_flow->setText("NaN");
    ui->lineEdit_FM_6_flow->setText("NaN");
    ui->lineEdit_FM_7_flow->setText("NaN");
    ui->lineEdit_FM_8_flow->setText("NaN");
    ui->lineEdit_FM_9_flow->setText("NaN");
    ui->lineEdit_FM_10_flow->setText("NaN");
    ui->lineEdit_FM_11_flow->setText("NaN");
    ui->lineEdit_FM_12_flow->setText("NaN");





}

void FSC_MainWindow::SocketInit(void)
{
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

        connect(fsc_global::sktTcp[i], SIGNAL(readyRead()), sktReadMapper, SLOT(map()));
        sktReadMapper->setMapping(fsc_global::sktTcp[i], i);
    }

    connect(sktConMapper, SIGNAL(mapped(int)), this, SLOT(skt_connect_suc(int)));
    connect(sktDisconMapper, SIGNAL(mapped(int)), this, SLOT(skt_connect_dis(int)));
    connect(sktErrMapper, SIGNAL(mapped(int)), this, SLOT(skt_error(int)));
    connect(sktReadMapper, SIGNAL(mapped(int)), this, SLOT(skt_read(int)));

    for (int i = 0; i < SOCKET_NUMBER; i++)
    {
        sktConed[i] = false;
        fsc_global::sktTcp[i]->connectToHost(QHostAddress(fsc_global::ip[i]), fsc_global::port_number[i]);
        sktConCommandTime[i] = QDateTime::currentDateTime().toTime_t();
    }
}

void FSC_MainWindow::SendScaleShow(void)
{
    sktBufSend[SOCKET_SCALE_INDEX].resize(2);
    sktBufSend[SOCKET_SCALE_INDEX][0]=0x1B;
    sktBufSend[SOCKET_SCALE_INDEX][1]=0x70;

    if (fsc_global::sktTcp[SOCKET_SCALE_INDEX])
    {
        fsc_global::sktTcp[SOCKET_SCALE_INDEX]->write(sktBufSend[SOCKET_SCALE_INDEX]);

        FSCLOG << "Socket write: " + QString::number(SOCKET_SCALE_INDEX) + " " + QString::number(sktBufSend[SOCKET_SCALE_INDEX].size()) + \
                  " " + ByteArrayToHexString(sktBufSend[SOCKET_SCALE_INDEX]);

    }

    sktBufSend[SOCKET_SCALE_INDEX].resize(0);
}

void FSC_MainWindow::SendScaleZero(void)
{
    sktBufSend[SOCKET_SCALE_INDEX].resize(2);
    sktBufSend[SOCKET_SCALE_INDEX][0]=0x1B;
    sktBufSend[SOCKET_SCALE_INDEX][1]=0x74;

    if (fsc_global::sktTcp[SOCKET_SCALE_INDEX])
    {
        fsc_global::sktTcp[SOCKET_SCALE_INDEX]->write(sktBufSend[SOCKET_SCALE_INDEX]);

        FSCLOG << "Socket write: " + QString::number(SOCKET_SCALE_INDEX) + " " + QString::number(sktBufSend[SOCKET_SCALE_INDEX].size()) + \
                  " " + ByteArrayToHexString(sktBufSend[SOCKET_SCALE_INDEX]);
    }

    sktBufSend[SOCKET_SCALE_INDEX].resize(0);
}

void FSC_MainWindow::mainLoop()
{
    static int j = 0;

    j++;

    if (j % 10 == 0)
    {
        sktBufSend[SOCKET_FLOWM1_INDEX].resize(2);
        sktBufSend[SOCKET_FLOWM1_INDEX][0]=0x1B;
        sktBufSend[SOCKET_FLOWM1_INDEX][1]=0x74;

        if (sktConed[SOCKET_FLOWM1_INDEX])
        {
            fsc_global::sktTcp[SOCKET_FLOWM1_INDEX]->write(sktBufSend[SOCKET_FLOWM1_INDEX]);

            FSCLOG << "Socket write: " + QString::number(SOCKET_FLOWM1_INDEX) + " " + QString::number(sktBufSend[SOCKET_FLOWM1_INDEX].size()) + \
                      " " + ByteArrayToHexString(sktBufSend[SOCKET_FLOWM1_INDEX]);
        }

    }

    SendScaleShow();

    for (int i = 0; i < SOCKET_NUMBER; i++)
    {
        if (! sktConed[i] &&  (sktConCommandTime[i] + SOCKET_TCP_RETRY_CON_TIMEOUT) < QDateTime::currentDateTime().toTime_t() )
        {

            fsc_global::sktTcp[i]->abort();

            fsc_global::sktTcp[i]->connectToHost(QHostAddress(fsc_global::ip[i]), fsc_global::port_number[i]);
            sktConCommandTime[i] = QDateTime::currentDateTime().toTime_t();


            FSCLOG << QString::number(i) << " socket con retry";
        }

    }

    ui->lineEdit_scale_show->setEnabled(sktConed[SOCKET_SCALE_INDEX]);
    ui->lineEdit_scale_flow->setEnabled(sktConed[SOCKET_SCALE_INDEX]);

    ui->lineEdit_stdFM_sum->setEnabled(sktConed[SOCKET_STD_FLOWM_INDEX]);
    ui->lineEdit_stdFM_flow->setEnabled(sktConed[SOCKET_STD_FLOWM_INDEX]);

    ui->lineEdit_FM_1->setEnabled(sktConed[SOCKET_FLOWM1_INDEX]);
    ui->lineEdit_FM_2->setEnabled(sktConed[SOCKET_FLOWM2_INDEX]);
    ui->lineEdit_FM_3->setEnabled(sktConed[SOCKET_FLOWM3_INDEX]);
    ui->lineEdit_FM_4->setEnabled(sktConed[SOCKET_FLOWM4_INDEX]);
    ui->lineEdit_FM_5->setEnabled(sktConed[SOCKET_FLOWM5_INDEX]);
    ui->lineEdit_FM_6->setEnabled(sktConed[SOCKET_FLOWM6_INDEX]);
    ui->lineEdit_FM_7->setEnabled(sktConed[SOCKET_FLOWM7_INDEX]);
    ui->lineEdit_FM_8->setEnabled(sktConed[SOCKET_FLOWM8_INDEX]);
    ui->lineEdit_FM_9->setEnabled(sktConed[SOCKET_FLOWM9_INDEX]);
    ui->lineEdit_FM_10->setEnabled(sktConed[SOCKET_FLOWM10_INDEX]);
    ui->lineEdit_FM_11->setEnabled(sktConed[SOCKET_FLOWM11_INDEX]);
    ui->lineEdit_FM_12->setEnabled(sktConed[SOCKET_FLOWM12_INDEX]);

    ui->lineEdit_FM_1_flow->setEnabled(sktConed[SOCKET_FLOWM1_INDEX]);
    ui->lineEdit_FM_2_flow->setEnabled(sktConed[SOCKET_FLOWM2_INDEX]);
    ui->lineEdit_FM_3_flow->setEnabled(sktConed[SOCKET_FLOWM3_INDEX]);
    ui->lineEdit_FM_4_flow->setEnabled(sktConed[SOCKET_FLOWM4_INDEX]);
    ui->lineEdit_FM_5_flow->setEnabled(sktConed[SOCKET_FLOWM5_INDEX]);
    ui->lineEdit_FM_6_flow->setEnabled(sktConed[SOCKET_FLOWM6_INDEX]);
    ui->lineEdit_FM_7_flow->setEnabled(sktConed[SOCKET_FLOWM7_INDEX]);
    ui->lineEdit_FM_8_flow->setEnabled(sktConed[SOCKET_FLOWM8_INDEX]);
    ui->lineEdit_FM_9_flow->setEnabled(sktConed[SOCKET_FLOWM9_INDEX]);
    ui->lineEdit_FM_10_flow->setEnabled(sktConed[SOCKET_FLOWM10_INDEX]);
    ui->lineEdit_FM_11_flow->setEnabled(sktConed[SOCKET_FLOWM11_INDEX]);
    ui->lineEdit_FM_12_flow->setEnabled(sktConed[SOCKET_FLOWM12_INDEX]);

//    ui->lineEdit_scale_show->setText(showScaleSum);
//    ui->lineEdit_scale_flow->setText("NaN");

//    ui->lineEdit_stdFM_sum->setText("NaN");
//    ui->lineEdit_stdFM_flow->setText("NaN");


//    showScaleSum = static_cast<double>(nanf(""));
//    showScaleFlow = static_cast<double>(nanf(""));
//    showSTDFMSum = static_cast<double>(nanf(""));
//    showSTDFMFlow = static_cast<double>(nanf(""));

//    for (int i = 0; i < SCALE_NUMBER; i++)
//    {
//        showFMSum[i] = static_cast<double>(nanf(""));
//        showFMFlow[i] = static_cast<double>(nanf(""));
//    }

//    ui->lineEdit_FM_1->setText(QString::number(showScaleSum, 'f', 2));
//    ui->lineEdit_FM_2->setText("NaN");
//    ui->lineEdit_FM_3->setText("NaN");
//    ui->lineEdit_FM_4->setText("NaN");
//    ui->lineEdit_FM_5->setText("NaN");
//    ui->lineEdit_FM_6->setText("NaN");
//    ui->lineEdit_FM_7->setText("NaN");
//    ui->lineEdit_FM_8->setText("NaN");
//    ui->lineEdit_FM_9->setText("NaN");
//    ui->lineEdit_FM_10->setText("NaN");
//    ui->lineEdit_FM_11->setText("NaN");
//    ui->lineEdit_FM_12->setText("NaN");

//    ui->lineEdit_FM_1_flow->setText("NaN");
//    ui->lineEdit_FM_2_flow->setText("NaN");
//    ui->lineEdit_FM_3_flow->setText("NaN");
//    ui->lineEdit_FM_4_flow->setText("NaN");
//    ui->lineEdit_FM_5_flow->setText("NaN");
//    ui->lineEdit_FM_6_flow->setText("NaN");
//    ui->lineEdit_FM_7_flow->setText("NaN");
//    ui->lineEdit_FM_8_flow->setText("NaN");
//    ui->lineEdit_FM_9_flow->setText("NaN");
//    ui->lineEdit_FM_10_flow->setText("NaN");
//    ui->lineEdit_FM_11_flow->setText("NaN");
//    ui->lineEdit_FM_12_flow->setText("NaN");



}

void FSC_MainWindow::skt_read(int i)
{
    QByteArray last = sktBufRev[i];

    sktBufRev[i] = fsc_global::sktTcp[i]->readAll();

    FSCLOG << "Socket read: " + QString::number(i) + " " + QString::number(sktBufRev[i].size()) + " " + ByteArrayToHexString(sktBufRev[i]);

    switch (i)
    {
    case SOCKET_SCALE_INDEX:
        ui->lineEdit_scale_show->setText("");
        ui->lineEdit_scale_flow->setText("");

        FSCLOG << "Socket read: " + QString::number(i) + " " + QString::number(sktBufRev[i].size()) + " " + sktBufRev[i];

        ui->lineEdit_scale_show->setText(sktBufRev[i]);


        {
            float f1 = sktBufRev[i].toFloat();
            float f2 = last.toFloat();

            ui->lineEdit_scale_flow->setText(QByteArray::number( static_cast<double>(f1 - f2) , 'f', 2)  );

        }

        break;

    case SOCKET_STD_FLOWM_INDEX:

        ui->lineEdit_stdFM_sum->setText("");
        ui->lineEdit_stdFM_flow->setText("");

        if (fsc_global::sktTcp[SOCKET_STD_FLOWM_INDEX])
        {
            static double scale_test = 1.1;
            static int j = 1;

            scale_test += 0.1 * j++;

            QByteArray tmp = QByteArray::number(scale_test, 'f', 2 );

            fsc_global::sktTcp[SOCKET_STD_FLOWM_INDEX]->write(tmp);

            FSCLOG << "Socket write: " + QString::number(SOCKET_STD_FLOWM_INDEX) + " " + tmp;
        }

        break;

    case SOCKET_FLOWM1_INDEX:
        ui->lineEdit_FM_1->setText("");
        ui->lineEdit_FM_1_flow->setText("");
        break;

    case SOCKET_FLOWM2_INDEX:
        ui->lineEdit_FM_2->setText("");
        ui->lineEdit_FM_2_flow->setText("");
        break;

    case SOCKET_FLOWM3_INDEX:
        ui->lineEdit_FM_3->setText("");
        ui->lineEdit_FM_3_flow->setText("");
        break;

    case SOCKET_FLOWM4_INDEX:
        ui->lineEdit_FM_4->setText("");
        ui->lineEdit_FM_4_flow->setText("");
        break;

    case SOCKET_FLOWM5_INDEX:
        ui->lineEdit_FM_5->setText("");
        ui->lineEdit_FM_5_flow->setText("");
        break;


    case SOCKET_FLOWM6_INDEX:
        ui->lineEdit_FM_6->setText("");
        ui->lineEdit_FM_6_flow->setText("");
        break;

    case SOCKET_FLOWM7_INDEX:
        ui->lineEdit_FM_7->setText("");
        ui->lineEdit_FM_7_flow->setText("");
        break;

    case SOCKET_FLOWM8_INDEX:
        ui->lineEdit_FM_8->setText("");
        ui->lineEdit_FM_8_flow->setText("");
        break;

    case SOCKET_FLOWM9_INDEX:
        ui->lineEdit_FM_9_flow->setText("");
        break;

    case SOCKET_FLOWM10_INDEX:
        ui->lineEdit_FM_10->setText("");
        ui->lineEdit_FM_10_flow->setText("");
        break;

    case SOCKET_FLOWM11_INDEX:
        ui->lineEdit_FM_11->setText("");
        ui->lineEdit_FM_11_flow->setText("");
        break;

    case SOCKET_FLOWM12_INDEX:
        ui->lineEdit_FM_12->setText("");
        ui->lineEdit_FM_12_flow->setText("");
        break;

    }

}

void FSC_MainWindow::skt_connect_suc(int i)
{
    sktConed[i] = true;
    FSCLOG << QString::number(i) + " socket con";
}

void FSC_MainWindow::skt_connect_dis(int i)
{
    fsc_global::sktTcp[i]->abort();

    sktConed[i] = false;
    fsc_global::sktTcp[i]->connectToHost(QHostAddress(fsc_global::ip[i]), fsc_global::port_number[i]);
    sktConCommandTime[i] = QDateTime::currentDateTime().toTime_t();

    FSCLOG << QString::number(i) << " socket discon - recon";

    switch (i)
    {
    case SOCKET_SCALE_INDEX:

        ui->lineEdit_scale_show->setText("NaN");
        ui->lineEdit_scale_flow->setText("NaN");

        break;

    case SOCKET_STD_FLOWM_INDEX:

        ui->lineEdit_scale_show->setText("NaN");
        ui->lineEdit_scale_flow->setText("NaN");

        break;

    case SOCKET_FLOWM1_INDEX:

        ui->lineEdit_scale_show->setText("NaN");
        ui->lineEdit_scale_flow->setText("NaN");

        break;

    case SOCKET_FLOWM2_INDEX:

        ui->lineEdit_scale_show->setText("NaN");
        ui->lineEdit_scale_flow->setText("NaN");

        break;

    case SOCKET_FLOWM3_INDEX:

        ui->lineEdit_scale_show->setText("NaN");
        ui->lineEdit_scale_flow->setText("NaN");

        break;

    case SOCKET_FLOWM4_INDEX:

        ui->lineEdit_scale_show->setText("NaN");
        ui->lineEdit_scale_flow->setText("NaN");

        break;

    case SOCKET_FLOWM5_INDEX:

        ui->lineEdit_scale_show->setText("NaN");
        ui->lineEdit_scale_flow->setText("NaN");

        break;


    case SOCKET_FLOWM6_INDEX:

        ui->lineEdit_scale_show->setText("NaN");
        ui->lineEdit_scale_flow->setText("NaN");

        break;

    case SOCKET_FLOWM7_INDEX:

        ui->lineEdit_scale_show->setText("NaN");
        ui->lineEdit_scale_flow->setText("NaN");

        break;

    case SOCKET_FLOWM8_INDEX:

        ui->lineEdit_scale_show->setText("NaN");
        ui->lineEdit_scale_flow->setText("NaN");

        break;

    case SOCKET_FLOWM9_INDEX:

        ui->lineEdit_scale_show->setText("NaN");
        ui->lineEdit_scale_flow->setText("NaN");

        break;

    case SOCKET_FLOWM10_INDEX:

        ui->lineEdit_scale_show->setText("NaN");
        ui->lineEdit_scale_flow->setText("NaN");

        break;

    case SOCKET_FLOWM11_INDEX:

        ui->lineEdit_scale_show->setText("NaN");
        ui->lineEdit_scale_flow->setText("NaN");

        break;

    case SOCKET_FLOWM12_INDEX:

        ui->lineEdit_scale_show->setText("NaN");
        ui->lineEdit_scale_flow->setText("NaN");

        break;


    }
}

void FSC_MainWindow::skt_error(int i)
{
    FSCLOG << "info Socket: " + QString::number(i) + " " + fsc_global::sktTcp[i]->QAbstractSocket::peerAddress().toString()\
              + "  " + fsc_global::sktTcp[i]->errorString();
}

void FSC_MainWindow::PlotReplay(const QString &arg1)
{
    //---------------------------曲线-----------------------------
    FSCLOG  << arg1;

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
    PlotReplay(arg1);
}

void FSC_MainWindow::on_comboBox_SensorTypeName_currentIndexChanged(int index)
{

    ui->leFlowSpeed_SensorSpan->setText(QString::number(fsc_global::para_ini.at(index).span_ml_per_min));

    ui->checkBox_100SpanCal->setChecked(fsc_global::para_ini.at(index).span10_cal[9]);
    ui->checkBox_90SpanCal->setChecked(fsc_global::para_ini.at(index).span10_cal[8]);
    ui->checkBox_80SpanCal->setChecked(fsc_global::para_ini.at(index).span10_cal[7]);
    ui->checkBox_70SpanCal->setChecked(fsc_global::para_ini.at(index).span10_cal[6]);
    ui->checkBox_60SpanCal->setChecked(fsc_global::para_ini.at(index).span10_cal[5]);
    ui->checkBox_50SpanCal->setChecked(fsc_global::para_ini.at(index).span10_cal[4]);
    ui->checkBox_40SpanCal->setChecked(fsc_global::para_ini.at(index).span10_cal[3]);
    ui->checkBox_30SpanCal->setChecked(fsc_global::para_ini.at(index).span10_cal[2]);
    ui->checkBox_20SpanCal->setChecked(fsc_global::para_ini.at(index).span10_cal[1]);
    ui->checkBox_10SpanCal->setChecked(fsc_global::para_ini.at(index).span10_cal[0]);

    ui->checkBox_100SpanCheck->setChecked(fsc_global::para_ini.at(index).span10_check[9]);
    ui->checkBox_90SpanCheck->setChecked(fsc_global::para_ini.at(index).span10_check[8]);
    ui->checkBox_80SpanCheck->setChecked(fsc_global::para_ini.at(index).span10_check[7]);
    ui->checkBox_70SpanCheck->setChecked(fsc_global::para_ini.at(index).span10_check[6]);
    ui->checkBox_60SpanCheck->setChecked(fsc_global::para_ini.at(index).span10_check[5]);
    ui->checkBox_50SpanCheck->setChecked(fsc_global::para_ini.at(index).span10_check[4]);
    ui->checkBox_40SpanCheck->setChecked(fsc_global::para_ini.at(index).span10_check[3]);
    ui->checkBox_30SpanCheck->setChecked(fsc_global::para_ini.at(index).span10_check[2]);
    ui->checkBox_20SpanCheck->setChecked(fsc_global::para_ini.at(index).span10_check[1]);
    ui->checkBox_10SpanCheck->setChecked(fsc_global::para_ini.at(index).span10_check[0]);

    ui->checkBox_100SpanModify->setChecked(fsc_global::para_ini.at(index).span10_correct[9]);
    ui->checkBox_90SpanModify->setChecked(fsc_global::para_ini.at(index).span10_correct[8]);
    ui->checkBox_80SpanModify->setChecked(fsc_global::para_ini.at(index).span10_correct[7]);
    ui->checkBox_70SpanModify->setChecked(fsc_global::para_ini.at(index).span10_correct[6]);
    ui->checkBox_60SpanModify->setChecked(fsc_global::para_ini.at(index).span10_correct[5]);
    ui->checkBox_50SpanModify->setChecked(fsc_global::para_ini.at(index).span10_correct[4]);
    ui->checkBox_40SpanModify->setChecked(fsc_global::para_ini.at(index).span10_correct[3]);
    ui->checkBox_30SpanModify->setChecked(fsc_global::para_ini.at(index).span10_correct[2]);
    ui->checkBox_20SpanModify->setChecked(fsc_global::para_ini.at(index).span10_correct[1]);
    ui->checkBox_10SpanModify->setChecked(fsc_global::para_ini.at(index).span10_correct[0]);

}


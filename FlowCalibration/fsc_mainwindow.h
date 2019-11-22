#ifndef FSC_MAINWINDOW_H
#define FSC_MAINWINDOW_H

#include <QMainWindow>
#include "dialog_checkdev.h"
#include <QtNetwork>
#include <QSignalMapper>

QByteArray  HexStringToByteArray(QString HexString);
QString     ByteArrayToHexString(QByteArray &ba);

namespace Ui {
class FSC_MainWindow;
}

#define FSCLOG  qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz")

#define SCALE_NUMBER    12
#define SOCKET_NUMBER   17

#define SOCKET_PLC_INDEX        0
#define SOCKET_SCALE_INDEX      1
#define SOCKET_STD_FLOWM_INDEX  2
#define SOCKET_FLOWM1_INDEX     3
#define SOCKET_FLOWM2_INDEX     4
#define SOCKET_FLOWM3_INDEX     5
#define SOCKET_FLOWM4_INDEX     6
#define SOCKET_FLOWM5_INDEX     7
#define SOCKET_FLOWM6_INDEX     8
#define SOCKET_FLOWM7_INDEX     9
#define SOCKET_FLOWM8_INDEX     10
#define SOCKET_FLOWM9_INDEX     11
#define SOCKET_FLOWM10_INDEX    12
#define SOCKET_FLOWM11_INDEX    13
#define SOCKET_FLOWM12_INDEX    14

#define SOCKET_TCP_RETRY_CON_TIMEOUT    5

class FSC_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FSC_MainWindow(QWidget *parent = nullptr);
    ~FSC_MainWindow();

private slots:
    void on_tbnSysDevCheck_clicked();

    void on_tbnManualCheckDev_clicked();

    void on_comboBox_PlotSenSel_currentIndexChanged(const QString &arg1);

    void on_comboBox_SensorTypeName_currentIndexChanged(int index);

    void skt_connect_suc(int i);
    void skt_connect_dis(int i);
    void skt_error(int i);
    void skt_read(int i);

    void mainLoop();

private:
    Ui::FSC_MainWindow *ui;

    void ParaInit(void);
    void PlotInit(void);
    void DataInit(void);
    void SocketInit(void);

    void PlotReplay(const QString &arg1);

    void SendScaleShow(void);
    void SendScaleZero(void);


    bool        sktConed[SOCKET_NUMBER];
    QByteArray  sktBufSend[SOCKET_NUMBER];
    QByteArray  sktBufRev[SOCKET_NUMBER];

    QSignalMapper * sktConMapper;
    QSignalMapper * sktDisconMapper;
    QSignalMapper * sktErrMapper;
    QSignalMapper * sktReadMapper;

    QTimer  *mainLoopTimer = nullptr;

    uint sktConCommandTime[SOCKET_NUMBER];

    double  showScaleSum;
    double  showScaleFlow;
    double  showSTDFMSum;
    double  showSTDFMFlow;
    double  showFMSum[SCALE_NUMBER];
    double  showFMFlow[SCALE_NUMBER];
};

class fsc_para_ini
{

public:

    QString type_name;

    double span_ml_per_min;

    bool    span10_cal[10];
    bool    span10_check[10];
    bool    span10_correct[10];

    QVector <uint> new_cal_pos;
    QVector <uint> new_check_pos;
    QVector <uint> new_correct_pos;

};

class fsc_global
{

public:

    static QVector <fsc_para_ini> para_ini;

    static QTcpSocket *sktTcp[SOCKET_NUMBER];
    static QString ip_PLC;
    static QString ip_RS_Server;
    static quint16 port_number[SOCKET_NUMBER];
    static QString ip[SOCKET_NUMBER];
};



#endif // FSC_MAINWINDOW_H

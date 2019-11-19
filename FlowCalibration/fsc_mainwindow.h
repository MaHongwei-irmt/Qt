#ifndef FSC_MAINWINDOW_H
#define FSC_MAINWINDOW_H

#include <QMainWindow>
#include "dialog_checkdev.h"
#include <QtNetwork>
#include <QSignalMapper>

namespace Ui {
class FSC_MainWindow;
}



#define SOCKET_NUMBER  16

#define SOCKET_PLC_INDEX       0
#define SOCKET_SCALE_INDEX     1
#define SOCKET_STD_FLOWM_INDEX  2
#define SOCKET_FLOWM1_INDEX   3
#define SOCKET_FLOWM2_INDEX   4
#define SOCKET_FLOWM3_INDEX   5
#define SOCKET_FLOWM4_INDEX   6
#define SOCKET_FLOWM5_INDEX   7
#define SOCKET_FLOWM6_INDEX   8
#define SOCKET_FLOWM7_INDEX   9
#define SOCKET_FLOWM8_INDEX   10
#define SOCKET_FLOWM9_INDEX   11
#define SOCKET_FLOWM10_INDEX  12
#define SOCKET_FLOWM11_INDEX  13
#define SOCKET_FLOWM12_INDEX  14


class FSC_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FSC_MainWindow(QWidget *parent = nullptr);
    ~FSC_MainWindow();

    bool sktConed[SOCKET_NUMBER];

private slots:


    void on_tbnSysDevCheck_clicked();

    void on_tbnManualCheckDev_clicked();

    void on_comboBox_PlotSenSel_currentIndexChanged(const QString &arg1);

    void on_comboBox_SensorTypeName_currentIndexChanged(int index);

    void sktScale_connect_suc(int i);
    void sktScale_connect_dis(int i);
    void sktScale_error(QAbstractSocket::SocketError, int i);
    void mainTimerUpdate();


private:
    Ui::FSC_MainWindow *ui;

    void ParaInit();
    void PlotInit();
    void PlotReplay();

    QString ConnectQStringAndNum(QString str, int i);

    QSignalMapper * sktConMapper;
    QSignalMapper * sktDisconMapper;
    QSignalMapper * sktErrMapper;
    QSignalMapper * sktReadMapper;

    QTimer           *mainTimer         = nullptr;

    int sktConCommandTime[SOCKET_NUMBER];


};

class fsc_para_ini
{

 public:

    QString type_name;

    float span_ml_per_min;

    bool span_100_cal;
    bool span_90_cal;
    bool span_80_cal;
    bool span_70_cal;
    bool span_60_cal;
    bool span_50_cal;
    bool span_40_cal;
    bool span_30_cal;
    bool span_20_cal;
    bool span_10_cal;


    bool span_100_check;
    bool span_90_check;
    bool span_80_check;
    bool span_70_check;
    bool span_60_check;
    bool span_50_check;
    bool span_40_check;
    bool span_30_check;
    bool span_20_check;
    bool span_10_check;



    bool span_100_correct;
    bool span_90_correct;
    bool span_80_correct;
    bool span_70_correct;
    bool span_60_correct;
    bool span_50_correct;
    bool span_40_correct;
    bool span_30_correct;
    bool span_20_correct;
    bool span_10_correct;







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
    static int port_number[SOCKET_NUMBER];
};



#endif // FSC_MAINWINDOW_H

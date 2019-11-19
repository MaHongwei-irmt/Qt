/********************************************************************************
** Form generated from reading UI file 'fsc_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FSC_MAINWINDOW_H
#define UI_FSC_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_FSC_MainWindow
{
public:
    QWidget *centralwidget;
    QToolButton *tbnSysDevCheck;
    QLabel *label;
    QComboBox *comboBox_SensorTypeName;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_28;
    QLineEdit *leFlowSpeed_SensorSpan;
    QLabel *label_14;
    QSpacerItem *verticalSpacer_53;
    QSpacerItem *verticalSpacer_54;
    QSpacerItem *horizontalSpacer_33;
    QLabel *lbC_2;
    QLabel *label_2;
    QCheckBox *checkBox_100SpanCal;
    QCheckBox *checkBox_100SpanCheck;
    QLabel *label_3;
    QCheckBox *checkBox_80SpanCal;
    QCheckBox *checkBox_80SpanCheck;
    QLabel *label_4;
    QCheckBox *checkBox_60SpanCal;
    QCheckBox *checkBox_60SpanCheck;
    QLabel *label_5;
    QCheckBox *checkBox_40SpanCal;
    QCheckBox *checkBox_40SpanCheck;
    QLabel *label_6;
    QCheckBox *checkBox_20SpanCal;
    QCheckBox *checkBox_20SpanCheck;
    QCheckBox *checkBox_10SpanCal;
    QCheckBox *checkBox_10SpanCheck;
    QLabel *label_7;
    QLabel *label_8;
    QCheckBox *checkBox_90SpanCal;
    QCheckBox *checkBox_90SpanCheck;
    QCheckBox *checkBox_70SpanCal;
    QCheckBox *checkBox_70SpanCheck;
    QLabel *label_9;
    QCheckBox *checkBox_50SpanCheck;
    QLabel *label_10;
    QCheckBox *checkBox_50SpanCal;
    QCheckBox *checkBox_30SpanCal;
    QCheckBox *checkBox_30SpanCheck;
    QLabel *label_11;
    QTextBrowser *textBrow_sysdev_ckeck_info;
    QToolButton *tbnManualCheckDev;
    QToolButton *tbnSensorType_3;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_12;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QToolButton *tbnSensorType_4;
    QTextBrowser *textBrow_sysdev_ckeck_info_2;
    QLabel *label_16;
    QLineEdit *lineEdit_scale_show_1;
    QLineEdit *lineEdit_scale_show_2;
    QLineEdit *lineEdit_scale_show_4;
    QLineEdit *lineEdit_scale_show_3;
    QLineEdit *lineEdit_scale_show_6;
    QLineEdit *lineEdit_scale_show_5;
    QLineEdit *lineEdit_scale_show_8;
    QLineEdit *lineEdit_scale_show_7;
    QLineEdit *lineEdit_scale_show_12;
    QLineEdit *lineEdit_scale_show_11;
    QLineEdit *lineEdit_scale_show_13;
    QLineEdit *lineEdit_scale_show_9;
    QLineEdit *lineEdit_scale_show;
    QLineEdit *lineEdit_scale_show_10;
    QLabel *label_17;
    QLabel *label_18;
    QLineEdit *lineEdit_scale_show_17;
    QLabel *label_19;
    QLabel *label_20;
    QLineEdit *lineEdit_scale_show_18;
    QLabel *label_15;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *lineEdit_scale_show_19;
    QLabel *label_23;
    QLabel *label_24;
    QCustomPlot *MyCustomPlot;
    QToolButton *tbnSensorType_5;
    QGroupBox *groupBox;
    QComboBox *comboBox_PlotSenSel;
    QFrame *line_6;
    QCheckBox *checkBox_90SpanModify;
    QCheckBox *checkBox_80SpanModify;
    QCheckBox *checkBox_10SpanModify;
    QCheckBox *checkBox_40SpanModify;
    QCheckBox *checkBox_20SpanModify;
    QCheckBox *checkBox_60SpanModify;
    QCheckBox *checkBox_100SpanModify;
    QCheckBox *checkBox_70SpanModify;
    QCheckBox *checkBox_50SpanModify;
    QCheckBox *checkBox_30SpanModify;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FSC_MainWindow)
    {
        if (FSC_MainWindow->objectName().isEmpty())
            FSC_MainWindow->setObjectName(QStringLiteral("FSC_MainWindow"));
        FSC_MainWindow->resize(1165, 866);
        centralwidget = new QWidget(FSC_MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tbnSysDevCheck = new QToolButton(centralwidget);
        tbnSysDevCheck->setObjectName(QStringLiteral("tbnSysDevCheck"));
        tbnSysDevCheck->setGeometry(QRect(30, 547, 121, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 70, 141, 16));
        comboBox_SensorTypeName = new QComboBox(centralwidget);
        comboBox_SensorTypeName->setObjectName(QStringLiteral("comboBox_SensorTypeName"));
        comboBox_SensorTypeName->setEnabled(true);
        comboBox_SensorTypeName->setGeometry(QRect(30, 100, 231, 22));
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 130, 167, 41));
        gridLayout_28 = new QGridLayout(layoutWidget_2);
        gridLayout_28->setObjectName(QStringLiteral("gridLayout_28"));
        gridLayout_28->setContentsMargins(0, 0, 0, 0);
        leFlowSpeed_SensorSpan = new QLineEdit(layoutWidget_2);
        leFlowSpeed_SensorSpan->setObjectName(QStringLiteral("leFlowSpeed_SensorSpan"));
        leFlowSpeed_SensorSpan->setEnabled(true);
        leFlowSpeed_SensorSpan->setReadOnly(true);

        gridLayout_28->addWidget(leFlowSpeed_SensorSpan, 1, 2, 1, 1);

        label_14 = new QLabel(layoutWidget_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_28->addWidget(label_14, 1, 3, 1, 1);

        verticalSpacer_53 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_28->addItem(verticalSpacer_53, 0, 2, 1, 1);

        verticalSpacer_54 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_28->addItem(verticalSpacer_54, 2, 2, 1, 1);

        horizontalSpacer_33 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_28->addItem(horizontalSpacer_33, 1, 1, 1, 1);

        lbC_2 = new QLabel(layoutWidget_2);
        lbC_2->setObjectName(QStringLiteral("lbC_2"));

        gridLayout_28->addWidget(lbC_2, 1, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 180, 61, 16));
        checkBox_100SpanCal = new QCheckBox(centralwidget);
        checkBox_100SpanCal->setObjectName(QStringLiteral("checkBox_100SpanCal"));
        checkBox_100SpanCal->setEnabled(true);
        checkBox_100SpanCal->setGeometry(QRect(100, 180, 51, 16));
        checkBox_100SpanCal->setChecked(true);
        checkBox_100SpanCheck = new QCheckBox(centralwidget);
        checkBox_100SpanCheck->setObjectName(QStringLiteral("checkBox_100SpanCheck"));
        checkBox_100SpanCheck->setEnabled(true);
        checkBox_100SpanCheck->setGeometry(QRect(160, 180, 51, 16));
        checkBox_100SpanCheck->setChecked(true);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 240, 61, 16));
        checkBox_80SpanCal = new QCheckBox(centralwidget);
        checkBox_80SpanCal->setObjectName(QStringLiteral("checkBox_80SpanCal"));
        checkBox_80SpanCal->setEnabled(true);
        checkBox_80SpanCal->setGeometry(QRect(100, 240, 51, 16));
        checkBox_80SpanCal->setChecked(false);
        checkBox_80SpanCheck = new QCheckBox(centralwidget);
        checkBox_80SpanCheck->setObjectName(QStringLiteral("checkBox_80SpanCheck"));
        checkBox_80SpanCheck->setEnabled(true);
        checkBox_80SpanCheck->setGeometry(QRect(160, 240, 51, 16));
        checkBox_80SpanCheck->setChecked(true);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 300, 61, 16));
        checkBox_60SpanCal = new QCheckBox(centralwidget);
        checkBox_60SpanCal->setObjectName(QStringLiteral("checkBox_60SpanCal"));
        checkBox_60SpanCal->setEnabled(true);
        checkBox_60SpanCal->setGeometry(QRect(100, 300, 51, 16));
        checkBox_60SpanCal->setChecked(false);
        checkBox_60SpanCheck = new QCheckBox(centralwidget);
        checkBox_60SpanCheck->setObjectName(QStringLiteral("checkBox_60SpanCheck"));
        checkBox_60SpanCheck->setEnabled(true);
        checkBox_60SpanCheck->setGeometry(QRect(160, 300, 51, 16));
        checkBox_60SpanCheck->setChecked(true);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 360, 61, 16));
        checkBox_40SpanCal = new QCheckBox(centralwidget);
        checkBox_40SpanCal->setObjectName(QStringLiteral("checkBox_40SpanCal"));
        checkBox_40SpanCal->setEnabled(true);
        checkBox_40SpanCal->setGeometry(QRect(100, 360, 51, 16));
        checkBox_40SpanCal->setChecked(false);
        checkBox_40SpanCheck = new QCheckBox(centralwidget);
        checkBox_40SpanCheck->setObjectName(QStringLiteral("checkBox_40SpanCheck"));
        checkBox_40SpanCheck->setEnabled(true);
        checkBox_40SpanCheck->setGeometry(QRect(160, 360, 51, 16));
        checkBox_40SpanCheck->setChecked(true);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 420, 61, 16));
        checkBox_20SpanCal = new QCheckBox(centralwidget);
        checkBox_20SpanCal->setObjectName(QStringLiteral("checkBox_20SpanCal"));
        checkBox_20SpanCal->setEnabled(true);
        checkBox_20SpanCal->setGeometry(QRect(100, 420, 51, 16));
        checkBox_20SpanCal->setChecked(false);
        checkBox_20SpanCheck = new QCheckBox(centralwidget);
        checkBox_20SpanCheck->setObjectName(QStringLiteral("checkBox_20SpanCheck"));
        checkBox_20SpanCheck->setEnabled(true);
        checkBox_20SpanCheck->setGeometry(QRect(160, 420, 51, 16));
        checkBox_20SpanCheck->setChecked(true);
        checkBox_10SpanCal = new QCheckBox(centralwidget);
        checkBox_10SpanCal->setObjectName(QStringLiteral("checkBox_10SpanCal"));
        checkBox_10SpanCal->setEnabled(true);
        checkBox_10SpanCal->setGeometry(QRect(100, 450, 51, 16));
        checkBox_10SpanCal->setChecked(false);
        checkBox_10SpanCheck = new QCheckBox(centralwidget);
        checkBox_10SpanCheck->setObjectName(QStringLiteral("checkBox_10SpanCheck"));
        checkBox_10SpanCheck->setEnabled(true);
        checkBox_10SpanCheck->setGeometry(QRect(160, 450, 51, 16));
        checkBox_10SpanCheck->setChecked(true);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 450, 61, 16));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 210, 61, 16));
        checkBox_90SpanCal = new QCheckBox(centralwidget);
        checkBox_90SpanCal->setObjectName(QStringLiteral("checkBox_90SpanCal"));
        checkBox_90SpanCal->setEnabled(true);
        checkBox_90SpanCal->setGeometry(QRect(100, 210, 51, 16));
        checkBox_90SpanCal->setChecked(false);
        checkBox_90SpanCheck = new QCheckBox(centralwidget);
        checkBox_90SpanCheck->setObjectName(QStringLiteral("checkBox_90SpanCheck"));
        checkBox_90SpanCheck->setEnabled(true);
        checkBox_90SpanCheck->setGeometry(QRect(160, 210, 51, 16));
        checkBox_90SpanCheck->setChecked(false);
        checkBox_70SpanCal = new QCheckBox(centralwidget);
        checkBox_70SpanCal->setObjectName(QStringLiteral("checkBox_70SpanCal"));
        checkBox_70SpanCal->setEnabled(true);
        checkBox_70SpanCal->setGeometry(QRect(100, 270, 51, 16));
        checkBox_70SpanCal->setChecked(false);
        checkBox_70SpanCheck = new QCheckBox(centralwidget);
        checkBox_70SpanCheck->setObjectName(QStringLiteral("checkBox_70SpanCheck"));
        checkBox_70SpanCheck->setEnabled(true);
        checkBox_70SpanCheck->setGeometry(QRect(160, 270, 51, 16));
        checkBox_70SpanCheck->setChecked(false);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 270, 61, 16));
        checkBox_50SpanCheck = new QCheckBox(centralwidget);
        checkBox_50SpanCheck->setObjectName(QStringLiteral("checkBox_50SpanCheck"));
        checkBox_50SpanCheck->setEnabled(true);
        checkBox_50SpanCheck->setGeometry(QRect(160, 330, 51, 16));
        checkBox_50SpanCheck->setChecked(false);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 330, 61, 16));
        checkBox_50SpanCal = new QCheckBox(centralwidget);
        checkBox_50SpanCal->setObjectName(QStringLiteral("checkBox_50SpanCal"));
        checkBox_50SpanCal->setEnabled(true);
        checkBox_50SpanCal->setGeometry(QRect(100, 330, 51, 16));
        checkBox_50SpanCal->setChecked(false);
        checkBox_30SpanCal = new QCheckBox(centralwidget);
        checkBox_30SpanCal->setObjectName(QStringLiteral("checkBox_30SpanCal"));
        checkBox_30SpanCal->setEnabled(true);
        checkBox_30SpanCal->setGeometry(QRect(100, 390, 51, 16));
        checkBox_30SpanCal->setChecked(false);
        checkBox_30SpanCheck = new QCheckBox(centralwidget);
        checkBox_30SpanCheck->setObjectName(QStringLiteral("checkBox_30SpanCheck"));
        checkBox_30SpanCheck->setEnabled(true);
        checkBox_30SpanCheck->setGeometry(QRect(160, 390, 51, 16));
        checkBox_30SpanCheck->setChecked(false);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 390, 61, 16));
        textBrow_sysdev_ckeck_info = new QTextBrowser(centralwidget);
        textBrow_sysdev_ckeck_info->setObjectName(QStringLiteral("textBrow_sysdev_ckeck_info"));
        textBrow_sysdev_ckeck_info->setGeometry(QRect(30, 580, 256, 91));
        tbnManualCheckDev = new QToolButton(centralwidget);
        tbnManualCheckDev->setObjectName(QStringLiteral("tbnManualCheckDev"));
        tbnManualCheckDev->setGeometry(QRect(30, 680, 71, 21));
        tbnSensorType_3 = new QToolButton(centralwidget);
        tbnSensorType_3->setObjectName(QStringLiteral("tbnSensorType_3"));
        tbnSensorType_3->setGeometry(QRect(380, 40, 61, 21));
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(350, 10, 301, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(780, 10, 361, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(690, 10, 61, 16));
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(342, 15, 20, 801));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(350, 780, 791, 71));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(1130, 20, 20, 791));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        tbnSensorType_4 = new QToolButton(centralwidget);
        tbnSensorType_4->setObjectName(QStringLiteral("tbnSensorType_4"));
        tbnSensorType_4->setGeometry(QRect(1040, 40, 61, 21));
        textBrow_sysdev_ckeck_info_2 = new QTextBrowser(centralwidget);
        textBrow_sysdev_ckeck_info_2->setObjectName(QStringLiteral("textBrow_sysdev_ckeck_info_2"));
        textBrow_sysdev_ckeck_info_2->setGeometry(QRect(380, 70, 721, 91));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(380, 255, 111, 16));
        lineEdit_scale_show_1 = new QLineEdit(centralwidget);
        lineEdit_scale_show_1->setObjectName(QStringLiteral("lineEdit_scale_show_1"));
        lineEdit_scale_show_1->setEnabled(true);
        lineEdit_scale_show_1->setGeometry(QRect(490, 255, 71, 20));
        lineEdit_scale_show_1->setLayoutDirection(Qt::LeftToRight);
        lineEdit_scale_show_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_scale_show_1->setReadOnly(true);
        lineEdit_scale_show_2 = new QLineEdit(centralwidget);
        lineEdit_scale_show_2->setObjectName(QStringLiteral("lineEdit_scale_show_2"));
        lineEdit_scale_show_2->setEnabled(true);
        lineEdit_scale_show_2->setGeometry(QRect(570, 255, 71, 20));
        lineEdit_scale_show_2->setLayoutDirection(Qt::LeftToRight);
        lineEdit_scale_show_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_scale_show_2->setReadOnly(true);
        lineEdit_scale_show_4 = new QLineEdit(centralwidget);
        lineEdit_scale_show_4->setObjectName(QStringLiteral("lineEdit_scale_show_4"));
        lineEdit_scale_show_4->setEnabled(true);
        lineEdit_scale_show_4->setGeometry(QRect(730, 255, 71, 20));
        lineEdit_scale_show_4->setLayoutDirection(Qt::LeftToRight);
        lineEdit_scale_show_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_scale_show_4->setReadOnly(true);
        lineEdit_scale_show_3 = new QLineEdit(centralwidget);
        lineEdit_scale_show_3->setObjectName(QStringLiteral("lineEdit_scale_show_3"));
        lineEdit_scale_show_3->setEnabled(true);
        lineEdit_scale_show_3->setGeometry(QRect(650, 255, 71, 20));
        lineEdit_scale_show_3->setLayoutDirection(Qt::LeftToRight);
        lineEdit_scale_show_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_scale_show_3->setReadOnly(true);
        lineEdit_scale_show_6 = new QLineEdit(centralwidget);
        lineEdit_scale_show_6->setObjectName(QStringLiteral("lineEdit_scale_show_6"));
        lineEdit_scale_show_6->setEnabled(true);
        lineEdit_scale_show_6->setGeometry(QRect(890, 255, 71, 20));
        lineEdit_scale_show_6->setLayoutDirection(Qt::LeftToRight);
        lineEdit_scale_show_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_scale_show_6->setReadOnly(true);
        lineEdit_scale_show_5 = new QLineEdit(centralwidget);
        lineEdit_scale_show_5->setObjectName(QStringLiteral("lineEdit_scale_show_5"));
        lineEdit_scale_show_5->setEnabled(true);
        lineEdit_scale_show_5->setGeometry(QRect(810, 255, 71, 20));
        lineEdit_scale_show_5->setLayoutDirection(Qt::LeftToRight);
        lineEdit_scale_show_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_scale_show_5->setReadOnly(true);
        lineEdit_scale_show_8 = new QLineEdit(centralwidget);
        lineEdit_scale_show_8->setObjectName(QStringLiteral("lineEdit_scale_show_8"));
        lineEdit_scale_show_8->setEnabled(true);
        lineEdit_scale_show_8->setGeometry(QRect(570, 280, 71, 20));
        lineEdit_scale_show_8->setLayoutDirection(Qt::LeftToRight);
        lineEdit_scale_show_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_scale_show_8->setReadOnly(true);
        lineEdit_scale_show_7 = new QLineEdit(centralwidget);
        lineEdit_scale_show_7->setObjectName(QStringLiteral("lineEdit_scale_show_7"));
        lineEdit_scale_show_7->setEnabled(true);
        lineEdit_scale_show_7->setGeometry(QRect(490, 280, 71, 20));
        lineEdit_scale_show_7->setLayoutDirection(Qt::LeftToRight);
        lineEdit_scale_show_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_scale_show_7->setReadOnly(true);
        lineEdit_scale_show_12 = new QLineEdit(centralwidget);
        lineEdit_scale_show_12->setObjectName(QStringLiteral("lineEdit_scale_show_12"));
        lineEdit_scale_show_12->setEnabled(true);
        lineEdit_scale_show_12->setGeometry(QRect(810, 280, 71, 20));
        lineEdit_scale_show_12->setLayoutDirection(Qt::LeftToRight);
        lineEdit_scale_show_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_scale_show_12->setReadOnly(true);
        lineEdit_scale_show_11 = new QLineEdit(centralwidget);
        lineEdit_scale_show_11->setObjectName(QStringLiteral("lineEdit_scale_show_11"));
        lineEdit_scale_show_11->setEnabled(true);
        lineEdit_scale_show_11->setGeometry(QRect(730, 280, 71, 20));
        lineEdit_scale_show_11->setLayoutDirection(Qt::LeftToRight);
        lineEdit_scale_show_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_scale_show_11->setReadOnly(true);
        lineEdit_scale_show_13 = new QLineEdit(centralwidget);
        lineEdit_scale_show_13->setObjectName(QStringLiteral("lineEdit_scale_show_13"));
        lineEdit_scale_show_13->setEnabled(true);
        lineEdit_scale_show_13->setGeometry(QRect(890, 280, 71, 20));
        lineEdit_scale_show_13->setLayoutDirection(Qt::LeftToRight);
        lineEdit_scale_show_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_scale_show_13->setReadOnly(true);
        lineEdit_scale_show_9 = new QLineEdit(centralwidget);
        lineEdit_scale_show_9->setObjectName(QStringLiteral("lineEdit_scale_show_9"));
        lineEdit_scale_show_9->setEnabled(true);
        lineEdit_scale_show_9->setGeometry(QRect(650, 280, 71, 20));
        lineEdit_scale_show_9->setLayoutDirection(Qt::LeftToRight);
        lineEdit_scale_show_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_scale_show_9->setReadOnly(true);
        lineEdit_scale_show = new QLineEdit(centralwidget);
        lineEdit_scale_show->setObjectName(QStringLiteral("lineEdit_scale_show"));
        lineEdit_scale_show->setEnabled(true);
        lineEdit_scale_show->setGeometry(QRect(452, 179, 101, 20));
        lineEdit_scale_show->setLayoutDirection(Qt::LeftToRight);
        lineEdit_scale_show->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_scale_show->setReadOnly(true);
        lineEdit_scale_show_10 = new QLineEdit(centralwidget);
        lineEdit_scale_show_10->setObjectName(QStringLiteral("lineEdit_scale_show_10"));
        lineEdit_scale_show_10->setEnabled(true);
        lineEdit_scale_show_10->setGeometry(QRect(452, 204, 101, 20));
        lineEdit_scale_show_10->setLayoutDirection(Qt::LeftToRight);
        lineEdit_scale_show_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_scale_show_10->setReadOnly(true);
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(380, 207, 71, 16));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(380, 182, 61, 16));
        lineEdit_scale_show_17 = new QLineEdit(centralwidget);
        lineEdit_scale_show_17->setObjectName(QStringLiteral("lineEdit_scale_show_17"));
        lineEdit_scale_show_17->setEnabled(true);
        lineEdit_scale_show_17->setGeometry(QRect(680, 179, 101, 20));
        lineEdit_scale_show_17->setLayoutDirection(Qt::LeftToRight);
        lineEdit_scale_show_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_scale_show_17->setReadOnly(true);
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(590, 182, 81, 16));
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(890, 185, 81, 16));
        lineEdit_scale_show_18 = new QLineEdit(centralwidget);
        lineEdit_scale_show_18->setObjectName(QStringLiteral("lineEdit_scale_show_18"));
        lineEdit_scale_show_18->setEnabled(true);
        lineEdit_scale_show_18->setGeometry(QRect(980, 182, 101, 20));
        lineEdit_scale_show_18->setLayoutDirection(Qt::LeftToRight);
        lineEdit_scale_show_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_scale_show_18->setReadOnly(true);
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(790, 182, 36, 20));
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(1090, 182, 36, 20));
        label_22 = new QLabel(centralwidget);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(560, 205, 36, 20));
        lineEdit_scale_show_19 = new QLineEdit(centralwidget);
        lineEdit_scale_show_19->setObjectName(QStringLiteral("lineEdit_scale_show_19"));
        lineEdit_scale_show_19->setEnabled(true);
        lineEdit_scale_show_19->setGeometry(QRect(742, 204, 101, 20));
        lineEdit_scale_show_19->setLayoutDirection(Qt::LeftToRight);
        lineEdit_scale_show_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_scale_show_19->setReadOnly(true);
        label_23 = new QLabel(centralwidget);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(850, 205, 36, 20));
        label_24 = new QLabel(centralwidget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(620, 207, 121, 16));
        MyCustomPlot = new QCustomPlot(centralwidget);
        MyCustomPlot->setObjectName(QStringLiteral("MyCustomPlot"));
        MyCustomPlot->setGeometry(QRect(390, 330, 711, 471));
        tbnSensorType_5 = new QToolButton(MyCustomPlot);
        tbnSensorType_5->setObjectName(QStringLiteral("tbnSensorType_5"));
        tbnSensorType_5->setGeometry(QRect(0, 450, 111, 21));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(380, 310, 731, 501));
        comboBox_PlotSenSel = new QComboBox(centralwidget);
        comboBox_PlotSenSel->setObjectName(QStringLiteral("comboBox_PlotSenSel"));
        comboBox_PlotSenSel->setGeometry(QRect(1010, 304, 91, 22));
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(30, 500, 301, 16));
        line_6->setStyleSheet(QStringLiteral(""));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        checkBox_90SpanModify = new QCheckBox(centralwidget);
        checkBox_90SpanModify->setObjectName(QStringLiteral("checkBox_90SpanModify"));
        checkBox_90SpanModify->setEnabled(true);
        checkBox_90SpanModify->setGeometry(QRect(220, 210, 51, 16));
        checkBox_90SpanModify->setChecked(false);
        checkBox_80SpanModify = new QCheckBox(centralwidget);
        checkBox_80SpanModify->setObjectName(QStringLiteral("checkBox_80SpanModify"));
        checkBox_80SpanModify->setEnabled(true);
        checkBox_80SpanModify->setGeometry(QRect(220, 240, 51, 16));
        checkBox_80SpanModify->setChecked(false);
        checkBox_10SpanModify = new QCheckBox(centralwidget);
        checkBox_10SpanModify->setObjectName(QStringLiteral("checkBox_10SpanModify"));
        checkBox_10SpanModify->setEnabled(true);
        checkBox_10SpanModify->setGeometry(QRect(220, 450, 51, 16));
        checkBox_10SpanModify->setChecked(true);
        checkBox_40SpanModify = new QCheckBox(centralwidget);
        checkBox_40SpanModify->setObjectName(QStringLiteral("checkBox_40SpanModify"));
        checkBox_40SpanModify->setEnabled(true);
        checkBox_40SpanModify->setGeometry(QRect(220, 360, 51, 16));
        checkBox_40SpanModify->setChecked(false);
        checkBox_20SpanModify = new QCheckBox(centralwidget);
        checkBox_20SpanModify->setObjectName(QStringLiteral("checkBox_20SpanModify"));
        checkBox_20SpanModify->setEnabled(true);
        checkBox_20SpanModify->setGeometry(QRect(220, 420, 51, 16));
        checkBox_20SpanModify->setChecked(true);
        checkBox_60SpanModify = new QCheckBox(centralwidget);
        checkBox_60SpanModify->setObjectName(QStringLiteral("checkBox_60SpanModify"));
        checkBox_60SpanModify->setEnabled(true);
        checkBox_60SpanModify->setGeometry(QRect(220, 300, 51, 16));
        checkBox_60SpanModify->setChecked(false);
        checkBox_100SpanModify = new QCheckBox(centralwidget);
        checkBox_100SpanModify->setObjectName(QStringLiteral("checkBox_100SpanModify"));
        checkBox_100SpanModify->setEnabled(true);
        checkBox_100SpanModify->setGeometry(QRect(220, 180, 51, 16));
        checkBox_100SpanModify->setChecked(false);
        checkBox_70SpanModify = new QCheckBox(centralwidget);
        checkBox_70SpanModify->setObjectName(QStringLiteral("checkBox_70SpanModify"));
        checkBox_70SpanModify->setEnabled(true);
        checkBox_70SpanModify->setGeometry(QRect(220, 270, 51, 16));
        checkBox_70SpanModify->setChecked(false);
        checkBox_50SpanModify = new QCheckBox(centralwidget);
        checkBox_50SpanModify->setObjectName(QStringLiteral("checkBox_50SpanModify"));
        checkBox_50SpanModify->setEnabled(true);
        checkBox_50SpanModify->setGeometry(QRect(220, 330, 51, 16));
        checkBox_50SpanModify->setChecked(false);
        checkBox_30SpanModify = new QCheckBox(centralwidget);
        checkBox_30SpanModify->setObjectName(QStringLiteral("checkBox_30SpanModify"));
        checkBox_30SpanModify->setEnabled(true);
        checkBox_30SpanModify->setGeometry(QRect(220, 390, 51, 16));
        checkBox_30SpanModify->setChecked(false);
        FSC_MainWindow->setCentralWidget(centralwidget);
        groupBox->raise();
        tbnSysDevCheck->raise();
        label->raise();
        comboBox_SensorTypeName->raise();
        layoutWidget_2->raise();
        label_2->raise();
        checkBox_100SpanCal->raise();
        checkBox_100SpanCheck->raise();
        label_3->raise();
        checkBox_80SpanCal->raise();
        checkBox_80SpanCheck->raise();
        label_4->raise();
        checkBox_60SpanCal->raise();
        checkBox_60SpanCheck->raise();
        label_5->raise();
        checkBox_40SpanCal->raise();
        checkBox_40SpanCheck->raise();
        label_6->raise();
        checkBox_20SpanCal->raise();
        checkBox_20SpanCheck->raise();
        checkBox_10SpanCal->raise();
        checkBox_10SpanCheck->raise();
        label_7->raise();
        label_8->raise();
        checkBox_90SpanCal->raise();
        checkBox_90SpanCheck->raise();
        checkBox_70SpanCal->raise();
        checkBox_70SpanCheck->raise();
        label_9->raise();
        checkBox_50SpanCheck->raise();
        label_10->raise();
        checkBox_50SpanCal->raise();
        checkBox_30SpanCal->raise();
        checkBox_30SpanCheck->raise();
        label_11->raise();
        textBrow_sysdev_ckeck_info->raise();
        tbnManualCheckDev->raise();
        tbnSensorType_3->raise();
        line->raise();
        line_2->raise();
        label_12->raise();
        line_3->raise();
        line_4->raise();
        line_5->raise();
        tbnSensorType_4->raise();
        textBrow_sysdev_ckeck_info_2->raise();
        label_16->raise();
        lineEdit_scale_show_1->raise();
        lineEdit_scale_show_2->raise();
        lineEdit_scale_show_4->raise();
        lineEdit_scale_show_3->raise();
        lineEdit_scale_show_6->raise();
        lineEdit_scale_show_5->raise();
        lineEdit_scale_show_8->raise();
        lineEdit_scale_show_7->raise();
        lineEdit_scale_show_12->raise();
        lineEdit_scale_show_11->raise();
        lineEdit_scale_show_13->raise();
        lineEdit_scale_show_9->raise();
        lineEdit_scale_show->raise();
        lineEdit_scale_show_10->raise();
        label_17->raise();
        label_18->raise();
        lineEdit_scale_show_17->raise();
        label_19->raise();
        label_20->raise();
        lineEdit_scale_show_18->raise();
        label_15->raise();
        label_21->raise();
        label_22->raise();
        lineEdit_scale_show_19->raise();
        label_23->raise();
        label_24->raise();
        MyCustomPlot->raise();
        comboBox_PlotSenSel->raise();
        line_6->raise();
        checkBox_90SpanModify->raise();
        checkBox_80SpanModify->raise();
        checkBox_10SpanModify->raise();
        checkBox_40SpanModify->raise();
        checkBox_20SpanModify->raise();
        checkBox_60SpanModify->raise();
        checkBox_100SpanModify->raise();
        checkBox_70SpanModify->raise();
        checkBox_50SpanModify->raise();
        checkBox_30SpanModify->raise();
        menubar = new QMenuBar(FSC_MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1165, 23));
        FSC_MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(FSC_MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        FSC_MainWindow->setStatusBar(statusbar);

        retranslateUi(FSC_MainWindow);

        QMetaObject::connectSlotsByName(FSC_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FSC_MainWindow)
    {
        FSC_MainWindow->setWindowTitle(QApplication::translate("FSC_MainWindow", "\346\265\201\351\207\217\344\274\240\346\204\237\345\231\250\346\240\207\345\256\232\350\275\257\344\273\266", Q_NULLPTR));
        tbnSysDevCheck->setText(QApplication::translate("FSC_MainWindow", "\350\207\252\345\212\250\346\243\200\346\237\245\347\263\273\347\273\237\350\256\276\345\244\207", Q_NULLPTR));
        label->setText(QApplication::translate("FSC_MainWindow", "\351\200\211\346\213\251\345\276\205\346\240\207\345\256\232\344\274\240\346\204\237\345\231\250\345\236\213\345\217\267\357\274\232", Q_NULLPTR));
        label_14->setText(QApplication::translate("FSC_MainWindow", "ml/min", Q_NULLPTR));
        lbC_2->setText(QApplication::translate("FSC_MainWindow", "\351\207\217\347\250\213\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("FSC_MainWindow", "100%\351\207\217\347\250\213\357\274\232", Q_NULLPTR));
        checkBox_100SpanCal->setText(QApplication::translate("FSC_MainWindow", "\346\240\207\345\256\232", Q_NULLPTR));
        checkBox_100SpanCheck->setText(QApplication::translate("FSC_MainWindow", "\351\252\214\350\257\201", Q_NULLPTR));
        label_3->setText(QApplication::translate("FSC_MainWindow", "80%\351\207\217\347\250\213\357\274\232", Q_NULLPTR));
        checkBox_80SpanCal->setText(QApplication::translate("FSC_MainWindow", "\346\240\207\345\256\232", Q_NULLPTR));
        checkBox_80SpanCheck->setText(QApplication::translate("FSC_MainWindow", "\351\252\214\350\257\201", Q_NULLPTR));
        label_4->setText(QApplication::translate("FSC_MainWindow", "60%\351\207\217\347\250\213\357\274\232", Q_NULLPTR));
        checkBox_60SpanCal->setText(QApplication::translate("FSC_MainWindow", "\346\240\207\345\256\232", Q_NULLPTR));
        checkBox_60SpanCheck->setText(QApplication::translate("FSC_MainWindow", "\351\252\214\350\257\201", Q_NULLPTR));
        label_5->setText(QApplication::translate("FSC_MainWindow", "40%\351\207\217\347\250\213\357\274\232", Q_NULLPTR));
        checkBox_40SpanCal->setText(QApplication::translate("FSC_MainWindow", "\346\240\207\345\256\232", Q_NULLPTR));
        checkBox_40SpanCheck->setText(QApplication::translate("FSC_MainWindow", "\351\252\214\350\257\201", Q_NULLPTR));
        label_6->setText(QApplication::translate("FSC_MainWindow", "20%\351\207\217\347\250\213\357\274\232", Q_NULLPTR));
        checkBox_20SpanCal->setText(QApplication::translate("FSC_MainWindow", "\346\240\207\345\256\232", Q_NULLPTR));
        checkBox_20SpanCheck->setText(QApplication::translate("FSC_MainWindow", "\351\252\214\350\257\201", Q_NULLPTR));
        checkBox_10SpanCal->setText(QApplication::translate("FSC_MainWindow", "\346\240\207\345\256\232", Q_NULLPTR));
        checkBox_10SpanCheck->setText(QApplication::translate("FSC_MainWindow", "\351\252\214\350\257\201", Q_NULLPTR));
        label_7->setText(QApplication::translate("FSC_MainWindow", "10%\351\207\217\347\250\213\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("FSC_MainWindow", "90%\351\207\217\347\250\213\357\274\232", Q_NULLPTR));
        checkBox_90SpanCal->setText(QApplication::translate("FSC_MainWindow", "\346\240\207\345\256\232", Q_NULLPTR));
        checkBox_90SpanCheck->setText(QApplication::translate("FSC_MainWindow", "\351\252\214\350\257\201", Q_NULLPTR));
        checkBox_70SpanCal->setText(QApplication::translate("FSC_MainWindow", "\346\240\207\345\256\232", Q_NULLPTR));
        checkBox_70SpanCheck->setText(QApplication::translate("FSC_MainWindow", "\351\252\214\350\257\201", Q_NULLPTR));
        label_9->setText(QApplication::translate("FSC_MainWindow", "70%\351\207\217\347\250\213\357\274\232", Q_NULLPTR));
        checkBox_50SpanCheck->setText(QApplication::translate("FSC_MainWindow", "\351\252\214\350\257\201", Q_NULLPTR));
        label_10->setText(QApplication::translate("FSC_MainWindow", "50%\351\207\217\347\250\213\357\274\232", Q_NULLPTR));
        checkBox_50SpanCal->setText(QApplication::translate("FSC_MainWindow", "\346\240\207\345\256\232", Q_NULLPTR));
        checkBox_30SpanCal->setText(QApplication::translate("FSC_MainWindow", "\346\240\207\345\256\232", Q_NULLPTR));
        checkBox_30SpanCheck->setText(QApplication::translate("FSC_MainWindow", "\351\252\214\350\257\201", Q_NULLPTR));
        label_11->setText(QApplication::translate("FSC_MainWindow", "30%\351\207\217\347\250\213\357\274\232", Q_NULLPTR));
        textBrow_sysdev_ckeck_info->setHtml(QApplication::translate("FSC_MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">10:21:23 \346\211\223\345\274\200\350\277\233\346\260\264\351\230\200</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">10:21:26 \346\211\223\345\274\200\346\260\264\346\263\265</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">...</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">....</p>\n"
"<p style=\"-qt-paragraph-type:empty; ma"
                        "rgin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-ri"
                        "ght:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">AsasaSAS</p>\n"
"<p style=\" margin-"
                        "top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">A</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">S</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">asasaSA</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">ssaS</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">AsasaSA</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">sasaasA</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">SS</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; tex"
                        "t-indent:0px;\">asasA</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">S</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">AsaSasaa</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">SsaS</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">A</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        tbnManualCheckDev->setText(QApplication::translate("FSC_MainWindow", "\346\211\213\345\212\250\346\243\200\346\237\245", Q_NULLPTR));
        tbnSensorType_3->setText(QApplication::translate("FSC_MainWindow", "\345\274\200\345\247\213", Q_NULLPTR));
        label_12->setText(QApplication::translate("FSC_MainWindow", "\350\207\252\345\212\250\346\240\207\345\256\232", Q_NULLPTR));
        tbnSensorType_4->setText(QApplication::translate("FSC_MainWindow", "\347\273\210\346\255\242", Q_NULLPTR));
        textBrow_sysdev_ckeck_info_2->setHtml(QApplication::translate("FSC_MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">10:21:20 \345\220\257\345\212\250\346\240\207\345\256\232</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">10:21:23 \346\211\223\345\274\200\350\277\233\346\260\264\351\230\200</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">10:21:26 \346\211\223\345\274\200\346\260\264\346\263\265</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\""
                        ">...</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">....</p></body></html>", Q_NULLPTR));
        label_16->setText(QApplication::translate("FSC_MainWindow", "\345\276\205\346\240\207\345\256\232\344\274\240\346\204\237\345\231\250\346\230\276\347\244\272\357\274\232", Q_NULLPTR));
        lineEdit_scale_show_1->setText(QApplication::translate("FSC_MainWindow", "-22100.123", Q_NULLPTR));
        lineEdit_scale_show_2->setText(QApplication::translate("FSC_MainWindow", "0.1", Q_NULLPTR));
        lineEdit_scale_show_4->setText(QApplication::translate("FSC_MainWindow", "0.1", Q_NULLPTR));
        lineEdit_scale_show_3->setText(QApplication::translate("FSC_MainWindow", "0.1", Q_NULLPTR));
        lineEdit_scale_show_6->setText(QApplication::translate("FSC_MainWindow", "0.1", Q_NULLPTR));
        lineEdit_scale_show_5->setText(QApplication::translate("FSC_MainWindow", "0.1", Q_NULLPTR));
        lineEdit_scale_show_8->setText(QApplication::translate("FSC_MainWindow", "0.1", Q_NULLPTR));
        lineEdit_scale_show_7->setText(QApplication::translate("FSC_MainWindow", "0.1", Q_NULLPTR));
        lineEdit_scale_show_12->setText(QApplication::translate("FSC_MainWindow", "0.1", Q_NULLPTR));
        lineEdit_scale_show_11->setText(QApplication::translate("FSC_MainWindow", "0.1", Q_NULLPTR));
        lineEdit_scale_show_13->setText(QApplication::translate("FSC_MainWindow", "0.1", Q_NULLPTR));
        lineEdit_scale_show_9->setText(QApplication::translate("FSC_MainWindow", "0.1", Q_NULLPTR));
        lineEdit_scale_show->setText(QApplication::translate("FSC_MainWindow", "0.1", Q_NULLPTR));
        lineEdit_scale_show_10->setText(QApplication::translate("FSC_MainWindow", "0.1", Q_NULLPTR));
        label_17->setText(QApplication::translate("FSC_MainWindow", "\346\240\207\345\207\206\346\265\201\351\207\217\350\256\241\357\274\232", Q_NULLPTR));
        label_18->setText(QApplication::translate("FSC_MainWindow", "\345\244\251\345\271\263\346\230\276\347\244\272\357\274\232", Q_NULLPTR));
        lineEdit_scale_show_17->setText(QApplication::translate("FSC_MainWindow", "0.1", Q_NULLPTR));
        label_19->setText(QApplication::translate("FSC_MainWindow", "\345\244\251\345\271\263\350\256\241\347\256\227\346\265\201\351\200\237\357\274\232", Q_NULLPTR));
        label_20->setText(QApplication::translate("FSC_MainWindow", "\345\244\251\345\271\263\347\264\257\350\256\241\346\265\201\351\207\217\357\274\232", Q_NULLPTR));
        lineEdit_scale_show_18->setText(QApplication::translate("FSC_MainWindow", "0.1", Q_NULLPTR));
        label_15->setText(QApplication::translate("FSC_MainWindow", "ml/min", Q_NULLPTR));
        label_21->setText(QApplication::translate("FSC_MainWindow", "ml", Q_NULLPTR));
        label_22->setText(QApplication::translate("FSC_MainWindow", "ml/min", Q_NULLPTR));
        lineEdit_scale_show_19->setText(QApplication::translate("FSC_MainWindow", "0.1", Q_NULLPTR));
        label_23->setText(QApplication::translate("FSC_MainWindow", "ml", Q_NULLPTR));
        label_24->setText(QApplication::translate("FSC_MainWindow", "\346\240\207\345\207\206\346\265\201\351\207\217\350\256\241\347\264\257\350\256\241\346\265\201\351\207\217\357\274\232", Q_NULLPTR));
        tbnSensorType_5->setText(QApplication::translate("FSC_MainWindow", "\346\237\245\347\234\213\346\240\207\345\256\232\346\212\245\345\221\212", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("FSC_MainWindow", "\345\217\230\345\214\226\346\233\262\347\272\277", Q_NULLPTR));
        comboBox_PlotSenSel->clear();
        comboBox_PlotSenSel->insertItems(0, QStringList()
         << QApplication::translate("FSC_MainWindow", "\344\274\240\346\204\237\345\231\2501", Q_NULLPTR)
         << QApplication::translate("FSC_MainWindow", "\344\274\240\346\204\237\345\231\2502", Q_NULLPTR)
         << QApplication::translate("FSC_MainWindow", "\344\274\240\346\204\237\345\231\2503", Q_NULLPTR)
         << QApplication::translate("FSC_MainWindow", "\344\274\240\346\204\237\345\231\2504", Q_NULLPTR)
         << QApplication::translate("FSC_MainWindow", "\344\274\240\346\204\237\345\231\2505", Q_NULLPTR)
         << QApplication::translate("FSC_MainWindow", "\344\274\240\346\204\237\345\231\2506", Q_NULLPTR)
         << QApplication::translate("FSC_MainWindow", "\344\274\240\346\204\237\345\231\2507", Q_NULLPTR)
         << QApplication::translate("FSC_MainWindow", "\344\274\240\346\204\237\345\231\2508", Q_NULLPTR)
         << QApplication::translate("FSC_MainWindow", "\344\274\240\346\204\237\345\231\2509", Q_NULLPTR)
         << QApplication::translate("FSC_MainWindow", "\344\274\240\346\204\237\345\231\25010", Q_NULLPTR)
         << QApplication::translate("FSC_MainWindow", "\344\274\240\346\204\237\345\231\25011", Q_NULLPTR)
         << QApplication::translate("FSC_MainWindow", "\344\274\240\346\204\237\345\231\25012", Q_NULLPTR)
        );
        checkBox_90SpanModify->setText(QApplication::translate("FSC_MainWindow", "\344\277\256\346\255\243", Q_NULLPTR));
        checkBox_80SpanModify->setText(QApplication::translate("FSC_MainWindow", "\344\277\256\346\255\243", Q_NULLPTR));
        checkBox_10SpanModify->setText(QApplication::translate("FSC_MainWindow", "\344\277\256\346\255\243", Q_NULLPTR));
        checkBox_40SpanModify->setText(QApplication::translate("FSC_MainWindow", "\344\277\256\346\255\243", Q_NULLPTR));
        checkBox_20SpanModify->setText(QApplication::translate("FSC_MainWindow", "\344\277\256\346\255\243", Q_NULLPTR));
        checkBox_60SpanModify->setText(QApplication::translate("FSC_MainWindow", "\344\277\256\346\255\243", Q_NULLPTR));
        checkBox_100SpanModify->setText(QApplication::translate("FSC_MainWindow", "\344\277\256\346\255\243", Q_NULLPTR));
        checkBox_70SpanModify->setText(QApplication::translate("FSC_MainWindow", "\344\277\256\346\255\243", Q_NULLPTR));
        checkBox_50SpanModify->setText(QApplication::translate("FSC_MainWindow", "\344\277\256\346\255\243", Q_NULLPTR));
        checkBox_30SpanModify->setText(QApplication::translate("FSC_MainWindow", "\344\277\256\346\255\243", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FSC_MainWindow: public Ui_FSC_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FSC_MAINWINDOW_H

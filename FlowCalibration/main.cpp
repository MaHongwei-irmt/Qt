#include "FSC_MainWindow.h"
#include "FCMainWindow.h"
#include <QApplication>


void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    static QMutex mutex;
    mutex.lock();
    QString text;

    switch(type)
    {

    case QtDebugMsg:
        text = QString("Debug:");
        break;
    case QtWarningMsg:
        text = QString("Warning:");
        break;
    case QtCriticalMsg:
        text = QString("Critical:");
        break;
    case QtFatalMsg:
        text = QString("Fatal:");
        break;
    case QtInfoMsg:
        text = QString("Info:");
        break;
    }

    QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
    QString message = QString("%1 %2 %3").arg(text).arg(context_info).arg(msg);
    QString current_date = QDateTime::currentDateTime().toString("yyyy-MM");

    QFile file(current_date + "-log.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream << message << "\r\n";
    file.flush();
    file.close();
    mutex.unlock();
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FSC_MainWindow w;
    w.setWindowFlags(Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
    w.show();

    qInstallMessageHandler(outputMessage);
    qDebug() << "\r\nstart";

    return a.exec();
}


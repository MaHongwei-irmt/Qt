#include "FSC_MainWindow.h"
#include "FCMainWindow.h"
#include <QApplication>


void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    static QMutex mutex;
    mutex.lock();

    (void)type;

    QString context_info = QString("%1:%2:").arg(QString(context.file)).arg(context.line);
    QString message = QString("%1 %2").arg(context_info).arg(msg);
    QString current_date = QDateTime::currentDateTime().toString("yyyy-MM-dd");

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

    qInstallMessageHandler(outputMessage);
    FSCLOG << "\r\nstart";

    FSC_MainWindow w;
    w.setWindowFlags(Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
    w.show();

    return a.exec();
}


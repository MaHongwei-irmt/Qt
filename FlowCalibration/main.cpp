#include "FSC_MainWindow.h"
#include "FCMainWindow.h"
#include <QApplication>
#include <windows.h>


void mainloop(FSC_MainWindow *mw);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FSC_MainWindow w;
    w.setWindowFlags(Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
    //w.setFixedSize(w.width(),w.height());
    w.show();

    Sleep(1000);

    //while(1)
    {
          mainloop(&w);
    }

    return a.exec();
}

void mainloop(FSC_MainWindow *mw)
{
    Sleep(1000);
    static int j = 0;

    for (int i = 0; i < SOCKET_NUMBER; i++)
    {
        if (! mw->sktConed[i])
        {
            //fsc_global::sktTcp[i]->abort();
            //fsc_global::sktTcp[i]->connectToHost(QHostAddress(fsc_global::ip_RS_Server), fsc_global::port_number[i]);

             qDebug() <<QString::number(j++);
        }
    }

}

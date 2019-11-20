#include "FSC_MainWindow.h"
#include "FCMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FSC_MainWindow w;
    w.setWindowFlags(Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
    w.setFixedSize(w.width(),w.height());
    w.show();

    return a.exec();
}

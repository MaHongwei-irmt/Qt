#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_2_released()
{
    this->ui->label->setText("123455");

    dialog = new Dialog(this);


    dialog->setModal(false);
    dialog->show();

    //this->close();
}

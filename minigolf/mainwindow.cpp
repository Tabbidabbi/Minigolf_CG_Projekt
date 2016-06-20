#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->power->setRange(0,100);
     ui->shootAngle->setRange(-180,180);




      connect(ui->shootAngle, SIGNAL(valueChanged(int)), ui->glwidget, SLOT(setShootAngle(int)));
      connect(ui->power, SIGNAL(valueChanged(int)), ui->glwidget, SLOT(setPower(int)));



}

MainWindow::~MainWindow()
{
    delete ui;
}



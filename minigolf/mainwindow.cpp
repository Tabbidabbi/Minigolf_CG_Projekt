#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->power->setRange(0,100);


      connect(ui->zoom, SIGNAL(valueChanged(int)), ui->glwidget, SLOT(setZoom(int)));
      connect(ui->power, SIGNAL(valueChanged(int)), ui->glwidget, SLOT(setPower(int)));



}

MainWindow::~MainWindow()
{
    delete ui;
}



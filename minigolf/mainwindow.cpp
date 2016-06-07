#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

      connect(ui->zoom, SIGNAL(valueChanged(int)), ui->glwidget, SLOT(setZoom(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "./front/GUI/windowsearch.ui"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_start_clicked() {
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_logIn.h"
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->start, &QPushButton::clicked, this, &MainWindow::on_start_clicked);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_start_clicked() {
    QDialog loginDialog(this);
    Ui::logIn loginUI;


    connect(&loginDialog, &QDialog::finished, &loginDialog, &QDialog::deleteLater);
    loginUI.setupUi(&loginDialog);
    loginDialog.exec();
}


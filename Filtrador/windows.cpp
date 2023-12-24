#include "windows.h"
#include "ui_windows.h"

windows::windows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::windows)
{
    ui->setupUi(this);
}

windows::~windows()
{
    delete ui;
}

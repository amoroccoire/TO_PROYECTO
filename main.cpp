#include "mainwindow.h"
#include "./front/search/windowsearch.h"
#include "./front/upload/windowupload.h"
#include "./login/login.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login w;
    w.show();
    return a.exec();
}

#include "mainwindow.h"
#include "./front/search/windowsearch.h"
#include "./front/upload/windowupload.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    windowSearch m;
    WindowUpload r;
    //MainWindow w;
    m.show();
    //r.show();
    return a.exec();
}

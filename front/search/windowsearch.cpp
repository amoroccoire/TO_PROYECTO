#include "windowsearch.h"
#include "ui_windowsearch.h"
#include "../upload/windowupload.h"
#include "ui_windowupload.h"

windowSearch::windowSearch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::windowSearch)
{
    ui->setupUi(this);
    //inicialitation();
}

windowSearch::~windowSearch()
{
    delete ui;
}

void windowSearch::inicialitation() {

}

void windowSearch::on_importarCSV_clicked()
{
    WindowUpload* windowUpload = new WindowUpload();
    windowUpload->show();
}


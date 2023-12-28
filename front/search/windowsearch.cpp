#include "windowsearch.h"
#include "ui_windowsearch.h"
#include <QHeaderView>
#include <QComboBox>
#include <QTableWidget>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>

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

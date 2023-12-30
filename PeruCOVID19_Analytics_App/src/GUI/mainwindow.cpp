#include "../../includes/GUI/mainwindow.h"
#include "../../ui/GUI/ui_mainwindow.h"
#include "../../src/GUI/estadisticas/porDepartamento/formestadisticasdepartamento.h"
#include "../../src/GUI/estadisticas/porSexo/formestadisticassexo.h"
#include "../../src/GUI/estadisticas/porResultado/formestadisticaresultado.h"
#include "../../src/GUI/estadisticas/porTipoMuestra/formestadisticatipomuestra.h"

// En el encabezado de tu clase MainWindow

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    FormEstadisticasdepartamento *formEstadisticasDepartamento = new FormEstadisticasdepartamento(nullptr);

    formEstadisticasDepartamento->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    FormEstadisticasSexo *formEstadisticasSexo = new FormEstadisticasSexo(nullptr);
    formEstadisticasSexo->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    FormEstadisticaResultado *formEstadisticaResultado = new FormEstadisticaResultado(nullptr);
    formEstadisticaResultado->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    FormEstadisticaTipoMuestra *formEstadisticaMuestra = new FormEstadisticaTipoMuestra(nullptr);
    formEstadisticaMuestra->show();
}


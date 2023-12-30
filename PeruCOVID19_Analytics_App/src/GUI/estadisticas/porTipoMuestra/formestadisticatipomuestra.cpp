// #include "formestadisticatipomuestra.h"
// #include "ui_formestadisticatipomuestra.h"

// FormEstadisticaTipoMuestra::FormEstadisticaTipoMuestra(QWidget *parent)
//     : QWidget(parent)
//     , ui(new Ui::FormEstadisticaTipoMuestra)
// {
//     ui->setupUi(this);
// }

// FormEstadisticaTipoMuestra::~FormEstadisticaTipoMuestra()
// {
//     delete ui;
// }

#include "formestadisticatipomuestra.h"
#include "ui_formestadisticatipomuestra.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

FormEstadisticaTipoMuestra::FormEstadisticaTipoMuestra(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::FormEstadisticaTipoMuestra)
{
    ui->setupUi(this);

    // Crear el gráfico de tipo pie
    QChart *pieChart = new QChart;
    QPieSeries *pieSeries = new QPieSeries;

    // Datos para el gráfico de tipo pie
    QStringList tiposMuestra = {"LAVADO BRONCOALVEOLAR", "HISOPADO NASAL Y FARINGEO"};
    QList<int> cantidades = {1858, 1046626};

    for (int i = 0; i < tiposMuestra.size(); ++i) {
        QPieSlice *slice = pieSeries->append(tiposMuestra[i], cantidades[i]);
        slice->setLabel(QString("%1: %2").arg(tiposMuestra[i]).arg(cantidades[i]));
    }

    pieChart->addSeries(pieSeries);
    pieChart->setTitle("Gráfico de Tipo de Muestra");

    QChartView *pieChartView = new QChartView(pieChart);
    ui->verticalLayout->addWidget(pieChartView);
}

FormEstadisticaTipoMuestra::~FormEstadisticaTipoMuestra()
{
    delete ui;
}


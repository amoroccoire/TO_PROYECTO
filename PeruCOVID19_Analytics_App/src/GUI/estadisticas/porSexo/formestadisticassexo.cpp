// #include "formestadisticassexo.h"
// #include "ui_formestadisticassexo.h"

// FormEstadisticasSexo::FormEstadisticasSexo(QWidget *parent)
//     : QWidget(parent)
//     , ui(new Ui::FormEstadisticasSexo)
// {
//     ui->setupUi(this);
// }

// FormEstadisticasSexo::~FormEstadisticasSexo()
// {
//     delete ui;
// }
#include "formestadisticassexo.h"
#include "ui_formestadisticassexo.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

FormEstadisticasSexo::FormEstadisticasSexo(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::FormEstadisticasSexo)
{
    ui->setupUi(this);

    // Crear el gráfico de pie
    QChart *pieChart = new QChart;
    QPieSeries *pieSeries = new QPieSeries;

    // Datos para el gráfico de pie
    QStringList categorias = {"Masculino", "Femenino"};
    QList<int> valores = {670752, 377823};  // Reemplaza estos valores con tus datos reales

    for (int i = 0; i < categorias.size(); ++i) {
        QPieSlice *slice = pieSeries->append(categorias[i], valores[i]);
        slice->setLabel(QString("%1: %2").arg(categorias[i]).arg(valores[i]));
    }

    pieChart->addSeries(pieSeries);
    pieChart->setTitle("Distribución de Evaluados por Sexo");

    // Agregar el gráfico de pie a la vista
    QChartView *pieChartView = new QChartView(pieChart);
    ui->verticalLayout->addWidget(pieChartView);
}

FormEstadisticasSexo::~FormEstadisticasSexo()
{
    delete ui;
}

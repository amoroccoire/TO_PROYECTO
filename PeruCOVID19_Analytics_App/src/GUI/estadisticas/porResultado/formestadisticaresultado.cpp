// #include "formestadisticaresultado.h"
// #include "ui_formestadisticaresultado.h"

// FormEstadisticaResultado::FormEstadisticaResultado(QWidget *parent)
//     : QWidget(parent)
//     , ui(new Ui::FormEstadisticaResultado)
// {
//     ui->setupUi(this);
// }

// FormEstadisticaResultado::~FormEstadisticaResultado()
// {
//     delete ui;
// }

#include "formestadisticaresultado.h"
#include "ui_formestadisticaresultado.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

FormEstadisticaResultado::FormEstadisticaResultado(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::FormEstadisticaResultado)
{
    ui->setupUi(this);

    // Crear el gráfico de pie
    QChart *pieChart = new QChart;
    QPieSeries *pieSeries = new QPieSeries;

    // Datos para el gráfico de pie
    QStringList categorias = {"Positivo", "Negativo"};
    QList<int> valores = {157700, 890875};  // Reemplaza estos valores con tus datos reales

    for (int i = 0; i < categorias.size(); ++i) {
        QPieSlice *slice = pieSeries->append(categorias[i], valores[i]);
        slice->setLabel(QString("%1: %2").arg(categorias[i]).arg(valores[i]));
    }

    pieChart->addSeries(pieSeries);
    pieChart->setTitle("Distribución de Resultados");

    // Agregar el gráfico de pie a la vista
    QChartView *pieChartView = new QChartView(pieChart);
    ui->verticalLayout->addWidget(pieChartView);
}

FormEstadisticaResultado::~FormEstadisticaResultado()
{
    delete ui;
}


#include "formestadisticasdepartamento.h"
#include "ui_formestadisticasdepartamento.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLegend>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

FormEstadisticasdepartamento::FormEstadisticasdepartamento(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormEstadisticasdepartamento)
{
    ui->setupUi(this);
    // Crear el segundo gráfico de barras
    QChart *barChart2 = new QChart;
    QBarSeries *barSeries2 = new QBarSeries;

    // Datos para el segundo gráfico de barras
    QStringList departamentos = {"AREQUIPA", "LIMA", "PUNO", "ANCASH", "TACNA", "MOQUEGUA", "LORETO", "TUMBES", "ICA", "CUSCO", "LA LIBERTAD", "LAMBAYEQUE", "PASCO", "PIURA", "UCAYALI", "CAJAMARCA", "APURIMAC", "AMAZONAS", "JUNIN", "SAN MARTIN", "MADRE DE DIOS", "AYACUCHO", "HUANUCO", "HUANCAVELICA"};
    QList<int> evaluados = {65418, 565807, 16036, 44716, 6499, 11519, 5429, 10255, 19498, 30019, 26535, 16362, 21862, 17166, 3860, 52980, 6834, 5942, 43528, 8849, 1706, 8812, 13306, 10105};

    QBarSet *barSet2 = new QBarSet("Evaluados por Departamento");
    for (int i = 0; i < departamentos.size(); ++i) {
        *barSet2 << evaluados[i];
    }
    barSeries2->append(barSet2);

    barChart2->addSeries(barSeries2);

    QBarCategoryAxis *axisXBar2 = new QBarCategoryAxis;
    axisXBar2->append(departamentos);
    axisXBar2->setLabelsAngle(-90);
    barChart2->addAxis(axisXBar2, Qt::AlignBottom);

    QValueAxis *axisYBar2 = new QValueAxis;
    axisYBar2->setRange(0, 700000);  // Establecer la escala deseada
    barChart2->addAxis(axisYBar2, Qt::AlignLeft);

    barSeries2->attachAxis(axisXBar2);
    barSeries2->attachAxis(axisYBar2);


    QChartView *barChartView2 = new QChartView(barChart2);
    ui->verticalLayout->addWidget(barChartView2);

}

FormEstadisticasdepartamento::~FormEstadisticasdepartamento()
{
    delete ui;
}

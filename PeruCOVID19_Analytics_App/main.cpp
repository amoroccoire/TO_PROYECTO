#include "includes/GUI/mainwindow.h"
// #include "includes/GUI/formularioEstadisticas.h"
 // #include "src/GUI/estadisticas/porDepartamento/formestadisticasdepartamento.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    // FormularioEstadisticas estadisticasForm;
    // FormEstadisticasdepartamento estadisticasDepartamento;
    //     // Mostrar el formulario
    // // estadisticasForm.show();
    // estadisticasDepartamento.show();

    return a.exec();
}

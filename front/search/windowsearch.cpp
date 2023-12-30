#include "windowsearch.h"
#include "ui_windowsearch.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QString>
#include "../../back/modulos/search/domain/pruebacovid.h"
#include <QDebug>
#include <vector>
#include "../../back/modulos/search/application/sexcriteria.h"
#include "../../back/modulos/search/application/resultcriteria.h"

windowSearch::windowSearch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::windowSearch)
{
    ui->setupUi(this);
    lotes = 4;
    currentRange = 0;
}

windowSearch::~windowSearch()
{
    delete ui;
}

void windowSearch::inicialitation(AVLTreeWorker* worker) {
    QTableWidget* table = ui->tabla;

    std::vector<PruebaCovid*> list = worker->getTree()->inorder();
    //NodoDoubleList<QString, PruebaCovid*>* aux = list->getHead();
    /*if(aux == nullptr)
        qDebug() << "aux es null";*/
    for (PruebaCovid* prueba : list) {
        if (prueba != nullptr) {
            int numeroFilasActual = table->rowCount();
            table->setRowCount(numeroFilasActual + 1);
            QTableWidgetItem *uuid = new QTableWidgetItem(prueba->getUuid());
            QTableWidgetItem *fecMue = new QTableWidgetItem(prueba->getFecMuestra());
            QTableWidgetItem *fecCor = new QTableWidgetItem(prueba->getFecCorte());
            QTableWidgetItem *edad = new QTableWidgetItem(prueba->getEdad());
            QString valor;
            if (prueba->getSexo())
                valor = "MASCULINO";
            else
                valor = "FEMENINO";
            QTableWidgetItem *sexo = new QTableWidgetItem(valor);
            QTableWidgetItem *institucion = new QTableWidgetItem(prueba->getInstitucion());
            QTableWidgetItem *ubigeo = new QTableWidgetItem(prueba->getUbigeoPaciente());
            QTableWidgetItem *depPac = new QTableWidgetItem(prueba->getDepPac());
            QTableWidgetItem *proPac = new QTableWidgetItem(prueba->getProPac());
            QTableWidgetItem *disPac = new QTableWidgetItem(prueba->getDisPac());
            QTableWidgetItem *depMue = new QTableWidgetItem(prueba->getDepMue());
            QTableWidgetItem *proMue = new QTableWidgetItem(prueba->getProMue());
            QTableWidgetItem *disMue = new QTableWidgetItem(prueba->getDisMue());
            QTableWidgetItem *tipoMue = new QTableWidgetItem(prueba->getTipoPrueba());
            QString resultado;
            if (prueba->getResultado())
                resultado = "POSITIVO";
            else
                resultado = "NEGATIVO";
            QTableWidgetItem *res = new QTableWidgetItem(resultado);

            table->setItem(numeroFilasActual, 0, uuid);
            table->setItem(numeroFilasActual, 1, fecMue);
            table->setItem(numeroFilasActual, 2, fecCor);
            table->setItem(numeroFilasActual, 3, edad);
            table->setItem(numeroFilasActual, 4, sexo);
            table->setItem(numeroFilasActual, 5, institucion);
            table->setItem(numeroFilasActual, 6, ubigeo);
            table->setItem(numeroFilasActual, 7, depPac);
            table->setItem(numeroFilasActual, 8, proPac);
            table->setItem(numeroFilasActual, 9, disPac);
            table->setItem(numeroFilasActual, 10, depMue);
            table->setItem(numeroFilasActual, 11, proMue);
            table->setItem(numeroFilasActual, 12, disMue);
            table->setItem(numeroFilasActual, 13, tipoMue);
            table->setItem(numeroFilasActual, 14, res);
        }
    }

    /*while(aux != nullptr) {
        qDebug() << aux->getKey();
        int numeroFilasActual = table->rowCount();
        table->setRowCount(numeroFilasActual + 1);
        PruebaCovid* prueba = aux->getValue(aux->getKey());
        QTableWidgetItem *uuid = new QTableWidgetItem(prueba->getUuid());
        QTableWidgetItem *fecMue = new QTableWidgetItem(prueba->getFecMuestra());
        QTableWidgetItem *fecCor = new QTableWidgetItem(prueba->getFecCorte());
        QTableWidgetItem *edad = new QTableWidgetItem(prueba->getEdad());
        QString valor;
        if (prueba->getSexo())
            valor = "MASCULINO";
        else
            valor = "FEMENINO";
        QTableWidgetItem *sexo = new QTableWidgetItem(valor);
        QTableWidgetItem *institucion = new QTableWidgetItem(prueba->getInstitucion());
        QTableWidgetItem *ubigeo = new QTableWidgetItem(prueba->getUbigeoPaciente());
        QTableWidgetItem *depPac = new QTableWidgetItem(prueba->getDepPac());
        QTableWidgetItem *proPac = new QTableWidgetItem(prueba->getProPac());
        QTableWidgetItem *disPac = new QTableWidgetItem(prueba->getDisPac());
        QTableWidgetItem *depMue = new QTableWidgetItem(prueba->getDepMue());
        QTableWidgetItem *proMue = new QTableWidgetItem(prueba->getProMue());
        QTableWidgetItem *disMue = new QTableWidgetItem(prueba->getDisMue());
        QTableWidgetItem *tipoMue = new QTableWidgetItem(prueba->getTipoPrueba());
        QString resultado;
        if (prueba->getResultado())
            resultado = "POSITIVO";
        else
            resultado = "NEGATIVO";
        QTableWidgetItem *res = new QTableWidgetItem(resultado);

        table->setItem(numeroFilasActual, 0, uuid);
        table->setItem(numeroFilasActual, 1, fecMue);
        table->setItem(numeroFilasActual, 2, fecCor);
        table->setItem(numeroFilasActual, 3, edad);
        table->setItem(numeroFilasActual, 4, sexo);
        table->setItem(numeroFilasActual, 5, institucion);
        table->setItem(numeroFilasActual, 6, ubigeo);
        table->setItem(numeroFilasActual, 7, depPac);
        table->setItem(numeroFilasActual, 8, proPac);
        table->setItem(numeroFilasActual, 9, disPac);
        table->setItem(numeroFilasActual, 10, depMue);
        table->setItem(numeroFilasActual, 11, proMue);
        table->setItem(numeroFilasActual, 12, disMue);
        table->setItem(numeroFilasActual, 13, tipoMue);
        table->setItem(numeroFilasActual, 14, res);

        aux = aux->getNext();
    }*/
}

void windowSearch::createWorkerAndStart(const QString &filename, long start, long count) {
    AVLTreeWorker* worker = new AVLTreeWorker(filename, start, count);
    QObject::connect(worker, &AVLTreeWorker::finished, this, &windowSearch::onWorkerFinished);
    workers.push_back(worker);
    worker->process();
}

void windowSearch::onWorkerFinished(AVLTreeWorker* worker) {
    currentRange++;
    qDebug() << "Procesamiento del rango " << currentRange << " completado.";
    inicialitation(worker);
}

void windowSearch::on_importarCSV_clicked()
{
    windowUpload = new WindowUpload();
    connect(windowUpload, &WindowUpload::onSuccessUploadFile, this, &windowSearch::onSuccessFile);
    windowUpload->show();
}

void windowSearch::onSuccessFile() {
    windowUpload->close();
    //1048575
    long totalLines = 1048576;
    long linesPerThread = totalLines / 1024;
    QString filename = "../TO_PROYECTO/back/BASE_DATOS/PRUEBAS_COVID_CSV.csv";
    currentRange = 0;  // Iniciar con el rango 0

    createWorkerAndStart(filename, 1, linesPerThread);
}


void windowSearch::on_next_clicked() {
    if (currentRange >= 1024) {
        qDebug() << "Todos los rangos han sido procesados.";
        return;
    }

    long totalLines = 1048576;
    long linesPerThread = totalLines / 1024;
    QString filename = "../TO_PROYECTO/back/BASE_DATOS/PRUEBAS_COVID_CSV.csv";

    long startLine = currentRange * linesPerThread + 1;
    if (currentRange == 1024) {
        linesPerThread = totalLines - 1024 * linesPerThread;
    }
    createWorkerAndStart(filename, startLine, linesPerThread);
}


void windowSearch::on_opSexo_currentIndexChanged(int index) {
    std::vector<PruebaCovid*> listaFinal;
    bool isMale;
    switch (index) {
    case 0:{
        isMale = false;
        break;
    }
    case 1:{
        isMale = false;
        break;
    }
    case 2:{
        isMale = true;
        break;
    }
    default:
        break;
    }

    SexCriteria sexCriteria(isMale);
    if (index == 0)
        sexCriteria.setHasCriteria(false);
    //0, todos, 1, F, 2, M
    for (AVLTreeWorker* worker : workers) {
        std::vector<PruebaCovid*> list = worker->getTree()->inorder();
        for (PruebaCovid* prueba : list) {
            if (sexCriteria.matches(prueba))
                listaFinal.push_back(prueba);
        }
    }

    QTableWidget* table = ui->tabla;
    table->setRowCount(0);

    for (PruebaCovid* prueba : listaFinal) {
        if (prueba != nullptr) {
            int numeroFilasActual = table->rowCount();
            table->setRowCount(numeroFilasActual + 1);
            QTableWidgetItem *uuid = new QTableWidgetItem(prueba->getUuid());
            QTableWidgetItem *fecMue = new QTableWidgetItem(prueba->getFecMuestra());
            QTableWidgetItem *fecCor = new QTableWidgetItem(prueba->getFecCorte());
            QTableWidgetItem *edad = new QTableWidgetItem(prueba->getEdad());
            QString valor;
            if (prueba->getSexo())
                valor = "MASCULINO";
            else
                valor = "FEMENINO";
            QTableWidgetItem *sexo = new QTableWidgetItem(valor);
            QTableWidgetItem *institucion = new QTableWidgetItem(prueba->getInstitucion());
            QTableWidgetItem *ubigeo = new QTableWidgetItem(prueba->getUbigeoPaciente());
            QTableWidgetItem *depPac = new QTableWidgetItem(prueba->getDepPac());
            QTableWidgetItem *proPac = new QTableWidgetItem(prueba->getProPac());
            QTableWidgetItem *disPac = new QTableWidgetItem(prueba->getDisPac());
            QTableWidgetItem *depMue = new QTableWidgetItem(prueba->getDepMue());
            QTableWidgetItem *proMue = new QTableWidgetItem(prueba->getProMue());
            QTableWidgetItem *disMue = new QTableWidgetItem(prueba->getDisMue());
            QTableWidgetItem *tipoMue = new QTableWidgetItem(prueba->getTipoPrueba());
            QString resultado;
            if (prueba->getResultado())
                resultado = "POSITIVO";
            else
                resultado = "NEGATIVO";
            QTableWidgetItem *res = new QTableWidgetItem(resultado);

            table->setItem(numeroFilasActual, 0, uuid);
            table->setItem(numeroFilasActual, 1, fecMue);
            table->setItem(numeroFilasActual, 2, fecCor);
            table->setItem(numeroFilasActual, 3, edad);
            table->setItem(numeroFilasActual, 4, sexo);
            table->setItem(numeroFilasActual, 5, institucion);
            table->setItem(numeroFilasActual, 6, ubigeo);
            table->setItem(numeroFilasActual, 7, depPac);
            table->setItem(numeroFilasActual, 8, proPac);
            table->setItem(numeroFilasActual, 9, disPac);
            table->setItem(numeroFilasActual, 10, depMue);
            table->setItem(numeroFilasActual, 11, proMue);
            table->setItem(numeroFilasActual, 12, disMue);
            table->setItem(numeroFilasActual, 13, tipoMue);
            table->setItem(numeroFilasActual, 14, res);
        }
    }
}


void windowSearch::on_opTipoMuestra_2_currentIndexChanged(int index) {
    std::vector<PruebaCovid*> listaFinal;
    bool result;
    switch (index) {
    case 0:{
        result = false;
        break;
    }
    case 1:{
        result = true;
        break;
    }
    case 2:{
        result = false;
        break;
    }
    default:
        break;
    }

    ResultCriteria resultCriteria(result);

    if (index == 0)
        resultCriteria.setHasCriteria(false);
    //0, todos, 1, POS, 2, NEG
    for (AVLTreeWorker* worker : workers) {
        std::vector<PruebaCovid*> list = worker->getTree()->inorder();
        for (PruebaCovid* prueba : list) {
            if (resultCriteria.matches(prueba))
                listaFinal.push_back(prueba);
        }
    }

    QTableWidget* table = ui->tabla;
    table->setRowCount(0);

    for (PruebaCovid* prueba : listaFinal) {
        if (prueba != nullptr) {
            int numeroFilasActual = table->rowCount();
            table->setRowCount(numeroFilasActual + 1);
            QTableWidgetItem *uuid = new QTableWidgetItem(prueba->getUuid());
            QTableWidgetItem *fecMue = new QTableWidgetItem(prueba->getFecMuestra());
            QTableWidgetItem *fecCor = new QTableWidgetItem(prueba->getFecCorte());
            QTableWidgetItem *edad = new QTableWidgetItem(prueba->getEdad());
            QString valor;
            if (prueba->getSexo())
                valor = "MASCULINO";
            else
                valor = "FEMENINO";
            QTableWidgetItem *sexo = new QTableWidgetItem(valor);
            QTableWidgetItem *institucion = new QTableWidgetItem(prueba->getInstitucion());
            QTableWidgetItem *ubigeo = new QTableWidgetItem(prueba->getUbigeoPaciente());
            QTableWidgetItem *depPac = new QTableWidgetItem(prueba->getDepPac());
            QTableWidgetItem *proPac = new QTableWidgetItem(prueba->getProPac());
            QTableWidgetItem *disPac = new QTableWidgetItem(prueba->getDisPac());
            QTableWidgetItem *depMue = new QTableWidgetItem(prueba->getDepMue());
            QTableWidgetItem *proMue = new QTableWidgetItem(prueba->getProMue());
            QTableWidgetItem *disMue = new QTableWidgetItem(prueba->getDisMue());
            QTableWidgetItem *tipoMue = new QTableWidgetItem(prueba->getTipoPrueba());
            QString resultado;
            if (prueba->getResultado())
                resultado = "POSITIVO";
            else
                resultado = "NEGATIVO";
            QTableWidgetItem *res = new QTableWidgetItem(resultado);

            table->setItem(numeroFilasActual, 0, uuid);
            table->setItem(numeroFilasActual, 1, fecMue);
            table->setItem(numeroFilasActual, 2, fecCor);
            table->setItem(numeroFilasActual, 3, edad);
            table->setItem(numeroFilasActual, 4, sexo);
            table->setItem(numeroFilasActual, 5, institucion);
            table->setItem(numeroFilasActual, 6, ubigeo);
            table->setItem(numeroFilasActual, 7, depPac);
            table->setItem(numeroFilasActual, 8, proPac);
            table->setItem(numeroFilasActual, 9, disPac);
            table->setItem(numeroFilasActual, 10, depMue);
            table->setItem(numeroFilasActual, 11, proMue);
            table->setItem(numeroFilasActual, 12, disMue);
            table->setItem(numeroFilasActual, 13, tipoMue);
            table->setItem(numeroFilasActual, 14, res);
        }
    }
}


void windowSearch::on_exportarCSV_clicked() {
    //Export* paraExportar = new Export();
    //paraExportar->exportToPdf(ui->tabla);
}


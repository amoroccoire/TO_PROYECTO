#include "avltreeworker.h"
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QDebug>

AVLTreeWorker::AVLTreeWorker(const QString& filename, long startLine, long numLines) {
    avlTree = new AVLTree();
    lista = new DoubleLinkedList<QString, PruebaCovid*>();
    this->filename = filename;
    this->startLine = startLine;
    this->numLines = numLines;
}

void AVLTreeWorker::process() {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QString line;
    long currentLine = 0;

    while (currentLine < startLine && !in.atEnd()) {
        qDebug() << currentLine;
        line = in.readLine();
        qDebug() << line;
        currentLine++;
    }

    while (currentLine < startLine + numLines && !in.atEnd()) {
        line = in.readLine();
        qDebug() << line;
        QStringList list = line.split(";");
        qDebug() << "ANTES DE INSERTADO 0000";
        if (list[1] != "NULL") {
            qDebug() << "ANTES DE INSERTADO";
            PruebaCovid* prueba = extractKeyFromLine(list);
            avlTree->insert(prueba);
            qDebug() << "INSERTADO";
            currentLine++;
        }
        else
            continue;
    }

    emit finished(this);
}

DoubleLinkedList<QString, PruebaCovid*>* AVLTreeWorker::getLista() {
    return this->lista;
}

AVLTree* AVLTreeWorker::getTree() {
    return this->avlTree;
}

PruebaCovid* AVLTreeWorker::extractKeyFromLine(QStringList& line) {
    PruebaCovid* prueba = new PruebaCovid();
    prueba->setFecCorte(line[0]);
    prueba->setUuid(line[1]);
    prueba->setFecMuestra(line[2]);
    prueba->setEdad(line[3].toInt());
    if (line[4][0] == 'F')
        prueba->setSexo(false);
    else
        prueba->setSexo(true);
    prueba->setInstitucion(line[5]);
    prueba->setUbigeoPaciente(line[6]);
    prueba->setDepPac(line[7]);
    prueba->setProPac(line[8]);
    prueba->setDisPac(line[9]);
    prueba->setDepMue(line[10]);
    prueba->setProMue(line[11]);
    prueba->setDisMue(line[12]);
    prueba->setTipoPrueba(line[13]);

    if (line[14][0] == 'N')
        prueba->setResultado(false);
    else
        prueba->setResultado(true);

    return prueba;
}

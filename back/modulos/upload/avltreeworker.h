#ifndef AVLTREEWORKER_H
#define AVLTREEWORKER_H

#include <QObject>
#include <QString>
#pragma once
#include "avltree.h"

class AVLTreeWorker : public QObject {
    Q_OBJECT
public:
    AVLTreeWorker(const QString& filename, long startLine, long numLines);
    void process();

signals:
    void finished();

private:
    AVLTree avlTree;
    QString filename;
    long startLine;
    long numLines;

    int extractKeyFromLine(QString& line);

};

#endif // AVLTREEWORKER_H

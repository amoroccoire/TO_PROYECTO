#include "avltreeworker.h"

AVLTreeWorker::AVLTreeWorker(const QString& filename, long startLine, long numLines) {
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
        line = in.readLine();
        currentLine++;
    }

    while (currentLine < startLine + numLines && !in.atEnd()) {
        line = in.readLine();
        int key = extractKeyFromLine(line);
        avlTree.insert(key);
        currentLine++;
    }

    emit finished();
}

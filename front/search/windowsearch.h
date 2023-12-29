#ifndef WINDOWSEARCH_H
#define WINDOWSEARCH_H

#include <QWidget>
#include "../../back/modulos/upload/avltreeworker.h"
#include "../upload/windowupload.h"
#include "ui_windowupload.h"

namespace Ui {
class windowSearch;
}

class windowSearch : public QWidget
{
    Q_OBJECT

public:
    explicit windowSearch(QWidget *parent = nullptr);
    ~windowSearch();

    void createWorkerAndStart(const QString& filename, long start, long count);

private slots:
    void on_importarCSV_clicked();
    void onSuccessFile();

    void on_next_clicked();

    void onWorkerFinished(AVLTreeWorker* worker);

    void inicialitation(AVLTreeWorker* worker);

private:
    Ui::windowSearch *ui;
    WindowUpload* windowUpload;
    AVLTreeWorker* worker1;
    AVLTreeWorker* worker2;
    AVLTreeWorker* worker3;
    AVLTreeWorker* worker4;

    int lotes;
    int currentRange;

};

#endif // WINDOWSEARCH_H

#ifndef WINDOWSEARCH_H
#define WINDOWSEARCH_H

#include <QWidget>
#include "../../back/modulos/upload/avltreeworker.h"
#include "../upload/windowupload.h"
#include "ui_windowupload.h"
#include <vector>

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

    void on_opSexo_currentIndexChanged(int index);

    void on_opTipoMuestra_2_currentIndexChanged(int index);

private:
    Ui::windowSearch *ui;
    WindowUpload* windowUpload;
    std::vector<AVLTreeWorker*> workers;

    int lotes;
    int currentRange;

};

#endif // WINDOWSEARCH_H

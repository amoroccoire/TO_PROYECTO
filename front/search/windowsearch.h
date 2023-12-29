#ifndef WINDOWSEARCH_H
#define WINDOWSEARCH_H

#include <QWidget>

namespace Ui {
class windowSearch;
}

class windowSearch : public QWidget
{
    Q_OBJECT

public:
    explicit windowSearch(QWidget *parent = nullptr);
    ~windowSearch();

private slots:
    void on_importarCSV_clicked();
    void onSuccessFile();

private:
    Ui::windowSearch *ui;

    void inicialitation();
};

#endif // WINDOWSEARCH_H

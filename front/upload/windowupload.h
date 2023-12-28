#ifndef WINDOWUPLOAD_H
#define WINDOWUPLOAD_H

#include <QWidget>

namespace Ui {
class WindowUpload;
}

class WindowUpload : public QWidget
{
    Q_OBJECT

public:
    explicit WindowUpload(QWidget *parent = nullptr);
    ~WindowUpload();

private slots:

    void on_botonSubir_clicked();

private:
    Ui::WindowUpload *ui;
};

#endif // WINDOWUPLOAD_H

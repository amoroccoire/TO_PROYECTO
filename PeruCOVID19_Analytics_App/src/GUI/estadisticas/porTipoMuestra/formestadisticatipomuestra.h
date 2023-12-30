#ifndef FORMESTADISTICATIPOMUESTRA_H
#define FORMESTADISTICATIPOMUESTRA_H

#include <QWidget>

namespace Ui {
class FormEstadisticaTipoMuestra;
}

class FormEstadisticaTipoMuestra : public QWidget
{
    Q_OBJECT

public:
    explicit FormEstadisticaTipoMuestra(QWidget *parent = nullptr);
    ~FormEstadisticaTipoMuestra();

private:
    Ui::FormEstadisticaTipoMuestra *ui;
};

#endif // FORMESTADISTICATIPOMUESTRA_H

#ifndef FORMESTADISTICASDEPARTAMENTO_H
#define FORMESTADISTICASDEPARTAMENTO_H

#include <QWidget>

namespace Ui {
class FormEstadisticasdepartamento;
}

class FormEstadisticasdepartamento : public QWidget
{
    Q_OBJECT

public:
    explicit FormEstadisticasdepartamento(QWidget *parent = nullptr);
    ~FormEstadisticasdepartamento();

private:
    Ui::FormEstadisticasdepartamento *ui;
};

#endif // FORMESTADISTICASDEPARTAMENTO_H

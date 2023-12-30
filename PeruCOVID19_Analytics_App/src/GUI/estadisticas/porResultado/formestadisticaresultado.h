#ifndef FORMESTADISTICARESULTADO_H
#define FORMESTADISTICARESULTADO_H

#include <QWidget>

namespace Ui {
class FormEstadisticaResultado;
}

class FormEstadisticaResultado : public QWidget
{
    Q_OBJECT

public:
    explicit FormEstadisticaResultado(QWidget *parent = nullptr);
    ~FormEstadisticaResultado();

private:
    Ui::FormEstadisticaResultado *ui;
};

#endif // FORMESTADISTICARESULTADO_H

#ifndef FORMESTADISTICASSEXO_H
#define FORMESTADISTICASSEXO_H

#include <QWidget>

namespace Ui {
class FormEstadisticasSexo;
}

class FormEstadisticasSexo : public QWidget
{
    Q_OBJECT

public:
    explicit FormEstadisticasSexo(QWidget *parent = nullptr);
    ~FormEstadisticasSexo();

private:
    Ui::FormEstadisticasSexo *ui;
};

#endif // FORMESTADISTICASSEXO_H

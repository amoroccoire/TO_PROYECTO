#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

    //DELCARANDO FUNCIONES
    bool usuarioExiste(const QString& nombre);
    void agregarNuevoUsuario(const QString& nombre, const QString& contrasena);
    void cerrarVentana();

private slots:
    void on_btn1_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H

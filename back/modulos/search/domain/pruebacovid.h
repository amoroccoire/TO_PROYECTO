#ifndef PRUEBACOVID_H
#define PRUEBACOVID_H
#include <QString>

class PruebaCovid {
public:
    PruebaCovid();

    QString getUuid();
    QString getFecCorte();
    QString getFecMuestra();
    int getEdad();
    bool getSexo();
    QString getInstitucion();
    QString getUbigeoPaciente();
    QString getDepPac();
    QString getProPac();
    QString getDisPac();
    QString getDepMue();
    QString getProMue();
    QString getDisMue();
    QString getTipoPrueba();
    bool getResultado();

    void setUuid(QString);
    void setFecCorte(QString);
    void setFecMuestra(QString);
    void setEdad(int);
    void setSexo(bool);
    void setInstitucion(QString);
    void setUbigeoPaciente(QString);
    void setDepPac(QString);
    void setProPac(QString);
    void setDisPac(QString);
    void setDepMue(QString);
    void setProMue(QString);
    void setDisMue(QString);
    void setTipoPrueba(QString);
    void setResultado(bool);

private:
    QString uuid;
    QString fechaCorte;
    QString fechaMuestra;
    int edad;
    bool sexo;
    QString institucion;
    QString ubigeoPaciente;
    QString depPaciente;
    QString proPaciente;
    QString disPaciente;
    QString depMuestra;
    QString proMuestra;
    QString disMuestr;
    QString tipoPrueba;
    bool resultado;
};

#endif // PRUEBACOVID_H

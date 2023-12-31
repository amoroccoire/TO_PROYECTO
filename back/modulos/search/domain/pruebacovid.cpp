#include "pruebacovid.h"

PruebaCovid::PruebaCovid() : uuid(""), fechaCorte(""), fechaMuestra(""), edad(-1), sexo(false),
    institucion(""), ubigeoPaciente(""), depPaciente(""), proPaciente(""),
    disPaciente(""), depMuestra(""), proMuestra(""), disMuestr(""),
    tipoPrueba(""), resultado(false) { //true: HOMBRE, false: MUJER
}

// Métodos Get
QString PruebaCovid::getUuid() {
    return uuid;
}

QString PruebaCovid::getFecCorte() {
    return fechaCorte;
}

QString PruebaCovid::getFecMuestra() {
    return fechaMuestra;
}

int PruebaCovid::getEdad() {
    return edad;
}

bool PruebaCovid::getSexo() {
    return sexo;
}

QString PruebaCovid::getInstitucion() {
    return institucion;
}

QString PruebaCovid::getUbigeoPaciente() {
    return ubigeoPaciente;
}

QString PruebaCovid::getDepPac() {
    return depPaciente;
}

QString PruebaCovid::getProPac() {
    return proPaciente;
}

QString PruebaCovid::getDisPac() {
    return disPaciente;
}

QString PruebaCovid::getDepMue() {
    return depMuestra;
}

QString PruebaCovid::getProMue() {
    return proMuestra;
}

QString PruebaCovid::getDisMue() {
    return disMuestr;
}

QString PruebaCovid::getTipoPrueba() {
    return tipoPrueba;
}

bool PruebaCovid::getResultado() {
    return resultado;
}

// Métodos Set
void PruebaCovid::setUuid(QString val) {
    uuid = val;
}

void PruebaCovid::setFecCorte(QString val) {
    fechaCorte = val;
}

void PruebaCovid::setFecMuestra(QString val) {
    fechaMuestra = val;
}

void PruebaCovid::setEdad(int val) {
    edad = val;
}

void PruebaCovid::setSexo(bool val) {
    sexo = val;
}

void PruebaCovid::setInstitucion(QString val) {
    institucion = val;
}

void PruebaCovid::setUbigeoPaciente(QString val) {
    ubigeoPaciente = val;
}

void PruebaCovid::setDepPac(QString val) {
    depPaciente = val;
}

void PruebaCovid::setProPac(QString val) {
    proPaciente = val;
}

void PruebaCovid::setDisPac(QString val) {
    disPaciente = val;
}

void PruebaCovid::setDepMue(QString val) {
    depMuestra = val;
}

void PruebaCovid::setProMue(QString val) {
    proMuestra = val;
}

void PruebaCovid::setDisMue(QString val) {
    disMuestr = val;
}

void PruebaCovid::setTipoPrueba(QString val) {
    tipoPrueba = val;
}

void PruebaCovid::setResultado(bool val) {
    resultado = val;
}

// En el archivo RegistroCovid.h
#ifndef REGISTRO_COVID_H
#define REGISTRO_COVID_H

#include <string>
#include <ostream>


class RegistroCovid {
public:
    std::string fechaCorte;
    std::string uuid;
    std::string fechaMuestra;
    int edad;
    bool esFemenino;
    std::string institucion;
    std::string ubigeoPaciente;
    std::string departamentoPaciente;
    std::string provinciaPaciente;
    std::string distritoPaciente;
    std::string departamentoMuestra;
    std::string provinciaMuestra;
    std::string distritoMuestra;
    std::string tipoMuestra;
    bool esPositivo;

    // Definición del operador <
    bool operator<(const RegistroCovid& otro) const {
        // Comparación lexicográfica de las fechas de corte
        return fechaCorte.compare(otro.fechaCorte) < 0;
    }

    // Definición del operador >
    bool operator>(const RegistroCovid& otro) const {
        // Comparación lexicográfica inversa de las fechas de corte
        return fechaCorte.compare(otro.fechaCorte) > 0;
    }

    RegistroCovid(const RegistroCovid& otro);
    void imprimir() const;
    friend std::ostream& operator<<(std::ostream& os, const RegistroCovid& registro) {
        os << "Fecha de Corte: " << registro.fechaCorte << ", ";
        os << "UUID: " << registro.uuid << ", ";
        // Agregar otros campos...
        return os;
    }

    // Constructor
    RegistroCovid(const std::string& fechaCorte, const std::string& uuid, const std::string& fechaMuestra,
                  int edad, bool esFemenino, const std::string& institucion,
                  const std::string& ubigeoPaciente, const std::string& departamentoPaciente,
                  const std::string& provinciaPaciente, const std::string& distritoPaciente,
                  const std::string& departamentoMuestra, const std::string& provinciaMuestra,
                  const std::string& distritoMuestra, const std::string& tipoMuestra,
                  bool esPositivo)
        : fechaCorte(fechaCorte), uuid(uuid), fechaMuestra(fechaMuestra),
        edad(edad), esFemenino(esFemenino), institucion(institucion),
        ubigeoPaciente(ubigeoPaciente), departamentoPaciente(departamentoPaciente),
        provinciaPaciente(provinciaPaciente), distritoPaciente(distritoPaciente),
        departamentoMuestra(departamentoMuestra), provinciaMuestra(provinciaMuestra),
        distritoMuestra(distritoMuestra), tipoMuestra(tipoMuestra),
        esPositivo(esPositivo) {
        // Otras inicializaciones si es necesario
    }

    // Constructor por defecto
    RegistroCovid()
        : fechaCorte("FechaPorDefecto"),
        uuid("00001"),
        fechaMuestra("FechaMuestraPorDefecto"),
        edad(0),
        esFemenino(false),
        institucion("InstitucionPorDefecto"),
        ubigeoPaciente("UbigeoPacientePorDefecto"),
        departamentoPaciente("DepartamentoPacientePorDefecto"),
        provinciaPaciente("ProvinciaPacientePorDefecto"),
        distritoPaciente("DistritoPacientePorDefecto"),
        departamentoMuestra("DepartamentoMuestraPorDefecto"),
        provinciaMuestra("ProvinciaMuestraPorDefecto"),
        distritoMuestra("DistritoMuestraPorDefecto"),
        tipoMuestra("TipoMuestraPorDefecto"),
        esPositivo(false) {
        // Otras inicializaciones si es necesario
    }

    // Método para convertir y almacenar la fecha
    void setFechaCorte(const std::string& fechaCompacta);

    // Otros métodos...

};

#endif // REGISTRO_COVID_H



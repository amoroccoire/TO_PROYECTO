// En RegistroCovid.cpp
#include "../../includes/model/registroCovid.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>

void RegistroCovid::setFechaCorte(const std::string& fechaCompacta) {
    // Verificar que la cadena tenga al menos 8 caracteres
    if (fechaCompacta.size() >= 8) {
        // Extraer el año, mes y día de la cadena compacta
        std::string annoStr = fechaCompacta.substr(0, 4);
        std::string mesStr = fechaCompacta.substr(4, 2);
        std::string diaStr = fechaCompacta.substr(6, 2);

        // Convertir las subcadenas a enteros
        int anno = std::stoi(annoStr);
        int mes = std::stoi(mesStr);
        int dia = std::stoi(diaStr);

        // Almacenar la fecha (asumiendo que fechaCorte es de tipo std::chrono::system_clock::time_point)
        // Aquí puedes usar las librerías de manejo de tiempo, como <chrono>
        // Por ejemplo, si quieres almacenar la fecha en segundos desde el epoch:
        std::tm tm_date = {0};
        tm_date.tm_year = anno - 1900; // Ajuste para el año
        tm_date.tm_mon = mes - 1;      // Ajuste para el mes
        tm_date.tm_mday = dia;
        std::time_t time_stamp = std::mktime(&tm_date);
        std::string timeString = std::ctime(&time_stamp);
        fechaCorte = timeString.substr(0, timeString.find('\n'));
;
    } else {
        // Manejar el caso de una cadena no válida (puedes lanzar una excepción, imprimir un mensaje, etc.)
        // Por ejemplo:
        throw std::invalid_argument("La cadena de fecha no tiene el formato esperado.");
    }
};



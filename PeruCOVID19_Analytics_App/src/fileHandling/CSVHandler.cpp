// En un archivo como CSVHandler.cpp
#include "../../includes/fileHandling/CSVHandler.h"
#include "../../includes/model/registroCovid.h"
#include "../../includes/dataStructures/avl_tree.h"
#include "../../src/dataStructures/avl_tree.cpp"

#include <sstream>

void CSVHandler::procesarArchivo(const std::string& rutaArchivo, AVLTree<RegistroCovid>& arbol) {
    std::ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        // Manejo de error: no se pudo abrir el archivo
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream ss(linea);
        std::vector<std::string> campos;

        std::string campo;
        while (std::getline(ss, campo, '\t')) {
            campos.push_back(campo);
        }

        // Crear una instancia de RegistroCovid y agregar al árbol
        RegistroCovid registro;
        registro.fechaCorte = campos[0];
        registro.uuid = campos[1];
        // Asignar otros campos...

        arbol.insert(registro);
    }

    archivo.close();
}

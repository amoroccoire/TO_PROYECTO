#ifndef CSVHANDLER_H
#define CSVHANDLER_H

#include <fstream>
#include <vector>
#include "../../includes/model/registroCovid.h"
#include "../../includes/dataStructures/avl_tree.h"

class CSVHandler {
public:
    static void procesarArchivo(const std::string& rutaArchivo, AVLTree<RegistroCovid>& arbol);
};

#endif // CSV_HANDLER_H

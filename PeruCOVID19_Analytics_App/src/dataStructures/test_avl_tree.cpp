#include "../../includes/dataStructures/avl_tree.h"
#include <iostream>

int main() {
    AVLTree<int> avlTree;

    // Insertar elementos
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.insert(40);
    avlTree.insert(50);

    // Mostrar el árbol inorden
    std::cout << "Inorden traversal del arbol AVL: ";
    avlTree.printInOrder();

    // Buscar un elemento
    int keyToSearch = 30;
    if (avlTree.search(keyToSearch)) {
        std::cout << keyToSearch << " encontrado en el arbol." << std::endl;
    } else {
        std::cout << keyToSearch << " no encontrado en el arbol." << std::endl;
    }

    // Eliminar un elemento
    int keyToRemove = 30;
    avlTree.remove(keyToRemove);

    // Mostrar el árbol después de la eliminación
    std::cout << "Inorden traversal del arbol AVL despues de eliminar " << keyToRemove << ": ";
    avlTree.printInOrder();

    return 0;
}

project(tests)

# Buscar la biblioteca de pruebas Catch2 (si aún no la tienes)
find_package(Catch2 REQUIRED)

# Agregar ejecutables de pruebas aquí
add_executable(test_avl_tree avl_tree.cpp test_avl_tree.cpp)

# Enlazar bibliotecas necesarias
target_link_libraries(test_avl_tree PRIVATE Catch2::Catch2)

# Registrar las pruebas con CTest
include(CTest)
include(Catch)
catch_discover_tests(test_avl_tree)

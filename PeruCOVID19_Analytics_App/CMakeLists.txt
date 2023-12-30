cmake_minimum_required(VERSION 3.5)

project(PeruCOVID19_Analytics_App VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_PREFIX_PATH "RUTA_AL_DIRECTORIO_DE_QT;${CMAKE_PREFIX_PATH}")
# set(CMAKE_PREFIX_PATH "C:/Qt")
# set(QT_DIR "C:/Qt")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
#find_package(Qt6 COMPONENTS Widgets Charts REQUIRED)
#find_package(Qt5 COMPONENTS Widgets Charts REQUIRED)
# include other modules above
#find_package(QT NAMES Qt6 COMPONENTS Widgets Charts REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets Charts)

set(PROJECT_SOURCES
        main.cpp
        src/GUI/mainwindow.cpp
        includes/GUI/mainwindow.h
        ui/GUI/mainwindow.ui
        src/fileHandling/CSVHandler.cpp
        src/model/RegistroCovid.cpp

)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(PeruCOVID19_Analytics_App
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        data/exceldeprueba.csv
        src/dataStructures/avl_tree.cpp
        includes/dataStructures/avl_tree.h
        src/logic/fileHandler.cpp
        includes/logic/fileHandler.h
        src/fileHandling/CSVHandler.cpp
        includes/fileHandling/CSVHandler.h
        src/model/registroCovid.cpp
        includes/model/registroCovid.h
        src/fileHandling/fileMainPrueba.cpp
        includes/dataStructures/pila.h
        src/dataStructures/pila.cpp
        src/dataStructures/pila_test.cpp
        src/GUI/estadisticas/porDepartamento/formestadisticasdepartamento.h src/GUI/estadisticas/porDepartamento/formestadisticasdepartamento.cpp src/GUI/estadisticas/porDepartamento/formestadisticasdepartamento.ui
        src/GUI/estadisticas/porSexo/formestadisticassexo.h src/GUI/estadisticas/porSexo/formestadisticassexo.cpp src/GUI/estadisticas/porSexo/formestadisticassexo.ui
        src/GUI/estadisticas/porResultado/formestadisticaresultado.h src/GUI/estadisticas/porResultado/formestadisticaresultado.cpp src/GUI/estadisticas/porResultado/formestadisticaresultado.ui



#        src/dataStructures/test_avl_tree.cpp

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET PeruCOVID19_Analytics_App APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(PeruCOVID19_Analytics_App SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(PeruCOVID19_Analytics_App
            ${PROJECT_SOURCES}
        )
    endif()
endif()


target_link_libraries(PeruCOVID19_Analytics_App PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(PeruCOVID19_Analytics_App PRIVATE Qt6::Widgets Qt6::Charts)
# target_link_libraries(PeruCOVID19_Analytics_App PUBLIC Qt::QtCharts)

#target_link_libraries(PeruCOVID19_Analytics_App PRIVATE Qt6::Widgets Qt6::Charts)

#target_link_libraries(PeruCOVID19_Analytics_App PRIVATE Qt6::Widgets Qt5::Charts )

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.PeruCOVID19_Analytics_App)
endif()
set_target_properties(PeruCOVID19_Analytics_App PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS PeruCOVID19_Analytics_App
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(PeruCOVID19_Analytics_App)
endif()

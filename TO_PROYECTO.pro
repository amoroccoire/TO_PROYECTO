QT       += core gui
QT += widgets printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    back/modulos/handlerFile/infraestructure/JsonFileRepository.cpp \
    back/modulos/search/application/agecriteria.cpp \
    back/modulos/search/application/andcriteria.cpp \
    back/modulos/search/application/orcriteria.cpp \
    back/modulos/search/application/resultcriteria.cpp \
    back/modulos/search/application/sexcriteria.cpp \
    back/modulos/search/domain/pruebacovid.cpp \
    back/modulos/upload/avltree.cpp \
    back/modulos/upload/avltreeworker.cpp \
    back/modulos/upload/nodeavl.cpp \
    back/modulos/user/application/containuser.cpp \
    back/modulos/user/application/createuser.cpp \
    back/modulos/user/application/verifyuser.cpp \
    back/modulos/user/domain/user.cpp \
    back/modulos/user/infraestructure/userfilerepository.cpp \
    front/search/windowsearch.cpp \
    front/upload/windowupload.cpp \
    login/filehandler.cpp \
    login/form.cpp \
    login/login.cpp \
    main.cpp \
    mainwindow.cpp \
    shared/BST/bst.cpp \
    shared/BST/nodobst.cpp \
    shared/DoubleLinkedList/doublelinkedlist.cpp \
    shared/DoubleLinkedList/nododoublelist.cpp

HEADERS += \
    back/modulos/handlerFile/domain/FileRepository.h \
    back/modulos/handlerFile/domain/JsonFileRepository.h \
    back/modulos/search/application/DynamiCriteria.h \
    back/modulos/search/application/agecriteria.h \
    back/modulos/search/application/andcriteria.h \
    back/modulos/search/application/orcriteria.h \
    back/modulos/search/application/resultcriteria.h \
    back/modulos/search/application/sexcriteria.h \
    back/modulos/search/domain/pruebacovid.h \
    back/modulos/upload/avltree.h \
    back/modulos/upload/avltreeworker.h \
    back/modulos/upload/nodeavl.h \
    back/modulos/user/application/containuser.h \
    back/modulos/user/application/createuser.h \
    back/modulos/user/application/verifyuser.h \
    back/modulos/user/domain/IUserRepository.h \
    back/modulos/user/domain/user.h \
    back/modulos/user/infraestructure/userfilerepository.h \
    front/search/windowsearch.h \
    front/upload/windowupload.h \
    login/filehandler.h \
    login/form.h \
    login/login.h \
    mainwindow.h \
    shared/BST/bst.h \
    shared/BST/nodobst.h \
    shared/DoubleLinkedList/doublelinkedlist.h \
    shared/DoubleLinkedList/nododoublelist.h

FORMS += \
    front/GUI/windowsearch.ui \
    front/GUI/windowupload.ui \
    login/form.ui \
    login/login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../Fil2/NewLogin/register.csv \
    login/register.csv

DESTDIR = $$OUT_PWD
FILES += login/register.csv

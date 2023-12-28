QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    back/modulos/handlerFile/infraestructure/JsonFileRepository.cpp \
    back/modulos/user/application/containuser.cpp \
    back/modulos/user/application/createuser.cpp \
    back/modulos/user/application/verifyuser.cpp \
    back/modulos/user/domain/user.cpp \
    back/modulos/user/infraestructure/userfilerepository.cpp \
    front/search/windowsearch.cpp \
    front/upload/windowupload.cpp \
    main.cpp \
    mainwindow.cpp \
    shared/BST/bst.cpp \
    shared/BST/nodobst.cpp \
    shared/DoubleLinkedList/doublelinkedlist.cpp \
    shared/DoubleLinkedList/nododoublelist.cpp

HEADERS += \
    back/modulos/handlerFile/domain/FileRepository.h \
    back/modulos/handlerFile/domain/JsonFileRepository.h \
    back/modulos/user/application/containuser.h \
    back/modulos/user/application/createuser.h \
    back/modulos/user/application/verifyuser.h \
    back/modulos/user/domain/IUserRepository.h \
    back/modulos/user/domain/user.h \
    back/modulos/user/infraestructure/userfilerepository.h \
    front/search/windowsearch.h \
    front/upload/windowupload.h \
    mainwindow.h \
    shared/BST/bst.h \
    shared/BST/nodobst.h \
    shared/DoubleLinkedList/doublelinkedlist.h \
    shared/DoubleLinkedList/nododoublelist.h

FORMS += \
    front/GUI/windowsearch.ui \
    front/GUI/windowupload.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

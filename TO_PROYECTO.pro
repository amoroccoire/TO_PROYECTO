QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    back/modulos/user/application/containuser.cpp \
    back/modulos/user/application/createuser.cpp \
    back/modulos/user/application/verifyuser.cpp \
    back/modulos/user/domain/user.cpp \
    back/modulos/user/infraestructure/userfilerepository.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    back/modulos/user/application/containuser.h \
    back/modulos/user/application/createuser.h \
    back/modulos/user/application/verifyuser.h \
    back/modulos/user/domain/IUserRepository.h \
    back/modulos/user/domain/user.h \
    back/modulos/user/infraestructure/userfilerepository.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

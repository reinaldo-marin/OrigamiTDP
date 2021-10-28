QT       += core gui
CONFIG += c++11 console
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bala.cpp \
    barra.cpp \
    cuerpo.cpp \
    enemigo.cpp \
    fondo.cpp \
    inventario.cpp \
    inventory.cpp \
    jugador.cpp \
    main.cpp \
    mainwindow.cpp \
    movimiento.cpp \
    objeto.cpp \
    viento.cpp

HEADERS += \
    bala.h \
    barra.h \
    cuerpo.h \
    enemigo.h \
    fondo.h \
    inventario.h \
    inventory.h \
    jugador.h \
    mainwindow.h \
    movimiento.h \
    objeto.h \
    viento.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

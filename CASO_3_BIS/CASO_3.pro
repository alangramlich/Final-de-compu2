QT += core
QT -= gui

LIBS += -lOpenGL32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../CodigoInicial_JuegoDeLaMemoria_v2/anillo.cpp \
        ../CodigoInicial_JuegoDeLaMemoria_v2/carta.cpp \
        ../CodigoInicial_JuegoDeLaMemoria_v2/circulo.cpp \
        ../CodigoInicial_JuegoDeLaMemoria_v2/cruz.cpp \
        ../CodigoInicial_JuegoDeLaMemoria_v2/cuadrado.cpp \
        ../CodigoInicial_JuegoDeLaMemoria_v2/espiral.cpp \
        ../CodigoInicial_JuegoDeLaMemoria_v2/estrella.cpp \
        ../CodigoInicial_JuegoDeLaMemoria_v2/figura.cpp \
        ../CodigoInicial_JuegoDeLaMemoria_v2/flecha.cpp \
        ../CodigoInicial_JuegoDeLaMemoria_v2/juegodelamemoria.cpp \
        ../CodigoInicial_JuegoDeLaMemoria_v2/mesa.cpp \
        ../CodigoInicial_JuegoDeLaMemoria_v2/onda.cpp \
        ../CodigoInicial_JuegoDeLaMemoria_v2/triangulo.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../CodigoInicial_JuegoDeLaMemoria_v2/anillo.h \
    ../CodigoInicial_JuegoDeLaMemoria_v2/carta.h \
    ../CodigoInicial_JuegoDeLaMemoria_v2/circulo.h \
    ../CodigoInicial_JuegoDeLaMemoria_v2/cruz.h \
    ../CodigoInicial_JuegoDeLaMemoria_v2/cuadrado.h \
    ../CodigoInicial_JuegoDeLaMemoria_v2/espiral.h \
    ../CodigoInicial_JuegoDeLaMemoria_v2/estrella.h \
    ../CodigoInicial_JuegoDeLaMemoria_v2/figura.h \
    ../CodigoInicial_JuegoDeLaMemoria_v2/flecha.h \
    ../CodigoInicial_JuegoDeLaMemoria_v2/juegodelamemoria.h \
    ../CodigoInicial_JuegoDeLaMemoria_v2/mesa.h \
    ../CodigoInicial_JuegoDeLaMemoria_v2/onda.h \
    ../CodigoInicial_JuegoDeLaMemoria_v2/pixel.h \
    ../CodigoInicial_JuegoDeLaMemoria_v2/triangulo.h

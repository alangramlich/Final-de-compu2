QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
LIBS = -lOpengl32
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
        ../Graficador2D/Juego_SC.cpp \
        ../Graficador2D/dibujo.cpp \
        ../SaltoDelCaballo_OpenGL/caballo.cpp \
        ../SaltoDelCaballo_OpenGL/solversaltocaballo.cpp \
        ../SaltoDelCaballo_OpenGL/tablero.cpp \
        ../SaltoDelCaballo_OpenGL/texto.cpp \
        archivobinario.cpp \
        archivodetexto.cpp \
        graficadordesempenio.cpp \
        interfazdeconsola.cpp \
        main.cpp \
        paciente.cpp

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
    ../CodigoInicial_JuegoDeLaMemoria_v2/triangulo.h \
    ../Graficador2D/Juego_SC.h \
    ../Graficador2D/dibujo.h \
    ../SaltoDelCaballo_OpenGL/caballo.h \
    ../SaltoDelCaballo_OpenGL/solversaltocaballo.h \
    ../SaltoDelCaballo_OpenGL/tablero.h \
    ../SaltoDelCaballo_OpenGL/texto.h \
    archivobinario.h \
    archivodetexto.h \
    graficadordesempenio.h \
    interfazdeconsola.h \
    paciente.h

DISTFILES += \

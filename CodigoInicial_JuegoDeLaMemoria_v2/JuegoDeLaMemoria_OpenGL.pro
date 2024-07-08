QT += core
QT -= gui

LIBS += -lOpenGL32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JuegoDeLaMemoria
TEMPLATE = app

CONFIG += c++11 console
CONFIG -= app_bundle

#LIBS += -lOpenGL32

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    anillo.cpp \
    carta.cpp \
    circulo.cpp \
    cruz.cpp \
    cuadrado.cpp \
    espiral.cpp \
    estrella.cpp \
    figura.cpp \
    flecha.cpp \
    juegodelamemoria.cpp \
    mesa.cpp \
    onda.cpp \
    triangulo.cpp

HEADERS += \
    anillo.h \
    carta.h \
    circulo.h \
    cruz.h \
    cuadrado.h \
    espiral.h \
    estrella.h \
    figura.h \
    flecha.h \
    juegodelamemoria.h \
    mesa.h \
    onda.h \
    pixel.h \
    triangulo.h

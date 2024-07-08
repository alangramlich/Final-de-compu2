QT -= gui

QT += widgets

LIBS += -lOpenGL32

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
        ../Graficador2D/Juego_SC.cpp \
        ../Graficador2D/dibujo.cpp \
        ../Graficador2D/rectangulo.cpp \
        ../SaltoDelCaballo_OpenGL/caballo.cpp \
        ../SaltoDelCaballo_OpenGL/solversaltocaballo.cpp \
        ../SaltoDelCaballo_OpenGL/tablero.cpp \
        ../SaltoDelCaballo_OpenGL/texto.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../Graficador2D/Juego_SC.h \
    ../Graficador2D/dibujo.h \
    ../Graficador2D/rectangulo.h \
    ../SaltoDelCaballo_OpenGL/caballo.h \
    ../SaltoDelCaballo_OpenGL/solversaltocaballo.h \
    ../SaltoDelCaballo_OpenGL/tablero.h \
    ../SaltoDelCaballo_OpenGL/texto.h

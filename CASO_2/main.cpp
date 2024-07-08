#include <QApplication>
#include "../CodigoInicial_JuegoDeLaMemoria_v2/juegodelamemoria.h"
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JuegoDeLaMemoria juego;
    Pixel color_de_fondo(0.5f,0.6f,0.5f);
    juego.setInicianDadasVuelta(true);
    juego.setColorDeFondo(color_de_fondo);
    juego.setTiempoDadasVueltaAlInicio(1000);
    juego.setTiempoDadasVueltaSiSonDiferentes(500);
    juego.seleccionaMazo(1);
    juego.iniciar();
    cout<<"El tiempo que tardo en resolver correctamente el nivel mas alto fue: "<<juego.getTiempoFinDelJuego()<<" segundos.";
    return a.exec();
}

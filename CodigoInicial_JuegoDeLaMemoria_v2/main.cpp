#include <QApplication>
#include <ctime>
#include <iostream>
#include "juegodelamemoria.h"
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(static_cast<unsigned int>(time(nullptr)));

    JuegoDeLaMemoria juego;
    Pixel color_de_fondo(0.5f,0.6f,0.5f);
    juego.setInicianDadasVuelta(true);
    juego.setNivel(1);
    juego.setColorDeFondo(color_de_fondo);
    juego.setTiempoDadasVueltaAlInicio(1000);
    juego.setTiempoDadasVueltaSiSonDiferentes(500);
    juego.iniciar();
    cout<<"El nivel maximo fue: "<<juego.getNivel()<<endl;
    cout<<"El tiempo fue: "<<juego.getTiempoFinDelJuego()<<endl;
    return 0;
}

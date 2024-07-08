#include <QCoreApplication>
#include "../CodigoInicial_JuegoDeLaMemoria_v2/juegodelamemoria.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JuegoDeLaMemoria juego;
    Pixel color_de_fondo(0.5f,0.6f,0.5f);
    juego.setInicianDadasVuelta(true);
    juego.setCASO_TRES(true);
    juego.setColorDeFondo(color_de_fondo);
    juego.setTiempoDadasVueltaAlInicio(1000);
    juego.setTiempoDadasVueltaSiSonDiferentes(500);
    juego.seleccionaMazo(1);
    juego.iniciar();
    return a.exec();
}

#include <QApplication>
#include "../Graficador2D/Juego_SC.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Juego_SC juego(&a);
    juego.setCASO_3(true);
    juego.setNivelInicio(1);
    return a.exec();
}

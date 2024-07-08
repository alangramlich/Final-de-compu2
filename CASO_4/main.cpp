#include <QApplication>
#include "../Graficador2D/Juego_SC.h"
int main(int argc, char *argv[])
{
    //ATENCION: Este caso de prueba FUERZA UNA SOLUCION CORRECTA.
    //Se recomienda probar solo en los niveles 1 y 2.
    //Para el nivel 1 y 2, existen soluciones correctas en las casillas iniciales y se pueden encontrar rapidamente.
    //En el caso del nivel 7: existen soluciones correctas partiendo desde cualquier casilla.
    //Sin embargo, encontrarlas puede llevar tiempo.
    QApplication a(argc, argv);
    Juego_SC solucion(&a);
    solucion.setCASO_4(true);
    solucion.setNivelInicio(1);
    return a.exec();
}

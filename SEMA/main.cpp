#include <QApplication>
#include "archivodetexto.h"
#include "archivobinario.h"
#include "interfazdeconsola.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //"DatosDePacientes_SEMA_v1.txt"
    InterfazDeConsola interfaz(&a);
    int opcion;
    do{
        interfaz.mostrarMenu();
        cin>>opcion;
        interfaz.Opcion(opcion);
    }
    while (opcion!=100);
    return 0;
}

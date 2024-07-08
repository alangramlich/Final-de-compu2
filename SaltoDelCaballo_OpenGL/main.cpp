#include <QApplication>

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "tablero.h"
#include "caballo.h"
#include "texto.h"
#include "../Graficador2D/graficador2d.h"
#include "solversaltocaballo.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    system("chcp 65001");

    srand(unsigned(time(nullptr)));

    Graficador2D graf(&app);
    graf.setNivelInicio(1);

/*
    // Se debe indicar tamaño de tablero y posición inicial del caballo

    // Casos para tablero 5x5: NO existe solución (f,c) en casilleros negros (interesante ¿no?)
    unsigned cantFil = 5;
    unsigned cantCol = 5;
    unsigned filInicial = 2;
    unsigned colInicial = 1;

    // Caso para tablero 5 x 5: Existe solución (en casilleros blancos)
    // cantFil = 5;
    // cantCol = 5;
    // filInicial = 1;
    // colInicial = 1;

    // Máxima profundiad de soluciones: Contando la posición inicial, indica el salto más profundo que será correcto (a menos que otra condición lo impida, como una limitación por tiempo por ejemplo).
    unsigned maxProfundidad = cantFil*cantCol; // Probar un número menor para probar.
    // maxProfundidad = cantFil*cantCol/2;

    // Se crea graficador
    Graficador2D graficador(&app);

    // Se crea dibujo de un tablero
    Tablero dib_tablero(cantFil, cantCol);

    // Se carga dibujo de tablero en graficador
    graficador.cargarDibujo( &dib_tablero );

    // Se crea un solver para generar una solución del problema del caballo
    SolverSaltoCaballo solver;

    // Se inidca al solver la profundiad máxima de las soluciones que se desea. Esto permite crear "soluciones incorrectas" a gusto.
    solver.setProfundidadMaxima(maxProfundidad);

    // Se indica al solver que se desea imprimir el resultado por consola para testeos
    solver.setImprimirSolucion(true); // false: para no imprimir
    solver.setMostrarPosicionesIncorrectas(false);

    // Se establece un tiempo límite de 2 segundos para encontrar la solución (para evitar demoras!)
    solver.setFinalizarPorTiempo(true); // Se debe habilitar opción. (Si es falsa, el algoritmo busca sin parar hasta encontrar una solución; y puede demorar un largo tiempo)
    solver.setLimiteDeTiempo(2); // En segundos. Si coloca 0, por lo general todo será incorrecto, excepto posición inicial.

    // Se crea una solución en blanco que será rellenada por el solver.
    Solucion sol;

    //Se genera trayecto de un caballo por todos los cuadros de un tablero de ajedrez
    sol = solver.generarUnaSolucionDesde(filInicial, colInicial, cantFil, cantCol);

    //Se muestran algunos parámetros de la solución
    cout << "El resultado es: " << (sol.correcta?"CORRECTO":"INCORRECTO") << endl << endl;

    //Se cargan en el graficador los "dibujos de los textos" que contienen el número correspondiente
    //  a cada casillero del tablero
    for(unsigned int i=0; i<sol.texto_posiciones.size(); ++i){
        graficador.cargarDibujo( &(sol.texto_posiciones[i]) );
    }

    //Se cargan los dibujos del caballo en su posición inicial y final
    graficador.cargarDibujo( &sol.caballo_inicial );
    graficador.cargarDibujo( &sol.caballo_final );

    //Se muestra el gráfico
    graficador.mostrar(400, 400);

    if(!sol.correcta){
        solver.setMostrarPosicionesIncorrectas(true);
        sol = solver.getSol(); // Se retorna solución con nuevos colores

        graficador.limpiarDibujos();
        graficador.cargarDibujo( &dib_tablero );
        for(unsigned int i=0; i<sol.texto_posiciones.size(); ++i){
            graficador.cargarDibujo( &(sol.texto_posiciones[i]) );
        }
        //Se cargan los dibujos del caballo en su posición inicial y final
        graficador.cargarDibujo( &sol.caballo_inicial );
        graficador.cargarDibujo( &sol.caballo_final );
        //Se muestra el gráfico
        graficador.mostrar(400, 400);
    }

    // ******************************************************+***
    // **********************************************************
    // *** Prueba de un nuevo juego con diferentes parámetros ***
    // ****************************************************+*****
    // **********************************************************

    //Se genera trayecto de un caballo por todos los cuadros de un tablero de ajedrez
    filInicial = 3;
    colInicial = 2;
    cantFil = 8;
    cantCol = 8;

    maxProfundidad = cantFil*cantCol;

    // ***************************************************************
    // Seteos del solver: Aquí Usted podría modificar cosas a gusto
    // ***************************************************************
    solver.setProfundidadMaxima(maxProfundidad);
    solver.setImprimirSolucion(true); // false: para no imprimir
    solver.setMostrarPosicionesIncorrectas(false);
    solver.setFinalizarPorTiempo(true); // Se debe habilitar opción. (Si es falsa, el algoritmo busca sin parar hasta encontrar una solución; y puede demorar un largo tiempo)
    solver.setLimiteDeTiempo(2); // En segundos. Si coloca 0, por lo general todo será incorrecto, excepto posición inicial.
    // *********************************************

    // Se genera nueva solución
    sol = solver.generarUnaSolucionDesde(filInicial, colInicial, cantFil, cantCol);

    // ESTO ES NUEVO: Se limpian los dibujos del graficador para poder graficar nuevamente.
    graficador.limpiarDibujos();
    Tablero dib_tablero2(cantFil, cantCol);
    graficador.cargarDibujo(&dib_tablero2);

    //Se muestran algunos parámetros de la solución
    cout << "El resultado es: " << (sol.correcta?"CORRECTO":"INCORRECTO") << endl << endl;

    //Se cargan en el graficador los "dibujos de los textos" que contienen el número correspondiente
    //  a cada casillero del tablero
    for(unsigned int i=0; i<sol.texto_posiciones.size(); ++i){
        graficador.cargarDibujo( &(sol.texto_posiciones[i]) );
    }

    //Se cargan los dibujos del caballo en su posición inicial y final
    graficador.cargarDibujo( &sol.caballo_inicial );
    graficador.cargarDibujo( &sol.caballo_final );

    //Se muestra el gráfico
    graficador.mostrar(400, 400);

    if(!sol.correcta){
        solver.setMostrarPosicionesIncorrectas(true);
        sol = solver.getSol(); // Se retorna solución con nuevos colores

        graficador.limpiarDibujos();
        graficador.cargarDibujo( &dib_tablero2 );
        for(unsigned int i=0; i<sol.texto_posiciones.size(); ++i){
            graficador.cargarDibujo( &(sol.texto_posiciones[i]) );
        }
        //Se cargan los dibujos del caballo en su posición inicial y final
        graficador.cargarDibujo( &sol.caballo_inicial );
        graficador.cargarDibujo( &sol.caballo_final );
        //Se muestra el gráfico
        graficador.mostrar(400, 400);
    }



    //return app.exec();
    */
    return 0;
}

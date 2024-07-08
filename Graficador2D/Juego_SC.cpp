#include "Juego_SC.h"
#include <iostream>
#include <QOpenGLFunctions>
#include <QMouseEvent>
using namespace std;
Juego_SC::Juego_SC(QApplication *pApp)
{
    if(pApp != nullptr)
        ptr_app = pApp;
    inicio=true;
    borrar=false;
    solver= new SolverSaltoCaballo;
    juegoTerminado=false;
    CASO_4=false;
    CASO_3=false;
    srand(time(0));
}

void Juego_SC::cargarDibujo(Dibujo* pPtr_dib)
{
    if( pPtr_dib != nullptr )
        ptrs_dib.push_back(pPtr_dib);
}

void Juego_SC::limpiarDibujos()
{
    ptrs_dib.clear();
}
void Juego_SC::setearNivel(int nivel)
{{
    switch (nivel){
    case 1:
        limpiarDibujos();
        delete(solver);
        solver=new SolverSaltoCaballo;
        solver->setProfundidadMaxima(5*5);
        solver->setImprimirSolucion(false); // false: para no imprimir
        solver->setMostrarPosicionesIncorrectas(false);
        solver->setFinalizarPorTiempo(true);
        if (CASO_4==true){
            solver->setFinalizarPorTiempo(false);
            dib_tablero2.setCantFilas(5);
            dib_tablero2.setCantColumnas(5);
            solver2=new SolverSaltoCaballo;
            solver2->setGenerar_solucion_incorrecta(false);
            solver2->setProfundidadMaxima(3*3);
            solver2->setImprimirSolucion(false); // false: para no imprimir
            solver2->setMostrarPosicionesIncorrectas(true);
            solver2->setFinalizarPorTiempo(true);
            solver2->setLimiteDeTiempo(2);
            sol2 = solver2->generarUnaSolucionDesde(0, 0, 5, 5);
        }
        solver->setLimiteDeTiempo(2);
        sol = solver->generarUnaSolucionDesde(0, 0, 5, 5);
        dib_tablero.setCantFilas(5);
        dib_tablero.setCantColumnas(5);
        cargarDibujo(&dib_tablero);
        //cout << "El resultado es: " << (sol.correcta?"CORRECTO":"INCORRECTO") << endl << endl;
        //Se cargan en el graficador los "dibujos de los textos" que contienen el número correspondiente
        //  a cada casillero del tablero
        for(unsigned int i=0; i<sol.texto_posiciones.size(); ++i){
            cargarDibujo( &(sol.texto_posiciones[i]) );
        }
        //Se cargan los dibujos del caballo en su posición inicial y final
        cargarDibujo( &sol.caballo_inicial );
        cargarDibujo( &sol.caballo_final );

        //Se muestra el gráfico
        if (inicio==true){
            tiempoDeInicio=time(0);
            inicio=false;
            mostrar(400, 400);
        }
        break;
    case 2:
        limpiarDibujos();
        delete(solver);
        solver=new SolverSaltoCaballo;
        dib_tablero.setCantFilas(5);
        dib_tablero.setCantColumnas(5);
        cargarDibujo(&dib_tablero);
        solver->setProfundidadMaxima(5*5);
        solver->setImprimirSolucion(false); // false: para no imprimir
        solver->setMostrarPosicionesIncorrectas(false);
        solver->setFinalizarPorTiempo(true);
        if (CASO_4==true){
            solver->setFinalizarPorTiempo(false);
            dib_tablero2.setCantFilas(5);
            dib_tablero2.setCantColumnas(5);
            solver2=new SolverSaltoCaballo;
            solver2->setGenerar_solucion_incorrecta(false);
            solver2->setProfundidadMaxima(3*3);
            solver2->setImprimirSolucion(false); // false: para no imprimir
            solver2->setMostrarPosicionesIncorrectas(true);
            solver2->setFinalizarPorTiempo(true);
            solver2->setLimiteDeTiempo(2);
            sol2 = solver2->generarUnaSolucionDesde(2, 2, 5, 5);
        }
        solver->setLimiteDeTiempo(2);
        sol=solver->generarUnaSolucionDesde(2, 2, 5, 5);
        //cout << "El resultado es: " << (sol.correcta?"CORRECTO":"INCORRECTO") << endl << endl;
        //Se cargan en el graficador los "dibujos de los textos" que contienen el número correspondiente
        //  a cada casillero del tablero
        for(unsigned int i=0; i<sol.texto_posiciones.size(); ++i){
            cargarDibujo( &(sol.texto_posiciones[i]) );
        }

        //Se cargan los dibujos del caballo en su posición inicial y final
        cargarDibujo( &sol.caballo_inicial );
        cargarDibujo( &sol.caballo_final );

        //Se muestra el gráfico
        if (inicio==true){
            tiempoDeInicio=time(0);
            inicio=false;
            mostrar(400, 400);
            }
        break;
    case 3:
        limpiarDibujos();
        delete(solver);
        solver=new SolverSaltoCaballo;
        dib_tablero.setCantFilas(5);
        dib_tablero.setCantColumnas(5);
        cargarDibujo(&dib_tablero);
        solver->setProfundidadMaxima(5*5);
        solver->setImprimirSolucion(false); // false: para no imprimir
        solver->setMostrarPosicionesIncorrectas(false);
        solver->setFinalizarPorTiempo(true);
        if (CASO_4==true){
            solver->setFinalizarPorTiempo(false);
            dib_tablero2.setCantFilas(5);
            dib_tablero2.setCantColumnas(5);
            solver2=new SolverSaltoCaballo;
            solver2->setGenerar_solucion_incorrecta(false);
            solver2->setProfundidadMaxima(3*3);
            solver2->setImprimirSolucion(false); // false: para no imprimir
            solver2->setMostrarPosicionesIncorrectas(true);
            solver2->setFinalizarPorTiempo(true);
            solver2->setLimiteDeTiempo(2);
            sol2 = solver2->generarUnaSolucionDesde(rand()%4, rand()%4, 5, 5);
        }
        solver->setLimiteDeTiempo(2);
        sol=solver->generarUnaSolucionDesde(rand()%4, rand()%4, 5, 5);
        //cout << "El resultado es: " << (sol.correcta?"CORRECTO":"INCORRECTO") << endl << endl;
        //Se cargan en el graficador los "dibujos de los textos" que contienen el número correspondiente
        //  a cada casillero del tablero
        for(unsigned int i=0; i<sol.texto_posiciones.size(); ++i){
            cargarDibujo( &(sol.texto_posiciones[i]) );
        }

        //Se cargan los dibujos del caballo en su posición inicial y final
        cargarDibujo( &sol.caballo_inicial );
        cargarDibujo( &sol.caballo_final );

        //Se muestra el gráfico
        if (inicio==true){
            tiempoDeInicio=time(0);
            inicio=false;
            mostrar(400, 400);
            }
        break;
    case 4:
        limpiarDibujos();
        delete(solver);
        solver=new SolverSaltoCaballo;
        dib_tablero.setCantFilas(6);
        dib_tablero.setCantColumnas(6);
        cargarDibujo(&dib_tablero);
        solver->setProfundidadMaxima(6*6);
        solver->setImprimirSolucion(false); // false: para no imprimir
        solver->setMostrarPosicionesIncorrectas(false);
        solver->setFinalizarPorTiempo(true);
        if (CASO_4==true){
            solver->setFinalizarPorTiempo(false);
            dib_tablero2.setCantFilas(6);
            dib_tablero2.setCantColumnas(6);
            solver2=new SolverSaltoCaballo;
            solver2->setGenerar_solucion_incorrecta(false);
            solver2->setProfundidadMaxima(3*3);
            solver2->setImprimirSolucion(false); // false: para no imprimir
            solver2->setMostrarPosicionesIncorrectas(true);
            solver2->setFinalizarPorTiempo(true);
            solver2->setLimiteDeTiempo(2);
            sol2 = solver2->generarUnaSolucionDesde(rand()%5, rand()%5, 6, 6);
        }
        solver->setLimiteDeTiempo(2);
        sol=solver->generarUnaSolucionDesde(rand()%5, rand()%5, 6, 6);
        //cout << "El resultado es: " << (sol.correcta?"CORRECTO":"INCORRECTO") << endl << endl;
        //Se cargan en el graficador los "dibujos de los textos" que contienen el número correspondiente
        //  a cada casillero del tablero
        for(unsigned int i=0; i<sol.texto_posiciones.size(); ++i){
            cargarDibujo( &(sol.texto_posiciones[i]) );
        }

        //Se cargan los dibujos del caballo en su posición inicial y final
        cargarDibujo( &sol.caballo_inicial );
        cargarDibujo( &sol.caballo_final );

        //Se muestra el gráfico
        if (inicio==true){
            tiempoDeInicio=time(0);
            inicio=false;
            mostrar(400, 400);
            }
        break;
    case 5:
        limpiarDibujos();
        delete(solver);
        solver=new SolverSaltoCaballo;
        dib_tablero.setCantFilas(7);
        dib_tablero.setCantColumnas(7);
        cargarDibujo(&dib_tablero);
        solver->setProfundidadMaxima(7*7);
        solver->setImprimirSolucion(false); // false: para no imprimir
        solver->setMostrarPosicionesIncorrectas(false);
        solver->setFinalizarPorTiempo(true);
        if (CASO_4==true){
            solver->setFinalizarPorTiempo(false);
            dib_tablero2.setCantFilas(7);
            dib_tablero2.setCantColumnas(7);
            solver2=new SolverSaltoCaballo;
            solver2->setGenerar_solucion_incorrecta(false);
            solver2->setProfundidadMaxima(3*3);
            solver2->setImprimirSolucion(false); // false: para no imprimir
            solver2->setMostrarPosicionesIncorrectas(true);
            solver2->setFinalizarPorTiempo(true);
            solver2->setLimiteDeTiempo(2);
            sol2 = solver2->generarUnaSolucionDesde(3, 3, 7, 7);
        }
        solver->setLimiteDeTiempo(2);
        sol=solver->generarUnaSolucionDesde(3, 3, 7, 7);
        //cout << "El resultado es: " << (sol.correcta?"CORRECTO":"INCORRECTO") << endl << endl;
        //Se cargan en el graficador los "dibujos de los textos" que contienen el número correspondiente
        //  a cada casillero del tablero
        for(unsigned int i=0; i<sol.texto_posiciones.size(); ++i){
            cargarDibujo( &(sol.texto_posiciones[i]) );
        }

        //Se cargan los dibujos del caballo en su posición inicial y final
        cargarDibujo( &sol.caballo_inicial );
        cargarDibujo( &sol.caballo_final );

        //Se muestra el gráfico
        if (inicio==true){
            tiempoDeInicio=time(0);
            inicio=false;
            mostrar(400, 400);
            }
        break;
    case 6:
        limpiarDibujos();
        delete(solver);
        solver=new SolverSaltoCaballo;
        dib_tablero.setCantFilas(7);
        dib_tablero.setCantColumnas(7);
        cargarDibujo(&dib_tablero);
        solver->setProfundidadMaxima(7*7);
        solver->setImprimirSolucion(false); // false: para no imprimir
        solver->setMostrarPosicionesIncorrectas(false);
        solver->setFinalizarPorTiempo(true);
        if (CASO_4==true){
            solver->setFinalizarPorTiempo(false);
            dib_tablero2.setCantFilas(7);
            dib_tablero2.setCantColumnas(7);
            solver2=new SolverSaltoCaballo;
            solver2->setGenerar_solucion_incorrecta(false);
            solver2->setProfundidadMaxima(3*3);
            solver2->setImprimirSolucion(false); // false: para no imprimir
            solver2->setMostrarPosicionesIncorrectas(true);
            solver2->setFinalizarPorTiempo(true);
            solver2->setLimiteDeTiempo(2);
            sol2 = solver2->generarUnaSolucionDesde(rand()%6, rand()%6, 7, 7);
        }
        solver->setLimiteDeTiempo(2);
        sol=solver->generarUnaSolucionDesde(rand()%6, rand()%6, 7, 7);
        //cout << "El resultado es: " << (sol.correcta?"CORRECTO":"INCORRECTO") << endl << endl;
        //Se cargan en el graficador los "dibujos de los textos" que contienen el número correspondiente
        //  a cada casillero del tablero
        for(unsigned int i=0; i<sol.texto_posiciones.size(); ++i){
            cargarDibujo( &(sol.texto_posiciones[i]) );
        }

        //Se cargan los dibujos del caballo en su posición inicial y final
        cargarDibujo( &sol.caballo_inicial );
        cargarDibujo( &sol.caballo_final );

        //Se muestra el gráfico
        if (inicio==true){
            tiempoDeInicio=time(0);
            inicio=false;
            mostrar(400, 400);
            }
        break;
    case 7:
        limpiarDibujos();
        delete(solver);
        solver=new SolverSaltoCaballo;
        dib_tablero.setCantFilas(8);
        dib_tablero.setCantColumnas(8);
        cargarDibujo(&dib_tablero);
        solver->setProfundidadMaxima(8*8);
        solver->setImprimirSolucion(false); // false: para no imprimir
        solver->setMostrarPosicionesIncorrectas(false);
        solver->setFinalizarPorTiempo(true);
        if (CASO_4==true){
            solver->setFinalizarPorTiempo(false);
            dib_tablero2.setCantFilas(8);
            dib_tablero2.setCantColumnas(8);
            solver2=new SolverSaltoCaballo;
            solver2->setGenerar_solucion_incorrecta(false);
            solver2->setProfundidadMaxima(3*3);
            solver2->setImprimirSolucion(false); // false: para no imprimir
            solver2->setMostrarPosicionesIncorrectas(true);
            solver2->setFinalizarPorTiempo(true);
            solver2->setLimiteDeTiempo(2);
            sol2 = solver2->generarUnaSolucionDesde(rand()%7, rand()%7, 8, 8);
        }
        solver->setLimiteDeTiempo(2);
        sol=solver->generarUnaSolucionDesde(rand()%7, rand()%7, 8, 8);
        //cout << "El resultado es: " << (sol.correcta?"CORRECTO":"INCORRECTO") << endl << endl;
        //Se cargan en el graficador los "dibujos de los textos" que contienen el número correspondiente
        //  a cada casillero del tablero
        for(unsigned int i=0; i<sol.texto_posiciones.size(); ++i){
            cargarDibujo( &(sol.texto_posiciones[i]) );
        }

        //Se cargan los dibujos del caballo en su posición inicial y final
        cargarDibujo( &sol.caballo_inicial );
        cargarDibujo( &sol.caballo_final );

        //Se muestra el gráfico
        if (inicio==true){
            tiempoDeInicio=time(0);
            inicio=false;
            mostrar(400, 400);
            }
        break;
    case 8:
        limpiarDibujos();
        delete(solver);
        solver=new SolverSaltoCaballo;
        dib_tablero.setCantFilas(9);
        dib_tablero.setCantColumnas(9);
        cargarDibujo(&dib_tablero);
        solver->setProfundidadMaxima(9*9);
        solver->setImprimirSolucion(false); // false: para no imprimir
        solver->setMostrarPosicionesIncorrectas(false);
        solver->setFinalizarPorTiempo(true);
        if (CASO_4==true){
            solver->setFinalizarPorTiempo(false);
            dib_tablero2.setCantFilas(9);
            dib_tablero2.setCantColumnas(9);
            solver2=new SolverSaltoCaballo;
            solver2->setGenerar_solucion_incorrecta(false);
            solver2->setProfundidadMaxima(3*3);
            solver2->setImprimirSolucion(false); // false: para no imprimir
            solver2->setMostrarPosicionesIncorrectas(true);
            solver2->setFinalizarPorTiempo(true);
            solver2->setLimiteDeTiempo(2);
            sol2 = solver2->generarUnaSolucionDesde(rand()%8, rand()%8, 9, 9);
        }
        solver->setLimiteDeTiempo(2);
        sol=solver->generarUnaSolucionDesde(rand()%8, rand()%8, 9, 9);
        //cout << "El resultado es: " << (sol.correcta?"CORRECTO":"INCORRECTO") << endl << endl;
        //Se cargan en el graficador los "dibujos de los textos" que contienen el número correspondiente
        //  a cada casillero del tablero
        for(unsigned int i=0; i<sol.texto_posiciones.size(); ++i){
            cargarDibujo( &(sol.texto_posiciones[i]) );
        }

        //Se cargan los dibujos del caballo en su posición inicial y final
        cargarDibujo( &sol.caballo_inicial );
        cargarDibujo( &sol.caballo_final );

        //Se muestra el gráfico
        if (inicio==true){
            tiempoDeInicio=time(0);
            inicio=false;
            mostrar(400, 400);
            }
        break;
    case 9:
        //tiempoDeFin=time(0);
        cout<<"Niveles completados con exito."<<endl;
        break; 
    }


    /*case 400:
        CASO_4=true;
        //hago la solucion correcta
        limpiarDibujos();
        delete(solver);
        solver=new SolverSaltoCaballo;
        solver->setProfundidadMaxima(5*5);
        solver->setImprimirSolucion(false); // false: para no imprimir
        solver->setMostrarPosicionesIncorrectas(false);
        solver->setFinalizarPorTiempo(true);
        solver->setLimiteDeTiempo(2);
        sol = solver->generarUnaSolucionDesde(0, 0, 5, 5);
        dib_tablero.setCantFilas(5);
        dib_tablero.setCantColumnas(5);
        cargarDibujo(&dib_tablero);
        //cout << "El resultado es: " << (sol.correcta?"CORRECTO":"INCORRECTO") << endl << endl;
        //Se cargan en el graficador los "dibujos de los textos" que contienen el número correspondiente
        //  a cada casillero del tablero
        for(unsigned int i=0; i<sol.texto_posiciones.size(); ++i){
            cargarDibujo( &(sol.texto_posiciones[i]) );
        }
        //Se cargan los dibujos del caballo en su posición inicial y final
        cargarDibujo( &sol.caballo_inicial );
        cargarDibujo( &sol.caballo_final );

        //Se muestra el gráfico
        if (inicio==true){
            tiempoDeInicio=time(0);
            inicio=false;
            mostrar(400, 400);
        }
        break;*/
    }



    update();
}


void Juego_SC::mostrar(int w, int h)
{
    resize(w,h);
    show();
    if(ptr_app != nullptr)
        ptr_app->exec();
}

void Juego_SC::mousePressEvent(QMouseEvent *event)
{
    if (CASO_4==false and CASO_3==false){
    if(juegoTerminado==false){
    if(event->button() == Qt::LeftButton){
        double posX = event->x() * ((float)maxX+1.5) / width();
        double posY = (height()-event->y()) * ((float)maxY) / height();
        posY=(float)posY*1.2;
         if (posX>=maxX && posY>0.5 && posX<maxX+1 && posY<(float)maxY/2+0.6){
             //cout<<"ROJO";
             eleccion=false;
             resumenDelNivel();
                      }
         if (posX>=maxX && posY>(float)maxY/2+0.6 && posX<maxX+1 && posY<(float)maxY+0.6){
             eleccion=true;
             //cout<<"VERDE";
             resumenDelNivel();
         }

    }
    }
update();
    }}

void Juego_SC::setCASO_3(bool value)
{
    CASO_3 = value;
}

int Juego_SC::getNivel() const
{
    return nivel;
}

int Juego_SC::getTiempoDeFin() const
{
    return tiempoDeFin;
}

void Juego_SC::setCASO_4(bool value)
{
    CASO_4 = value;
}

void Juego_SC::setNivelInicio(int value)
{
    nivel = value;
    setearNivel(nivel);
}

bool Juego_SC::getEleccion() const
{
    return eleccion;
}

void Juego_SC::determinarDimensiones()
{
    if(ptrs_dib.size()>0){
        if(ptrs_dib[0] != nullptr){
            minX = ptrs_dib[0]->getMinX();
            maxX = ptrs_dib[0]->getMaxX();
            minY = ptrs_dib[0]->getMinY();
            maxY = ptrs_dib[0]->getMaxY();

            for(unsigned int i=1; i<ptrs_dib.size(); ++i) {
                if(ptrs_dib[i] != nullptr){
                    if(minX > ptrs_dib[i]->getMinX())
                        minX = ptrs_dib[i]->getMinX();
                    if(maxX < ptrs_dib[i]->getMaxX())
                        maxX = ptrs_dib[i]->getMaxX();
                    if(minY > ptrs_dib[i]->getMinY())
                        minY = ptrs_dib[i]->getMinY();
                    if(maxY < ptrs_dib[i]->getMaxY())
                        maxY = ptrs_dib[i]->getMaxY();
                }
            }
        }
    }
}

void Juego_SC::resumenDelNivel()
{
    bool IGNORAR_IFS_SIGUIENTES=false;
    if (eleccion==true && sol.correcta==true && IGNORAR_IFS_SIGUIENTES==false){
        IGNORAR_IFS_SIGUIENTES=true;
        cout<<"Eleccion correcta. Nivel superado."<<endl;
        nivel++;
        tiempoDeFin=time(0)-tiempoDeInicio;
        //cout<<"Tiempo en resolver el nivel: "<<tiempoDeFin<<endl;
        tiempoDeInicio=time(0);
        borrar=true;
        limpiarDibujos();
        setearNivel(nivel);
    }
    if (eleccion==false && sol.correcta==false && IGNORAR_IFS_SIGUIENTES==false){
        IGNORAR_IFS_SIGUIENTES=true;
        cout<<"Eleccion correcta. Nivel superado."<<endl;
        nivel++;
        tiempoDeFin=time(0)-tiempoDeInicio;
        //cout<<"Tiempo en resolver el nivel: "<<tiempoDeFin<<endl;
        tiempoDeInicio=time(0);
        borrar=true;
        limpiarDibujos();
        setearNivel(nivel);
    }
    if (eleccion==true && sol.correcta==false && IGNORAR_IFS_SIGUIENTES==false){
        IGNORAR_IFS_SIGUIENTES=true;
        cout<<"Eleccion incorrecta. Se muestra la solucion en ventana."<<endl;
        juegoTerminado=true;
        //nivel++;

            solver->setMostrarPosicionesIncorrectas(true);
            sol = solver->getSol(); // Se retorna solución con nuevos colores

            limpiarDibujos();
            cargarDibujo( &dib_tablero );
            for(unsigned int i=0; i<sol.texto_posiciones.size(); ++i){
                cargarDibujo( &(sol.texto_posiciones[i]) );
            }
            //Se cargan los dibujos del caballo en su posición inicial y final
            cargarDibujo( &sol.caballo_inicial );
            cargarDibujo( &sol.caballo_final );
            //Se muestra el gráfico
            update();

    }
    if (eleccion==false && sol.correcta==true && IGNORAR_IFS_SIGUIENTES==false){
        IGNORAR_IFS_SIGUIENTES=true;
        cout<<"Eleccion incorrecta. Se muestra la solucion en ventana."<<endl;
        juegoTerminado=true;
            //nivel++;
            solver->setMostrarPosicionesIncorrectas(true);
            sol = solver->getSol(); // Se retorna solución con nuevos colores

            limpiarDibujos();
            cargarDibujo( &dib_tablero );
            for(unsigned int i=0; i<sol.texto_posiciones.size(); ++i){
                cargarDibujo( &(sol.texto_posiciones[i]) );
            }
            //Se cargan los dibujos del caballo en su posición inicial y final
            cargarDibujo( &sol.caballo_inicial );
            cargarDibujo( &sol.caballo_final );
            //Se muestra el gráfico
            update();

    }
}

void Juego_SC::initializeGL()
{
    glClearColor(1,1,1,0); // fondo blanco
}

void Juego_SC::resizeGL(int w, int h)
{
    if (CASO_3==false and CASO_4==false){
        determinarDimensiones(); // Se actualizan dimensiones
        if (w>h)
            glViewport(0,0,h,h);
        if (w<h)
            glViewport(0,0,w,w);
        if(w==h)
            glViewport(0,0,w,h);
        //glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho( minX, maxX+1, minY, maxY, -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
    if (CASO_4 == true){
        determinarDimensiones();
        if (w>h)
            glViewport(0,0,h,h);
        if (w<h)
            glViewport(0,0,w,w);
        if(w==h)
            glViewport(0,0,w,h);
        //glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho( minX, 2*(maxX+1), minY, maxY, -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
    if (CASO_3 == true){
        determinarDimensiones(); // Se actualizan dimensiones
        if (w>h)
            glViewport(0,0,h,h);
        if (w<h)
            glViewport(0,0,w,w);
        if(w==h)
            glViewport(0,0,w,h);
        //glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho( minX, maxX+1, minY, maxY, -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
}

void Juego_SC::paintGL()
{
resizeGL(width(), height());
glClear(GL_COLOR_BUFFER_BIT);
for(unsigned int i=0; i<ptrs_dib.size(); ++i){
if( ptrs_dib[i] != nullptr ){
ptrs_dib[i]->dibujar();
}
}
if (CASO_4==true){
    glPushMatrix();
    glTranslatef(maxX+1, 0, 0);

    dib_tablero2.dibujar();
    for(unsigned int i=0; i<sol2.texto_posiciones.size(); ++i){
        sol2.texto_posiciones[i].dibujar();
    }
    sol2.caballo_inicial.dibujar();
    sol2.caballo_final.dibujar();

    glPopMatrix();
}
}



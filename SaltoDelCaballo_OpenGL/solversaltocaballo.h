#ifndef SOLVERSALTOCABALLO_H
#define SOLVERSALTOCABALLO_H

#include <iostream>
#include <iomanip>
#include <vector>

#include "caballo.h"
#include "texto.h"

using namespace std;
///
/// \brief The Solucion class. Almacena informacion de una solucion.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class Solucion{
public:
    Caballo caballo_inicial, caballo_final;
    vector<bool> posiciones_correctas; // true donde el salto del caballo es correcto
    vector<Texto> texto_posiciones;
    vector<int> tablero; // tablero como un arreglo 1D
    bool correcta;
    Solucion(int filIni=0, int colIni=0){
        caballo_inicial.setPosicion(colIni, filIni);
        correcta = false;
    }
};
///
/// \brief SolverSaltoCaballo class. Esta clase encuentra soluciones al problema del salto del caballo.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class SolverSaltoCaballo{
public:
    SolverSaltoCaballo();

    ///
    /// \brief Setea la opcion de finalizar la busqueda de una solucion por tiempo.
    /// \param pBandera
    ///
    void setFinalizarPorTiempo(bool pBandera);
    ///
    /// \brief Setea la opcion para imprimir la solucion por pantalla.
    /// \param pBandera
    ///
    void setImprimirSolucion(bool pBandera);
    ///
    /// \brief Setea la opcion para mostrar las posiciones incorrectas con otro color.
    /// \param pBandera
    ///
    void setMostrarPosicionesIncorrectas(bool pBandera);
    ///
    /// \brief Setea la profundidad maxima de la solucion que se esta buscando.
    /// \param pMaxProfundidad
    ///
    void setProfundidadMaxima(unsigned pMaxProfundidad);
    ///
    /// \brief Limita el tiempo para obtener la solucion.
    /// \param segundos
    ///
    void setLimiteDeTiempo(unsigned int segundos);
    ///
    /// \brief Setea el color en que se dibuja el caballo en la posicion de inicio.
    /// \param pR
    /// \param pG
    /// \param pB
    ///
    void setColorCaballoInicial(float pR=0, float pG=0.5, float pB=0);
    ///
    /// \brief Setea el color en que se dibuja el caballo en la posicion final.
    /// \param pR
    /// \param pG
    /// \param pB
    ///
    void setColorCaballoFinal(float pR=0, float pG=1, float pB=0);

    ///
    /// \brief Genera una solucion con los parametros seteados anteriormente.
    /// \param pF Posicion inicial del caballo.
    /// \param pC Posicion inicial del caballo.
    /// \param pCantFil Dimensiones del tablero.
    /// \param pCantCol Dimensiones del tablero.
    /// \return Retorna la solucion encontrada.
    ///
    Solucion generarUnaSolucionDesde(int pF, int pC, int pCantFil, int pCantCol);
    ///
    /// \brief getSol
    /// \return Retorna la ultima solucion encontrada.
    ///
    Solucion getSol() const;

    ~SolverSaltoCaballo();
    ///
    /// \brief Setea la opcion para generar una solucion totalmente incorrecta. Si su valor es true, ningun salto de caballo sera valido.
    /// \param value
    ///
    void setGenerar_solucion_incorrecta(bool value);

private:
    int cantFil, cantCol;
    int* tablero;
    int dfila[8];
    int dcol[8];
    Solucion sol; // Una solución al problema (puede ser correcta o incorrecta)
    bool volcarSolucionEnConsola;
    bool generar_solucion_incorrecta;

    // Parámetros varios
    vector<float> colorCabInicial, colorCabFinal;
    bool resaltarPosicionesIncorrectas;

    // Métodos privados
    ///
    /// \brief Inicia el algoritmo recursivo para encontrar una solucion desde la posicion indicada.
    /// \brief Analiza si la solucion encontrada es o no correcta.
    /// \param xinic Coordenada X inicial
    /// \param yinic Coordenada Y inicial.
    ///
    void salta(int xinic, int yinic);
    ///
    /// \brief Algoritmo recursivo. Busca un salto correcto y, a partir de ese salto, busca un siguiente salto correcto.
    /// \brief Esto se repite hasta que en la casilla actual no exista ningun movimiento correcto posible.
    /// \param finic
    /// \param cinic
    /// \param nsalto
    /// \param sol_mas_profunda
    /// \param intento
    /// \param c_inicial
    /// \param pos_mas_profunda
    ///
    void salta_recursivo(int finic, int cinic, int nsalto,
                         vector<int> &sol_mas_profunda,
                         int &intento, int &c_inicial,
                         int &pos_mas_profunda);
    ///
    /// \brief Imprime la solucion por consola.
    ///
    void imprimirSolucion();

    // Variables auxiliares de algoritmo recursivo
    bool salir;

    // Variables para finalizar por límite de tiempo
    bool finalizar_por_tiempo;
    bool mostrar_solucion_mas_profunda;
    unsigned int tiempo_limite; // En segundos
    int max_profundidad;
};

#endif // SOLVERSALTOCABALLO_H

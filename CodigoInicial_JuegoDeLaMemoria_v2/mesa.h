#ifndef MESA_H
#define MESA_H

#include <stdio.h>

#include "carta.h"

///
/// \brief The Mesa class. Esta clase simula una mesa de juego en donde se acomodan las cartas.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class Mesa
{
public:
    Mesa();
    ~Mesa();

    /*!
     * \brief Rellena la mesa con las cartas recibidas en masoDeCartas
     * \param pCantFilas: cantidad de filas
     * \param pCantColumnas: cantidad de columnas
     * \param mazoDeCartas: mazo de cartas a repartir
     */
    void repartirCartas(unsigned pCantFilas, unsigned pCantColumnas, vector<Carta*> mazoDeCartas);

    /*!
     * \brief Mezcla las cartas para comenzar una nueva partida
     */
    void mezclarCartas();

    /*!
     * \brief operator () Retorna la carta que se encuentra en una posición fila-columna
     * \param fil: fila seleccionada
     * \param col: columna seleccionada
     * \return Puntero a la carta seleccionada
     */
    Carta* operator()(unsigned fil, unsigned col);

    void dibujar();
    unsigned getCantFilas() const;
    unsigned getCantColumnas() const;

private:
    unsigned cantFilas;
    unsigned cantColumnas;

    vector<vector<Carta*>> distribucionDeCartas;
    vector<Carta*> mazoDeCartas;
};

#endif // MESA_H

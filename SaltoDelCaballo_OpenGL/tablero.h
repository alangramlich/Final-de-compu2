#ifndef TABLERO_H
#define TABLERO_H
#include "../Graficador2D/dibujo.h"

///
/// \brief The Tablero class. Clase derivada de Dibujo. Dibuja un tablero de ajedrez con dos botones al costado.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class Tablero : public Dibujo
{
public:
    Tablero();
    ///
    /// \brief Inicializa un tablero con sus atributos principales.
    /// \param pCantFil
    /// \param pCantCol
    ///
    Tablero(unsigned int pCantFil, unsigned int pCantCol);

    void dibujar() override;

    void setCantFilas(unsigned int value);

    void setCantColumnas(unsigned int value);

private:
    // Atributos
    unsigned int cantFilas, cantColumnas;
    // Métodos auxiliares
    void dibujarCuadrado(float x1, float y1, float lado);
    void dibujarRectangulo(float x1, float y1, float lado1, float lado2);
    void dibujarBotones();
};

#endif // TABLERO_H

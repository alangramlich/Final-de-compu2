#ifndef CUADRADO_H
#define CUADRADO_H

#include "figura.h"
///
/// \brief The Cuadrado class. Clase derivada de figura.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class Cuadrado: public Figura
{
public:
    ///
    /// \brief Cuadrado
    /// \param pColor
    ///
    Cuadrado(Pixel pColor);
    ~Cuadrado();
    ///
    /// \brief dibujar
    ///
    void dibujar();
};

#endif // CUADRADO_H

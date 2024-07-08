#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "figura.h"
///
/// \brief The Triangulo class. Clase derivada de figura.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class Trianglo: public Figura
{
public:
    ///
    /// \brief Trianglo
    /// \param pColor
    ///
    Trianglo(Pixel pColor);
    ~Trianglo();

    void dibujar();
};

#endif // TRIANGULO_H

#ifndef CIRCULO_H
#define CIRCULO_H

#include "figura.h"
///
/// \brief The Circulo class. Clase derivada de figura.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class Circulo: public Figura
{
public:
    ///
    /// \brief Circulo
    /// \param pColor
    ///
    Circulo(Pixel pColor);

    ~Circulo();
    ///
    /// \brief dibujar
    ///
    void dibujar();
};

#endif // CIRCULO_H

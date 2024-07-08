#ifndef ESTRELLA_H
#define ESTRELLA_H

#include "figura.h"
///
/// \brief The Estrella class. Clase derivada de figura.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class Estrella: public Figura
{
public:
    ///
    /// \brief Estrella
    /// \param pColor
    ///
    Estrella(Pixel pColor);
    ~Estrella();
    ///
    /// \brief dibujar
    ///
    void dibujar();
};

#endif // ESTRELLA_H

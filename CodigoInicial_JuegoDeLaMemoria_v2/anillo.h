#ifndef ANILLO_H
#define ANILLO_H

#include "figura.h"
///
/// \brief The Anillo class. Clase derivada de figura.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class Anillo: public Figura
{
public:
    ///
    /// \brief Anillo
    /// \param pColor
    ///
    Anillo(Pixel pColor);
    ~Anillo();
    ///
    /// \brief dibujar
    ///
    void dibujar();
};

#endif // ANILLO_H

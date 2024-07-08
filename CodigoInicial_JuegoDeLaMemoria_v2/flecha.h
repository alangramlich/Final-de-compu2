#ifndef FLECHA_H
#define FLECHA_H
#include "figura.h"
///
/// \brief The Flecha class. Clase derivada de figura.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class Flecha: public Figura
{
public:
    ///
    /// \brief Flecha
    /// \param pColor
    ///
    Flecha(Pixel pColor);
    ~Flecha();
    ///
    /// \brief dibujar
    ///
    void dibujar();
};

#endif // FLECHA_H

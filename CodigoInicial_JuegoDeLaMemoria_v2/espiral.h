#ifndef ESPIRAL_H
#define ESPIRAL_H
#include "figura.h"
#include "math.h"
///
/// \brief The Espiral class. Clase derivada de figura.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class Espiral: public Figura
{
public:
    ///
    /// \brief Espiral
    /// \param pColor
    ///
    Espiral(Pixel pColor);
    ~Espiral();
    ///
    /// \brief dibujar
    ///
    void dibujar();
};

#endif // ESPIRAL_H

#ifndef ONDA_H
#define ONDA_H
#include "figura.h"
///
/// \brief The Onda class. Clase derivada de figura.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class Onda: public Figura
{
public:
    ///
    /// \brief Onda
    /// \param pColor
    ///
    Onda(Pixel pColor);
    ~Onda();

    void dibujar();
};

#endif // ONDA_H

#ifndef CRUZ_H
#define CRUZ_H

#include "figura.h"
///
/// \brief The Cruz class. Clase derivada de figura.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class Cruz: public Figura
{
public:
    ///
    /// \brief Cruz
    /// \param pColor
    ///
    Cruz(Pixel pColor);
    ~Cruz();
    ///
    /// \brief dibujar
    ///
    void dibujar();
};

#endif // CRUZ_H

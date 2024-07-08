#ifndef FIGURA_H
#define FIGURA_H

#include <QOpenGLFunctions>

#include "pixel.h"
///
/// \brief The Figura class. Clase abstracta. Esta clase permite dibujar varias figuras distintas por medio de polimorfismo.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class Figura
{
public:
    ///
    /// \brief Figura
    /// \param color
    ///
    Figura(Pixel color);
    ///
    /// \brief Dibuja la figura. En cada clase hija se define de manera apropiada.
    ///
    virtual void dibujar()=0;
    virtual ~Figura();

protected:
    ///
    /// \brief color
    ///
    Pixel color;
};

#endif // FIGURA_H

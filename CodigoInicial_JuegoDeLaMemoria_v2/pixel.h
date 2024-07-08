#ifndef PIXEL_H
#define PIXEL_H
///
/// \brief The Pixel class. Esta clase guarda los datos de un color RGB compatible con funciones de OpenGL.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class Pixel
{
public:
    Pixel(float pR=0.0f, float pG=0.0f, float pB=0.0f)
        { rojo = pR; verde = pG; azul = pB;}
    float rojo, verde, azul;
};

#endif // PIXEL_H

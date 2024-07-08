#ifndef CABALLO_H
#define CABALLO_H
#include "../Graficador2D/dibujo.h"
///
/// \brief The Caballo class. Clase derivada de dibujo.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class Caballo : public Dibujo
{
public:
    Caballo(int pPosX = 0, int pPosY = 0);
    ///
    /// \brief Setea la posicion en la que se desea dibujar el caballo.
    /// \param pX
    /// \param pY
    ///
    void setPosicion(int pX, int pY);
    ///
    /// \brief Setea el color en que se dibuja el caballo.
    /// \param pR
    /// \param pG
    /// \param pB
    ///
    void setColor(float pR, float pG, float pB);

    void dibujar() override;

private:
    float posX, posY; // posición
    float cR, cG, cB; // color
};

#endif // CABALLO_H

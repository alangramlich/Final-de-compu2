#ifndef TEXTO_H
#define TEXTO_H
#include <string>
#include <QOpenGLContext>
#include "../Graficador2D/dibujo.h"
///
/// \brief The Texto class. Clase derivada de Dibujo. Dibuja los numeros correspondientes al salto de caballo.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
using namespace std;

class Texto : public Dibujo
{
public:
    ///
    /// \brief Texto
    /// \param pFrase El numero que se va a dibujar.
    /// \param pX El casillero en que se va a dibujar.
    /// \param pY El casillero en que se va a dibujar.
    /// \param pR Color con el que se dibuja.
    /// \param pG Color con el que se dibuja.
    /// \param pB Color con el que se dibuja.
    ///
    Texto(string pFrase, int pX, int pY, float pR=1, float pG=0, float pB=0);
    ///
    /// \brief Setea el color con el que se dibuja.
    /// \param pR
    /// \param pG
    /// \param pB
    ///
    void setColor(float pR=1, float pG=0, float pB=0);

    void dibujar() override;



private:
    string frase;
    int posX, posY;
    vector<float> color;

    // parámetros de texto
    unsigned int tamTexto = 10;
    unsigned int anchoLineaTexto = 2; // En pixeles

    ///
    /// \brief Dibuja el numero.
    /// \param pTexto Numero que se va a dibujar.
    /// \param pX
    /// \param pY
    /// \param pTam
    ///
    void dibujarTexto(string pTexto, float pX=0, float pY=0, unsigned char pTam=10);
};

#endif // TEXTO_H

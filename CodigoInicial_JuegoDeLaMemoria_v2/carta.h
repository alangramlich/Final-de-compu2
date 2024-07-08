#ifndef CARTA_H
#define CARTA_H

#include<string>
#include <QApplication>
#include <QOpenGLWidget>
#include <QTimer>

#include "triangulo.h"
#include "pixel.h"

using namespace std;
///
/// \brief The Carta class.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
enum figuras {FIG_TRIANGULO = 1, FIG_CUADRADO = 2, FIG_CRUZ = 3,
              FIG_ANILLO = 4, FIG_CIRCULO = 5, FIG_ESTRELLA = 6,
              FIG_FLECHA = 7, FIG_ONDA = 8, FIG_ESPIRAL = 9};

class Carta
{
   // Q_OBJECT
public:
    ///
    /// \brief Carta
    /// \param id
    ///
    Carta(unsigned id);
    ///
    /// \brief Carta
    /// \param id
    /// \param pTipoDeFigura
    /// \param pColor
    ///
    Carta(unsigned id, char pTipoDeFigura, Pixel pColor);

    ~Carta();
    ///
    /// \brief dibujar
    ///
    void dibujar();
    ///
    /// \brief setAngulo
    ///
    void setAngulo(float);
    ///
    /// \brief setColorFondo
    /// \param color
    ///
    void setColorFondo(const Pixel color);
    ///
    /// \brief setFigura
    /// \param pTipoDeFigura
    /// \param color
    ///
    void setFigura(char pTipoDeFigura, Pixel color);
    ///
    /// \brief getVisible
    /// \return
    ///
    bool getVisible() const;
    ///
    /// \brief setVisible
    /// \param value
    ///
    void setVisible(bool value);
    ///
    /// \brief getEstaEmparejada
    /// \return
    ///
    bool getEstaEmparejada() const;
    ///
    /// \brief setEstaEmparejada
    /// \param value
    ///
    void setEstaEmparejada(bool value);
    ///
    /// \brief getId
    ///
    unsigned getId() const;

private:
    ///
    /// \brief angulo
    ///
    float angulo;
    ///
    /// \brief figura
    ///
    Figura* figura;
    ///
    /// \brief visible
    ///
    bool visible;
    ///
    /// \brief estaEmparejada
    ///
    bool estaEmparejada;
    ///
    /// \brief id
    ///
    unsigned id;
    ///
    /// \brief colorDorso
    ///
    Pixel colorDorso;

};

#endif // CARTA_H

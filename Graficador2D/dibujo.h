#ifndef DIBUJO_H
#define DIBUJO_H
///
/// \brief The Dibujo class. Clase abstracta. Esta clase permite dibujar varias figuras por medio de polimorfismo.
/// \details
/// \author     Gramlich Klein Alan
/// \version    2020
/// \date       12/08/2020
/// \pre        Ninguno
/// \bug        Ninguno
/// \warning    Ninguno
/// \copyright  Ninguno
class Dibujo
{
public:
    Dibujo();
    virtual void dibujar() = 0;

    double getMinX();
    double getMaxX();
    double getMinY();
    double getMaxY();

    virtual ~Dibujo() {}

protected:
    double minX, maxX, minY, maxY;

private:
};

#endif // DIBUJO_H

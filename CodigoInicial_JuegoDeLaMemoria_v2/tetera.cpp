#include "tetera.h"


Tetera::Tetera(Pixel pColor) : Figura(pColor)
{

}

Tetera::~Tetera()
{

}

void Tetera::dibujar()
{
    glColor3f(color.rojo, color.verde, color.azul);
    glPushMatrix();
    glBegin(GL_TEAPO)
}

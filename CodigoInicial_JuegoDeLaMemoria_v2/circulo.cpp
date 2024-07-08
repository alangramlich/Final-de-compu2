#include "circulo.h"
#include <math.h>
Circulo::Circulo(Pixel pColor): Figura(pColor)
{

}

Circulo::~Circulo()
{

}

void Circulo::dibujar()
{
    glColor3f(color.rojo, color.verde, color.azul);
    glPushMatrix();
    glBegin(GL_POLYGON);
    for (float i=0; i<2*3.14; i+=0.1)
    glVertex2f(cos(i)*0.6/2+0.5,sin(i)*0.6/2+0.5);
    glEnd();
    glPopMatrix();
}

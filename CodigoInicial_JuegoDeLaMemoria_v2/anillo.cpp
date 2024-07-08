#include "anillo.h"
#include <math.h>
Anillo::Anillo(Pixel pColor) : Figura(pColor)
{

}

Anillo::~Anillo()
{

}

void Anillo::dibujar()
{
    glColor3f(color.rojo, color.verde, color.azul);
    glPushMatrix();
    glBegin(GL_POLYGON);
    for (float i=0; i<2*3.14; i+=0.1)
    glVertex2f(cos(i)*0.6/2+0.5,sin(i)*0.6/2+0.5);
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for (float i=0; i<2*3.14; i+=0.1)
    glVertex2f(cos(i)*0.4/2+0.5,sin(i)*0.4/2+0.5);
    glEnd();
    glPopMatrix();
}

#include "onda.h"
#include "math.h"
Onda::Onda(Pixel pColor): Figura(pColor)
{

}

Onda::~Onda()
{

}

void Onda::dibujar()
{
    glColor3f(color.rojo, color.verde, color.azul);
    glPushMatrix();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    for (float i=0; i<2*3.14; i+=0.1)
    glVertex2f(i/2/3.14*0.6+0.2,sin(i)*0.6/2+0.5);
    glEnd();
    glPopMatrix();
}

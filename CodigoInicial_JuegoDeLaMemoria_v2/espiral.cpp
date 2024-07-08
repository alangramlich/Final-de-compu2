#include "espiral.h"

Espiral::Espiral(Pixel pColor): Figura(pColor)
{

}

Espiral::~Espiral()
{

}

void Espiral::dibujar()
{
    float amplitud=0;
    glColor3f(color.rojo, color.verde, color.azul);
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    for (float i=0; i<25*3.14; i+=0.1){
        amplitud+=0.002;
        glVertex2f((cos(i)*0.6/2)*amplitud+0.5,(sin(i)*0.6/2)*amplitud+0.5);
    }
    glEnd();
    glPopMatrix();
}

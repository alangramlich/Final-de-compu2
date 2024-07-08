#include "triangulo.h"

Trianglo::Trianglo(Pixel pColor) : Figura(pColor)
{

}

void Trianglo::dibujar()
{
    glColor3f(color.rojo, color.verde, color.azul);
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glVertex2f(0.2f,0.2f);
    glVertex2f(0.8f,0.2f);
    glVertex2f(0.5f,0.8f);
    glEnd();
    glPopMatrix();
}

Trianglo::~Trianglo()
{

}

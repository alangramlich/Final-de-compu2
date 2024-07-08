#include "estrella.h"

Estrella::Estrella(Pixel pColor): Figura(pColor)
{

}

Estrella::~Estrella()
{

}

void Estrella::dibujar()
{
    glColor3f(color.rojo, color.verde, color.azul);
    glPushMatrix();
    glLineWidth(3.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.5f,0.81f);
    glVertex2f(0.58f,0.6f);
    glVertex2f(0.8f,0.58f);
    glVertex2f(0.6f,0.458f);
    glVertex2f(0.7f,0.2f);
    glVertex2f(0.5f,0.3f);
    glVertex2f(0.3f,0.2f);
    glVertex2f(0.4f,0.458f);
    glVertex2f(0.2f,0.58f);
    glVertex2f(0.42f,0.6f);
    glVertex2f(0.5f,0.81f);
    glEnd();
    glPopMatrix();
}

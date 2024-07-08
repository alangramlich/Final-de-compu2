#include "flecha.h"

Flecha::Flecha(Pixel pColor): Figura (pColor)
{

}

Flecha::~Flecha()
{

}

void Flecha::dibujar()
{
    glColor3f(color.rojo, color.verde, color.azul);
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex2f(0.4f,0.2f);
    glVertex2f(0.4f,0.55f);
    glVertex2f(0.6f,0.55f);
    glVertex2f(0.6f,0.2f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(0.5f,0.8f);
    glVertex2f(0.7f,0.55f);
    glVertex2f(0.3f,0.55f);
    glEnd();
    glPopMatrix();
}

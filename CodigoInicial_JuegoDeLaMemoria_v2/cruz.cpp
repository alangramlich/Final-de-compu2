#include "cruz.h"

Cruz::Cruz(Pixel pColor) : Figura(pColor)
{

}

Cruz::~Cruz()
{

}

void Cruz::dibujar()
{
    glColor3f(color.rojo, color.verde, color.azul);
    glPushMatrix();
    glPushAttrib(GL_LINE_WIDTH);
    glLineWidth(15.0);
    glBegin(GL_LINES);
    glVertex2f(0.2f,0.2f);
    glVertex2f(0.8f,0.8f);
    glVertex2f(0.2f,0.8f);
    glVertex2f(0.8f,0.2f);
    glEnd();
    glPopAttrib();
    glPopMatrix();
}

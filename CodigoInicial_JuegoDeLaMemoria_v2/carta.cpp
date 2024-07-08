#include "carta.h"
#include "triangulo.h"
#include "cuadrado.h"
#include "cruz.h"
#include "anillo.h"
#include "circulo.h"
#include "espiral.h"
#include "estrella.h"
#include "flecha.h"
#include "onda.h"
#include <QOpenGLFunctions>

Carta::Carta(unsigned id)
{       
    Pixel colorDorsoCarta = Pixel();
    *this = Carta(id, -1, colorDorsoCarta);    
}

Carta::Carta(unsigned id, char pTipoDeFigura, Pixel pColor)
{   
    this->id = id;
    figura = nullptr;
    visible = false;
    estaEmparejada = false;
    if(pTipoDeFigura != -1)
        setFigura(pTipoDeFigura, pColor);
}

Carta::~Carta()
{
    if(figura!=nullptr){
        delete figura;
        figura = nullptr;
    }
}

void Carta::dibujar()
{

    if (visible) {
        glColor3f(1.0,1.0,1.0);
        glPushMatrix();
        glScalef(1,1,1.0);
        glTranslatef(0.5, 0.5, 0);
        glRotatef(angulo, 0, 1, 0);
        glTranslatef(-0.5, -0.5, 0);
        glBegin(GL_QUADS);
        glVertex2f(0,0);
        glVertex2f(1,0);
        glVertex2f(1,1);
        glVertex2f(0,1);
        glEnd();
        //glPopMatrix();
        //glPushMatrix();
        if (figura!=nullptr)
            figura->dibujar();
        glPopMatrix();

    }
    else{
        glColor3f(colorDorso.rojo, colorDorso.verde, colorDorso.azul);
        glPushMatrix();
        glScalef(1,1,1.0);
        glTranslatef(0.5, 0.5, 0);
        glRotatef(angulo, 0, 1, 0);
        glTranslatef(-0.5, -0.5, 0);
        glBegin(GL_QUADS);
        glVertex2f(0,0);
        glVertex2f(1,0);
        glVertex2f(1,1);
        glVertex2f(0,1);
        glEnd();
        glPopMatrix();
    }
}

void Carta::setAngulo(float ang)
{
    angulo=ang;
}

void Carta::setColorFondo(const Pixel color)
{
    colorDorso = color;
}

void Carta::setFigura(char pTipoDeFigura, Pixel color)
{
    if(figura!=nullptr)
        delete figura;

    switch (pTipoDeFigura) {
    case FIG_TRIANGULO:
        figura = new Trianglo(color);
        break;
    case FIG_CUADRADO:
        figura = new Cuadrado(color);
        break;
    case FIG_CRUZ:
        figura = new Cruz(color);
        break;
    case FIG_ANILLO:
        figura = new Anillo(color);
        break;
    case FIG_CIRCULO:
        figura = new Circulo(color);
        break;
    case FIG_ESTRELLA:
        figura = new Estrella(color);
        break;
    case FIG_FLECHA:
        figura = new Flecha(color);
        break;
    case FIG_ONDA:
        figura = new Onda(color);
        break;
    case FIG_ESPIRAL:
        figura = new Espiral(color);
        break;
    default:
        break;
    }
}

bool Carta::getVisible() const
{
    return visible;
}

void Carta::setVisible(bool value)
{
    visible = value;
    angulo=0;
}

bool Carta::getEstaEmparejada() const
{
    return estaEmparejada;
}

void Carta::setEstaEmparejada(bool value)
{
    estaEmparejada = value;
}

unsigned Carta::getId() const
{
    return id;
}



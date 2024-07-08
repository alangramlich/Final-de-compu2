#include "tablero.h"

#include <QOpenGLFunctions>

Tablero::Tablero()
{
    *this = Tablero(8, 8);
}

Tablero::Tablero(unsigned int pCantFil, unsigned int pCantCol)
{
    cantFilas = pCantFil;
    cantColumnas = pCantCol;

    minX = -1;
    maxX = cantColumnas + 1;
    minY = -1;
    maxY = cantFilas + 1;
}

void Tablero::dibujar()
{
    // Dibujo cuadros negros:
    int lado = 1;
    for(int fil=0; fil<cantFilas; ++fil){
        for(int col=0; col<cantColumnas; ++col){
            if(fil%2==0 && col%2==1){
                dibujarCuadrado(col, fil, lado);
            }else
                if(fil%2==1 && col%2==0){
                    dibujarCuadrado(col, fil, lado);
                }
        }
    }

    // Borde gris
    {
        float anchoBorde = 0.5;
        // Borde inferior
        dibujarRectangulo(-anchoBorde,-anchoBorde, cantColumnas + 2*anchoBorde, anchoBorde);
        // Borde derecho
        dibujarRectangulo(cantColumnas, 0, anchoBorde, cantFilas);
        // Borde izquierdo
        dibujarRectangulo(-anchoBorde, 0, anchoBorde, cantFilas);
        // Borde superior
        dibujarRectangulo(-anchoBorde, cantFilas, cantColumnas + 2*anchoBorde, anchoBorde);
    }
    //Botones
    dibujarBotones();
}

void Tablero::setCantFilas(unsigned int value)
{
    cantFilas = value;
    maxY = cantFilas + 1;
}

void Tablero::setCantColumnas(unsigned int value)
{
    cantColumnas = value;
    maxX = cantColumnas + 1;
}

void Tablero::dibujarCuadrado(float x1, float y1, float lado)
{
    // Dibujo
    glColor3f(0,0,0);
    // Base
    glBegin(GL_POLYGON);{
        glVertex2f(x1, y1);
        glVertex2f(x1 + lado, y1);
        glVertex2f(x1 + lado, y1 + lado);
        glVertex2f(x1, y1 + lado);
    }glEnd();
}

void Tablero::dibujarRectangulo(float x1, float y1, float lado1, float lado2)
{
    // Dibujo
    glColor3f(0.5,0.5,0.5);
    // Base
    glBegin(GL_POLYGON);{
        glVertex2f(x1, y1);
        glVertex2f(x1 + lado1, y1);
        glVertex2f(x1 + lado1, y1 + lado2);
        glVertex2f(x1, y1 + lado2);
    }glEnd();
}

void Tablero::dibujarBotones()
{
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);{
        glVertex2f(cantColumnas+0.5, (float)cantFilas/2);
        glVertex2f(cantColumnas+1.5, (float)cantFilas/2);
        glVertex2f(cantColumnas+1.5, (float)cantFilas+0.5);
        glVertex2f(cantColumnas+0.5, (float)cantFilas+0.5);
        glEnd();
    }
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);{
        glVertex2f(cantColumnas+0.5, 0-0.5);
        glVertex2f(cantColumnas+1.5, 0-0.5);
        glVertex2f(cantColumnas+1.5, (float)cantFilas/2);
        glVertex2f(cantColumnas+0.5, (float)cantFilas/2);
        glEnd();
    }
}

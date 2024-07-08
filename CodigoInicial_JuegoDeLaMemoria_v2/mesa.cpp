#include "mesa.h"

#include <algorithm>

Mesa::Mesa()
{

}

Mesa::~Mesa()
{

}

void Mesa::dibujar()
{
    for (unsigned f=0; f < cantFilas; ++f) {
        glPushMatrix();{
            glTranslatef(-1.1f, f + f*0.1f,  0.0f);
            for (unsigned c=0; c< cantColumnas; ++c) {
                glTranslatef(1.1f, 0,  0.0f);
                distribucionDeCartas[f][c]->dibujar();
            }
        }glPopMatrix();
    }
}


unsigned Mesa::getCantFilas() const
{
    return cantFilas;
}

unsigned Mesa::getCantColumnas() const
{
    return cantColumnas;
}

void Mesa::repartirCartas(unsigned pCantFilas, unsigned pCantColumnas, vector<Carta*> mazoDeCartas)
{
    if (pCantFilas * pCantColumnas == mazoDeCartas.size()) {
        cantFilas = pCantFilas;
        cantColumnas = pCantColumnas;
        this->mazoDeCartas = mazoDeCartas;

        // Se Mezclan las cartas
        mezclarCartas();

        // Se reparten las cartas en el tablero
        distribucionDeCartas.resize(pCantFilas);
        for (unsigned i =0; i<pCantFilas; ++i) {
            distribucionDeCartas[i].resize(pCantColumnas);
            for (unsigned j =0; j<pCantColumnas; ++j) {
                distribucionDeCartas[i][j] = this->mazoDeCartas[j+i*pCantColumnas];
            }
        }
    }
}

void Mesa::mezclarCartas()
{
    // Se mezclan
    random_shuffle(mazoDeCartas.begin(), mazoDeCartas.end());

    // Se ponen boca abajo
    for (unsigned i=0; i<mazoDeCartas.size(); ++i) {
        mazoDeCartas[i]->setEstaEmparejada(false);
        mazoDeCartas[i]->setVisible(false);
    }
}

Carta* Mesa::operator()(unsigned fil, unsigned col)
{
    if (distribucionDeCartas.size() > 0
            && fil < distribucionDeCartas.size()
            && col < distribucionDeCartas[0].size())
        return distribucionDeCartas[fil][col];
    else
        return nullptr;
}

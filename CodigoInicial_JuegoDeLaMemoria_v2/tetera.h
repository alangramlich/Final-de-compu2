#ifndef TETERA_H
#define TETERA_H

#include "figura.h"

class Tetera: public Figura
{
public:
    Tetera(Pixel pColor);
    ~Tetera();

    void dibujar();
};

#endif // TETERA_H
